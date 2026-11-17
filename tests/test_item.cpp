// tests/test_item.cpp
// GoogleTest suite for Item, Book, Game, and Audiobook.
// Built by the item_tests target in CMakeLists.txt (links person, patron, item, gtest_main).

#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "Item.h"
#include "Book.h"
#include "Game.h"
#include "Audiobook.h"
#include "Patron.h"

// -----------------------------
// Helpers
// -----------------------------

// Feeds a string to std::cin for as long as this object exists,
// so create_item() reads it instead of waiting for keyboard input.
// clear() resets cin's error/EOF flags, which belong to cin itself
// and would otherwise leak from one test into the next.
class FakeInput {
    std::istringstream input;
    std::streambuf* original;
public:
    explicit FakeInput(const std::string& text) : input(text) {
        original = std::cin.rdbuf(input.rdbuf());
        std::cin.clear();
    }
    ~FakeInput() {
        std::cin.rdbuf(original);
        std::cin.clear();
    }
};

// Silences the "Title: " style prompts create_item() prints,
// so test output stays readable.
class QuietOutput {
    std::ostringstream sink;
    std::streambuf* original;
public:
    QuietOutput() { original = std::cout.rdbuf(sink.rdbuf()); }
    ~QuietOutput() { std::cout.rdbuf(original); }
};

// Every test makes patrons through this one function.
// If Patron's constructor changes, update ONLY this function.
// Person's constructor throws on id <= 0 or an empty name/email/password.
static Patron makePatron(const std::string& name, int id) {
    return Patron(id, name, name + "@example.com", "password");
}

// Builds an item of type T from fake input in one call.
template <typename T>
static T makeItem(const std::string& inputLines) {
    T item;
    FakeInput in(inputLines);
    QuietOutput quiet;
    item.create_item();
    return item;
}

static bool contains(const std::string& haystack, const std::string& needle) {
    return haystack.find(needle) != std::string::npos;
}

// Input lines must match the ORDER of prompts in each create_item(),
// one line per getline / cin >>.
// Book:      Title, Author, Pages
// Game:      Title, Rating
// Audiobook: Title, Author, Narrator, Total Minutes
const std::string BOOK_INPUT      = "Dune\nFrank Herbert\n412\n";
const std::string LONG_BOOK_INPUT = "The Left Hand of Darkness\nUrsula K. Le Guin\n304\n";
const std::string GAME_INPUT      = "Stardew Valley\nE\n";
const std::string AUDIO_INPUT     = "Project Hail Mary\nAndy Weir\nRay Porter\n970\n";

// -----------------------------
// Book
// -----------------------------

TEST(BookTest, CreateItemReadsAllFields) {
    Book b = makeItem<Book>(BOOK_INPUT);
    std::string out = b.display_item();
    EXPECT_TRUE(contains(out, "Dune"));
    EXPECT_TRUE(contains(out, "Frank Herbert"));
    EXPECT_TRUE(contains(out, "412"));
}

TEST(BookTest, TitleWithSpacesIsKept) {
    Book b = makeItem<Book>(LONG_BOOK_INPUT);
    EXPECT_TRUE(contains(b.display_item(), "The Left Hand of Darkness"));
}

// -----------------------------
// Game
// -----------------------------

TEST(GameTest, CreateItemReadsAllFields) {
    Game g = makeItem<Game>(GAME_INPUT);
    std::string out = g.display_item();
    EXPECT_TRUE(contains(out, "Stardew Valley"));
    EXPECT_TRUE(contains(out, "Rated:  E"));
}

// -----------------------------
// Audiobook
// -----------------------------

TEST(AudiobookTest, CreateItemReadsAllFields) {
    Audiobook a = makeItem<Audiobook>(AUDIO_INPUT);
    std::string out = a.display_item();
    EXPECT_TRUE(contains(out, "Project Hail Mary"));
    EXPECT_TRUE(contains(out, "Andy Weir"));
    EXPECT_TRUE(contains(out, "Ray Porter"));
    EXPECT_TRUE(contains(out, "970"));
}

// -----------------------------
// display_short_name (shared in Item)
// -----------------------------

TEST(ShortNameTest, LongTitleIsCutTo15) {
    Book b = makeItem<Book>(LONG_BOOK_INPUT);
    EXPECT_EQ(b.display_short_name(), "The Left Hand o");
    EXPECT_EQ(b.display_short_name().size(), 15u);
}

TEST(ShortNameTest, ShortTitleIsUnchanged) {
    Book b = makeItem<Book>(BOOK_INPUT);
    EXPECT_EQ(b.display_short_name(), "Dune");
}

TEST(ShortNameTest, WorksForEverySubclass) {
    Game g = makeItem<Game>(GAME_INPUT);
    Audiobook a = makeItem<Audiobook>(AUDIO_INPUT);
    EXPECT_EQ(g.display_short_name(), "Stardew Valley");     // 14 chars, unchanged
    EXPECT_EQ(a.display_short_name(), "Project Hail Ma");    // cut to 15
}

// -----------------------------
// Hold queue (shared in Item)
// -----------------------------

TEST(HoldQueueTest, StartsEmpty) {
    Book b;
    EXPECT_FALSE(b.hasHolds());
    EXPECT_EQ(b.nextHold(), nullptr);
}

TEST(HoldQueueTest, FirstInFirstOut) {
    Book b;
    Patron alice = makePatron("Alice", 200000001);
    Patron bob   = makePatron("Bob",   200000002);

    b.addHold(&alice);
    b.addHold(&bob);

    ASSERT_TRUE(b.hasHolds());
    EXPECT_EQ(b.nextHold(), &alice);
    EXPECT_EQ(b.nextHold(), &bob);
    EXPECT_FALSE(b.hasHolds());
}

TEST(HoldQueueTest, EmptyAfterDrainReturnsNull) {
    Game g;
    Patron alice = makePatron("Alice", 200000001);
    g.addHold(&alice);
    g.nextHold();
    EXPECT_EQ(g.nextHold(), nullptr);
}

// -----------------------------
// Polymorphism through Item*
// -----------------------------

TEST(PolymorphismTest, BasePointerCallsSubclassVersion) {
    std::unique_ptr<Item> item = std::make_unique<Book>();
    {
        FakeInput in(BOOK_INPUT);
        QuietOutput quiet;
        item->create_item();
    }
    EXPECT_TRUE(contains(item->display_item(), "Book: Dune"));
}

TEST(PolymorphismTest, EachSubclassDescribesItselfDifferently) {
    Book b = makeItem<Book>(BOOK_INPUT);
    Game g = makeItem<Game>(GAME_INPUT);
    Audiobook a = makeItem<Audiobook>(AUDIO_INPUT);

    Item* items[] = { &b, &g, &a };
    EXPECT_NE(items[0]->display_item(), items[1]->display_item());
    EXPECT_NE(items[1]->display_item(), items[2]->display_item());
}
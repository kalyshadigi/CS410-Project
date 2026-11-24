#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>
#include "Catalog.h"
#include "Item.h"

// Minimal concrete subclass in case Item is abstract or requires specific fields.
// Adjust constructor/overrides to match your Item.h definition.
class TestItem : public Item {
private:
    std::string title;
public:
    explicit TestItem(const std::string& t) : title(t) {}

    std::string getTitle() const {
        return title;
    }

    void display() const override {
        std::cout << "Item: " << title << std::endl;
    }
};

class CatalogTest : public ::testing::Test {
protected:
    Catalog catalog;
    TestItem* book1 = nullptr;
    TestItem* book2 = nullptr;

    void SetUp() override {
        book1 = new TestItem("Dune");
        book2 = new TestItem("Neuromancer");
    }

    void TearDown() override {
        delete book1;
        delete book2;
    }
};

TEST_F(CatalogTest, AddAndFindExistingItem) {
    catalog.addItem(book1);
    catalog.addItem(book2);

    Item* found = catalog.findItem("Neuromancer");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getTitle(), "Neuromancer");
}

TEST_F(CatalogTest, FindNonExistentItemReturnsNullptr) {
    catalog.addItem(book1);

    Item* found = catalog.findItem("Foundation");
    EXPECT_EQ(found, nullptr);
}

TEST_F(CatalogTest, AddNullItemIsIgnored) {
    catalog.addItem(nullptr);

    EXPECT_EQ(catalog.findItem("Dune"), nullptr);
}

TEST_F(CatalogTest, RemoveExistingItemSucceedsAndRemovesFromCatalog) {
    catalog.addItem(book1);
    catalog.addItem(book2);

    bool removed = catalog.removeItem("Dune");
    EXPECT_TRUE(removed);
    EXPECT_EQ(catalog.findItem("Dune"), nullptr);
    EXPECT_NE(catalog.findItem("Neuromancer"), nullptr);
}

TEST_F(CatalogTest, RemoveNonExistentItemReturnsFalse) {
    catalog.addItem(book1);

    bool removed = catalog.removeItem("NonExistentTitle");
    EXPECT_FALSE(removed);
}

TEST_F(CatalogTest, DisplayEmptyCatalogPrintsMessage) {
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    catalog.displayCatalog();

    std::cout.rdbuf(oldCout);
    EXPECT_NE(buffer.str().find("Catalog is empty"), std::string::npos);
}

TEST_F(CatalogTest, DisplayPopulatedCatalogOutputsItems) {
    catalog.addItem(book1);
    catalog.addItem(book2);

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    catalog.displayCatalog();

    std::cout.rdbuf(oldCout);
    std::string output = buffer.str();
    EXPECT_NE(output.find("Dune"), std::string::npos);
    EXPECT_NE(output.find("Neuromancer"), std::string::npos);
}
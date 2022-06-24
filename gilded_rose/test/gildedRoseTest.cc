#include <vector>
#include <iterator>
#include <gtest/gtest.h>
#include "../src/GildedRose.h"


// todo
//
// overload << for helpful diagnostic output for failed tests.
//     need to figure out how to do this without crashing gtest
// improve test names


using std::vector;
using std::string;


struct TestDataStruct {
    string test_name;
    Item input;
    Item expected;
};

class GildedRoseTest :
public testing::TestWithParam<struct TestDataStruct> {
};

TEST(gilded_rose_test, noItems_yields_noItems) {
    vector<Item> items;
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(items.size(), 0);
}

TEST(gilded_rose_test, twoItems_yields_twoItems) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 0, 47));
    items.push_back(Item("AllOtherNames", 0, 3));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(items.size(), 2);
    EXPECT_EQ(items[0].name,    "Aged Brie");
    EXPECT_EQ(items[0].sellIn,  -1);
    EXPECT_EQ(items[0].quality, 49);
    EXPECT_EQ(items[1].name,    "AllOtherNames");
    EXPECT_EQ(items[1].sellIn,  -1);
    EXPECT_EQ(items[1].quality, 1);
}

INSTANTIATE_TEST_SUITE_P(
    AgedBrie,
    GildedRoseTest,
    testing::Values(
        TestDataStruct {
            "AgedBrie_1_10_DecreaseSellInAndIncreaseQuality",
            Item("Aged Brie", 1, 10),
            Item("Aged Brie", 0, 11)
        },
        TestDataStruct {
            "AgedBrie_0_0_DecreaseSellInAndIncreaseQuality",
            Item("Aged Brie", 0, 0),
            Item("Aged Brie", -1, 2)
        },
        TestDataStruct {
            "AgedBrie_0_40_DecrementsSellinAndDoubleIncrementsQuality",
            Item("Aged Brie", 0, 40),
            Item("Aged Brie", -1, 42)
        },
        TestDataStruct {
            "AgedBrie_0_47_DecrementsSellInAndDoubleIncrementsQuality",
            Item("Aged Brie", 0, 47),
            Item("Aged Brie", -1, 49)
        },
        TestDataStruct {
            "AgedBrie_0_48_DecrementsSellInAndDoubleIncrementsQuality",
            Item("Aged Brie", 0, 48),
            Item("Aged Brie", -1, 50)
        },
        TestDataStruct {
            "AgedBrie_0_49_DecrementsSellInAndIncrementsQuality",
            Item("Aged Brie", 0, 49),
            Item("Aged Brie", -1, 50)
        },
        TestDataStruct {
            "AgedBrie_0_50_DecrementsSellIn",
            Item("Aged Brie", 0, 50),
            Item("Aged Brie", -1, 50)
        },
        TestDataStruct {
            "AgedBrie_0_60_DecrementsSellin",
            Item("Aged Brie", 0, 60),
            Item("Aged Brie", -1, 60)
        },
        TestDataStruct {
            "AgedBrie_1_40_DecrementsSellinAndIncrementsQuality",
            Item("Aged Brie", 1, 40),
            Item("Aged Brie", 0, 41)
        },
        TestDataStruct {
            "AgedBrie_1_49_DecrementsSellinAndIncrementsQuality",
            Item("Aged Brie", 1, 49),
            Item("Aged Brie", 0, 50)
        },
        TestDataStruct {
            "AgedBrie_1_50_DecrementsSellin",
            Item("Aged Brie", 1, 50),
            Item("Aged Brie", 0, 50)
        },
        TestDataStruct {
            "AgedBrie_1_51_DecrementsSellin",
            Item("Aged Brie", 1, 51),
            Item("Aged Brie", 0, 51)
        },
        TestDataStruct {
            "AgedBrie_1_99_DecrementsSellin",
            Item("Aged Brie", 1, 99),
            Item("Aged Brie", 0, 99)
        },
        TestDataStruct {
            "BackstagePass_0_0_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 0),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_99_50_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 99, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 98, 50)
        },
        TestDataStruct {
            "BackstagePass_99_49_DecreaseSellInAndIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 99, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 98, 50)
        },
        TestDataStruct {
            "BackstagePass_11_50_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 11, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 50)
        },
        TestDataStruct {
            "BackstagePass_11_49_DecreaseSellInAndIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 11, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 50)
        },
        TestDataStruct {
            "BackstagePass_10_50_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 9, 50)
        },
        TestDataStruct {
            "BackstagePass_10_49_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 9, 50)
        },
        TestDataStruct {
            "BackstagePass_6_51_DecrementsSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 6, 51),
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 51)
        },
        TestDataStruct {
            "BackstagePass_6_50_DecrementsSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 6, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 50)
        },
        TestDataStruct {
            "BackstagePass_6_49_DecrementsSellInIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 6, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 50)
        },
        TestDataStruct {
            "BackstagePass_6_48_DecrementsSellInDoubleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 6, 48),
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 50)
        },
        TestDataStruct {
            "BackstagePass_6_47_DecrementsSellInDoubleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 6, 47),
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 49)
        },
        TestDataStruct {
            "BackstagePass_5_51_DecrementsSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 51),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 51)
        },
        TestDataStruct {
            "BackstagePass_5_50_DecrementsSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 50)
        },
        TestDataStruct {
            "BackstagePass_5_49_DecrementsSellInAndIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 50)
        },
        TestDataStruct {
            "BackstagePass_5_48_DecrementsSellInAndDoubleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 48),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 50)
        },
        TestDataStruct {
            "BackstagePass_5_47_DecrementsSellInAndTripleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 47),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 50)
        },
        TestDataStruct {
            "BackstagePass_5_46_DecrementsSellInAndTripleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 46),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 49)
        },
        TestDataStruct {
            "BackstagePass_1_51_DecrementsSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 1, 51),
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 51)
        },
        TestDataStruct {
            "BackstagePass_1_50_DecrementsSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 1, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 50)
        },
        TestDataStruct {
            "BackstagePass_1_49_DecrementsSellInAndIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 1, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 50)
        },
        TestDataStruct {
            "BackstagePass_1_48_DecrementsSellInAndDoubleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 1, 48),
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 50)
        },
        TestDataStruct {
            "BackstagePass_1_47_DecrementsSellInAndTripleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 1, 47),
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 50)
        },
        TestDataStruct {
            "BackstagePass_1_46_DecrementsSellInAndTripleIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 1, 46),
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 49)
        },
        TestDataStruct {
            "BackstagePass_0_51_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 51),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_0_50_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_0_49_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_0_48_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 48),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_0_47_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 47),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_0_46_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 46),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_0_45_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 45),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_Minus99_51_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", -99, 51),
            Item("Backstage passes to a TAFKAL80ETC concert", -100, 0)
        },
        TestDataStruct {
            "BackstagePass_Minus99_50_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", -99, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", -100, 0)
        },
        TestDataStruct {
            "BackstagePass_Minus99_49_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", -99, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", -100, 0)
        },
        TestDataStruct {
            "BackstagePass_Minus99_48_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", -99, 48),
            Item("Backstage passes to a TAFKAL80ETC concert", -100, 0)
        },
        TestDataStruct {
            "BackstagePass_Minus99_47_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", -99, 47),
            Item("Backstage passes to a TAFKAL80ETC concert", -100, 0)
        },
        TestDataStruct {
            "BackstagePass_Minus99_46_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", -99, 46),
            Item("Backstage passes to a TAFKAL80ETC concert", -100, 0)
        },
        TestDataStruct {
            "BackstagePass_Minus99_45_DecrementsSellInAndZerosQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", -99, 45),
            Item("Backstage passes to a TAFKAL80ETC concert", -100, 0)
        },
        TestDataStruct {
            "Sulfuras_0_1_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", 0, 1),
            Item("Sulfuras, Hand of Ragnaros", 0, 1)
        },
        TestDataStruct {
            "Sulfuras_0_700_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", 0, 700),
            Item("Sulfuras, Hand of Ragnaros", 0, 700)
        },
        TestDataStruct {
            "Sulfuras_1_700_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", 1, 700),
            Item("Sulfuras, Hand of Ragnaros", 1, 700)
        },
        TestDataStruct {
            "Sulfuras_Negative1_700_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", -1, 700),
            Item("Sulfuras, Hand of Ragnaros", -1, 700)
        },
        TestDataStruct {
            "AllOtherNames_Negative1_0_DecrementsSellIn",
            Item("AllOtherNames", -1, 0),
            Item("AllOtherNames", -2, 0)
        },
        TestDataStruct {
            "AllOtherNames_Negative1_1_DecrementsSellInAndQuality",
            Item("AllOtherNames", -1, 1),
            Item("AllOtherNames", -2, 0)
        },
        TestDataStruct {
            "AllOtherNames_0_0_DecrementsSellIn",
            Item("AllOtherNames", 0, 0),
            Item("AllOtherNames", -1, 0)
        },
        TestDataStruct {
            "AllOtherNames_0_1_DecrementsSellInAndQuality",
            Item("AllOtherNames", 0, 1),
            Item("AllOtherNames", -1, 0)
        },
        TestDataStruct {
            "AllOtherNames_0_2_DecrementsSellInAndDoubleDecrementsQuality",
            Item("AllOtherNames", 0, 2),
            Item("AllOtherNames", -1, 0)
        },
        TestDataStruct {
            "AllOtherNames_0_3_DecrementsSellInAndDoubleDecrementsQuality",
            Item("AllOtherNames", 0, 3),
            Item("AllOtherNames", -1, 1)
        },
        TestDataStruct {
            "AllOtherNames_1_0_DecrementsSellIn",
            Item("AllOtherNames", 1, 0),
            Item("AllOtherNames", 0, 0)
        },
        TestDataStruct {
            "AllOtherNames_1_1_DecrementsSellInAndQuality",
            Item("AllOtherNames", 1, 1),
            Item("AllOtherNames", 0, 0)
        },
        TestDataStruct {
            "AllOtherNames_2_0_DecrementsSellIn",
            Item("AllOtherNames", 2, 0),
            Item("AllOtherNames", 1, 0)
        },
        TestDataStruct {
            "AllOtherNames_2_1_DecrementsSellInAndQuality",
            Item("AllOtherNames", 2, 1),
            Item("AllOtherNames", 1, 0)
        }
    ),
    [](const testing::TestParamInfo<GildedRoseTest::ParamType>& test_data) {
        return test_data.param.test_name;}
    );

TEST_P(GildedRoseTest, TestUpdateQuality_ItemName_SellIn_Quality){
    vector<Item> items;
    struct TestDataStruct parameters = GetParam();
    Item inputItem = parameters.input;
    Item expected = parameters.expected;
    items.push_back(inputItem);
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(items.size(), 1);
    EXPECT_EQ(items[0].name,    expected.name);
    EXPECT_EQ(items[0].sellIn,  expected.sellIn);
    EXPECT_EQ(items[0].quality, expected.quality);
}

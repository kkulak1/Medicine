#include "catch.hpp"
#include "../date.h"
#include "../producer.h"
#include "../ingredient.h"
#include "../medicine.h"
#include <stdexcept>

TEST_CASE("date simple tests", "[date]")
{
    Date date(10, 9, 2000);

    CHECK(date.get_day() == 10);
    CHECK(date.get_month() == 9);
    CHECK(date.get_year() == 2000);

    SECTION("test set day")
    {
        date.set_day(2);
        CHECK(date.get_day() == 2);
        CHECK(date.get_month() == 9);
        CHECK(date.get_year() == 2000);
    }

    SECTION("test set month")
    {
        date.set_month(2);
        CHECK(date.get_day() == 10);
        CHECK(date.get_month() == 2);
        CHECK(date.get_year() == 2000);
    }

    SECTION("test set year")
    {
        date.set_year(2001);
        CHECK(date.get_day() == 10);
        CHECK(date.get_month() == 9);
        CHECK(date.get_year() == 2001);
    }

    SECTION("test errors")
    {
        CHECK_THROWS(date.set_day(200));
        CHECK_THROWS(date.set_day(0));
        CHECK_THROWS(date.set_day(-1));
        CHECK_THROWS(date.set_month(200));
        CHECK_THROWS(date.set_month(0));
        CHECK_THROWS(date.set_month(-1));
        CHECK_THROWS(date.set_year(0));

        date.set_month(2);
        date.set_year(2001);

        CHECK_THROWS(date.set_day(29));
    }
}

TEST_CASE("Producer simple tests", "[producer]")
{
    Producer producer("Jan Kowalski", "Warszawa");

    CHECK(producer.get_name() == "Jan Kowalski");
    CHECK(producer.get_address() == "Warszawa");

    SECTION("test setters")
    {
        producer.set_name("Maciek Wysocki");
        producer.set_address("Suwalki");

        CHECK(producer.get_name() == "Maciek Wysocki");
        CHECK(producer.get_address() == "Suwalki");
    }
}

TEST_CASE("Ingredient tests", "[ingredient]")
{
    Ingredient ingredient("cynk", 200);

    CHECK(ingredient.get_name() == "cynk");
    CHECK(ingredient.get_amount() == 200);

    SECTION("test setters")
    {
        ingredient.set_name("zelazo");
        ingredient.set_amount(30);

        CHECK(ingredient.get_name() == "zelazo");
        CHECK(ingredient.get_amount() == 30);
    }
}

TEST_CASE("Medicine test", "[medicine]")
{
    Date date(10, 9, 2000);
    Producer producer("Jan Kowalski", "Warszawa");
    vector<Ingredient> ingredients;
    Ingredient ingredient1("cynk", 200);
    Ingredient ingredient2("zelazo", 300);
    Ingredient ingredient5("sol", 20);
    ingredients.push_back(ingredient1);
    ingredients.push_back(ingredient2);
    Medicine medicine("duac", 100, "duax", 2, producer, 1, date, ingredients);

    CHECK(medicine.get_name() == "duac");
    CHECK(medicine.get_capacity() == 100);
    CHECK(medicine.get_active_substance_name() == "duax");
    CHECK(medicine.get_dose() == 2);
    CHECK(medicine.get_producer().get_name() == "Jan Kowalski");
    CHECK(medicine.get_producer().get_address() == "Warszawa");
    CHECK(medicine.get_nr() == 1);
    CHECK(medicine.get_date().get_day() == 10);
    CHECK(medicine.get_date().get_month() == 9);
    CHECK(medicine.get_date().get_year() == 2000);

    SECTION("test ingredients")
    {
        CHECK(medicine.check_ingredient_in(ingredient1));
        CHECK_FALSE(medicine.check_ingredient_in(ingredient5));

        CHECK(medicine.count_ingredient(200) == 2);
        CHECK(medicine.count_ingredient(300) == 1);
        CHECK(medicine.count_ingredient(400) == 0);

        CHECK_THROWS(medicine.add_ingredient(ingredient1));

        medicine.add_ingredient(ingredient5);

        CHECK(medicine.check_ingredient_in(ingredient5));

        CHECK(medicine.count_ingredient(10) == 3);

        CHECK(medicine.check_ingredient_in(ingredient5));
        CHECK(medicine.check_ingredient_in(ingredient2));

        medicine.delete_ingredient(ingredient2);

        CHECK(medicine.count_ingredient(10) == 2);
        CHECK_FALSE(medicine.check_ingredient_in(ingredient2));

        CHECK_THROWS(medicine.delete_ingredient(ingredient2));

        CHECK(medicine.check_ingredient_in(ingredient1));
        CHECK(medicine.check_ingredient_in(ingredient5));

        Ingredient ingredient3("losa", 50);
        Ingredient ingredient4("masa", 300);

        CHECK_FALSE(medicine.check_ingredient_in(ingredient3));

        medicine.add_ingredient(ingredient3);

        CHECK(medicine.check_ingredient_in(ingredient3));

        medicine.modify_ingredient(ingredient3, ingredient4);

        CHECK_FALSE(medicine.check_ingredient_in(ingredient3));
        CHECK(medicine.check_ingredient_in(ingredient4));

        medicine.operatorposti();
        CHECK(medicine.get_capacity() == 101);

        medicine.operatorpred();
        CHECK(medicine.get_capacity() == 100);

        medicine.operatorpostd();
        CHECK(medicine.get_capacity() == 99);

        medicine.operatorprei();
        CHECK(medicine.get_capacity() == 100);
    }
}

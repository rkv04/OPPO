#include <boost/test/unit_test.hpp>

#include "../src/utils.hpp"
#include "../src/fish.hpp"
#include "../src/sea.hpp"

BOOST_AUTO_TEST_SUITE(TestUtilsClass)

BOOST_AUTO_TEST_CASE(test_strToFloat_function_on_valid_data) {
	BOOST_CHECK_NO_THROW(strToFloat("3.1415"));
}

BOOST_AUTO_TEST_CASE(test_strToFloat_function_on_invalid_data) {
	std::vector<std::string> invalid_data_set = {"*.001", "float", "3.14p15"};
	for (auto i : invalid_data_set) {
		BOOST_CHECK_THROW(strToFloat(i), std::invalid_argument);
	}
}

BOOST_AUTO_TEST_CASE(test_parseLine_function_on_valid_data) {
	std::string valid_line = "\"Средиземное море\" 5109 0.38 скумбрия минтай";
	std::vector<std::string> valid_vector = {"Средиземное море", "5109", "0.38", "скумбрия", "минтай"};
	std::vector<std::string> result_vector;
	parseLine(valid_line, result_vector, ' ');
	BOOST_CHECK_EQUAL_COLLECTIONS(result_vector.begin(), result_vector.end(), valid_vector.begin(), valid_vector.end());
}

BOOST_AUTO_TEST_CASE(test_parseLine_function_on_invalid_data) {
	std::string lineWithoutQuote = "\"Средиземное море 5109 0.38       скумбрия минтай";
	std::vector<std::string> resultVector;
	BOOST_CHECK_THROW(parseLine(lineWithoutQuote, resultVector, ' '), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(TestSeaClass)

BOOST_AUTO_TEST_CASE(test_validate_title_function_on_valid_data) {
	BOOST_CHECK_NO_THROW(Sea::validateTitle("Средиземное море"));
}

BOOST_AUTO_TEST_CASE(test_validate_title_function_on_invalid_data) {
	BOOST_CHECK_THROW(Sea::validateTitle("Средизе8ное море"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_validate_depth_function_on_valid_data) {
	BOOST_CHECK_NO_THROW(Sea::validateDepth(5109));
}

BOOST_AUTO_TEST_CASE(test_validate_depth_function_on_invalid_data) {
	BOOST_CHECK_THROW(Sea::validateDepth(-5109), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_validate_salinity_function_on_valid_data) {
	BOOST_CHECK_NO_THROW(Sea::validateSalinity(0.38));
}

BOOST_AUTO_TEST_CASE(test_validate_salinity_function_on_invalid_data) {
	BOOST_CHECK_THROW(Sea::validateSalinity(3.8), std::runtime_error);
	BOOST_CHECK_THROW(Sea::validateSalinity(-0.38), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_validate_function_on_valid_data) {
	BOOST_CHECK_NO_THROW(Sea::validateData("Средиземное море", 5109, 0.38));
}

BOOST_AUTO_TEST_CASE(test_validate_function_on_invalid_data) {
	BOOST_CHECK_THROW(Sea::validateData("Средиземное море", 5109, 3.8), std::runtime_error);
	BOOST_CHECK_THROW(Sea::validateData("Средиземное море", 5109, -0.38), std::runtime_error);
	BOOST_CHECK_THROW(Sea::validateData("Средиземное море", -5109, 0.38), std::runtime_error);
	BOOST_CHECK_THROW(Sea::validateData("Средиз2мное море", 5109, 0.38), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_constructor_on_valid_data) {
	const std::vector<std::vector<std::string>> valid_data_set = {
		{"Средиземное море", "5109", "0.38", "скумбрия", "минтай"},
		{"Средиземное море", "5109", "0.38"}
	};
	for (auto i : valid_data_set) {
		BOOST_CHECK_NO_THROW(Sea sea(i));
	}
}

BOOST_AUTO_TEST_CASE(test_constructor_on_invalid_data) {
	const std::vector<std::vector<std::string>> invalid_data_set = {
		{"Средиземное море", "0.39"},
		{"Средиземное море", "5109", "1.1", "скумбрия", "минтай"},
		{"Средиземное море", "-5109", "0.38", "скумбрия", "минтай"}
	};
	for (auto i : invalid_data_set) {
		BOOST_CHECK_THROW(Sea sea(i), std::runtime_error);
	}
}

BOOST_AUTO_TEST_SUITE_END()
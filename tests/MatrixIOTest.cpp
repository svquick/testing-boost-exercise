#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
#include <Eigen/Dense>
#include <fstream>

BOOST_AUTO_TEST_SUITE(MatrixTest)

BOOST_AUTO_TEST_CASE(MatrixIOOpenData)
{
    std::string filename = "data/m3.csv";
    int expectedSize = 3;

    Eigen::MatrixXd m = matrixIO::openData(filename, expectedSize);

    BOOST_REQUIRE_EQUAL(m.rows(), expectedSize);
    BOOST_CHECK_CLOSE(m(0, 0), 0.680375, 0.001);
    BOOST_CHECK_CLOSE(m(0, 1),  0.59688,   0.001);
    BOOST_CHECK_CLOSE(m(0, 2), -0.329554, 0.001);
    BOOST_CHECK_CLOSE(m(1, 0), -0.211234, 0.001);
    BOOST_CHECK_CLOSE(m(1, 1),  0.823295,  0.001);
    BOOST_CHECK_CLOSE(m(1, 2),  0.536459,  0.001);
    BOOST_CHECK_CLOSE(m(2, 0),  0.566198,  0.001);
    BOOST_CHECK_CLOSE(m(2, 1), -0.604897, 0.001);
    BOOST_CHECK_CLOSE(m(2, 2), -0.444451, 0.001);
}

BOOST_AUTO_TEST_SUITE_END()
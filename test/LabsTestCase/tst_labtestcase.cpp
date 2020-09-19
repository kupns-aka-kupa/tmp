#include <QtTest>

#include <iostream>
#include "../../labs/v1.hpp"
#include "../../labs/v9.hpp"

class LabsTestCase : public QObject
{
    Q_OBJECT
    size_t n;

public:
    LabsTestCase() = default;
    ~LabsTestCase() = default;

private slots:
    void init();
    void initTestCase();
    void cleanupTestCase();
    void v1TestCase();
    void v9TestCase();
};

void LabsTestCase::init() { }

void LabsTestCase::initTestCase() {
    n = 5;
}

void LabsTestCase::cleanupTestCase() { }

void LabsTestCase::v1TestCase()
{
    QBENCHMARK
    {
        auto r = expression_v1(n);
        r = expression_v1(++n);
        r = expression_v1(++n);
        QWARN(std::to_string(r).c_str());
    }
}

void LabsTestCase::v9TestCase()
{
    QBENCHMARK
    {
        auto r = expression_v9(n);
//        QWARN(std::to_string(r).c_str());
    }
}

QTEST_APPLESS_MAIN(LabsTestCase)

#include "tst_labtestcase.moc"

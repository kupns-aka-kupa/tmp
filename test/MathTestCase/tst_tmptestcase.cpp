#include <QtTest>

#include <iostream>
#include "../tmp.hpp"

class LabTestCase : public QObject
{
    Q_OBJECT

public:
    LabTestCase() = default;
    ~LabTestCase() = default;

private slots:
    void initTestCase();
    void cleanupTestCase();
    void factorial_test_case();
    void perm_w_r_test_case();
    void comb_test_case();
    void accom_test_case();
    void accom_w_r_test_case();
    void fibonacci_test_case();
    void power_test_case();
    void is_prime_test_case();

};

void LabTestCase::initTestCase()
{}

void LabTestCase::cleanupTestCase()
{}

void LabTestCase::factorial_test_case()
{
    auto p = permutations<10>::value;
    QCOMPARE(p, 3628800);
    p = permutations<9>::value;
    QCOMPARE(p, 362880);
    p = permutations<5>::value;
    QCOMPARE(p, 120);
}

void LabTestCase::perm_w_r_test_case()
{
    auto p_ = permutations_with_replacement<9, 4>::value;
    QCOMPARE(p_, 1260);
//    p_ = permutations_with_replacement<9, 10>::value;
}

void LabTestCase::comb_test_case()
{
    auto c = combinations<5, 2>::value;
    QCOMPARE(c, 10);
    c = combinations<10, 6>::value;
    QCOMPARE(c, 210);
    c = combinations<10, 7>::value;
    QCOMPARE(c, 120);
}

void LabTestCase::accom_test_case()
{
    auto a = accommodation<12, 4>::value;
    QCOMPARE(a, 11880);
}

void LabTestCase::accom_w_r_test_case()
{
    auto a_ = accommodation_with_replacement<2, 3>::value;
    QCOMPARE(a_, 8);
    a_ = accommodation_with_replacement<3, 5>::value;
    QCOMPARE(a_, 243);
    a_ = constexp_pow<3, 5>::value;
    QCOMPARE(a_, 243);
}

void LabTestCase::fibonacci_test_case()
{
    auto i = fibonacci<10>(0, 1);
    QCOMPARE(i, 144);
}

void LabTestCase::power_test_case()
{
    auto i = power<3>(3);
    QCOMPARE(i, 27);
    i = power<-3>(3);
    QCOMPARE(i, 1 / 27);
}

void LabTestCase::is_prime_test_case()
{
    QVERIFY(is_prime<13>::value);
    QVERIFY(!is_prime<12>::value);
    QVERIFY(!is_prime<144>::value);
    QVERIFY(is_prime<101>::value);
}

QTEST_APPLESS_MAIN(LabTestCase)

#include "tst_tmptestcase.moc"

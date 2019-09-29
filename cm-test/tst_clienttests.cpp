#include <QtTest>

// add necessary includes here

class ClientTests : public QObject
{
    Q_OBJECT

public:
    ClientTests();
    ~ClientTests();

private slots:
    void test_case1();

};

ClientTests::ClientTests()
{

}

ClientTests::~ClientTests()
{

}

void ClientTests::test_case1()
{

}

QTEST_APPLESS_MAIN(ClientTests)

#include "tst_clienttests.moc"

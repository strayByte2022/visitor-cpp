#include <iostream>
#include <string>
using namespace std;
class Building
{
public:
    virtual void accept(class Inspector &v) = 0;
    virtual int getProgress() = 0;
    virtual int getAmountPaid() = 0;
    virtual int getRemainingAmount() = 0;
};

class BuildingA : public Building
{
public:
    void accept(Inspector &v);
    int getProgress()
    {
        return 80;
    }
    int getAmountPaid()
    {
        return 50000;
    }
    int getRemainingAmount()
    {
        return 20000;
    }
};

class BuildingB : public Building
{
public:
    void accept(Inspector &v);
    int getProgress()
    {
        return 60;
    }
    int getAmountPaid()
    {
        return 30000;
    }
    int getRemainingAmount()
    {
        return 15000;
    }
};

class Inspector
{
public:

    // visitor o day 

    virtual void visit(BuildingA *e) = 0;
    virtual void visit(BuildingB *e) = 0;
};

void BuildingA::accept(Inspector &v)
{
    v.visit(this);
}

void BuildingB::accept(Inspector &v)
{
    v.visit(this);
}

class ProjectManagementInspector : public Inspector
{
public:
    void visit(BuildingA *e)
    {
        cout << "Building A progress: " << e->getProgress() << "%\n";
    }

    void visit(BuildingB *e)
    {
        cout << "Building B progress: " << e->getProgress() << "%\n";
    }
};

class FinanceInspector : public Inspector
{
public:
    void visit(BuildingA *e)
    {
        cout << "Building A amount paid: $" << e->getAmountPaid() << "\n";
        cout << "Building A remaining amount: $" << e->getRemainingAmount() << "\n";
    }

    void visit(BuildingB *e)
    {
        cout << "Building B amount paid: $" << e->getAmountPaid() << "\n";
        cout << "Building B remaining amount: $" << e->getRemainingAmount() << "\n";
    }
};

int main()
{
    BuildingA buildingA;
    BuildingB buildingB;

    ProjectManagementInspector pmInspector;
    FinanceInspector financeInspector;

    buildingA.accept(pmInspector);
    buildingA.accept(financeInspector);

    buildingB.accept(pmInspector);
    buildingB.accept(financeInspector);

    return 0;
}

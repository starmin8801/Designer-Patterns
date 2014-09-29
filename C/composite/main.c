#include "new.h"
#include "concreteCompany.h"
#include "financeDepartment.h"
#include "hrDepartment.h"

int main(int argc, char *argv[]) {
    void *root = New(ConcreteCompany, "总公司");
    void *leaf1 = New(FinanceDepartment, "财务部");
    void *leaf2 = New(HRDepartment, "人力资源部");

    Add(root, leaf1);
    Add(root, leaf2);

    void *mid1 = New(ConcreteCompany, "华东分公司");
    void *leaf3 = New(FinanceDepartment, "华东分公司财务部");
    void *leaf4 = New(HRDepartment, "华东分公司人力资源部");

    Add(mid1, leaf3);
    Add(mid1, leaf4);
    Add(root, mid1);

    void *mid2 = New(ConcreteCompany, "南京办事处");
    void *leaf5 = New(FinanceDepartment, "南京办事处财务部");
    void *leaf6 = New(HRDepartment, "南京办事处人力资源部");

    Add(mid2, leaf5);
    Add(mid2, leaf6);
    Add(root, mid2);

    void *mid3 = New(ConcreteCompany, "杭州办事处");
    void *leaf7 = New(FinanceDepartment, "杭州办事处财务部");
    void *leaf8 = New(HRDepartment, "杭州办事处人力资源部");

    Add(mid3, leaf7);
    Add(mid3, leaf8);
    Add(mid2, mid3);

    Display(root, 0);

    Delete(leaf1);
    Delete(leaf2);
    Delete(leaf3);
    Delete(leaf4);
    Delete(leaf5);
    Delete(leaf6);
    Delete(leaf7);
    Delete(leaf8);
    Delete(mid1);
    Delete(mid2);
    Delete(mid3);
    Delete(root);
    
    return 0;
}

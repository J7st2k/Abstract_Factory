#include <QCoreApplication>
#include "Factory.h"
#include <iostream>


std::string generateProgram(Factory& factory) {
    auto myClass = factory.CreateClass( "MyClass" );
    if (myClass == nullptr) {
        return "Out of memory for MyClass";
    }
    myClass->add(
        factory.CreateMethod( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass->add(
        factory.CreateMethod( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE_PROTECTED
        );
    myClass->add(
        factory.CreateMethod( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = factory.CreateMethod( "testFunc4", "void", MethodUnit::STATIC );
    if (method) {
        method->add( factory.CreatePrintOperator( R"(Hello, world!\n)" ) );
        myClass->add( method, ClassUnit::PROTECTED );
    }
    return myClass->compile();
}

int main(int argc, char *argv[])
{
    CPlusFactory CFactory;
    CSharpFactory SFactory;
    JavaFactory JFactory;
    QCoreApplication a(argc, argv);
    std::cout << generateProgram(CFactory) << std::endl;
    std::cout << generateProgram(SFactory) << std::endl;
    std::cout << generateProgram(JFactory) << std::endl;
    return a.exec();
}

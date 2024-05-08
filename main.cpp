#include <QCoreApplication>
#include "ClassUnit.h"
#include "PrintOperatorUnit.h"
#include "MethodUnit.h"
#include <iostream>


std::string generateProgram() {
    CPlusClass myClass( "MyClass" );
    myClass.add(
        std::make_shared< CPlusMethod >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< CPlusMethod >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< CPlusMethod >( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = std::make_shared< CPlusMethod >( "testFunc4", "void", MethodUnit::STATIC );
    method->add( std::make_shared< CPlusPrintOperator >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram() << std::endl;
    return a.exec();
}

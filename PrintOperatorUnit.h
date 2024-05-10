#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "Unit.h"

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
protected:
    std::string m_text;
};

class CPlusPrintOperator : public PrintOperatorUnit
{
public:
    explicit CPlusPrintOperator( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access = "" ) const {
        Q_UNUSED(access)
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

class CSharpPrintOperator : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperator( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access = "" ) const {
        Q_UNUSED(access)
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

class JavaPrintOperator : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperator( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0, std::string access = "" ) const {
        Q_UNUSED(access)
        return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORUNIT_H

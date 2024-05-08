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
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // PRINTOPERATORUNIT_H

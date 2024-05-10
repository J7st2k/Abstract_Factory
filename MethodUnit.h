#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "Unit.h"

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        m_body.push_back( unit );
    }
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class CPlusMethod : public MethodUnit
{
public:
    CPlusMethod ( const std::string& name, const std::string& returnType, Flags flags ) : MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0, std::string access = "" ) const;
};

class CSharpMethod : public MethodUnit
{
public:
    CSharpMethod ( const std::string& name, const std::string& returnType, Flags flags ) : MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0, std::string access = "" ) const;
};

class JavaMethod : public MethodUnit
{
public:
    JavaMethod ( const std::string& name, const std::string& returnType, Flags flags ) : MethodUnit(name, returnType, flags) {}
    std::string compile( unsigned int level = 0, std::string access = "" ) const;
};

#endif // METHODUNIT_H

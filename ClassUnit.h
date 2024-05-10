#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "Unit.h"

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const std::string& name );

 protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class CPlusClass : public ClassUnit
{
public:
    CPlusClass( const std::string& name ):ClassUnit( name ) {}
    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    std::string compile( unsigned int level = 0, std::string access = "" ) const;
};

class CSharpClass : public ClassUnit
{
public:
    CSharpClass( const std::string& name ):ClassUnit( name ) {}
    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    std::string compile( unsigned int level = 0, std::string access = "" ) const;
};


#endif // CLASSUNIT_H

#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "Unit.h"

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit( const std::string& name );
    void add( const std::shared_ptr< Unit >& unit, Flags flags );

 protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class CPlusClass : public ClassUnit
{
public:
    CPlusClass( const std::string& name ):ClassUnit( name ) {}
    std::string compile( unsigned int level = 0 ) const;
};

#endif // CLASSUNIT_H

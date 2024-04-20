#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>

class Unit {
public:
    using Flags = unsigned int;
public:
    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags ) {
        throw std::runtime_error( "Not supported" );
    }
    virtual std::string compile( unsigned int level = 0 ) const =
        0;
protected:
    virtual std::string generateShift( unsigned int level ) const;
};

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
    std::string compile( unsigned int level = 0 ) const;
private:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) {
        m_body.push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const;
private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};

#endif // UNIT_H

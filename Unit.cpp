#ifndef UNIT_CPP
#define UNIT_CPP
#include "Unit.h"

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private" };


std::string Unit::generateShift(unsigned int level) const
{
    static const auto DEFAULT_SHIFT = "    ";
    std::string result;
    for( unsigned int i = 0; i < level; ++i ) {
        result += DEFAULT_SHIFT;
    }
    return result;
}

ClassUnit::ClassUnit(const std::string &name) : m_name( name ) {
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void ClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[ accessModifier ].push_back( unit );
}

std::string ClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[ i ] + ":\n";
        for( const auto& f : m_fields[ i ] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}

std::string MethodUnit::compile(unsigned int level) const {
    std::string result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

#endif

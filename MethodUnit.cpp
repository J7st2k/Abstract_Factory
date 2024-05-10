#include "MethodUnit.h"

std::string CPlusMethod::compile(unsigned int level, std::string access) const {
    Q_UNUSED(access)
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

std::string CSharpMethod::compile(unsigned int level, std::string access) const {
    std::string result;
    if(access == "") {
        result = generateShift( level );
    } else {
        result = generateShift( level ) + access + " ";
    }
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
        result += b->compile( level + 1, access );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

std::string JavaMethod::compile(unsigned int level, std::string access) const {

    std::string result;
    if(access == "") {
        result = generateShift( level );
    } else {
        result = generateShift( level ) + access + " ";
    }
    if( m_flags & STATIC && m_flags & FINAL ) {
         result += "static final ";
    } else if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & FINAL ) {
        result += "final ";
    } else if( m_flags & ABSTRACT ) {
        result += "abstract ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if( m_flags & ABSTRACT ) {
        result += ";\n";
        if(!m_body.empty()) {
            result += generateShift( level + 1 ) + "Cant place methods in abstract method\n" ;
        }
    } else {
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1, access );
        }
        result += generateShift( level ) + "}\n";
    }
    return result;
}

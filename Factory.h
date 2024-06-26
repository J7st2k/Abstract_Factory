#ifndef FACTORY_H
#define FACTORY_H
#include <memory>
#include "Unit.h"
#include "MethodUnit.h"
#include "ClassUnit.h"
#include "PrintOperatorUnit.h"

class Factory
{
public:
    virtual std::shared_ptr<Unit> CreateClass(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    virtual std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) = 0;
    virtual ~Factory() = default;
};

class CPlusFactory : public Factory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) {
        return std::make_shared<CPlusClass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<CPlusMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) {
        return std::make_shared<CPlusPrintOperator>(text);
    }
};

class CSharpFactory : public Factory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) {
        return std::make_shared<CSharpClass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<CSharpMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) {
        return std::make_shared<CSharpPrintOperator>(text);
    }
};

class JavaFactory : public Factory
{
public:
    std::shared_ptr<Unit> CreateClass(const std::string& name) {
        return std::make_shared<JavaClass>(name);
    }
    std::shared_ptr<Unit> CreateMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
        return std::make_shared<JavaMethod>(name, returnType, flags);
    }
    std::shared_ptr<Unit> CreatePrintOperator(const std::string& text) {
        return std::make_shared<JavaPrintOperator>(text);
    }
};
#endif // FACTORY_H

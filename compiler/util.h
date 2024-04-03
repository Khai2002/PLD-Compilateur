#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct VariableInfo
{
    int index;     // Index de la variable
    int value;     // Valeur de la variable
    int callCount; // Nombre de fois que la variable est appelée

    // Constructeur pour initialiser les valeurs par défaut
    VariableInfo() : index(0), value(0), callCount(0) {}

    // Constructeur avec des valeurs spécifiques
    VariableInfo(int index, int value = 0, int callCount = 0) : index(index), value(value), callCount(callCount) {}
};

class Type
{
public:
    // Enum definition
    enum TypeEnum
    {
        INT,
        CHAR,
        VOID
    };

    // Constructor
    Type(TypeEnum type) : type(type) {}
    Type() : type(TypeEnum::INT) {}

    // Getter for the type
    TypeEnum getType() const
    {
        return type;
    }

protected:
    // Protected member variable to store the enum value
    TypeEnum type;
};
struct Function_info
{
    vector<Type> Param;
    string Return_type;

    // Constructeur pour initialiser les valeurs par défaut
    Function_info() {}
    void addReturnType(const string type)
    {
        Return_type = type;
    }
    void addType(const Type &type)
    {
        Param.push_back(type);
    }
    int get_number_params()
    {
        return Param.size();
    }

    string Get_Return_type()
    {
        return Return_type;
    }
};

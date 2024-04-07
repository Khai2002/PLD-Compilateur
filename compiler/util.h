#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @struct VariableInfo
 * @brief Represents information about a variable in a specific scope.
 *
 * This structure holds details such as the variable's index within its scope
 * and the number of times it is referenced or called.
 * @note Here the index isn't used since the Symbol table is recreated in the IR but it could have been used if we used the same symbol table.
 */
struct VariableInfo
{
    int index;     ///< Index of the variable in its scope.
    int callCount; ///< Number of times the variable is referenced or called.

    /**
     * Default constructor initializing values to zero.
     */
    VariableInfo() : index(0), callCount(0) {}

    /**
     * Constructor allowing to set specific values for index and callCount.
     * @param index The index of the variable.
     * @param callCount The number of times the variable is referenced or called (defaults to 0).
     */
    VariableInfo(int index, int callCount = 0) : index(index), callCount(callCount) {}
};

/**
 * @class Type
 * @brief Represents a type in a programming language (e.g., C).
 *
 * This class encapsulates a type enumeration which includes types such as INT, CHAR, and VOID,
 * representing different data types in the programming language.
 */
class Type
{
public:
    /**
     * Enumeration for possible types.
     */
    enum TypeEnum
    {
        INT,  ///< Represents an integer type.
        CHAR, ///< Represents a character type.
        VOID  ///< Represents a void type.
    };

    /**
     * Constructor with specific type.
     * @param type The specific type as TypeEnum.
     */
    Type(TypeEnum type) : type(type) {}

    /**
     * Default constructor setting type to INT.
     */
    Type() : type(TypeEnum::INT) {}

    /**
     * Getter for retrieving the type.
     * @return The type as TypeEnum.
     */
    TypeEnum getType() const
    {
        return type;
    }

protected:
    TypeEnum type; ///< Protected member variable to store the type enumeration.
};

/**
 * @struct Function_info
 * @brief Represents information about a function.
 *
 * This structure contains details such as the types of parameters the function accepts
 * and its return type.
 */
struct Function_info
{
    vector<Type> Param; ///< Vector of parameters' types.
    string Return_type; ///< String representing the return type of the function.

    /**
     * Default constructor.
     */
    Function_info() {}

    /**
     * Method to set the return type of the function.
     * @param type The return type as a string.
     */
    void addReturnType(const string type)
    {
        Return_type = type;
    }

    /**
     * Method to add a parameter's type to the function.
     * @param type The type of the parameter to add.
     */
    void addType(const Type &type)
    {
        Param.push_back(type);
    }

    /**
     * Method to get the number of parameters of the function.
     * @return The number of parameters as an integer.
     */
    int get_number_params()
    {
        return Param.size();
    }

    /**
     * Method to get the return type of the function.
     * @return The return type as a string.
     */
    string Get_Return_type()
    {
        return Return_type;
    }
};

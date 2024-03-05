#pragma once

#include <iostream>
#include <string>
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

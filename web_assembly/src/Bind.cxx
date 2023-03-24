#include "Calculator.h"
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

static Calculator& GetInstance()
{
    static Calculator calc;
    return calc;
}

static void Key(std::string val)
{
    for (auto it = val.begin(); it != val.end(); ++it)
    {
        GetInstance().Key(*it);   
    }
}
static std::string Print()
{
    return GetInstance().Print();
}

EMSCRIPTEN_BINDINGS(CalculatorInstance) {
    emscripten::function("Key", &Key);
    emscripten::function("Print", &Print);
}


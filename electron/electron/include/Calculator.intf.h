#ifndef CALCULATOR_INTF_H_
#define CALCULATOR_INTF_H_

#include "Calculator.h"

#include <node.h>
#include <napi.h>
#include <thread>

class CalculatorIntf
{
private:
    static CalculatorIntf ms_instance;
public:
    static CalculatorIntf& GetInstance();
    static Napi::Value Initialization(const Napi::CallbackInfo& info);
    static Napi::Value Input(const Napi::CallbackInfo& info);
    static Napi::Value Terminate(const Napi::CallbackInfo& info);
private:
    bool m_run;
    Calculator m_calc;
    std::thread m_th;
    Napi::ThreadSafeFunction m_th_safe;
public:
    CalculatorIntf();
public:
    ~CalculatorIntf();
public:
    bool CreateThread(Napi::Env env, const Napi::Function& update_cb);
    bool Key(const Napi::String& val);
    bool Stop();
};


#endif //!CALCULATOR_INTF_H_


#include "Calculator.intf.h"

#include <iostream>
#include <utility>

CalculatorIntf CalculatorIntf::ms_instance;

CalculatorIntf& CalculatorIntf::GetInstance()
{
    return ms_instance;
}

Napi::Value CalculatorIntf::Initialization(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    if ( info.Length() < 1 )
    {
        throw Napi::TypeError::New( env, "Expected two arguments" );
    }
    else if ( !info[0].IsFunction() )
    {
        throw Napi::TypeError::New( env, "Expected first arg to be function" );
    }

    auto status = GetInstance().CreateThread(env,
        info[0].As<Napi::Function>());

    return Napi::Boolean::New(env, status);
}

Napi::Value CalculatorIntf::Input(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    if ( info.Length() < 1 )
    {
        throw Napi::TypeError::New( env, "Expected two arguments" );
    }
    else if ( !info[0].IsString() )
    {
        throw Napi::TypeError::New( env, "Expected first arg to be function" );
    }

    return Napi::Boolean::New(env, 
        GetInstance().Key(info[0].As<Napi::String>()));
}

Napi::Value CalculatorIntf::Terminate(const Napi::CallbackInfo& info)
{
    Napi::Env env = info.Env();
    GetInstance().Stop();
    return Napi::Boolean::New(env, true);
}

CalculatorIntf::CalculatorIntf() :
    m_run(false),
    m_calc(),
    m_th(),
    m_th_safe()
{}

CalculatorIntf::~CalculatorIntf()
{}

bool CalculatorIntf::CreateThread(Napi::Env env, 
    const Napi::Function& update_cb)
{
    if (!m_run)
    {
        m_run = true;
        m_th_safe = Napi::ThreadSafeFunction::New(env, update_cb,
            "Update Output", 0, 1, [&](Napi::Env)
            {
                m_run = false; 
                m_th.join();
            });
        m_th = std::thread([&]
        {
            auto cb = [](Napi::Env env, Napi::Function js_cb, 
                std::string* val)
            {
                js_cb.Call({Napi::String::New(env, *val)});
                delete val;
            };
            
            std::cout << "thread run!" << std::endl;
            while(m_run)
            {
                std::string * str = new std::string(m_calc.Print());
                napi_status status = m_th_safe.BlockingCall(str, cb);

                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            std::cout << "thread end!" << std::endl;
            m_th_safe.Release();
        });
        return true;
    }
    return false;
}

bool CalculatorIntf::Key(const Napi::String& val)
{
    std::cout << "key" << std::endl; 
    auto utf8_val = val.Utf8Value();
    if (utf8_val.size() > 0)
    {
        m_calc.Key(utf8_val[0]);
        return true;
    }
    return false;
}

bool CalculatorIntf::Stop()
{
    m_run = false;
    return true;
}

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    exports.Set("initialization", Napi::Function::New(env,
        CalculatorIntf::Initialization));
    exports.Set("input", Napi::Function::New(env, 
        CalculatorIntf::Input));
    exports.Set("terminate", Napi::Function::New(env, 
        CalculatorIntf::Terminate));
    return exports;
}

NODE_API_MODULE(calculator, Init)


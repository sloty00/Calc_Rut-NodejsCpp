#include <node.h>
#include <string>
#include <algorithm>

using namespace v8;

std::string calculateDV(int rut) {
    int sum = 0;
    int multiplier = 2;

    while (rut > 0) {
        sum += (rut % 10) * multiplier;
        rut /= 10;
        multiplier++;
        if (multiplier > 7) multiplier = 2;
    }

    int remainder = 11 - (sum % 11);
    if (remainder == 11) return "0";
    if (remainder == 10) return "K";
    return std::to_string(remainder);
}

void GetDV(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    if (args.Length() < 1 || !args[0]->IsNumber()) {
        isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Invalid argument").ToLocalChecked()));
        return;
    }

    int rut = args[0]->Int32Value(isolate->GetCurrentContext()).FromJust();
    std::string dv = calculateDV(rut);

    Local<Object> result = Object::New(isolate);
    result->Set(isolate->GetCurrentContext(), String::NewFromUtf8(isolate, "rut").ToLocalChecked(), Number::New(isolate, rut)).FromJust();
    result->Set(isolate->GetCurrentContext(), String::NewFromUtf8(isolate, "dv").ToLocalChecked(), String::NewFromUtf8(isolate, dv.c_str()).ToLocalChecked()).FromJust();

    args.GetReturnValue().Set(result);
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "calculateDV", GetDV);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
#pragma once

#include <memory>
#include <vector>

class SPLiteCallaback {
public:
    virtual ~SPLiteCallaback() = default;
    virtual void onInit()   {;}
    virtual void onFrame()  {;}
    virtual void onDeinit() {;}
    virtual void onError(unsigned err, const char *errStr) {;}

    virtual void touchOn(unsigned voice, float x,float y, float z) = 0;
    virtual void touchContinue(unsigned voice, float x,float y, float z) = 0;
    virtual void touchOff(unsigned voice, float x,float y, float z) = 0;
};

class SPLiteImpl_;

class SPLiteDevice {
public:
    SPLiteDevice();
    virtual ~SPLiteDevice();
    void start();
    void stop();
    void addCallback(std::shared_ptr<SPLiteCallaback>);
    void maxTouches(unsigned);
private:
    SPLiteImpl_* impl_;
};


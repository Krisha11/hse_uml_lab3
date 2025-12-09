#include "PhoneLine_sm.h"
#include <thread>
#include <atomic>

class PhoneLine
{
    private:
        PhoneLineContext _fsm;


    std::string response;

    std::thread timeoutThread;
    std::atomic<bool> timerActive{false};
    std::atomic<bool> shouldStop{false};

    public:
        PhoneLine() : _fsm(*this) {
        }
        
        ~PhoneLine() {
        	stopTimer();
        }

        PhoneLineContext& getContext() {
            return _fsm;
        }

        std::string offHook();

        std::string onHook();

        std::string validNumber();

        std::string invalidNumber();

        void soundDialTone();

        void disconnectedLine();

        void slowBusyTone();

        void fastBusyTone();

        void PlayMessage();

        void findConnection();

        void continues();

        void startTimer();

        void stopTimer();

};

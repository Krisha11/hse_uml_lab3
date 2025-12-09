#include "PhoneLine.h"

std::string PhoneLine::offHook() {
	_fsm.offHook();
	return response;
}

std::string PhoneLine::onHook() {
	_fsm.onHook();
	return response;
}

std::string PhoneLine::validNumber() {
	_fsm.validNumber();
	return response;
}

std::string PhoneLine::invalidNumber() {
	_fsm.invalidNumber();
	return response;
}

void PhoneLine::soundDialTone() {
    response = "soundDialTone";
}

void PhoneLine::disconnectedLine() {
    response = "disconnectedLine";
}

void PhoneLine::slowBusyTone() {
    response = "slowBusyTone";
}

void PhoneLine::fastBusyTone() {
    response = "fastBusyTone";
}

void PhoneLine::PlayMessage() {
    response = "PlayMessage";
}

void PhoneLine::findConnection() {
    response = "findConnection";
}

void PhoneLine::continues() {
    response = "continues";
}

void PhoneLine::startTimer() {        
        shouldStop = false;
	timerActive = true;

        timeoutThread = std::thread([this]() {
            for (int i = 0; i < 30 && !shouldStop; i++) {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
            
            if (timerActive && !shouldStop) {
	        (_fsm.getState()).Exit(_fsm);
		_fsm.clearState();
		_fsm.setState(PhoneLineFSM::Warning);
		(_fsm.getState()).Entry(_fsm);
            }
        });
}

void PhoneLine::stopTimer() {
        shouldStop = true;
        timerActive = false;
        
        if (timeoutThread.joinable()) {
                std::thread::id currentThreadId = std::this_thread::get_id();
	        std::thread::id timerThreadId = timeoutThread.get_id();

	        if (currentThreadId == timerThreadId) {
	            timeoutThread.detach();
	            return;
	        }
        
	        timeoutThread.join();
        }
}


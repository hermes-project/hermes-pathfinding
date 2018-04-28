
#include "Log.h"

Log* Log::singleton = nullptr;

Log::Log() {}

void Log::setFrame(LogFrame *logFrame) {
    this->frame = logFrame;
}

Log* Log::getInstance() {
    if(!singleton)
        singleton = new Log;
    return singleton;
}

void Log::debug(const char* mess){
    std::cout << DHEADER << mess << RESETHEADER << std::endl;
    if (frame != nullptr) {
        this->frame->debug(mess);
    }
}

void Log::warning(const char* mess){
    std::cout << WHEADER << mess << RESETHEADER << std::endl;
    if (frame != nullptr) {
        this->frame->warning(mess);
    }
}

void Log::error(const char* mess){
    std::cout << EHEADER << mess << RESETHEADER << std::endl;
    if (frame != nullptr) {
        this->frame->error(mess);
    }
}
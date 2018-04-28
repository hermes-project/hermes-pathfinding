//
// Created by rem on 27/04/18.
//

#ifndef HERMES_PATHFINDING_LOG_H
#define HERMES_PATHFINDING_LOG_H

#include <iostream>
#include "../display/LogFrame.h"

#define DHEADER "\033[34m            "
#define WHEADER "\033[33mWARNING :   "
#define EHEADER "\033[1;31mERROR :     "
#define RESETHEADER "\033[0m"

class Log {
private:
    /** Le log est un singleton */
    static Log* singleton;
    Log();

    /** La frame si besoin */
    LogFrame* frame;

public:
    /** Fonction permettant de récupérer le singleton */
    static Log* getInstance();

    /** Set la frame */
    void setFrame(LogFrame* logFrame);

    /** Méthodes d'affichage du debug */
    void debug(const std::string mess);
    void warning(const std::string mess);
    void error(const std::string mess);
};

#endif //HERMES_PATHFINDING_LOG_H

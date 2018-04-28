//
// Created by rem on 20/03/18.
//

#include "Window.h"

Window::Window(QWidget* parent, Landmark* landmark) :
        QWidget(parent),
        frame(new LandmarkFrame(this, new Graph(landmark))),
        logFrame(new LogFrame(this, landmark->getSize_Y() + 100)),
        menu(new Menu(this))
{
    // Initialisation de paramètres
    Log* log = Log::getInstance();
    log->setFrame(logFrame);

    // Paramètres globaux de la frame
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(40, 40, 40));

    // Liens des boutons du menu
    connect(menu->quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(menu->regenerate, &QPushButton::clicked, frame, &LandmarkFrame::regenerate);
    connect(menu->add, &QPushButton::clicked, frame, &LandmarkFrame::add);

    // Layout de la frame
    QGridLayout* layout = new QGridLayout;
    layout->addWidget(menu, 0, 0);
    layout->addWidget(frame, 1, 0);
    layout->addWidget(logFrame, 0, 1, 2, 2);
    this->setLayout(layout);
    this->setPalette(pal);
    this->show();
}
//
// Created by rem on 20/03/18.
//

#include <QtWidgets/QtWidgets>
#include "Window.h"

Window::Window(QWidget* parent, Landmark* landmark) : QWidget(parent), frame(new LandmarkFrame(this, landmark))
{
    // Paramètres globaux de la frame
    this->setFixedSize(landmark->getSize_X() + MARGE_X, landmark->getSize_Y() + MARGE_Y);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(40, 40, 40));

    // Les boutons à lier avec les bonnes méthodes
    QPushButton* quit = new QPushButton("Quit");
    QPushButton* regenerate = new QPushButton("Regenerate");
    QPushButton* start = new QPushButton("Start");
    QPushButton* stop = new QPushButton("Stop");

    quit->setFont(QFont("Cursive", 11, QFont::Bold));
    regenerate->setFont(QFont("Cursive", 11, QFont::Bold));;
    start->setFont(QFont("Cursive", 11, QFont::Bold));
    stop->setFont(QFont("Cursive", 11, QFont::Bold));

    // Le lien en question !
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(regenerate, &QPushButton::clicked, frame, &LandmarkFrame::regenerate);

    // Gestion des layouts
    QGridLayout* buttonLayout = new QGridLayout;
    buttonLayout->addWidget(regenerate, 0, 0, Qt::AlignBottom);
    buttonLayout->addWidget(quit, 0, 1, Qt::AlignBottom);
    buttonLayout->addWidget(start, 1, 0, Qt::AlignBottom);
    buttonLayout->addWidget(stop, 1, 1, Qt::AlignBottom);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(buttonLayout);
    layout->addWidget(frame);
    this->setLayout(layout);
    this->setPalette(pal);
    this->show();
}
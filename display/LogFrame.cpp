//
// Created by rem on 26/04/18.
//

#include "LogFrame.h"

LogFrame::LogFrame(QWidget *parent, int size_Y) :
        QFrame(parent)
{
    this->setFixedSize(300, size_Y);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(60, 70, 80));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    limitLine = size_Y/TEXT_SIZE;
    layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);
    this->setLayout(layout);
}

void LogFrame::debug(const char *line) {
    Line* newLine = new Line(this, line);
    if(nbLine > limitLine) {
        this->setFixedHeight(this->height() + TEXT_SIZE);
        if (this->width() != 285) {
            this->setFixedWidth(285);
        }
    }
    nbLine++;
    layout->addWidget(newLine);
}

void LogFrame::warning(const char *line) {
    Line* newLine = new Line(this, line);
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(255, 215, 40));
    newLine->setPalette(palette);

    if(nbLine > limitLine) {
        this->setFixedHeight(this->height() + TEXT_SIZE);
        if (this->width() != 285) {
            this->setFixedWidth(285);
        }
    }
    nbLine++;
    layout->addWidget(newLine);
}

void LogFrame::error(const char *line) {
    Line* newLine = new Line(this, line);
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(255, 120, 120));
    newLine->setPalette(palette);

    if(nbLine > limitLine) {
        this->setFixedHeight(this->height() + TEXT_SIZE);
        if (this->width() != 285) {
            this->setFixedWidth(285);
        }
    }
    nbLine++;
    layout->addWidget(newLine);
}

int LogFrame::getNbLine() const {
    return nbLine;
}

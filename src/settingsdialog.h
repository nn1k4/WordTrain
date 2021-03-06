/******************************************************************************
** WordTrain 0.9.3 -- Foreign words trainer
** Copyright (C) 2010  Valery Kharitonov <kharvd@gmail.com>
**
** This file is part of WordTrain.
**
** $QT_BEGIN_LICENSE:GPL$
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
** $QT_END_LICENSE$
**
** If you have questions regarding the use of this file, please contact me at
** kharvd@gmail.com.
**
******************************************************************************/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

class QComboBox;
class QLineEdit;
class QCheckBox;
class QPushButton;

// Dialog with settings
class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget *parent = 0);

private slots:
    void writeSettings();

private:
    //== Static constants ===============================================

    static const int kDefaultWidth = 300;
    static const int kDefaultHeight = 200;

    //===================================================================

    //== Private member functions =======================================

    // Dynamically gets available languages from resources
    void fillLanguages();

    //===================================================================


    //== Private widgets and other QObjects =============================

    QComboBox *cmbLanguages;
    QLineEdit *txtCorrAnswers;
    QCheckBox *chckSaveWinPosition;

    //===================================================================
};

#endif // SETTINGSDIALOG_H

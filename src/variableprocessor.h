/*
 * Copyright (C) 2019 Daren Liang, George Lewis
 *
 * This file is part of Resauce.
 *
 * Resauce is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Resauce is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Resauce.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef RESAUCERNUMBERING_H
#define RESAUCERNUMBERING_H

#include "resaucerprocessor.h"

template <typename T>
struct VariableProcessor : public ResaucerProcessor {

    VariableProcessor(QString& name);

    QString execute(QString name) override;

    void init(T val);

    void limit(T val);

    T initial; // Initial value
    T val; // Current value
    T step; // Amount to increase / decrease by
    T _limit; // Maximum value
    bool _limitB = false;
    int freq = 1; // With what frequency to adjust the value
    int count = 0;

private:

    virtual QString str();

    QString name;

};

struct FloatProcessor : public VariableProcessor<double> {

    FloatProcessor(QString& name);

    QString str() override;

    int precision = 2;

};

#endif // RESAUCERNUMBERING_H

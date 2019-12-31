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


#include "variableprocessor.h"

template <typename T>
VariableProcessor<T>::VariableProcessor(QString& name): ResaucerProcessor(), name{name} {}

template <typename T>
void VariableProcessor<T>::init(T val) {
    this->initial = val;
    this->val = val;
}

template <typename T>
QString VariableProcessor<T>::execute(QString name) {

    auto result = name.replace("{"+this->name+"}", str());

    count++;

    if (count >= freq) {
        val += step;
        count = 0;
    }

    if (_limitB) {

        if ( (step < 0 && val < _limit) || (step > 0 && val > _limit) ) {

            val = initial;

        }

    }

    return result;

}

template <typename T>
void VariableProcessor<T>::limit(T val) {
    this->_limit = val;
    this->_limitB = true;
}

template <typename T>
QString VariableProcessor<T>::str() {
    return QString::number(val);
}

FloatProcessor::FloatProcessor(QString& name): VariableProcessor<double>(name) {}

QString FloatProcessor::str() {
    return QString::number(val, 'f', precision);
}

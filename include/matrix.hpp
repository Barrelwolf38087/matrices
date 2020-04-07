/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iomanip>
#include <functional>

template<typename T, size_t _rows, size_t _cols>
class matrix {
    T mat[_cols][_rows];
    T fill; // Used in as()

public:
    matrix() : matrix{0} {}
    explicit matrix(T init) : mat{ { init } }, fill{init} {}

    matrix(const matrix& other) {
        *this = other;
    }

    matrix& operator=(const matrix& other) {
        if(this == &other) return *this;

        this->fill = other.fill;

        for (size_t i = 0; i < _rows; ++i) {
            for (size_t j = 0; j < _cols; ++j) {
                this->mat[i][j] = other.mat[i][j];
            }
        }

        return *this;
    }

    T *operator[](size_t index) {
        return mat[index];
    }



    template<typename U>
    matrix<U, _rows, _cols> as() {
        matrix<U, _rows, _cols> newMat{static_cast<U>(fill)};

        newMat.mapInPlace([this](size_t i, size_t j, const T &item) {
            return static_cast<U>(mat[i][j]);
        });



        return newMat;
    }

    void mapInPlace(std::function<T(size_t, size_t, const T&)> func) {
        for (size_t i = 0; i < _rows; ++i) {
            for (size_t j = 0; j < _cols; ++j) {
                auto newVal = func(i, j, mat[i][j]);
                mat[i][j] = newVal;
            }
        }
    }

    size_t rows() { return _rows; }
    size_t cols() { return _cols; }

    void print() {
        std::ios init{nullptr};
        init.copyfmt(std::cout);

        for (size_t i = 0; i < _rows; ++i) {
            for (size_t j = 0; j < _cols; ++j) {
                std::cout << std::setiosflags(std::ios::fixed) << mat[j][i] << " ";
            }
            std::cout << std::endl;
        }

        std::cout.copyfmt(init);
    }
};

#endif //MATRIX_HPP

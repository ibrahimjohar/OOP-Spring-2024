/*
*   Name: Ibrahim Johar Farooqi 
*   ID: 23K-0074
*   Task 3
*/

#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
    protected:
        T **matrix2D;
        int rows, cols;
    public:
        Matrix(int r, int c) : rows(r), cols(c) 
        {
            if (cols != rows) { cols = rows; }
            
            matrix2D = new T *[rows];
            for (int i = 0; i < rows; i++)
            {
                matrix2D[i] = new T[cols];
                for (int j = 0; j < cols; j++)
                {
                    matrix2D[i][j] = T();
                }
            }
        }
        
        void setValue(T value, int row, int col) 
        {
            matrix2D[row][col] = value;
        }

        T getValue() const { return matrix2D[rows][cols]; }
        

        Matrix<T>& operator+(const Matrix<T> &mat1)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix2D[i][j] += mat1.matrix2D[i][j];
                }
            }
            return *this;
        }

        Matrix<T>& operator-(const Matrix<T> &mat1)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix2D[i][j] -= mat1.matrix2D[i][j];
                }
            }
            return *this;
        }

        Matrix<T>& operator*(const Matrix<T> &mat1)
        {
            if (this->cols != mat1.rows)
            {
                throw invalid_argument("Matrices must have compatible dimensions");
            }

            T** mat2 = new T*[rows];
            for (int i = 0; i < rows; i++)
            {
                mat2[i] = new T[mat1.cols];
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < mat1.cols; j++)
                {
                    for(int k = 0; k < cols; k++)
                    {
                        mat2[i][j] += matrix2D[i][k] * mat1.matrix2D[k][j]; 
                    }
                }
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    matrix2D[i][j] = mat2[i][j];
                }
            }

            for (int i = 0; i < rows; i++)
            {
                delete[] mat2[i];
            }
            delete[] mat2;

            return *this;
        }

        virtual void display() const
        {
            cout << "Matrix:\n";

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << matrix2D[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        ~Matrix()
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] matrix2D[i];
            }
            delete[] matrix2D;
        }
};

template <typename T>
class IntMatrix : public Matrix<T>
{
    public:
        IntMatrix() {}
        IntMatrix(int r, int c) : Matrix<int>(r, c) {}

        void display() const override
        {
            cout << "Integer Matrix:\n";
            Matrix<T>::display();
        }

};

template <typename T>
class DoubleMatrix : public Matrix<T>
{
    public:
        DoubleMatrix(int r, int c) : Matrix<T>(r, c) {}

        void display() const override
        {
            cout << "Double Matrix:\n";
            Matrix<T>::display();
        }
};


int main()
{
    cout << "Ibrahim Johar Farooqi - 23K-0074 - Task 3\n\n";

    IntMatrix<int> matrix1(2,2);
    matrix1.setValue(10, 0, 0);
    matrix1.setValue(20, 0, 1);
    matrix1.setValue(15, 1, 0);
    matrix1.setValue(25, 1, 1);
    cout << "Matrix 1:\n";
    matrix1.display();

    IntMatrix<int> matrix2(2,2);
    matrix2.setValue(11, 0, 0);
    matrix2.setValue(21, 0, 1);
    matrix2.setValue(16, 1, 0);
    matrix2.setValue(26, 1, 1);
    cout << "Matrix 2:\n";
    matrix2.display();
    
    cout << "Matrix 1 + Matrix2:\n";
    (matrix1 + matrix2).display();

    cout << "Matrix 2 - Matrix 1:\n";
    (matrix2 - matrix1).display();

    DoubleMatrix<double> matrix3(2,2);
    matrix3.setValue(11.5f, 0, 0);
    matrix3.setValue(21.4f, 0, 1);
    matrix3.setValue(16.2f, 1, 0);
    matrix3.setValue(26.3f, 1, 1);
    cout << "Matrix 3:\n";
    matrix3.display();

    DoubleMatrix<double> matrix4(2,2);
    matrix4.setValue(10.5f, 0, 0);
    matrix4.setValue(20.4f, 0, 1);
    matrix4.setValue(15.2f, 1, 0);
    matrix4.setValue(21.3f, 1, 1);
    cout << "Matrix 4:\n";
    matrix4.display();

    cout << "Matrix 3 * Matrix4:\n";
    (matrix3 * matrix4).display();

    return 0;
}

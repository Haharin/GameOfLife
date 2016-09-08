#include <iostream>
using namespace std;

class Cell
{
  private:
    int state;
  public:
    Cell(int n_state){
        setState(n_state);
    }
    Cell(){
        setState(0);
    }
    void setState(int n_state){
        state   = n_state;
    }
    int getState(){
        //cout << state << endl;
        return state;
    }

};

class Field
{
  private:
    Cell **square;//������ ����
    int X, Y, T;//X - ������, Y - �������, T - ��� (0 - ������������, 1 - ���������)
  public:
    Field(int N, int M, int Type ){//�����������
        X = N;
        Y = M;
        T = Type;
        square = new Cell*[X+2];
        for (int i=0; i < X+2; i++){
                square[i] = new Cell [Y+2];
        }
        for (int i=0; i < X+2; i++){
            for (int j=0; j < Y+2; j++){
                square[i][j] = 0;
            }
        }
    }
    void modifyField(){ //����������� ���� � ����������
        int N = X+1, M = Y+1;
        for (int i=1; i<N; i++){
            square[i][M]=square[i][1];
            square[i][0]=square[i][M-1];
        }
        for (int i=1; i<M; i++){
            square[0][i]=square[N-1][i];
            square[N][i]=square[1][i];
        }
        square[N][M]=square[1][1];
        square[0][0]=square[N-1][M-1];
        square[0][M]=square[N-1][1];
        square[N][0]=square[1][M-1];
    }
    void setField(){//������ ������� ���� � ����������
        int temp;
        for (int i=1; i < X+1; i++){
            for (int j=1; j < Y+1; j++){
                cout << "Insert cell [" <<i<<"] ["<<j<<"] - ";
                cin >> temp;
                cout << endl;
                square[i][j].setState(temp);
            }
        }
    }
    void Show(){//�������� ������� ����
        for (int i=1; i < X+1; i++){
            for (int j=1; j < Y+1; j++){
                cout << square[i][j].getState()<<" ";
            }
        cout << endl;
        }
    }
     void ShowAll(){//�������� �� ����, � ��������������� "������������" ������
        for (int i=0; i < X+2; i++){
            for (int j=0; j < Y+2; j++){
                cout << square[i][j].getState()<<" ";
            }
        cout << endl;
        }
    }
    int Summ(int x, int y){//������� ����� ������-�������
        int sum;
        sum = 0;
        sum += square[x][y+1].getState();
        sum += square[x][y-1].getState();
        sum += square[x+1][y+1].getState();
        sum += square[x+1][y].getState();
        sum += square[x+1][y-1].getState();
        sum += square[x-1][y+1].getState();
        sum += square[x-1][y].getState();
        sum += square[x-1][y-1].getState();
        return sum;
    }
    int rule(int x, int y){//��� ������ ���������� ���������, � ����������� �� ����� ���������� ������
        if (square[x][y].getState() == 1)
            if (Summ(x,y) < 4 && Summ(x,y)>1 ){
                return 1;
            }
            else
                return 0;
        if (square[x][y].getState() == 0)
            if (Summ(x, y) == 3 ){
                return 1;
            }
            else
                return 0;
    }
    void Step(){//���� ��� �� �������
        int temp[X+2][Y+2];
        if (T == 1)
            modifyField();
        for(int i = 1; i < X+1; i++ ){
            for(int j = 1; j < Y+1; j++){
                temp[i][j] = rule(i,j);
                //cout << Summ(i,j) <<endl;
            }
        }
        for(int i = 1; i < X+1; i++ ){
            for(int j = 1; j < Y+1; j++){
                square[i][j] = temp[i][j];
            }
        }
    }
   ~Field(){//����������
        for(int i=0; i<X; i++){
            delete [] square[i];
        }
    }
  /*������ �������, ��������� ��� ������������*/
};

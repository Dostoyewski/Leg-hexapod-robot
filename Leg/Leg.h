#ifndef Leg_h
#define Leg_h
 
#include "Arduino.h"
#include <Servo.h>
 
class Leg
{
  public:
    void attach(int pov, int col, int nog, bool isLeft);								//Подключение ноги
    void attach(int pov, int col, int nog, bool isLeft, bool Forward, bool krai);		//Тоже, но для передних ног
    void move(float xm, float ym, float zm);											//Перемещение ноги в нулевой СК
    //void move(float xm, float ym, float zm, bool calc);									//Перемещение ноги в СК корпуса (только для крайних ног использовать)!!!
    void set(float x2, float y2, float z2);												//Установка центра ноги   
	float x = 0, y = 0, z = 14;															//Координаты центра ноги
  private:
    bool _isLeft = false, _Forward = false, _krai = false;								//Переменные положения ноги
    Servo s0, s2, s3;																	//Сервоприводы ноги
												
};

class Body
{
public:
	void init();															//Инициализация корпуса, привязка серв, введение единой СК
	void tangasch(float);													//Угол тангажа
	void kren(float);														//Угол крена
	void risk(float);														//Угол рысканья
	void move(float, float, float);											//Движение корпуса не отрывая ног
	void run(float, float, float);											//Перемещение корпуса в пространстве; три параметра - вектор скорости перемещения
	void set(float, float, float);
	Leg l1, l2, l3, l4, l5, l6;												//Шесть ног
private:
	float _tangle, _kangle, _rangle, x, y, z;								//Углы тангажа, крен, рысканья и координаты центра соответственно
};

#endif

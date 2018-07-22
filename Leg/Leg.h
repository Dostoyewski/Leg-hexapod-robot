#ifndef Leg_h
#define Leg_h
 
#include "Arduino.h"
#include <Servo.h>
 
class Leg
{
  public:
    void attach(int pov, int col, int nog, bool isLeft);								//����������� ����
    void attach(int pov, int col, int nog, bool isLeft, bool Forward, bool krai);		//����, �� ��� �������� ���
    void move(float xm, float ym, float zm);											//����������� ���� � ������� ��
    //void move(float xm, float ym, float zm, bool calc);									//����������� ���� � �� ������� (������ ��� ������� ��� ������������)!!!
    void set(float x2, float y2, float z2);												//��������� ������ ����   
	float x = 0, y = 0, z = 14;															//���������� ������ ����
  private:
    bool _isLeft = false, _Forward = false, _krai = false;								//���������� ��������� ����
    Servo s0, s2, s3;																	//������������ ����
												
};

class Body
{
public:
	void init();															//������������� �������, �������� ����, �������� ������ ��
	void tangasch(float);													//���� �������
	void kren(float);														//���� �����
	void risk(float);														//���� ��������
	void move(float, float, float);											//�������� ������� �� ������� ���
	void run(float, float, float);											//����������� ������� � ������������; ��� ��������� - ������ �������� �����������
	void set(float, float, float);
	Leg l1, l2, l3, l4, l5, l6;												//����� ���
private:
	float _tangle, _kangle, _rangle, x, y, z;								//���� �������, ����, �������� � ���������� ������ ��������������
};

#endif

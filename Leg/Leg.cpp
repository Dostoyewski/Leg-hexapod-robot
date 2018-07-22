#include <Leg.h>
#include <Arduino.h>
#include <Servo.h>
#define L1 9
#define L2 16

void Leg::attach(int pov, int col, int nog, bool isLeft){						//Функция инициализации ноги
    s0.attach(pov);
    s2.attach(col);
    s3.attach(nog);
    _isLeft = isLeft;
}

void Leg::attach(int pov, int col, int nog, bool isLeft, bool Forward, bool krai){			//инициализация ноги с указанием стороны и положения
    s0.attach(pov);
    s2.attach(col);
    s3.attach(nog);
    _isLeft = isLeft;
    _Forward = Forward;
	_krai = krai;
}

void Leg::set(float x2, float y2, float z2){								//Установка начальных координат
	x = x2;
	y = y2;
	z = z2 + 4;
}

void Leg::move(float xm, float ym, float zm){								//Передвижение ноги
	if (_krai == true) {
		float h, s, m, s1, u, b, v, p, a;
		if (z >= zm) {
			h = abs(z - zm);
			s = sqrt(abs(ym - y)*abs(ym - y) + abs(xm - x)*abs(xm - x));
			m = h * h + s * s;
			s1 = sqrt(m);
			u = (L1 * L1 + L2 * L2 - s1 * s1) / 2 / L1 / L2;
			b = acos(u) * 180 / PI;
			u = (s1 * s1 + L1 * L1 - L2 * L2) / 2 / s1 / L1;
			v = acos(u) * 180 / PI;
			u = h / s1;
			p = acos(u) * 180 / PI;
			a = 180 - v - p;
			if ((0 <= a) && (a <= 180) && (0 <= b) && (b <= 180)) {
				if (_isLeft == true) {
					s2.write(180 - a);
					s3.write(180 - b);
				}
				else {
					s2.write(a);
					s3.write(b);
				}
			}
		}
		else {
			h = abs(z - zm);
			//s = abs(y - ym);
			s = sqrt(abs(ym - y)*abs(ym - y) + abs(xm - x)*abs(xm - x));
			m = h * h + s * s;
			s1 = sqrt(m);
			u = (L1 * L1 + L2 * L2 - s1 * s1) / 2 / L1 / L2;
			b = acos(u) * 180 / PI;
			u = (s1 * s1 + L1 * L1 - L2 * L2) / 2 / s1 / L1;
			v = acos(u) * 180 / PI;
			u = h / s1;
			p = asin(u) * 180 / PI;
			a = 90 - v - p;
			if ((0 <= a) && (a <= 180) && (0 <= b) && (b <= 180)) {
				if (_isLeft == true) {
					s2.write(180 - a);
					s3.write(180 - b);
				}
				else {
					s2.write(a);
					s3.write(b);
				}
			}
		}
		if (_isLeft == true) {
			if (xm >= x) {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				if (_Forward)
					s0.write(180 - 57 - a);
				else
					s0.write(180 + 61 - a);
			}
			else {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				if (_Forward)
					s0.write(a - 57);
				else
					s0.write(a + 61);
			}
		}
		else {
			if (xm >= x) {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				if (_Forward)
					s0.write(a + 57);
				else
					s0.write(a - 61);
			}
			else {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				if (_Forward)
					s0.write(180 + 57 - a);
				else
					s0.write(180 - 61 - a);
			}
		}
	}
	else {
		float h, s, m, s1, u, b, v, p, a;
		if (z >= zm) {
			h = abs(z - zm);
			s = sqrt(abs(ym - y)*abs(ym - y) + abs(xm - x)*abs(xm - x));
			m = h * h + s * s;
			s1 = sqrt(m);
			u = (L1 * L1 + L2 * L2 - s1 * s1) / 2 / L1 / L2;
			b = acos(u) * 180 / PI;
			u = (s1 * s1 + L1 * L1 - L2 * L2) / 2 / s1 / L1;
			v = acos(u) * 180 / PI;
			u = h / s1;
			p = acos(u) * 180 / PI;
			a = 180 - v - p;
			if ((0 <= a) && (a <= 180) && (0 <= b) && (b <= 180)) {
				if (_isLeft == true) {
					s2.write(180 - a);
					s3.write(180 - b);
				}
				else {
					s2.write(a);
					s3.write(b);
				}
			}
		}
		else {
			h = abs(z - zm);
			s = sqrt(abs(ym - y)*abs(ym - y) + abs(xm - x)*abs(xm - x));
			m = h * h + s * s;
			s1 = sqrt(m);
			u = (L1 * L1 + L2 * L2 - s1 * s1) / 2 / L1 / L2;
			b = acos(u) * 180 / PI;
			u = (s1 * s1 + L1 * L1 - L2 * L2) / 2 / s1 / L1;
			v = acos(u) * 180 / PI;
			u = h / s1;
			p = asin(u) * 180 / PI;
			a = 90 - v - p;
			if ((0 <= a) && (a <= 180) && (0 <= b) && (b <= 180)) {
				if (_isLeft == true) {
					s2.write(180 - a);
					s3.write(180 - b);
				}
				else {
					s2.write(a);
					s3.write(b);
				}
			}
		}
		if (_isLeft == true) {
			if (xm >= x) {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				s0.write(180 - a);
			}
			else {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				s0.write(a);
			}
		}
		else {
			if (xm >= x) {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				s0.write(a);
			}
			else {
				h = abs(x - xm);
				s = abs(y - ym);
				m = h * h + s * s;
				s1 = sqrt(m);
				m = s / s1;
				a = asin(m) * 180 / PI;
				s0.write(180 - a);
			}
		}
	}
}

void Body::init() {										//Иницивлмзация корпуса, не использовать
	l1.attach(17, 20, 21, false, true, true);
	l2.attach(3, 2, 19, false);
	l3.attach(9, 8, 7, false, false, true);
	l4.attach(12, 11, 10, true, false, true);
	l5.attach(6, 5, 4, true);
	l6.attach(14, 15, 16, true, true, true);
	l1.set(0, 0, 0);
	l2.set(0, 0, 0);
	l3.set(0, 0, 0);
	l4.set(0, 0, 0);
	l5.set(0, 0, 0);
	l6.set(0, 0, 0);
	l1.move(8.5, 8.5, 0);
	l2.move(0, 12, 0);
	l3.move(-8.5, 8.5, 0);
	l4.move(-8.5, 8.5, 0);
	l5.move(0, 12, 0);
	l6.move(8.5, 8.5, 0);
	delay(1000);
	for (float i = 0; i <= 10; i += 0.5) {
		l1.set(0, 0, i);
		l2.set(0, 0, i);
		l3.set(0, 0, i);
		l4.set(0, 0, i);
		l5.set(0, 0, i);
		l6.set(0, 0, i);
		l1.move(8.5, 8.5, 0);
		l2.move(0, 12, 0);
		l3.move(-8.5, 8.5, 0);
		l4.move(-8.5, 8.5, 0);
		l5.move(0, 12, 0);
		l6.move(8.5, 8.5, 0);
		delay(50);
	}
	delay(5000);
}

void Body::risk(float distance) {								//Изменение угла рысканья
	l1.set(l1.x += distance, l1.y, l1.z - 4);
	l2.set(l2.x += distance, l2.y, l2.z - 4);
	l3.set(l3.x += distance, l3.y, l3.z - 4);
	l4.set(l4.x -= distance, l4.y, l4.z - 4);
	l5.set(l5.x -= distance, l5.y, l5.z - 4);
	l6.set(l6.x -= distance, l6.y, l6.z - 4);
	l1.move(10, 12, 0);
	l2.move(0, 12, 0);
	l3.move(-10, 12, 0);
	l4.move(-10, 12, 0);
	l5.move(0, 12, 0);
	l6.move(10, 12, 0);
}

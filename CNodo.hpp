#pragma once

template <class T>
class Nodo {
public:
	T e;
	Nodo<T>* s;
	Nodo<T>* a;
	Nodo(T e, Nodo<T>* s = nullptr, Nodo<T>* a = nullptr) : e(e), s(s), a(a) {}
};
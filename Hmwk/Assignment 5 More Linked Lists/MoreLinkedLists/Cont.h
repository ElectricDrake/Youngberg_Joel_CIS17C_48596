#ifndef CONT_H
#define CONT_H

class Cont{
private:
	int num;
public:
	int getNum();
	void setNum(int);
};

int Cont::getNum(){
	return num;
}
void Cont::setNum(int n){
	num = n;
}

#endif	/* CONT_H */
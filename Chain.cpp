#include <iostream>

using namespace std;
class Chain;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
	}
	Number& operator=(const Number& ref){
		num = ref.num;
		return *this;
	}
	operator int(){
		return num;
	}
	void ShowNumber() { cout << num << endl; }
};


class ChainNode {

    template <class T>
		friend class Chain;
		friend class Number;

			ChainNode(int element = 0, ChainNode* next = 0){
					data = element; link = next;
			}
		private:
			~ChainNode(){
			}
   			T data;
			ChainNode<T> *link;
			Number n = new Number(data);

};

template <class T>
class Chain {
		public:
				Chain() {
					  first = 0;
					  last = 0;
				}

				~Chain() {
						first = NULL;
						last = NULL;
				}
				void InsertFront();//
				void InsertBack();//
				T& Front();//
				T& Back();//
				T& Get();//
				void DeleteFront();//
				void DeleteBack();//
				void InsertNext();//
				void Delete();//
				Chain<T> :: ChainIterator<T> Begin(){
					ChainIterator<T> iter(first);
					return iter;
				}
				Chain<T> :: ChainIterator<T> End(){
					ChainIterator<T> iter(0);
					return iter;
				}
				};



		private:
				class ChainIterator{
						public:
								friend class Chain;
								ChainIterator(ChainNode <T>* startNode = 0)
								{current = startNode;}

								T& operator*() const {return current -> data;}
								T* operator -> () const {return &current -> data;}

								ChainIterator& operator++()
								{current = current -> link; return *this;}
								ChainIterator operator++(int)
								{
										ChainIterator old = *this;
										current = current -> link;
										return old;
								}
								bool operator!=(const ChainIterator right)const
								{return current != right.current;}
								bool operator==(const ChainIterator right)const
								{return current == right.current;}
						private:
								ChainNode <T>* current;
				};
				ChainNode<T> *first;
				ChainNode<T> *last;
};

template <class T>
~Chain(){
	ChainNode *previous = 0;
	while ( first != 0){
		previous = first;
		first = first -> link;
		delete previous;
	}
}


template <class T>
void Chain<T> :: InsertFront(const T& e) {
			if (first == 0){
					last = first = new ChainNode<T>(e);
			}
			else{
				ChainNode<T> *node = new ChainNode<T>(e);
				node -> link = first;
				first = node;
			}
}

template<class T>
void Chain<T> :: InsertBack(const T& e){
		if (first){
				last -> link = new ChainNode<T>(e);
				last = last -> link;
		}
		else
				first = last = new ChainNode<T>(e);
}

template<class T>
void Chain<T> :: DeleteFront() {
		first = first -> link;
}
template<class T>
void Chain<T> :: DeleteBack(){
	   ChainNode<T> *previous, *current;
   current = first;
   previous = first;
while(current != last){
	 previous = current;
     current = current -> link;
}
last = previous;
last -> link = 0;
current = NULL;
}

template<class T>
T& Chain<T> :: Front (){

		return first;
}
template<class T>
T& Chain<T> :: Back (){
		return last;
}

template<class T>
T& Chain<T> :: Get(int i){
	ChainNode<T> * find = first;
	for (int k = 0 ; k < i ; find = find -> link){
	}
	return find;
}
template <class T>
T& Chain<T> :: InsertNext(ChainIterator<T> iter, const T& contents){
	ChainNode<T> *node = new ChainNode<T>(contents);
	ChainNode<T> *previous = iter.node;
	if (previous == 0){
		if (first) {
		previous -> link = first;
		first = previous;
	}
	else{
		first = last = node;
	}
	}
	else{
		node -> link = previous -> link;
		previous -> link = node;
		if (previous == last){
			last = node;
		}
	}
}
template <class T>
void Chain<T> :: Delete(ChainIterator<T> iter){
	ChainNode<T> *find = iter.node;
	ChainNode<T> *previous, *current;
	if (find == 0){
first = first -> link;
	}
	else if (find == last){
  current = first;
  previous = first;
 while(current != last){
  previous = current;
 	 current = current -> link;
 }
 last = previous;
 last -> link = 0;
 current = NULL;
	}
	else{

		for(current = first; current != find  ; current = find->next)
			 {
					 previous = current;
			 }
		previous -> link = find -> link;
	}
}

int main(){

	Chain<int> c;
	for (int i = 1; i <= 9; i++){
		c.InsertBack(i);
	}
	cout << "1-9 출력"<<endl;

	for (int i = 0; i < 10; i++){
				cout << c.Get(i).data <<" ";
	}
		printf("\n");

	c.InsertFront(0);
	int sum = 0;
	cout << "전체 노드의 값 출력:" ;
	for (int i = 0; i <= 10; i++){
		cout << c.Get(i).data <<" ";
		sum += c.Get(i).data;
	}
	printf("\n");
	cout << "총합 출력: " << sum << endl;
	c.InsertBack(10);
	sum = 0;
	cout <<"전체 노드의 값:";
	for (int i = 0; i <= 10; i++){
		cout << c.Get(i).data <<" ";
		sum += c.Get(i).data;
	}
	cout <<"총합 출력: "<<sum <<endl;
  cout <<"Front 호출: ";
	c.ShowNumber(c.Front());
	cout <<"Back 호출: ";
	c.ShowNumber(c.Back());
	cout << "Get(2) 호출";
	c.ShowNumber(c.Get(2));
	c.DeleteFront();
	sum = 0;
	cout <<"전체 노드의 값:";
	for (int i = 0; i < 10; i++){
		cout << c.Get(i).data <<" ";
		sum += c.Get(i).data;
	}
	cout <<"총합 출력:"<<sum <<endl;

	c.DeleteBack();

	sum = 0;
	cout <<"전체 노드의 값:";
	for (int i = 0; i < 10; i++){
		cout << c.Get(i).data <<" ";
		sum += c.Get(i).data;
	}
	cout <<"총합 출력:"<<sum <<endl;
 ChainIterator<int> find = c.Begin();
 ChainIterator<int> last = c.End();
 for (int i = 0; i < 3; find++){

 }
	c.InsertNext(find,100);
	sum = 0;
	cout <<"전체 노드의 값:";
	for (int i = 0; i < 10; i++){
		cout << c.Get(i).data <<" ";
		sum += c.Get(i).data;
	}
	cout <<"총합 출력:"<<sum <<endl;
	for (int i = 0; i < 3; find++){

	}
	c.Delete(find);
	sum = 0;
	cout <<"전체 노드의 값:";
	for (int i = 0; i < 10; i++){
		cout << c.Get(i).data <<" ";
		sum += c.Get(i).data;
	}
	cout <<"총합 출력:"<<sum <<endl;
return 0;
}

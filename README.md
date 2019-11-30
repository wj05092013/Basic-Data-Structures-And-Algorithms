# Practice Algorithm

## 설명

기초적인 알고리즘을 복습하기 위해 몇년 전에 공부했던 자료구조 및 알고리즘 기본 학습서인 「열혈 자료구조」(저자 윤성우)에 등장하는 여러 자료구조와 알고리즘들을 C\+\+ 로 구현하였다.
흔히 사용하는 **C\+\+ STL**의 인터페이스와 유사하게 구성하였고, Container의 경우 **Iterator**를 통한 접근과 연산이 가능하도록 하였다.


## 구현 항목

#### Container

###### Linked List

* Doubly Linked List 방식으로 구현하였다.
* Iterator의 접근은 Front에서 Back 방향으로 순차적으로 진행한다.

###### Set

* Binary Search Tree 방식으로 구현하였다.
* Iterator의 접근은 정렬된 순서대로 진행한다.

###### Priority Queue

* 배열을 기반으로 한 Complete Binary Tree 방식으로 구현하였다.
* Iterator의 접근은 정렬된 순서대로 진행한다.
* **우선순위를 결정하기 위한 기본적인 연산자들을 제공한다.**
	* 연산자들은 Functor 형식으로 만들어졌다.
	* 'CompareFunctor'를 상속하는 'Less'와 'Greater'가 존재한다.

###### Hash Table

* Double Hashing Method를 이용한 **Open Addressing** 방식으로 구현하였다.
* **Iterator의 접근은 어떠한 순서도 보장하지 않는다.**
	* 순서를 보장하기 위해 key 값들을 set(Binary Search Tree)에 저장하여 관리하고자 하였으나, 이는 데이터 입력과 삭제 시 O(lg N)의 시간복잡도가 발생한다. Hash Table의 최대 장점인 상수시간 데이터 접근을 위해 데이터 순서 보장은 포기하였다.
* 데이터 입력 시, collision을 피하기 위해 table의 크기가 항상 **소수(Prime Number)**가 되도록 하였다.
* **std::function<>** 템플릿을 이용해, 사용자가 Hash 함수를 직접 등록할 수 있게 하였다.

#### Algorithm

###### Search

* Binary Search
* Interpolation Search

###### Sort

* Insertion Sort
* Selection Sort
* Merge Sort
* Quick Sort

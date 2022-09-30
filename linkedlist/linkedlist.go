package main

import "fmt"

type Node struct {
	val  int
	next *Node
}

type Linkedlist struct {
	head *Node
}

func (l *Linkedlist) Insert(data int) {
	node := &Node{val: data}
	if l.head == nil {
		l.head = node
		return
	}

	current := l.head
	for current.next != nil {
		current = current.next
	}

	current.next = node

}

func (l *Linkedlist) Print() {
	current := l.head
	for current != nil {
		fmt.Println(current.val)
		current = current.next
	}
}

func main() {
	l := Linkedlist{}
	l.Insert(1)
	l.Insert(2)
	l.Insert(3)
	l.Insert(4)
	l.Print()
}

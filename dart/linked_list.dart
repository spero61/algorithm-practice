// implementaion of a singly-linked list in Dart

class Node<T> {
  T value;
  Node<T>? next;

  // constructor with named arguments
  Node({required this.value, this.next});

  // recursively print all nodes
  @override
  String toString() {
    if (next == null) {
      return '$value';
    }
    return '$value -> ${next.toString()}';
  }
}

class LinkedList<E> {
  Node<E>? head;
  Node<E>? tail;

  bool get isEmpty {
    return head == null;
  }

  void push(E value) {
    head = Node(value: value, next: head);
    tail ??= head; // if tail is null, assign head to it
  }

  @override
  String toString() {
    if (isEmpty) {
      return 'This Linked List is Empty';
    }
    return head.toString();
  }
}

void main(List<String> arguments) {
  final list = LinkedList<int>();
  list.push(9);
  list.push(6);
  list.push(3);

  print(list); // 3 -> 6 -> 9
}

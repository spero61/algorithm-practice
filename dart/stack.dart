class Stack<E> {
  Stack() : _list = <E>[];
  final List<E> _list;

  // add element to the end of the list
  void push(E elem) {
    return _list.add(elem);
  }

  // removes and returns the last element of the list
  E pop() {
    return _list.removeLast();
  }

  @override
  String toString() {
    // to represent stack as top to bottom structure
    // join method API: https://api.dart.dev/stable/2.18.1/dart-async/Stream/join.html
    return '''----stack----
${_list.reversed.join('\n')}
------------''';
  }
}

void main(List<String> arguments) {
  final stack = Stack<String>();
  stack.push('first');
  stack.push('second');
  stack.push('third');
  stack.push('fourth');
  stack.push('fifth');
  print(stack);
  print('\n');

  final topElem = stack.pop();
  print('pop: $topElem');
  print('pop: ${stack.pop()}');

  print('\n');
  print(stack);
}

# Algorithm Practice

### Index:

- [Prime Factorization - C](./c/prime_factorization.c)
    <details open>
    <summary>note </summary>
    <br>
    Though this C-version is much faster than Python one,<br>
    it still takes some time when the input number is significantly large.<br>
    So I tried to pre-calculate prime numbers to speed up the process<br>
    using the program, an excerption of the original, as follows:<br>
    <a href="./c/primes_to_file.c">primes_to_file.c</a><br><br>
   
    
    ```bash
    clang -o primes_to_file primes_to_file.c -lm
    ./primes_to_file 100
    ```
    _primes.txt_<br>
    ```
    {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}
    ```
    <br>
    The output file size, however, drastically increases as the input number grows.<br>
    Therefore it is not reasonable to utilize precalculated prime numbers<br>
    because it requires considerable storage memory.<br><br>
    <table>
        <thead>
            <tr>
                <th colspan="2" style="text-align:center">input num</th>
                <th colspan="2" style="text-align:center">file size</th>
            </tr>
        </thead>
        <tbody style="text-align:right">
            <tr>
                <td>10,000,000</td>
                <td>10 million</td>
                <td>5,105KB</td>
                <td>4.98MB</td>
            </tr>
            <tr>
                <td>100,000,000</td>
                <td>100 million</td>
                <td>49,902KB</td>
                <td>48.7MB</td>   
            </tr>
            <tr>
                <td>1,000,000,000</td>
                <td>1 billion</td>
                <td>490,196KB</td>
                <td>478MB</td>
            </tr>
            <tr>
                <td>2,000,000,000</td>
                <td>2 billion</td>
                <td>999,104KB</td>
                <td>975MB</td>
            </tr>
        </tbody>
        <tfoot>
            <tr style="font-style: italic">
                <td colspan="4">There is no space but a comma between numbers</td>
            </tr>
        </tfoot>
    </table>
    </details>

    <details>
    <summary>usage </summary>
    <br>
    <image alt="fact_usage_c.png" src="./screenshots/fact_usage_c.png">
    </details>

#

- [Prime Factorization - Python](./python/prime_factorization.py)
    <details>
    <summary>usage </summary>
    <br>
    <image alt="fact_usage_py.png" src="./screenshots/fact_usage_py.png">
    </details>

#

- [Doubly Linked List - C++](./cpp/doubly_linked_list.cpp)
    <details open>
    <summary>output </summary>
    <br>
    <image alt="doubly_linked_list_cpp.png" src="./screenshots/doubly_linked_list_cpp.png">
    </details>


- [Stack and Heap - C++](./cpp/stack_and_heap.cpp)
    <details open>
    <summary>output </summary>
    <br>
    <image alt="stack_and_heap.png" src="./screenshots/stack_and_heap.png">
    </details>

- [Linked List - C](./c/linked_list.c)
- [Tree - C](./c/tree.c)
- [Palindrome - C++](./cpp/palindrome.cpp)
- [Palindrome - Python](./python/palindrome.py)


This repository is licensed under [a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International (CC BY-NC-SA 4.0) license](https://creativecommons.org/licenses/by-nc-sa/4.0/)

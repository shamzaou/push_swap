# Push Swap

Push Swap is an efficient sorting algorithm project implemented in C. The goal of this project is to sort a given set of numbers by applying a series of predefined operations. These operations are performed on two stacks: `stack_a` and `stack_b`. The project showcases the efficiency and effectiveness of the implemented algorithm, adhering to strict coding standards.

## Overview

The input numbers are initially stored in `stack_a`, while `stack_b` starts empty. The following operations are allowed to sort the numbers:

- `sa`: Swap the first two elements of `stack_a`
- `sb`: Swap the first two elements of `stack_b`
- `ss`: Perform both `sa` and `sb`
- `pa`: Push the top element of `stack_b` onto `stack_a`
- `pb`: Push the top element of `stack_a` onto `stack_b`
- `ra`: Rotate `stack_a` upwards (the first element becomes the last)
- `rb`: Rotate `stack_b` upwards (the first element becomes the last)
- `rr`: Perform both `ra` and `rb`
- `rra`: Rotate `stack_a` downwards (the last element becomes the first)
- `rrb`: Rotate `stack_b` downwards (the last element becomes the first)
- `rrr`: Perform both `rra` and `rrb`

The objective is to sort the numbers in `stack_a` using the least number of operations, while following the project's coding requirements.

## Approach

The sorting algorithm implemented in this project is based on the radix sort, with a few adaptations to manage negative numbers, as the original radix sort can't handle them. The algorithm leverages the concept of index assignments and ensures a constant number of steps when sorting a stack, regardless of the values inside.

The following techniques are used to sort different input sizes:

1. For input sizes of 3 or less, a simple sorting function is used to handle the sorting.
2. For input sizes between 4 and 6, the `five_sort` function is employed, which moves the smallest elements to `stack_b`, sorts `stack_a` using the 3-element sorting function, and then moves the elements back to `stack_a`.
3. For larger input sizes, the adapted radix sort algorithm is used, which sorts the numbers based on their indexes, allowing it to handle negative numbers efficiently.

These sorting methods are combined with efficient error handling and memory management to ensure optimal performance and robustness.

## Usage

To use the Push Swap project, first compile the program using the provided Makefile:

```
make
```

Then, run the program with a list of numbers as arguments:

```
./push_swap 4 3 1 6 8 2
```

The program will output a series of operations that can be applied to sort the input numbers. The resulting operations can be tested using the provided checker program.

## Conclusion

Push Swap is a demonstration of an efficient and elegant sorting algorithm implemented in C, showcasing the power of combining various sorting techniques and effective memory management. By adapting the radix sort algorithm to handle negative numbers and using index assignments, this project offers a practical tool for sorting numbers using a limited set of operations, while maintaining constant sorting steps.

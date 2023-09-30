#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename ForwardIterator>
void mixNumbers(ForwardIterator begin, ForwardIterator end)
{
    ForwardIterator current = begin; // Use the passed begin iterator
    ForwardIterator next;

    while (current != end)
    {
        int value = *current;

        if (value == 0) {
            current++;
            continue;
        }

        next = current;
        std::advance(next, value);

        if (next < begin || next >= end) {
            current++;
            continue;
        }

        while (next != current)
        {
            std::iter_swap(current, next);
            current = next;
            std::advance(next, value);

            if (next < begin || next >= end) {
                break;
            }
        }

        ++current;
    }
}



// template <typename ForwardIterator>
// void mixNumbers(ForwardIterator begin, ForwardIterator end)
// {
//     if (begin == end)
//     {
//         return;

//         ForwardIterator current = begin;
//         ForwardIterator next;

//         while (current != end)
//         {
//             int value = *current;

//             if (value == 0)
//             {
//                 current++;
//                 continue;
//             }

//             next = current;
//             std::advance(next, value);

//             if (next == current)
//             {
//                 current++;
//                 continue;
//             }

//             std::rotate(current, current, next);

//             if (next == end)
//             {

//                 while (next != current)
//                 {
//                     std::advance(next, -value);
//                     std::rotate(current, current, next);
//                 }
//             }
//             else if (next == begin)
//             {
//                 while (next != current)
//                 {
//                     std::advance(next, -value);
//                     std::rotate(next, next, current);
//                 }
//             }

//             current++;
//         }
//     }
// }

// using std::vector;

// template <typename ForwardIterator>
// void mixNumbers(ForwardIterator begin, ForwardIterator end)
// {
//     ForwardIterator current = begin;
//     ForwardIterator next;

//     while (current != end)
//     {
//         int value = *current;

//         if (value == 0) {
//             current++;
//             continue;
//         }

//         next = current;
//         std::advance(next, value);

//         if (next < end) {
//             std::iter_swap(current, next);
//             current = next;
//             std::advance(next, value);
//             current++;
//             continue;
//         }

//         if (next > end) {
//             std::iter_swap(next, current);
//             current = next;
//             std::advance(next, value);
//             current++;
//             continue;
//         }

//         if (next != end) {
//             std::iter_swap(current, next);
//             current = next;
//             std::advance(next, value);
//             current++;
//             continue;
//         }

//         // while (next != current)
//         // {
//         //     std::iter_swap(current, next);
//         //     current = next;
//         //     std::advance(next, value);

//         //     if (next < begin || next >= end) {
//         //         break;
//         //     }
//         // }

//         ++current;
//     }
// }

//     ForwardIterator current = begin;
//     ForwardIterator next;

//     while (current != end)
//     {
//         int value = *current;

//         next = current;
//         std::advance(next, value);

//         // if (next < begin || next >= end)
//         // {
//         //     current++;
//         //     continue;
//         // }

//         while (next != current)
//         {

//             if (value == 0)
//             {
//                 current++;
//                 continue;
//             }

//             if (value > 0)
//             {
//                 std::iter_swap(current, next);
//                 current = next;
//                 std::advance(next, value);
//             }

//             if (value < 0)
//             {
//                 std::iter_swap(current, next);
//                 current = next;
//                 std::advance(next, value);
//             }

//             std::iter_swap(current, next);
//             current = next;
//             std::advance(next, value);

//             if (next < begin || next >= end)
//             {
//                 break;
//             }
//         }

//         ++current;
//     }
// }

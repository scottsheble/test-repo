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

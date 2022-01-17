#include <stdio.h>
#include <math.h>

#define MAX 100

int kb_to_byte(int kb)
{
    int byte;
    byte = kb * 1024;
    return byte;
}

int mb_to_byte(int mb)
{
    int byte;
    byte = mb * 1024 * 1024;
    return byte;
}

int get_exponent(int num)
{
    int exponent = 0;
    while (num % 2 == 0)
    {
        num = num / 2;
        exponent++;
    }
    return exponent;
}

int binary_to_decimal(float n)
{
    int num = n, dec = 0, base = 1, temp = num;
    while (temp)
    {
        int last = temp % 10;
        temp = temp / 10;
        dec = dec + last * base;
        base = base * 2;
    }
    return dec;
}

int main()
{
    int process_size, page_size, physical_memory_size, page_table_capacity, total_frames, total_pages, valid_bit, physical_memory_bits, off_set_bits, logical_address_bits, page_number_bits, frames[MAX], valid_bits[MAX], i, page_number, page_offset;

    printf("Please enter process size [KB] : ");
    scanf("%d", &process_size);
    process_size = kb_to_byte(process_size);

    printf("Please enter page size [bytes] : ");
    scanf("%d", &page_size);

    printf("Please enter size of the physical memory [MB] : ");
    scanf("%d", &physical_memory_size);
    physical_memory_size = mb_to_byte(physical_memory_size);

    total_frames = physical_memory_size / page_size;

    total_pages = process_size / page_size;

    physical_memory_bits = get_exponent(physical_memory_size);

    off_set_bits = get_exponent(page_size);

    logical_address_bits = get_exponent(process_size);

    page_number_bits = logical_address_bits - off_set_bits;

    printf("Total frames in memory: 2^%d\n", get_exponent(total_frames));
    printf("Total number of pages: %d\n", total_pages);
    printf("Total number of bits in physical memory address: %d\n", physical_memory_bits);
    printf("Total number of bits in logical memory address: %d\n", logical_address_bits);
    printf("Total number of bits in offset: %d\n", off_set_bits);

    printf("Please enter the page table:\n");
    printf("------------------------------------\n");
    printf("| Page No. | Frame No. | Valid Bit |\n");
    printf("|----------|-----------|-----------|\n");
    for (i = 0; i < total_pages; i++)
    {
        printf("| %8d |         ", i);
        scanf("%d", &frames[i]);
        scanf("%d", &valid_bits[i]);
    }
    printf("------------------------------------\n");

    printf("Enter %d bit logical address: ", logical_address_bits);
    scanf("%d%d", &page_number, &page_offset);

    if (frames[binary_to_decimal(page_number)] == -1 || valid_bits[binary_to_decimal(page_number)] == 0)
    {
        printf("That was a page fault.\n");
    }
    else
    {
        printf("That was a page hit.\n");
    }
    return 0;
}
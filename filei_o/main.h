#ifndef MAIN_H
#define MAIN_H
#define ELF_HEADER_SIZE 64
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
*
*
*
*/
typedef struct
{
    unsigned char magic[4];
    uint8_t class;
    uint8_t data;
    uint8_t version;
    uint8_t os_abi;
    uint8_t abi_version;
    uint8_t padding[7];
    uint16_t type;
    uint16_t machine;
    uint32_t version2;
    uint64_t entry_point_address;
} ElfHeader;
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int main(int argc, char *argv[]);
void handle_error(int error_code, const char *file_path);
void print_elf_header_info(unsigned char *elf_header);
#endif

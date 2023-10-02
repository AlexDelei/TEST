#include "main.h"
/**
 *main - prints elf header info
 *@argc: arguement count
 *@argv: arguement array
 *Return: 0 success
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Could not open file '%s'\n", argv[1]);
		exit(1);
	}

	if (lseek(fileno(fp), 0, SEEK_SET) != 0)
	{
		perror("lseek");
		exit(1);
	}

	if (read(fileno(fp), &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		perror("read");
		exit(1);
	}
	printf("ELF Header:\n");
	printf("  Magic: 0x%08x\n", elf_header.e_ident[EI_MAG2]);
	printf("  Class: %d\n", elf_header.e_ident[EI_CLASS]);
	printf("  Data: %d\n", elf_header.e_ident[EI_DATA]);
	printf("  Version: %d\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI: %d\n", elf_header.e_ident[EI_OSABI]);
	printf("  ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type: %d\n", elf_header.e_type);
	printf("  Entry point: 0x%lx\n", elf_header.e_entry);
	fclose(fp);
	return (0);
}

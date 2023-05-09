#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <stdlib.h>

void print_error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(98);
}

void print_elf_header(const char *filename, Elf64_Ehdr *hdr) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < SELFMAG; i++) {
        printf("%02x ", hdr->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n",
           hdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           hdr->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           "Invalid");
    printf("  Data:                              %s\n",
           hdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           hdr->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
           "Invalid");
    printf("  Version:                           %d (current)\n",
           hdr->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n",
           hdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - GNU" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_AIX ? "UNIX - AIX" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_OPENBSD ? "UNIX - OpenBSD" :
           hdr->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" :
           "Invalid");
    printf("  ABI Version:                       %d\n",
           hdr->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n",
           hdr->e_type == ET_REL ? "REL (Relocatable file)" :
           hdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
           hdr->e_type == ET_DYN ? "DYN (Shared object file)" :
           hdr->e_type == ET_CORE ? "CORE (Core file)" :
           "Invalid");
    printf("  Entry point address:               0x%lx\n", hdr->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Failed to open file");
    }
    
    Elf64_Ehdr hdr;
    if (read(fd, &hdr, sizeof(hdr)) != sizeof(hdr)) {
        print_error("Failed to read ELF header");
    }

    if (hdr.e_ident[EI_MAG0] != ELFMAG0 ||
        hdr.e_ident[EI_MAG1] != ELFMAG1 ||
        hdr.e_ident[EI_MAG2] != ELFMAG2 ||
        hdr.e_ident[EI_MAG3] != ELFMAG3) {
        print_error("File is not an ELF file");
    }
    
    print_elf_header(argv[1], &hdr);
    
    if (close(fd) == -1) {
        print_error("Failed to close file");
    }
    
    return 0;
}

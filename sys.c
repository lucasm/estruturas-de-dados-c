#include <stdio.h>
#include <sys/utsname.h>

int main() {
    struct utsname system_info;

    if (uname(&system_info) != 0) {
        perror("Erro ao obter informações do sistema");
        return 1;
    }

    printf("Nome do sistema operacional: %s\n", system_info.sysname);
    printf("Nome da máquina: %s\n", system_info.nodename);
    printf("Versão do sistema operacional: %s\n", system_info.release);
    printf("Informações adicionais de versão: %s\n", system_info.version);
    printf("Arquitetura do processador: %s\n", system_info.machine);

    return 0;
}

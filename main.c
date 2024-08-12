#include <stdio.h>

int main(void) {
  int i, j;
  int dni;
  int atender[4][5];
  int salir = 0;
  int confirmar = 0;
  int horarioturno;
  int opcion, opcioncaso2;
  int medicoelegido;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      atender[i][j] = 0;
    }
  }
  while (salir == 0) {
    printf("1. Registrar un turno\n");
    printf("2. Mostrar en formato de tablas\n");
    printf("3. Salir\n");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      printf("ingrese con que medico quiere atenderse (1-4)\n");
      scanf("%d", &medicoelegido);

      printf("Ingrese su DNI\n");
      scanf("%d", &dni);

      if (medicoelegido < 1 || medicoelegido > 4) {
        printf("Ingrese un médico válido (1-4)\n");
      }

      printf("Ingrese la hora a la que desea el turno (0-4)\n");
      scanf("%d", &horarioturno);

      if (horarioturno < 0 || horarioturno > 24) {
        printf("Hora invlida (0-24)\n");
      }

      printf("Desea confirmar el turno? (1. SI / 0. NO)\n");
      scanf("%d", &confirmar);

      if (confirmar == 1) {
        printf("Se ha confirmado el turno\n");
        atender[medicoelegido - 1][horarioturno] = 1;
      } else {
        printf("Se ha cancelado el turno\n");
      }

      break;
    case 2:
      printf("1. todos los turnos de un medico específico\n");
      printf("que medico desea ver? (1-4)\n");
      scanf("%d", &medicoelegido);
      if (medicoelegido < 1 || medicoelegido > 4) {
        printf("no existe este medico en la clinica\n");
      }
      printf("\n");
      printf("0. TURNO NO CONFIRMADO\n");
      printf("1. TURNO CONFIRMADO\n");
      printf("\n");
      printf("Los turnos para el medico %d son:\n", medicoelegido);
      for (j = 0; j < 5; j++) {
        printf("%d\t", atender[medicoelegido - 1][j]);
      }
      printf("\n");

      printf("Los turnos confirmados de todos los medicos son:\n");

      for (i = 0; i < 4; i++) {
        printf("medico %d:\t", i + 1);
        for (j = 0; j < 5; j++) {
          if (atender[i][j] == 1) {
            printf("1\t");
          } else {
            printf("0\t");
          }
        }
        printf("\n");
      }
      break;

    case 3:
      salir = 1;
      printf("saliendo del programa...\n");
      break;

    default:
      printf("Opción invalida\n");
    }
  }
  return 0;
}
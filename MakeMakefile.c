#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void creerFIC(char nom[], char DOS[]){
    FILE* f;
    char nomF[256];

    sprintf (nomF, "%s/%s", DOS, nom);
    f = fopen(nomF, "w" );
    fclose(f);
}

void creerDOS(char nom[]){
    char mk[256]="mkdir ";
    strcat(mk,nom);
    system(mk);

    char cd[256]="cd ";
    strcat(cd,nom);
    system(cd);
}

void WmakeF(char nom[], char DOS[]){
    FILE* f;
    char chem[256];

    creerFIC(nom, DOS);
    sprintf (chem, "%s/%s", DOS, nom);
    f = fopen(chem, "w" );
    fprintf(f,"compil:\n	gcc -o main main.c -Wall\nrun: main\n	./main\n");
    fclose(f);
}

void ficC(char nom[], char DOS[]){
    FILE* f;
    char chem[256];

    creerFIC(nom, DOS);
    sprintf (chem, "%s/%s", DOS, nom);
    f = fopen(chem, "w" );
    fprintf(f,"#include <stdlib.h>\n#include <stdio.h>\n\n\nint main(){\n//Votre code ici\nreturn 0;\n}");
    fclose(f);
}

void ficPython(char nom[], char DOS[]){
    FILE* f;
    char chem[256];

    creerFIC(nom, DOS);
    sprintf (chem, "%s/%s", DOS, nom);
    f = fopen(chem, "w" );
    fprintf(f,"print(\"Hello World !\")");
    fclose(f);
    free(DOS);
}

void ficHTML(char nom[], char DOS[]){
    FILE* f;
    char chem[256];

    creerFIC(nom, DOS);
    sprintf (chem, "%s/%s", DOS, nom);
    f = fopen(chem, "w" );
    fprintf(f,"<!doctype html>\n<html lang='fr'>\n <head>\n	<meta charset=\"utf-8\">\n	<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n	<meta name=\"author\" content=\"\">\n	<meta name=\"description\" content=\"VOID\">\n	<title>index</title>\n	<link rel=\"icon\" href=\"\">\n	<link rel=\"stylesheet\" href=\"PageCSS.css\">\n </head>\n \n<body>\n\n\n</body>\n");
    fclose(f);
}

void ficCSS(char nom[], char DOS[]){
    FILE* f;
    char chem[256];

    creerFIC(nom, DOS);
    sprintf (chem, "%s/%s", DOS, nom);
    f = fopen(chem, "w" );
    fprintf(f,".");
    fclose(f);
}

void help(void)
{
    system("clear");
    printf("Utilisation : MMF [DOSSIER DE TRAVAIL][LANGAGE]\n\n");
    printf("-0 | Ne crée pas de nouveau dossier de travail. Reste dans le répertoire courant\n\n");
    printf("[Nom d'un nouveau dossier] | Crée un nouveau dossier de travail\n\n");
    printf("-python ou -C ou -html | Choisit le langage\n\n");
    printf("-UI | permet d'avoir un affichage plus graphique\n\n");
    printf("-h | Affiche ce menu d'aide.\n\n");
}

int ui(){
  char DOS[256];
  int choix1, choix0;
  choix1=0;
  choix0=-1;

      printf("\n###########################\n### Préparateur de Code ###\n###########################\n");
      printf("\nComment souhaitez-vous nommer ce nouveau dossier de travail ? \n");
      scanf("%s",DOS);
      creerDOS(DOS);

  // Module de choix à propos du langage
      printf("\n Quel langage souhaitez-vous ? \n ''1'' pour C, ''2'' pour HTML, ''3'' pour Python \n");
      scanf("%d",&choix0);

      while(choix0){
          if (choix0==1){
              printf("\nLe langage choisis est le C\n");
              // Module de choix à propos du makefile
              printf("\n Souhaitez-vous un Makefile ? \n ''1'' pour Oui, ''0'' pour non \n");
              scanf("%d",&choix1);
              while(choix1!=1 || choix1!=0){
                  if (choix1==1){
                      printf("\nUn makefile sera ajouté à votre environnement de travail\n");
                      WmakeF("Makefile",DOS);
                      ficC("main.c",DOS);
                      return 1;
                  }
                  if(choix1==0){
                      printf("\nAucun makefile ne sera ajouté à votre environnement de travail\n");
                      ficC("main.c",DOS);
                      return 1;
                  }
                  else{
                      return 999;
                  }
              }
          }
          if(choix0==2){
              printf("\nLe langage choisit est le HTML\n");
              ficHTML("index.html",DOS);
              ficCSS("PageCSS.css",DOS);
              return 1;
          }
          if(choix0==3){
              printf("\nLe langage choisit est le Python\n");
              ficPython("script.py",DOS);
              return 1;
          }
          else{
              printf("Pas compris");
              return 999;
          }
      }
}

int main(int argc, char ** argv){
  // MMF [Dossier o/n][Langage]
  int u;
  char *DOS;

  if (argc>3){
    printf("Trop d'arguments, ""faites MMF -h""\n");
  }

  // Dossier
  if (strcmp(argv[1], "-0") == 0){
    DOS=".";
  }
  if (strcmp(argv[1], "-UI") == 0){
    // Affichage graphique
    u=ui();
    if (u==1){
      return 1;
    }
    if (u==999){
      help();
      return 1;
    }
  }
  if (strcmp(argv[1], "-h") == 0){
    help();
    return 1;
  }
  if (strcmp(argv[1], "-0") != 0){
    DOS = argv[1];
    creerDOS(argv[1]); // avoir si on peut pas le retirer
  }

  // Choix du langage
  if (strcmp(argv[2], "-python") == 0){
    printf("%s\n", DOS);
    ficPython("script.py",DOS);
    return 1;
  }

  if (strcmp(argv[2], "-C") == 0){
    WmakeF("Makefile",DOS);
    ficC("main.c",DOS);
    return 1;
  }

  if (strcmp(argv[2], "-html") == 0){
    ficHTML("index.html",DOS);
    ficCSS("PageCSS.css",DOS);
    return 1;
  }


return 0;
}

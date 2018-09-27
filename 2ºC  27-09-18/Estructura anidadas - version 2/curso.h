
typedef struct{
int id;
char nombre[30];
int duracion;
char profesor[30];

}eCurso;
void inicializarCurso (eCurso*);
void mostrarCurso(eCurso );
void mostrarListadoCurso(eCurso* , int );

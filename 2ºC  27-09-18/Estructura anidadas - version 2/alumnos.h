

typedef struct
{
    int legajo;
    char nombre[50]; // Guarda una cadena. Por eso es un vector.
    char direccion[50];
    float promedio;
    int estado;
    int idCurso;
} eAlumno;



/**harcodeo**/
void inicializarAlumnosConDatos(eAlumno [], int );
/************/


eAlumno cargarAlumno();
void mostrarAlumno (eAlumno alumnoParametro);
int cargarListado(eAlumno [], int );
int modificarAlumno(eAlumno listado[], int tam);

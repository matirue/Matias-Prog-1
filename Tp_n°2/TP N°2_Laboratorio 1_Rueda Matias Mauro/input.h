/** \brief Solicita una leta al usuario y la devuelve.
 * \param [] char Es el mensaje a mostrar.
 * \return char Devuelve la letra ingresada.
 */
char getChar(char []);

/** \brief Verifica si el valor recibido contiene solo letras
 * \param char Array con la cadena a ser analizada
 * \return int 1 si contiene solo ' ' y 0 si no lo es
 *
 */
int esSoloLetra(char []);

/**
* \brief Pide un texto solo letras al usuario y lo devuelve
* \param char Es el texto a ser mostrado
* \param char Es el Arrat donde se cargara el texto pedido
* \return 1 si el texto contiene solo letras
*/
int getStringLetras(char [], char []);

/*********************************************************************************************************************/

/** \brief Solicita un número al usuario y devuelve el resultado
 * \param char Es el mensaje a ser mostrado
 * \return float El número ingresado por el usuario
 */
float getFloat(char []);

/**
* \brief Verifica si el valor recibido es numérico aceptando flotantes
* \param char Array con la cadena a ser analizada
* \return int 1 si es númerico y 0 si no lo es
*/
int esNumericoFlotante(char []);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param char Es el mensaje a ser mostrado
 * \param char Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char [],char []);

/*********************************************************************************************************************/

/** \brief Le pide un numero al ususario y devuelve un resultado.
 * \param char Es el mensaje a ser mostrado.
 * \return int Devuelve el numero ingresado por el usuario.
 */
int getInt(char []);

/**
* \brief verifica si el valor recibido es numerico
* \param  char Array  con la cadena a ser analizado
* \return int 1 si es numerico y 0 si no lo es.
*/
int esNumerico(char []);

/**
* \brief Pide un texto numerico al usuario y lo devuelve
* \param char Es el texto a ser mostrado
* \param char Es el Array donde se cargara el texto pedido
* \return 1 si el texto contiene solo numeros, 0 caso contrario
*/
int getStringNumeros(char [], char []);

 /**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param char Es el mensaje a ser mostrado para solicitar el dato
 * \param char Es el mensaje a ser mostrado en caso de error
 * \param int Es el valor minimo del rango
 * \param int Es el valor maximo del rango
 * \return El número ingresado por el usuario
 */
int getValidInt(char [],char [],int ,int );

/*********************************************************************************************************************/

/**
 * \brief Pide un texto al usuario y lo devuelve
 * \param char Es el texto a ser mostrado
 * \param char Es el Array donde se cargara el texto pedido
 * \return void
 */
 void getString(char [], char []);

 /**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param char Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */
 int esAlfaNumerico(char []);

 /**
 * \brief Solicita un string
 * \param char Es el mensaje a ser mostrado para solicitar el dato
 * \param char Es el mensaje a ser mostrado en caso de error
 * \param char Array donde se cargará el texto ingresado
 * \return void
 *
 */
void getValidString(char [],char [], char []);

/**
 * \brief Limpia el stdin, similar a fflush
 * \param void
 * \return void
 */
void clean_stdin(void);


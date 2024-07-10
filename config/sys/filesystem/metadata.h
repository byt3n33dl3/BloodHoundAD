/*
 *
 * Operating System Design / Diseño de Sistemas Operativos
 * (c) ARCOS.INF.UC3M.ES
 *
 * @file 	metadata.h
 * @brief 	Definition of the structures and data types of the file system.
 * @date	Last revision 01/04/2020
 *
 */

#define bitmap_getbit(bitmap_, i_) (bitmap_[i_ >> 3] & (1 << (i_ & 0x07)))

static inline void bitmap_setbit(char *bitmap_, int i_, int val_) {
  if (val_)
    bitmap_[(i_ >> 3)] |= (1 << (i_ & 0x07));
  else
    bitmap_[(i_ >> 3)] &= ~(1 << (i_ & 0x07));
}

#define MAX_FILES 48
#define MAX_LENGHT 32 //Máxima longitud para el nombre de un fichero y enlace simbólico
#define MAX_FILE_SIZE 10240
#define BLOCK_SIZE 2048
#define OPEN 1
#define CLOSE 0
#define BLOCKS_FOR_INODES 2
#define NUMBER_INODES_PER_BLOCK 24
#define NUMBER_DIRECT_BLOCKS 5

struct INode;
struct Superblock;

#define NUMINODO 48 //Habrá tantos inodos como archivos sea capaz de soportar el sistema
#define NUMBLOQUESDATO 300 //Número maximo de bloques que habrá pues son 600KB

typedef struct TipoSuperbloque{
    unsigned int numMagico;	                   /* Número mágico del superbloque: 0x000D5500 */
    unsigned int numInodos; 	                 /* Número de inodos en el dispositivo */
    unsigned int primerInodo;	                 /* Número del bloque del 1º inodo del disp. (inodo raíz) */
    unsigned int numBloquesDatos;              /* Número de bloques de datos en el disp. */
    unsigned int primerBloqueDatos;            /* Número de bloque del 1º bloque de datos */
    unsigned int tamDispositivo;	             /* Tamaño total del disp. (en bytes) */
    char i_map[NUMINODO/8] ; 			             /* Mapa de bits con los inodos (usado: i_map[x]=1 | libre: i_map[x]=0) */ 
    char b_map[NUMBLOQUESDATO/8] ; 	           /* Mapa de bits con los bloques (usado: b_map[x]=1 | libre: b_map[x]=0) */
    char relleno[BLOCK_SIZE-8*sizeof(int)-NUMINODO/8 -NUMBLOQUESDATO/8];    /* Campo de relleno (para completar un bloque entero en el superbloque) */
} TipoSuperbloque;


typedef struct TipoInodoDisco{
    /*  En el sistema considerado solo se tendrá soporte para ficheros y no directórios, tal y 
        como se especifica en los requisitos */
    
    char nombre[MAX_LENGHT];	              /* Nombre del fichero asociado */ 
    uint16_t size;	                        /* Tamaño actual del fichero en bytes */

    /*  Cada inodo apunta a un fichero y como el tamaño máximo de un fichero es 10240 Bytes
        y cada bloque tiene 2048 Bytes  entonces se apunta a 5 bloques como máximo */
    uint8_t bloqueDirecto[NUMBER_DIRECT_BLOCKS];	            /* Número del bloque directo */

    char integridad_boolean;             /* Booleano de integridad 0: No tiene integridad, 1: Tiene integridad. CHAR para ahorrar espacio. 1Byte*/
    uint32_t integridad ;                /* cada vez que se hace close se sincroniza */
    
    char tipo_enlace;                    /* Para distinguir si se trata de un enlace simbólico o no 0 fichero, 1 Enlace*/
    char nombre_apuntado[MAX_LENGHT];	   /* Nombre del fichero al que apunta el enlace simbólico */ 

} TipoInodoDisco;


typedef struct TipoInodosBloque{ 

  /* Cada inodo ocupa 64 Bytes, hay 48 luego son 3072B asi que no caben en un solo bloque */
  TipoInodoDisco inodos [NUMBER_INODES_PER_BLOCK];                           /* 1536 B */
  char relleno[BLOCK_SIZE-NUMBER_INODES_PER_BLOCK*sizeof(TipoInodoDisco)];   /* Campo relleno */

} TipoInodosBloque;
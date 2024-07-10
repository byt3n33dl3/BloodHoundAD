/*
 *
 * Operating System Design / Diseño de Sistemas Operativos
 * (c) ARCOS.INF.UC3M.ES
 *
 * @file 	auxiliary.h
 * @brief 	Headers for the auxiliary functions required by filesystem.c.
 * @date	Last revision 01/04/2020
 *
 */

/*
 * @brief 	Synchronises disk and memory
 * @return 	0 if success, -1 otherwise.
 */
int my_sync(void);

/*
 * @brief 	Allocates an inode
 * @return 	array of position of the inode if success, [-1, -1] otherwise.
 */
int * ialloc(void);

/*
 * @brief 	computes the position of the inode map
 * @return 	array of position of the inode exists [block, position in the block], [-1, -1] otherwise.
 */
int * computePositionInodeMap(int positionMap);

/*
 * @brief 	computes the position of the inodeX
 * @return 	position of the inodeX if success, -1 otherwise.
 */
int computePositionInodeX(int * arrayPosicion);

/*
 * @brief 	Allocates a block
 * @return 	block if success, -1 otherwise.
 */
int alloc(void);

/*
 * @brief 	Liberates an inode
 * @return  1 if success, -1 if fail
 */
int ifree(int * arrayPosicion);

/*
 * @brief 	Liberates a block
 * @return  1 if success, -1 if fail
 */
int bfree(uint8_t * arrayBloquesDirectos);

/*
 * @brief 	Search an inode looking at the name
 * @return 	array of position of the inode if success, [-1, -1] otherwise.
 */
int * namei(char *fileName);

/*
 * @brief 	Search the associated block given a file descriptor and an offset
 * @return 	block if success, -1 otherwise.
 */
int * bmap(int inodo_id, int offset);
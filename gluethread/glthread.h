#ifndef __GLUEHTREAD__
#define __GLUEHTREAD__

typedef struct _glthread{
	struct _glthread *left;
	struct _glthread *right;
} glthread_t;

//add next node
void glthread_add_next(glthread_t *curr_glthread, glthread_t *new_glthread);

//add before node
void glthread_add_before(glthread_t *curr_glthread, glthread_t *new_glthread);

void glthread_add_last(glthread_t *base_glthread, glthread_t *new_glthread);

//initiate glthread
void init_glthread(glthread_t *glthread);

void remove_glthread(glthread_t *glthread);

#define IS_GLTHREAD_LIST_EMPTY(glthreadptr)	\
	((glthreadptr)->right == 0 && (glthreadptr)->left == 0)

#define GLTHREAD_TO_STRUCT(fn_name, structure_name, field_name)	\
	static inline structure_name* fn_name(glthread_t* glthreadptr){	\
		return (structure_name *)((char *)(glthreadptr) - (char *)&(((structure_name *)0)->field_name));	\
	}

#define BASE(glthreadptr) ((glthreadptr)->right)

#define ITERATE_GLTHREAD_BEGIN(glthreadptrstart, glthreadptr)	\
{								\
	glthread_t* _glthread_ptr = NULL;	\
	glthreadptr = BASE(glthreadptrstart);	\
	for(; glthreadptr != NULL; glthreadptr = _glthread_ptr){	\
		_glthread_ptr = glthreadptr->right;
	
#define ITERATE_GLTHREAD_END(glthreadptrstart, glthreadptr)	\
	}}

#define GLTHREAD_GET_USER_DATA_FROM_OFFSET(glthreadptr, offset)	\
	(void*)((char*)(glthreadptr) - offset)

void delete_glthread_list(glthread_t* base_glthread);

unsigned int get_glthread_list_count(glthread_t* vase_glthread);

void glthread_priority_insert(glthread_t* base_glthread,
	       	              glthread_t* glthread, 
			      int (*comp_fn)(void* , void*), 
			      int offset);


#endif

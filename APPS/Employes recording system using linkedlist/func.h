#ifndef _H_FUNC_H
#define _H_FUNC_H
typedef enum {
	process_done,
	process_error
}process_status;
process_status add_employe(sll_t*list);
process_status modify_employe_data(sll_t*list);
process_status display_speceific_employe(sll_t*list);
void delete_employe(sll_t*list);
#endif
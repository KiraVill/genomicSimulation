#ifndef SIM_PRINTERS_H
#define SIM_PRINTERS_H

#include "utils.h"
#include "sim-gebv.h"

SEXP SXP_save_simdata(SEXP exd, SEXP filename);
SEXP SXP_save_genotypes(SEXP exd, SEXP filename, SEXP group, SEXP type);
SEXP SXP_save_counts(SEXP exd, SEXP filename, SEXP group, SEXP allele);
SEXP SXP_save_pedigrees(SEXP exd, SEXP filename, SEXP group, SEXP type);
SEXP SXP_save_GEBVs(SEXP exd, SEXP filename, SEXP group);

/* Savers */
void save_simdata(FILE* f, SimData* m);

void save_allele_matrix(FILE* f, AlleleMatrix* m, char** markers);
void save_transposed_allele_matrix(FILE* f, AlleleMatrix* m, char** markers);
void save_group_alleles(FILE* f, SimData* d, int group_id);
void save_transposed_group_alleles(FILE* f, SimData* d, int group_id);

void save_group_one_step_pedigree(FILE* f, SimData* d, int group); 
void save_one_step_pedigree(FILE* f, SimData* d); 
void save_group_full_pedigree(FILE* f, SimData* d, int group);
void save_full_pedigree(FILE* f, AlleleMatrix* m, AlleleMatrix* parents);
void save_parents_of(FILE* f, AlleleMatrix* m, unsigned int id);

void save_group_fitness(FILE* f, SimData* d, int group);
void save_fitness(FILE* f, DecimalMatrix* e, unsigned int* ids, char** names);
void save_all_fitness(FILE* f, SimData* d);

void save_count_matrix(FILE* f, SimData* d, char allele);
void save_count_matrix_of_group(FILE* f, SimData* d, char allele, int group);

#endif
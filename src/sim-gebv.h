#ifndef SIM_GEBV_H
#define SIM_GEBV_H

#include "utils.h"

/* Fitness calculators */
int split_group_by_fitness(SimData* d, int group, int top_n, int lowIsBest);
DecimalMatrix calculate_fitness_metric_of_group(SimData* d, int group);
DecimalMatrix calculate_fitness_metric( AlleleMatrix* m, EffectMatrix* e);
DecimalMatrix calculate_count_matrix_of_allele_for_ids( AlleleMatrix* m, unsigned int* for_ids, unsigned int n_ids, char allele);
DecimalMatrix calculate_full_count_matrix_of_allele( AlleleMatrix* m, char allele);
SEXP SXP_group_eval(SEXP exd, SEXP group);
SEXP SXP_simple_selection(SEXP exd, SEXP glen, SEXP groups, SEXP number, SEXP bestIsLow);
SEXP SXP_simple_selection_bypercent(SEXP exd, SEXP glen, SEXP groups, SEXP percent, SEXP bestIsLow);

#endif
#include "sim-crossers.h"
#include "sim-fitness.h"
#include "sim-loaders.h"
#include "sim-printers.h"
#include "sim-groups.h"

/*-------------------------- Loaders -------------------------*/

SEXP SXP_load_data(SEXP alleleFile, SEXP mapFile);
SEXP SXP_load_data_weff(SEXP alleleFile, SEXP mapFile, SEXP effectFile);
SEXP SXP_load_more_genotypes(SEXP exd, SEXP alleleFile);
SEXP SXP_load_new_effects(SEXP exd, SEXP effectFile);

/*----------------Crossing-----------------*/
GenOptions create_genoptions(SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
SEXP SXP_cross_randomly(SEXP exd, SEXP glen, SEXP groups, SEXP crosses, SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
SEXP SXP_cross_Rcombinations(SEXP exd, SEXP firstparents, SEXP secondparents,
		SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
SEXP SXP_cross_combinations(SEXP exd, SEXP filename, SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
SEXP SXP_dcross_combinations(SEXP exd, SEXP filename, SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
SEXP SXP_cross_unidirectional(SEXP exd, SEXP glen, SEXP groups, SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
/*SEXP cross_top(SEXP exd, SEXP group, SEXP percent, SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);*/
SEXP SXP_selfing(SEXP exd, SEXP glen, SEXP groups, SEXP n, SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
SEXP SXP_doubled(SEXP exd, SEXP glen, SEXP groups, SEXP name, SEXP namePrefix, SEXP familySize,
		SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, SEXP savePedigree,
		SEXP saveEffects, SEXP saveGenes, SEXP retain);
SEXP SXP_one_cross(SEXP exd, SEXP parent1_index, SEXP parent2_index, SEXP name, 
		SEXP namePrefix, SEXP familySize, SEXP trackPedigree, SEXP giveIds, SEXP filePrefix, 
		SEXP savePedigree, SEXP saveEffects, SEXP saveGenes, SEXP retain);

/*-----------------------------------Groups----------------------------------*/
SEXP SXP_combine_groups(SEXP exd, SEXP len, SEXP groups);
SEXP SXP_split_individuals(SEXP exd, SEXP group);
SEXP SXP_split_familywise(SEXP exd, SEXP group);
SEXP SXP_split_out(SEXP exd, SEXP len, SEXP indexes);

/*-----------------Fitness-------------------*/
SEXP SXP_group_eval(SEXP exd, SEXP group);
SEXP SXP_simple_selection(SEXP exd, SEXP glen, SEXP groups, SEXP number, SEXP bestIsLow);
SEXP SXP_simple_selection_bypercent(SEXP exd, SEXP glen, SEXP groups, SEXP percent, SEXP bestIsLow);


/*-----------------Data access---------------*/
SEXP SXP_get_best_genotype(SEXP exd);
SEXP SXP_get_best_GEBV(SEXP exd);

SEXP SXP_find_crossovers(SEXP exd, SEXP parentFile, SEXP outFile, SEXP windowSize, SEXP certainty);
SEXP SXP_send_map(SEXP exd);

SEXP SXP_get_groups(SEXP exd);
SEXP SXP_get_group_data(SEXP exd, SEXP group, SEXP whatData);

/*--------------------------------Printing-----------------------------------*/
SEXP SXP_save_simdata(SEXP exd, SEXP filename);
SEXP SXP_save_genotypes(SEXP exd, SEXP filename, SEXP group, SEXP type);
SEXP SXP_save_counts(SEXP exd, SEXP filename, SEXP group, SEXP allele);
SEXP SXP_save_pedigrees(SEXP exd, SEXP filename, SEXP group, SEXP type);
SEXP SXP_save_GEBVs(SEXP exd, SEXP filename, SEXP group);
SEXP SXP_save_file_block_effects(SEXP exd, SEXP filename, SEXP block_file, SEXP group);
SEXP SXP_save_chrsplit_block_effects(SEXP exd, SEXP filename, SEXP nslices, SEXP group);

/*--------------------------------Deletors------------------------------------*/
SEXP clear_simdata(SEXP exd);
void SXP_delete_simdata(SEXP sd);
SEXP SXP_delete_group(SEXP exd, SEXP group);
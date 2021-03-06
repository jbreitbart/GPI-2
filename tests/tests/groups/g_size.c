#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <test_utils.h>

//test groups size
int main(int argc, char *argv[])
{

  gaspi_group_t g;
  gaspi_number_t ngroups, i;
  gaspi_rank_t gsize, nprocs;
  
  TSUITE_INIT(argc, argv);
  
  ASSERT (gaspi_proc_init(GASPI_BLOCK));

  ASSERT(gaspi_proc_num(&nprocs));
  
  ASSERT(gaspi_group_num(&ngroups));

  //should have GASPI_GROUP_ALL and size = nranks
  assert((ngroups == 1));
  ASSERT(gaspi_group_size(GASPI_GROUP_ALL, &gsize));
  assert((gsize == nprocs));
    
  ASSERT (gaspi_group_create(&g));
  ASSERT(gaspi_group_size(g, &gsize));
  assert((gsize == 0));

  for(i = 0; i < nprocs; i++)
    {
      ASSERT(gaspi_group_add(g, i));
      ASSERT(gaspi_group_size(g, &gsize));
      assert(( gsize == (i+1) ));
    }

  ASSERT (gaspi_barrier(GASPI_GROUP_ALL, GASPI_BLOCK));
  
  ASSERT (gaspi_proc_term(GASPI_BLOCK));

  return EXIT_SUCCESS;
}

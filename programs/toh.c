/*towers of hanoi*/
#include "stdio.h"

	void towers(int,char,char,char);

	void towers(int n,char frompeg,char topeg,char auxpeg)
			{
					  if(n==1)
    { printf("\n1 from %c to %c",frompeg,topeg);
								    	      return;
									      	    }

	  	  towers(n-1,frompeg,auxpeg,topeg);

	  printf("\n%d from %c to %c",n,frompeg,topeg);
	  

  	  towers(n-1,auxpeg,topeg,frompeg);
					  	}
	main()
			{ int n;

	  	  scanf("%d",&n);
  	  towers(n,'A','C','B');
	  	  return 0;
									  	}

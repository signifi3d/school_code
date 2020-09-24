#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>      // for times()
#include <time.h>           // for clock()

char * name = "Blake Eakin";

/* I will be using only the two functions
 you will be changing when grading. So
 * don't write code you want to keep outside
 *  of the two functions (they won't be copied over)
 */

     // These can be changed for debugging purposes
         // but DO CHANGE THEM TO THE ORIGINAL VALUES
	     //    RUNS = 10000
	         //    SIZE = 10000
		     #define RUNS 10000
		         #define SIZE 10000


			     /*  write a function using gcc inline assembly
			          * that calculates the area of a triangle.
				        * the formula for doing so is:
					       *    area = 1/2 x side1 x side2
					               */
						       int calcArea(int side1, int side2)
						       {
						               int area = 1.0;

							               asm("mov %1, %0\n\t"
								                   "imul %2, %0\n\t"
										               "shr $1, %0"
											                   :"=r"(area)
													               :"r"(side1), "r"(side2)
														               );

															               return area;
																       }

																       /* this is the original function
																       * DON"T TOUCH THIS FUNCTION
																       * it's for reference only
																       */
																       int sumAreaOrig(int a, int b, int *arr)
																       {
																       int sum, i, j;

																       for(i=0; i<RUNS; i++) {

																       sum = 0;
																       for(j=0; j<SIZE; j++)  {
																       sum += arr[j]*calcArea(a,b) + j;
																       }

																       }
																       return sum;
																       }

																       /*  PLEASE MODIFY THIS FUNCTION
																       *  make sure it returns the same
																       *  sum as the original function
																       */
																       int sumAreaImprove(int a, int b, int *arr)
																       {
																               /* you can add any variables here */
																	               int sum, i, j;
																		               int area = calcArea(a,b);
																			               int acc0, acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9;

																				               /* leave this outer loop alon*/
																					               for(i=0; i < RUNS; i++)
																						               {
																							                       /* you can change this inner loop */
																									                       /* but remember it must sum over all values */
																											                       sum = 0;
																													                       acc0=0, acc1=0, acc2=0, acc3=0, acc4=0, acc5=0, acc6=0, acc7=0, acc8=0, acc9=0;
																															                       for(j=0; j<SIZE; j+=100)  {
																																	                               acc0 += (arr[j+0]*area + (j+0)) +(arr[j+1]*area + (j+1)) +(arr[j+2]*area + (j+2)) +(arr[j+3]*area + (j+3)) +(arr[j+4]*area + (j+4)) +(arr[j+5]*area + (j+5)) +(arr[j+6]*area + (j+6)) +(arr[j+7]*area + (j+7)) +(arr[j+8]*area + (j+8)) +(arr[j+9]*area+(j+9));
																																				                               acc1 += (arr[j+10]*area + (j+10)) +(arr[j+11]*area + (j+11)) +(arr[j+12]*area + (j+12)) +(arr[j+13]*area + (j+13)) +(arr[j+14]*area + (j+14)) +(arr[j+15]*area + (j+15)) +(arr[j+16]*area + (j+16)) +(arr[j+17]*area + (j+17)) +(arr[j+18]*area + (j+18)) +(arr[j+19]*area+(j+19));
																																							                               acc2 += (arr[j+20]*area + (j+20)) +(arr[j+21]*area + (j+21)) +(arr[j+22]*area + (j+22)) +(arr[j+23]*area + (j+23)) +(arr[j+24]*area + (j+24)) +(arr[j+25]*area + (j+25)) +(arr[j+26]*area + (j+26)) +(arr[j+27]*area + (j+27)) +(arr[j+28]*area + (j+28)) +(arr[j+29]*area+(j+29));
																																										                               acc3 += (arr[j+30]*area + (j+30)) +(arr[j+31]*area + (j+31)) +(arr[j+32]*area + (j+32)) +(arr[j+33]*area + (j+33)) +(arr[j+34]*area + (j+34)) +(arr[j+35]*area + (j+35)) +(arr[j+36]*area + (j+36)) +(arr[j+37]*area + (j+37)) +(arr[j+38]*area + (j+38)) +(arr[j+39]*area+(j+39));
																																													                               acc4 += (arr[j+40]*area + (j+40)) +(arr[j+41]*area + (j+41)) +(arr[j+42]*area + (j+42)) +(arr[j+43]*area + (j+43)) +(arr[j+44]*area + (j+44)) +(arr[j+45]*area + (j+45)) +(arr[j+46]*area + (j+46)) +(arr[j+47]*area + (j+47)) +(arr[j+48]*area + (j+48)) +(arr[j+49]*area+(j+49));
																																																                               acc5 += (arr[j+50]*area + (j+50)) +(arr[j+51]*area + (j+51)) +(arr[j+52]*area + (j+52)) +(arr[j+53]*area + (j+53)) +(arr[j+54]*area + (j+54)) +(arr[j+55]*area + (j+55)) +(arr[j+56]*area + (j+56)) +(arr[j+57]*area + (j+57)) +(arr[j+58]*area + (j+58)) +(arr[j+59]*area+(j+59));
																																																			                               acc6 += (arr[j+60]*area + (j+60)) +(arr[j+61]*area + (j+61)) +(arr[j+62]*area + (j+62)) +(arr[j+63]*area + (j+63)) +(arr[j+64]*area + (j+64)) +(arr[j+65]*area + (j+65)) +(arr[j+66]*area + (j+66)) +(arr[j+67]*area + (j+67)) +(arr[j+68]*area + (j+68)) +(arr[j+69]*area+(j+69));
																																																						                               acc7 += (arr[j+70]*area + (j+70)) +(arr[j+71]*area + (j+71)) +(arr[j+72]*area + (j+72)) +(arr[j+73]*area + (j+73)) +(arr[j+74]*area + (j+74)) +(arr[j+75]*area + (j+75)) +(arr[j+76]*area + (j+76)) +(arr[j+77]*area + (j+77)) +(arr[j+78]*area + (j+78)) +(arr[j+79]*area+(j+79));
																																																									                               acc8 += (arr[j+80]*area + (j+80)) +(arr[j+81]*area + (j+81)) +(arr[j+82]*area + (j+82)) +(arr[j+83]*area + (j+83)) +(arr[j+84]*area + (j+84)) +(arr[j+85]*area + (j+85)) +(arr[j+86]*area + (j+86)) +(arr[j+87]*area + (j+87)) +(arr[j+88]*area + (j+88)) +(arr[j+89]*area+(j+89));
																																																												                               acc9 += (arr[j+90]*area + (j+90)) +(arr[j+91]*area + (j+91)) +(arr[j+92]*area + (j+92)) +(arr[j+93]*area + (j+93)) +(arr[j+94]*area + (j+94)) +(arr[j+95]*area + (j+95)) +(arr[j+96]*area + (j+96)) +(arr[j+97]*area + (j+97)) +(arr[j+98]*area + (j+98)) +(arr[j+99]*area+(j+99));
																																																															                       }
																																																																	                       sum += acc0 + acc1 + acc2 + acc3 + acc4 + acc5 + acc6 + acc7 + acc8 + acc9;
																																																																			               }
																																																																				               return sum;
																																																																					       }

																																																																					       /* You can modify main for debugging
																																																																					       * but PLEASE RETURN IT TO THE ORIGINAL
																																																																					       * CODE. I will be using only your two functions
																																																																					       * above when grading.  So don't write code
																																																																					       * you want to keep outside of the above two
																																																																					       * functions (they won't be copied over)
																																																																					       */
																																																																					       int main(int argc, char **argv)
																																																																					       {
																																																																					               struct tms  origStart, origStop, impStart, impStop;
																																																																						               double origTime, impTime;
																																																																							               double difference;
																																																																								               int area, sumOrig, sumImprove;
																																																																									               int side1, side2;
																																																																										               int i;
																																																																											               int array[SIZE];

																																																																												               for(i=0; i<SIZE; i++)
																																																																													                       array[i] = i;

																																																																															               if(argc < 3) {
																																																																																                       printf("Need to provide two side measurements\n");
																																																																																		                       exit(-1);
																																																																																				               } else {
																																																																																					                       side1 = atoi(argv[1]);
																																																																																							                       side2 = atoi(argv[2]);
																																																																																									               }

																																																																																										               printf("side1: %d  side2: %d\n", side1, side2);

																																																																																											               printf("Name: %s\n",name);

																																																																																												               area = calcArea(side1, side2);
																																																																																													               printf("the area is: %d\n", area);

																																																																																														               //start time here
																																																																																															               times(&origStart);
																																																																																																               sumOrig = sumAreaOrig(side1, side2, array);
																																																																																																	               times(&origStop);
																																																																																																		               //end time here
																																																																																																			               printf("results from orignal: %d\n", sumOrig);

																																																																																																				               // start time here
																																																																																																					               times(&impStart);
																																																																																																						               sumImprove = sumAreaImprove(side1, side2, array);
																																																																																																							               times(&impStop);
																																																																																																								               // end time here
																																																																																																									               printf("results from improved: %d\n", sumImprove);

																																																																																																										               //do time calculations here
																																																																																																											               origTime = (origStop.tms_utime - origStart.tms_utime);
																																																																																																												               impTime =  (impStop.tms_utime - impStart.tms_utime);
																																																																																																													               printf("original user time: %f\n",origTime);
																																																																																																														               printf("improved user time: %f\n", impTime);
																																																																																																															               difference = ((origTime - impTime)/origTime)*100.0;
																																																																																																																               printf("percent difference:  %f\n", difference);

																																																																																																																	               return 0;
																																																																																																																		       }

																																																																																																																		       

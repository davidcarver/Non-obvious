double findArea1(int n, double x[], double y[])
{
   int i, j;
   double area;

   area = 0;
   for (i = 0; i < n; i++) 
   {
      j = (i + 1)% n;
      area += x[j] * y[i] - y[j] * x[i];
   }
   area /= 2.0;
   return(area < 0 ? -area : area);
}

double findArea2(int n, double x[], double y[])
{
   int i, j;
   double area;

   j = n - 1; // wrapper index

   area = 0;
   for (i = 0; i < n; i++) 
   {
      area += x[j] * y[i] - y[j] * x[i];
      j = i;
   }
   area /= 2.0;
   return(area < 0 ? -area : area);
}

double findArea3(int n, double x[], double y[])
{
  // Daniel Sunday (2002) Fast Polygon Area and Newell Normal Computation, Journal 
  // of Graphics Tools, 7:2, 9-13, DOI: 10.1080/10867651.2002.10487556

  // Robert D. Miller, East Lansing, Michigan Revised (2012?) to remove the two 
  // redundant data points, since only the first and last points of the array require
  // computing array indices modulo n and since the sum must be initialized anyway, 
  // a slight modification breaks those two special case triangles out of the loop. 

  int i;
  double area;

  // Initialize area with the boundary vertex terms
  area = x[0] * (y[1] - y[n-1]) + x[n-1] * (y[0] - y[n-2]);

  for (i = 1; i < n - 1; i++)
     area += x[i] * (y[i+1] - y[i-1]);

  area /= 2.0;
  return(area < 0 ? -area : area);
}

__kernel void ex1(__global float dataAlpha,
   				  __global const float * dataX,
   				  __global const float * dataY,
				  __global float * data)
{
	int id = get_global_id(0);
    data[id] = dataAlpha * dataX[id] + dataY[id];
}

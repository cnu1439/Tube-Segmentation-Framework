#ifndef TUBE_SEGMENTATION
#define TUBE_SEGMENTATION

#define CL_USE_DEPRECATED_OPENCL_1_1_APIS

#include "OpenCLUtilities/openCLUtilities.hpp"
#include "SIPL/Core.hpp"
#include <iostream>
#include <string>
#ifdef CPP11
#include <unordered_map>
using std::unordered_map;
#else
#include <boost/unordered_map.hpp>
using boost::unordered_map;
#endif
#include "commons.hpp"

typedef struct TubeSegmentation {
    float *Fx, *Fy, *Fz; // The GVF vector field
    float *TDF; // The TDF response
    float *radius;
    char *centerline;
    char *segmentation;
} TubeSegmentation;

typedef unordered_map<std::string, std::string> paramList;

cl::Image3D readDatasetAndTransfer(OpenCL, std::string, paramList, SIPL::int3 *);

paramList getParameters(int argc, char ** argv);

TubeSegmentation runCircleFittingAndRidgeTraversal(OpenCL, cl::Image3D dataset, SIPL::int3 size, paramList);

TubeSegmentation runCircleFittingAndNewCenterlineAlg(OpenCL, cl::Image3D dataset, SIPL::int3 size, paramList);

#endif

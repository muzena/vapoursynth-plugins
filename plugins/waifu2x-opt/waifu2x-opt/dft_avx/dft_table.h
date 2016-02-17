#ifndef WAIFU2X_DFT_AVX_TABLE_H
#define WAIFU2X_DFT_AVX_TABLE_H

#include "../common/x86.h"

namespace waifu2x {

ALIGNED(32) static const float RDFT15_TABLE[16 * 15] = {
	1.0000000f,  1.0000000f,  1.0000000f,  1.0000000f,  1.0000000f,  1.0000000f,  1.0000000f,  1.0000000f,
	0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,
	1.0000000f,  0.9135455f,  0.6691306f,  0.3090170f, -0.1045285f, -0.5000000f, -0.8090170f, -0.9781476f,
	0.0000000f, -0.4067366f, -0.7431448f, -0.9510565f, -0.9945219f, -0.8660254f, -0.5877853f, -0.2079117f,
	1.0000000f,  0.6691306f, -0.1045285f, -0.8090170f, -0.9781476f, -0.5000000f,  0.3090170f,  0.9135455f,
	0.0000000f, -0.7431448f, -0.9945219f, -0.5877853f,  0.2079117f,  0.8660254f,  0.9510565f,  0.4067366f,
	1.0000000f,  0.3090170f, -0.8090170f, -0.8090170f,  0.3090170f,  1.0000000f,  0.3090170f, -0.8090170f,
	0.0000000f, -0.9510565f, -0.5877853f,  0.5877853f,  0.9510565f,  0.0000000f, -0.9510565f, -0.5877853f,
	1.0000000f, -0.1045285f, -0.9781476f,  0.3090170f,  0.9135455f, -0.5000000f, -0.8090170f,  0.6691306f,
	0.0000000f, -0.9945219f,  0.2079117f,  0.9510565f, -0.4067366f, -0.8660254f,  0.5877853f,  0.7431448f,
	1.0000000f, -0.5000000f, -0.5000000f,  1.0000000f, -0.5000000f, -0.5000000f,  1.0000000f, -0.5000000f,
	0.0000000f, -0.8660254f,  0.8660254f,  0.0000000f, -0.8660254f,  0.8660254f, -0.0000000f, -0.8660254f,
	1.0000000f, -0.8090170f,  0.3090170f,  0.3090170f, -0.8090170f,  1.0000000f, -0.8090170f,  0.3090170f,
	0.0000000f, -0.5877853f,  0.9510565f, -0.9510565f,  0.5877853f,  0.0000000f, -0.5877853f,  0.9510565f,
	1.0000000f, -0.9781476f,  0.9135455f, -0.8090170f,  0.6691306f, -0.5000000f,  0.3090170f, -0.1045285f,
	0.0000000f, -0.2079117f,  0.4067366f, -0.5877853f,  0.7431448f, -0.8660254f,  0.9510565f, -0.9945219f,
	1.0000000f, -0.9781476f,  0.9135455f, -0.8090170f,  0.6691306f, -0.5000000f,  0.3090170f, -0.1045285f,
	0.0000000f,  0.2079117f, -0.4067366f,  0.5877853f, -0.7431448f,  0.8660254f, -0.9510565f,  0.9945219f,
	1.0000000f, -0.8090170f,  0.3090170f,  0.3090170f, -0.8090170f,  1.0000000f, -0.8090170f,  0.3090170f,
	0.0000000f,  0.5877853f, -0.9510565f,  0.9510565f, -0.5877853f,  0.0000000f,  0.5877853f, -0.9510565f,
	1.0000000f, -0.5000000f, -0.5000000f,  1.0000000f, -0.5000000f, -0.5000000f,  1.0000000f, -0.5000000f,
	0.0000000f,  0.8660254f, -0.8660254f,  0.0000000f,  0.8660254f, -0.8660254f, -0.0000000f,  0.8660254f,
	1.0000000f, -0.1045285f, -0.9781476f,  0.3090170f,  0.9135455f, -0.5000000f, -0.8090170f,  0.6691306f,
	0.0000000f,  0.9945219f, -0.2079117f, -0.9510565f,  0.4067366f,  0.8660254f, -0.5877853f, -0.7431448f,
	1.0000000f,  0.3090170f, -0.8090170f, -0.8090170f,  0.3090170f,  1.0000000f,  0.3090170f, -0.8090170f,
	0.0000000f,  0.9510565f,  0.5877853f, -0.5877853f, -0.9510565f,  0.0000000f,  0.9510565f,  0.5877853f,
	1.0000000f,  0.6691306f, -0.1045285f, -0.8090170f, -0.9781476f, -0.5000000f,  0.3090170f,  0.9135455f,
	0.0000000f,  0.7431448f,  0.9945219f,  0.5877853f, -0.2079117f, -0.8660254f, -0.9510565f, -0.4067366f,
	1.0000000f,  0.9135455f,  0.6691306f,  0.3090170f, -0.1045285f, -0.5000000f, -0.8090170f, -0.9781476f,
	0.0000000f,  0.4067366f,  0.7431448f,  0.9510565f,  0.9945219f,  0.8660254f,  0.5877853f,  0.2079117f,
};
ALIGNED(32) static const float IRDFT15_TABLE[16 * 16] = {
	 0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,
	 0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0666667f,  0.0000000f,
	 0.1333333f,  0.1218061f,  0.0892174f,  0.0412023f, -0.0139371f, -0.0666667f, -0.1078689f, -0.1304197f,
	-0.1304197f, -0.1078689f, -0.0666667f, -0.0139371f,  0.0412023f,  0.0892174f,  0.1218061f,  0.0000000f,
	 0.1333333f,  0.0892174f, -0.0139371f, -0.1078689f, -0.1304197f, -0.0666667f,  0.0412023f,  0.1218061f,
	 0.1218061f,  0.0412023f, -0.0666667f, -0.1304197f, -0.1078689f, -0.0139371f,  0.0892174f,  0.0000000f,
	 0.1333333f,  0.0412023f, -0.1078689f, -0.1078689f,  0.0412023f,  0.1333333f,  0.0412023f, -0.1078689f,
	-0.1078689f,  0.0412023f,  0.1333333f,  0.0412023f, -0.1078689f, -0.1078689f,  0.0412023f,  0.0000000f,
	 0.1333333f, -0.0139371f, -0.1304197f,  0.0412023f,  0.1218061f, -0.0666667f, -0.1078689f,  0.0892174f,
	 0.0892174f, -0.1078689f, -0.0666667f,  0.1218061f,  0.0412023f, -0.1304197f, -0.0139371f,  0.0000000f,
	 0.1333333f, -0.0666667f, -0.0666667f,  0.1333333f, -0.0666667f, -0.0666667f,  0.1333333f, -0.0666667f,
	-0.0666667f,  0.1333333f, -0.0666667f, -0.0666667f,  0.1333333f, -0.0666667f, -0.0666667f,  0.0000000f,
	 0.1333333f, -0.1078689f,  0.0412023f,  0.0412023f, -0.1078689f,  0.1333333f, -0.1078689f,  0.0412023f,
	 0.0412023f, -0.1078689f,  0.1333333f, -0.1078689f,  0.0412023f,  0.0412023f, -0.1078689f,  0.0000000f,
	 0.1333333f, -0.1304197f,  0.1218061f, -0.1078689f,  0.0892174f, -0.0666667f,  0.0412023f, -0.0139371f,
	-0.0139371f,  0.0412023f, -0.0666667f,  0.0892174f, -0.1078689f,  0.1218061f, -0.1304197f,  0.0000000f,
	 0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,
	 0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,  0.0000000f,
	 0.0000000f, -0.0542316f, -0.0990860f, -0.1268075f, -0.1326029f, -0.1154701f, -0.0783714f, -0.0277216f,
	 0.0277216f,  0.0783714f,  0.1154701f,  0.1326029f,  0.1268075f,  0.0990860f,  0.0542316f,  0.0000000f,
	 0.0000000f, -0.0990860f, -0.1326029f, -0.0783714f,  0.0277216f,  0.1154701f,  0.1268075f,  0.0542316f,
	-0.0542316f, -0.1268075f, -0.1154701f, -0.0277216f,  0.0783714f,  0.1326029f,  0.0990860f,  0.0000000f,
	 0.0000000f, -0.1268075f, -0.0783714f,  0.0783714f,  0.1268075f,  0.0000000f, -0.1268075f, -0.0783714f,
	 0.0783714f,  0.1268075f,  0.0000000f, -0.1268075f, -0.0783714f,  0.0783714f,  0.1268075f,  0.0000000f,
	 0.0000000f, -0.1326029f,  0.0277216f,  0.1268075f, -0.0542316f, -0.1154701f,  0.0783714f,  0.0990860f,
	-0.0990860f, -0.0783714f,  0.1154701f,  0.0542316f, -0.1268075f, -0.0277216f,  0.1326029f,  0.0000000f,
	 0.0000000f, -0.1154701f,  0.1154701f,  0.0000000f, -0.1154701f,  0.1154701f,  0.0000000f, -0.1154701f,
	 0.1154701f,  0.0000000f, -0.1154701f,  0.1154701f,  0.0000000f, -0.1154701f,  0.1154701f,  0.0000000f,
	 0.0000000f, -0.0783714f,  0.1268075f, -0.1268075f,  0.0783714f, -0.0000000f, -0.0783714f,  0.1268075f,
	-0.1268075f,  0.0783714f, -0.0000000f, -0.0783714f,  0.1268075f, -0.1268075f,  0.0783714f,  0.0000000f,
	 0.0000000f, -0.0277216f,  0.0542316f, -0.0783714f,  0.0990860f, -0.1154701f,  0.1268075f, -0.1326029f,
	 0.1326029f, -0.1268075f,  0.1154701f, -0.0990860f,  0.0783714f, -0.0542316f,  0.0277216f,  0.0000000f,
};

ALIGNED(32) static const float SIN_TABLE[] = {
	0.0000000f,  0.3826834f,  0.7071068f,  0.9238795f,  1.0000000f,  0.9238795f,  0.7071068f,  0.3826834f,
	0.0000000f, -0.3826834f, -0.7071068f, -0.9238795f, -1.0000000f, -0.9238795f, -0.7071068f, -0.3826834f,
};
ALIGNED(32) static const float COS_TABLE[] = {
	 1.0000000f,  0.9238795f,  0.7071068f,  0.3826834f,  0.0000000f, -0.3826834f, -0.7071068f, -0.9238795f,
	-1.0000000f, -0.9238795f, -0.7071068f, -0.3826834f, -0.0000000f,  0.3826834f,  0.7071068f,  0.9238795f,
};

}

#endif

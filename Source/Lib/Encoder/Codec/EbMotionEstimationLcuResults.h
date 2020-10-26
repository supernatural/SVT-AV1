/*
* Copyright(c) 2019 Intel Corporation
*
* This source code is subject to the terms of the BSD 2 Clause License and
* the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
* was not distributed with this source code in the LICENSE file, you can
* obtain it at https://www.aomedia.org/license/software-license. If the Alliance for Open
* Media Patent License 1.0 was not distributed with this source code in the
* PATENTS file, you can obtain it at https://www.aomedia.org/license/patent-license.
*/

#ifndef EbMotionEstimationLcuResults_h
#define EbMotionEstimationLcuResults_h

#include "EbDefinitions.h"
#include "EbObject.h"
#ifdef __cplusplus
extern "C" {
#endif

#define MAX_ME_PU_COUNT \
    209 // Sum of all the possible partitions which have both deminsions greater than 4.
#define MAX_PA_ME_MV 7 // 1 per ref = up 7 = up 4+ up to 3
#define MAX_PA_ME_CAND 23 // [Single Ref = 7] + [BiDir = 12 = 3*4 ] + [4 = 3+1]
#define SQUARE_PU_COUNT 85
typedef struct MeCandidate {
    uint8_t direction : 2;
    uint8_t ref_idx_l0 : 2; // allows for up to 4 references
    uint8_t ref_idx_l1 : 2;
    uint8_t ref0_list : 1;
    uint8_t ref1_list : 1;
} MeCandidate;
typedef struct MvCandidate {
    signed short x_mv;
    signed short y_mv;
} MvCandidate;
// move this to a new file with ctor & dtor
typedef struct MeSbResults {
    EbDctor       dctor;
    uint32_t      sb_distortion;
    uint8_t *     total_me_candidate_index;
    MvCandidate *me_mv_array;
    MeCandidate *me_candidate_array;
    // [PU][LAST, LAST2, LAST3, GOLD, BWD, ALT2, ALT] if MRP Mode 0,
    // [PU][LAST, LAST2, BWD, ALT2] if MRP Mode 1,
    uint8_t do_comp[MAX_NUM_OF_REF_PIC_LIST][REF_LIST_MAX_DEPTH];
} MeSbResults;
#ifdef __cplusplus
}
#endif
#endif // EbMotionEstimationLcuResults_h

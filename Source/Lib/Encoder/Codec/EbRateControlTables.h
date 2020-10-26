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

#ifndef EbRateControlTables_h
#define EbRateControlTables_h

#include "EbDefinitions.h"

/**************************************
 * Rate Control Defines
 **************************************/
#define SAD_PRECISION_INTERVAL 4

#define VAR_ROUND_INTERVAL 20

#define NUMBER_OF_SAD_INTERVALS 128 // number of intervals in SAD tables

#define NUMBER_OF_INTRA_SAD_INTERVALS \
    NUMBER_OF_SAD_INTERVALS // number of intervals in intra sad_ tables

#define TOTAL_NUMBER_OF_INTERVALS (NUMBER_OF_SAD_INTERVALS + NUMBER_OF_INTRA_SAD_INTERVALS)
#define TOTAL_NUMBER_OF_REF_QP_VALUES 64
#define TOTAL_NUMBER_OF_INITIAL_RC_TABLES_ENTRY (TOTAL_NUMBER_OF_REF_QP_VALUES)

/**************************************
  * The EbBitFraction is used to define the bit fraction numbers
  **************************************/
typedef uint16_t EbBitNumber;

/**************************************
 * Initial Rate Control Structure
 **************************************/
typedef struct InitialRateControlTables {
    EbBitNumber sad_bits_array[MAX_TEMPORAL_LAYERS][NUMBER_OF_SAD_INTERVALS];
    EbBitNumber intra_sad_bits_array[MAX_TEMPORAL_LAYERS][NUMBER_OF_INTRA_SAD_INTERVALS];
} RateControlTables;
/**************************************
 * Extern Function Declarations
 **************************************/
extern EbErrorType rate_control_tables_init(RateControlTables *rate_control_tables_array);

#endif //EbRateControlTables_h

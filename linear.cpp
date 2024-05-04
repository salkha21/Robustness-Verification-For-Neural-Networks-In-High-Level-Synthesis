
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <gmp.h>
#define __gmp_const const
#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "linear.h"


using namespace std;

void forward_node0(
  float v0[11],
  float &v1
) {	// L3
  #pragma HLS inline
  #pragma HLS resource variable=v0 core=ram_t2p_bram

  v1 = (float)0.000000;	// L5
  for (int v2 = 0; v2 < 11; v2 += 1) {	// L6
    #pragma HLS pipeline II=1
    float v3 = v0[v2];	// L7
    float v4 = v1;	// L8
    float v5 = v3 + v4;	// L9
    v1 = v5;	// L10
  }
}

void forward_node2(
  float v6[11],
  float v7[11],
  float v8[11],
  int v9
) {	// L14
  #pragma HLS resource variable=v7 core=ram_t2p_bram

  #pragma HLS resource variable=v8 core=ram_t2p_bram

  float v10 = v6[0];	// L16
  float v11 = v7[0];	// L17
  float v12 = v8[v9];	// L18
  float v13 = v10 * v11;	// L19
  float v14 = v12 + v13;	// L20
  float v15 = v6[1];	// L21
  float v16 = v7[1];	// L22
  float v17 = v15 * v16;	// L23
  float v18 = v14 + v17;	// L24
  float v19 = v6[2];	// L25
  float v20 = v7[2];	// L26
  float v21 = v19 * v20;	// L27
  float v22 = v18 + v21;	// L28
  float v23 = v6[3];	// L29
  float v24 = v7[3];	// L30
  float v25 = v23 * v24;	// L31
  float v26 = v22 + v25;	// L32
  float v27 = v6[4];	// L33
  float v28 = v7[4];	// L34
  float v29 = v27 * v28;	// L35
  float v30 = v26 + v29;	// L36
  float v31 = v6[5];	// L37
  float v32 = v7[5];	// L38
  float v33 = v31 * v32;	// L39
  float v34 = v30 + v33;	// L40
  float v35 = v6[6];	// L41
  float v36 = v7[6];	// L42
  float v37 = v35 * v36;	// L43
  float v38 = v34 + v37;	// L44
  float v39 = v6[7];	// L45
  float v40 = v7[7];	// L46
  float v41 = v39 * v40;	// L47
  float v42 = v38 + v41;	// L48
  float v43 = v6[8];	// L49
  float v44 = v7[8];	// L50
  float v45 = v43 * v44;	// L51
  float v46 = v42 + v45;	// L52
  float v47 = v6[9];	// L53
  float v48 = v7[9];	// L54
  float v49 = v47 * v48;	// L55
  float v50 = v46 + v49;	// L56
  float v51 = v6[10];	// L57
  float v52 = v7[10];	// L58
  float v53 = v51 * v52;	// L59
  float v54 = v50 + v53;	// L60
  float v55 = v54 + (float)0.000000;	// L61
  v8[v9] = v55;	// L62
}

void forward_node3(
  float v56[11]
) {	// L65
  #pragma HLS resource variable=v56 core=ram_t2p_bram

  v56[0] = (float)1.000000;	// L67
  v56[1] = (float)1.000000;	// L68
  v56[2] = (float)1.000000;	// L69
  v56[3] = (float)1.000000;	// L70
  v56[4] = (float)1.000000;	// L71
  v56[5] = (float)1.000000;	// L72
  v56[6] = (float)1.000000;	// L73
  v56[7] = (float)1.000000;	// L74
  v56[8] = (float)1.000000;	// L75
  v56[9] = (float)1.000000;	// L76
  v56[10] = (float)1.000000;	// L77
}

void forward_node1(
  float v57[11],
  float v58[11]
) {	// L80
  #pragma HLS resource variable=v58 core=ram_t2p_bram

  float v59[11];	// L81
  #pragma HLS resource variable=v59 core=ram_t2p_bram

  for (int v60 = 0; v60 < 11; v60 += 1) {	// L82
    #pragma HLS dataflow
    forward_node3(v59);	// L83
    forward_node2(v57, v59, v58, v60);	// L84
  }
}

/// This is top function.
void forward(
  float v61[11],
  float &v62
) {	// L88
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS dataflow


  #pragma HLS interface ap_memory port=v61
  #pragma HLS stable variable=v61

  float v65[11];	// L93
  #pragma HLS resource variable=v65 core=ram_t2p_bram

  forward_node1(v61, v65);	// L94
  forward_node0(v65, v62);	// L95
}


#ifndef RNN_DATA_H
#define RNN_DATA_H

#include "rnn.h"

struct RNNModel {
  int input_dense_size;
  const DenseLayer *input_dense;

  int vad_gru_size;
  const GRULayer *vad_gru;

  int vad_output_size;
  const DenseLayer *vad_output;
};

struct RNNState {
  const RNNModel *model;
  float *vad_gru_state;
};


#endif


#ifndef FILTROSTP2_H_
#define FILTROSTP2_H_


#define BLOCK_SIZE 1
#define NUMBER_OF_SAMPLING_FREQUENCYS 7
#define NUMBER_OF_FILTERS 4

#define fs_96k 6
#define fs_48k 5
#define fs_44k 4
#define fs_22k 3
#define fs_16k 2
#define fs_8k 1
#define fs_1k 0

#define lp 0
#define hp 1
#define bp 2
#define n 3

#define lowpass_96k_orden 100
#define bandpass_96k_orden 100
#define highpass_96k_orden 100
#define notch_96k_orden 102

#define lowpass_48k_orden 150
#define bandpass_48k_orden 150
#define highpass_48k_orden 151
#define notch_48k_orden 152

#define lowpass_44k_orden 200
#define bandpass_44k_orden 200
#define highpass_44k_orden 201
#define notch_44k_orden 202

#define lowpass_22k_orden 320
#define bandpass_22k_orden 320
#define highpass_22k_orden 321
#define notch_22k_orden 322

#define lowpass_16k_orden 400
#define bandpass_16k_orden 400
#define highpass_16k_orden 400
#define notch_16k_orden 402

#define lowpass_8k_orden 800
#define bandpass_8k_orden 800
#define highpass_8k_orden 800
#define notch_8k_orden 802

#define lowpass_1k_orden 1500
#define bandpass_1k_orden 800
#define highpass_1k_orden 1500
#define notch_1k_orden 1502


void initFiltros(void);


#endif /* FILTROSTP2_H_ */

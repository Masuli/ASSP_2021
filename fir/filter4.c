void fir_filter() {
	int d0 = 0;
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;
	int input_sample_1;
	int input_sample_2;
	int input_sample_3;
	int input_sample_4;
	int filtered_sample_1;
	int filtered_sample_2;
	int filtered_sample_3;
	int filtered_sample_4;
	int status = 1;

	while (status > 0) {
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_1, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_2, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_3, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_4, status);
		_TCE_SIMDFIR4(input_sample_1, input_sample_2, input_sample_3, input_sample_4, d0, d1, d2, d3, filtered_sample_1, filtered_sample_2, filtered_sample_3, filtered_sample_4, d0, d1, d2, d3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_1);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_2);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_4);

		_TCE_FIFO_U8_STREAM_IN(0, input_sample_1, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_2, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_3, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_4, status);
		_TCE_SIMDFIR4(input_sample_1, input_sample_2, input_sample_3, input_sample_4, d0, d1, d2, d3, filtered_sample_1, filtered_sample_2, filtered_sample_3, filtered_sample_4, d0, d1, d2, d3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_1);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_2);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_4);

		_TCE_FIFO_U8_STREAM_IN(0, input_sample_1, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_2, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_3, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_4, status);
		_TCE_SIMDFIR4(input_sample_1, input_sample_2, input_sample_3, input_sample_4, d0, d1, d2, d3, filtered_sample_1, filtered_sample_2, filtered_sample_3, filtered_sample_4, d0, d1, d2, d3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_1);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_2);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_4);

		_TCE_FIFO_U8_STREAM_IN(0, input_sample_1, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_2, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_3, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_4, status);
		_TCE_SIMDFIR4(input_sample_1, input_sample_2, input_sample_3, input_sample_4, d0, d1, d2, d3, filtered_sample_1, filtered_sample_2, filtered_sample_3, filtered_sample_4, d0, d1, d2, d3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_1);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_2);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_4);

		_TCE_FIFO_U8_STREAM_IN(0, input_sample_1, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_2, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_3, status);
		_TCE_FIFO_U8_STREAM_IN(0, input_sample_4, status);
		_TCE_SIMDFIR4(input_sample_1, input_sample_2, input_sample_3, input_sample_4, d0, d1, d2, d3, filtered_sample_1, filtered_sample_2, filtered_sample_3, filtered_sample_4, d0, d1, d2, d3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_1);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_2);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_3);
		_TCE_FIFO_U8_STREAM_OUT(filtered_sample_4);
	}
	_TCE_SIMDFIR4(0, 0, 0, 0, d0, d1, d2, d3, filtered_sample_1, filtered_sample_2, filtered_sample_3, filtered_sample_4, d0, d1, d2, d3);
	_TCE_FIFO_U8_STREAM_OUT(filtered_sample_1);
	_TCE_FIFO_U8_STREAM_OUT(filtered_sample_2);
	_TCE_FIFO_U8_STREAM_OUT(filtered_sample_3);
	_TCE_FIFO_U8_STREAM_OUT(filtered_sample_4);	
}

void copy_header(int size) {
	int i;
	int temp;
	int status;
	for (i = 0; i < size; i++) {
		_TCE_FIFO_U8_STREAM_IN(0, temp, status);
		_TCE_FIFO_U8_STREAM_OUT(temp);
	}
}

int main() {
	copy_header(44);
	fir_filter();
	return 0;
}

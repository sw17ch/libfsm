/* Generated by libfsm */

#include LF_HEADER

#include <assert.h>
#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_P_fsm(struct fsm *fsm, struct fsm_state *x, struct fsm_state *y)
{
	struct fsm_state *s[113];
	size_t i;

	assert(x != NULL);
	assert(y != NULL);

	for (i = 0; i < 113; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 1) {
			s[1] = y;
			continue;
		}

		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			return 0;
		}
	}

	for (i = 0x21; i <= 0x23; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}
	for (i = 0x25; i <= 0x2a; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}
	for (i = 0x2c; i <= 0x2f; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}
	for (i = 0x3a; i <= 0x3b; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}
	for (i = 0x3f; i <= 0x40; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}
	for (i = 0x5b; i <= 0x5d; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[0], s[1], '_')) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '{')) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '}')) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xc2)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[3], 0xcd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[4], 0xce)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[5], 0xd5)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[6], 0xd6)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[7], 0xd7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[8], 0xd8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[9], 0xd9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[10], 0xdb)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[11], 0xdc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[12], 0xdf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[13], 0xe0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[14], 0xe1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[15], 0xe2)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[16], 0xe3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[17], 0xea)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[18], 0xef)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[0], s[19], 0xf0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[1], 0xa1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[1], 0xa7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[1], 0xab)) { return 0; }
	for (i = 0xb6; i <= 0xb7; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[2], s[1], 0xbb)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[1], 0xbf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[3], s[1], 0xbe)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[4], s[1], 0x87)) { return 0; }
	for (i = 0x9a; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[1], i)) { return 0; }
	}
	for (i = 0x89; i <= 0x8a; i++) {
		if (!fsm_addedge_literal(fsm, s[6], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[6], s[1], 0xbe)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[7], s[1], 0x80)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[7], s[1], 0x83)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[7], s[1], 0x86)) { return 0; }
	for (i = 0xb3; i <= 0xb4; i++) {
		if (!fsm_addedge_literal(fsm, s[7], s[1], i)) { return 0; }
	}
	for (i = 0x89; i <= 0x8a; i++) {
		if (!fsm_addedge_literal(fsm, s[8], s[1], i)) { return 0; }
	}
	for (i = 0x8c; i <= 0x8d; i++) {
		if (!fsm_addedge_literal(fsm, s[8], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[8], s[1], 0x9b)) { return 0; }
	for (i = 0x9e; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[8], s[1], i)) { return 0; }
	}
	for (i = 0xaa; i <= 0xad; i++) {
		if (!fsm_addedge_literal(fsm, s[9], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[10], s[1], 0x94)) { return 0; }
	for (i = 0x80; i <= 0x8d; i++) {
		if (!fsm_addedge_literal(fsm, s[11], s[1], i)) { return 0; }
	}
	for (i = 0xb7; i <= 0xb9; i++) {
		if (!fsm_addedge_literal(fsm, s[12], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[13], s[52], 0xa0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[53], 0xa1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[54], 0xa5)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[55], 0xa7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[56], 0xab)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[57], 0xb7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[58], 0xb9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[59], 0xbc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[60], 0xbe)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[13], s[61], 0xbf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[22], 0x83)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[23], 0xb1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[51], 0xa8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[67], 0x81)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[68], 0x8d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[69], 0x90)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[70], 0x99)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[71], 0x9a)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[72], 0x9b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[73], 0x9c)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[74], 0x9f)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[75], 0xa0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[76], 0xa5)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[77], 0xaa)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[78], 0xad)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[79], 0xaf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[80], 0xb0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[14], s[81], 0xb3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[56], 0xb5)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[98], 0x80)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[99], 0x81)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[100], 0x82)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[101], 0x8c)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[102], 0x9d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[103], 0x9f)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[104], 0xa6)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[105], 0xa7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[106], 0xb3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[107], 0xb8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[15], s[108], 0xb9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[16], s[20], 0x80)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[16], s[21], 0x82)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[16], s[22], 0x83)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[23], 0x93)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[24], 0x98)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[25], 0x99)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[26], 0x9b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[27], 0xa1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[28], 0xa3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[29], 0xa4)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[30], 0xa5)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[31], 0xa7)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[32], 0xa9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[33], 0xab)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[17], s[34], 0xaf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[23], 0xb4)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[62], 0xb8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[63], 0xb9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[64], 0xbc)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[18], s[65], 0xbd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[35], 0x90)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[36], 0x91)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[37], 0x92)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[38], 0x96)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[39], 0x9b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[40], 0x9d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[19], s[41], 0x9e)) { return 0; }
	for (i = 0x81; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[20], s[1], i)) { return 0; }
	}
	for (i = 0x88; i <= 0x91; i++) {
		if (!fsm_addedge_literal(fsm, s[20], s[1], i)) { return 0; }
	}
	for (i = 0x94; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[20], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[20], s[1], 0xb0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[20], s[1], 0xbd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[21], s[1], 0xa0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[22], s[1], 0xbb)) { return 0; }
	for (i = 0xbe; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[23], s[1], i)) { return 0; }
	}
	for (i = 0x8d; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[24], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[25], s[1], 0xb3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[25], s[1], 0xbe)) { return 0; }
	for (i = 0xb2; i <= 0xb7; i++) {
		if (!fsm_addedge_literal(fsm, s[26], s[1], i)) { return 0; }
	}
	for (i = 0xb4; i <= 0xb7; i++) {
		if (!fsm_addedge_literal(fsm, s[27], s[1], i)) { return 0; }
	}
	for (i = 0x8e; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[28], s[1], i)) { return 0; }
	}
	for (i = 0xb8; i <= 0xba; i++) {
		if (!fsm_addedge_literal(fsm, s[28], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[28], s[1], 0xbc)) { return 0; }
	for (i = 0xae; i <= 0xaf; i++) {
		if (!fsm_addedge_literal(fsm, s[29], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[30], s[1], 0x9f)) { return 0; }
	for (i = 0x81; i <= 0x8d; i++) {
		if (!fsm_addedge_literal(fsm, s[31], s[1], i)) { return 0; }
	}
	for (i = 0x9e; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[31], s[1], i)) { return 0; }
	}
	for (i = 0x9c; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[32], s[1], i)) { return 0; }
	}
	for (i = 0x9e; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[33], s[1], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xb1; i++) {
		if (!fsm_addedge_literal(fsm, s[33], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[34], s[1], 0xab)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[30], 0x8e)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[42], 0x84)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[43], 0x8f)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[44], 0x95)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[45], 0xa1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[46], 0xa4)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[47], 0xa9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[48], 0xab)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[49], 0xac)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[35], s[50], 0xae)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[82], 0x81)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[83], 0x82)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[84], 0x83)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[85], 0x85)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[86], 0x87)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[87], 0x88)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[88], 0x8a)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[89], 0x91)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[90], 0x93)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[91], 0x97)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[92], 0x99)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[93], 0x9c)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[94], 0xa8)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[95], 0xa9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[96], 0xaa)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[36], s[97], 0xb1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[37], s[66], 0x91)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[38], s[29], 0xa9)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[38], s[110], 0xab)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[38], s[111], 0xac)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[38], s[112], 0xad)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[39], s[30], 0xb2)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[40], s[109], 0xaa)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[41], s[51], 0xa5)) { return 0; }
	for (i = 0x80; i <= 0x82; i++) {
		if (!fsm_addedge_literal(fsm, s[42], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[43], s[1], 0x90)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[44], s[1], 0xaf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[45], s[1], 0x97)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[46], s[1], 0x9f)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[46], s[1], 0xbf)) { return 0; }
	for (i = 0x90; i <= 0x98; i++) {
		if (!fsm_addedge_literal(fsm, s[47], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[47], s[1], 0xbf)) { return 0; }
	for (i = 0xb0; i <= 0xb6; i++) {
		if (!fsm_addedge_literal(fsm, s[48], s[1], i)) { return 0; }
	}
	for (i = 0xb9; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[49], s[1], i)) { return 0; }
	}
	for (i = 0x99; i <= 0x9c; i++) {
		if (!fsm_addedge_literal(fsm, s[50], s[1], i)) { return 0; }
	}
	for (i = 0x9e; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[51], s[1], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xbe; i++) {
		if (!fsm_addedge_literal(fsm, s[52], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[53], s[1], 0x9e)) { return 0; }
	for (i = 0xa4; i <= 0xa5; i++) {
		if (!fsm_addedge_literal(fsm, s[54], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[54], s[1], 0xb0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[55], s[1], 0xbd)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[56], s[1], 0xb0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[57], s[1], 0xb4)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[58], s[1], 0x8f)) { return 0; }
	for (i = 0x9a; i <= 0x9b; i++) {
		if (!fsm_addedge_literal(fsm, s[58], s[1], i)) { return 0; }
	}
	for (i = 0x84; i <= 0x92; i++) {
		if (!fsm_addedge_literal(fsm, s[59], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[59], s[1], 0x94)) { return 0; }
	for (i = 0xba; i <= 0xbd; i++) {
		if (!fsm_addedge_literal(fsm, s[59], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[60], s[1], 0x85)) { return 0; }
	for (i = 0x90; i <= 0x94; i++) {
		if (!fsm_addedge_literal(fsm, s[61], s[1], i)) { return 0; }
	}
	for (i = 0x99; i <= 0x9a; i++) {
		if (!fsm_addedge_literal(fsm, s[61], s[1], i)) { return 0; }
	}
	for (i = 0x90; i <= 0x99; i++) {
		if (!fsm_addedge_literal(fsm, s[62], s[1], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[62], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x92; i++) {
		if (!fsm_addedge_literal(fsm, s[63], s[1], i)) { return 0; }
	}
	for (i = 0x94; i <= 0xa1; i++) {
		if (!fsm_addedge_literal(fsm, s[63], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[63], s[1], 0xa3)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[63], s[1], 0xa8)) { return 0; }
	for (i = 0xaa; i <= 0xab; i++) {
		if (!fsm_addedge_literal(fsm, s[63], s[1], i)) { return 0; }
	}
	for (i = 0x81; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[64], s[1], i)) { return 0; }
	}
	for (i = 0x85; i <= 0x8a; i++) {
		if (!fsm_addedge_literal(fsm, s[64], s[1], i)) { return 0; }
	}
	for (i = 0x8c; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[64], s[1], i)) { return 0; }
	}
	for (i = 0x9a; i <= 0x9b; i++) {
		if (!fsm_addedge_literal(fsm, s[64], s[1], i)) { return 0; }
	}
	for (i = 0x9f; i <= 0xa0; i++) {
		if (!fsm_addedge_literal(fsm, s[64], s[1], i)) { return 0; }
	}
	for (i = 0xbb; i <= 0xbd; i++) {
		if (!fsm_addedge_literal(fsm, s[64], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[64], s[1], 0xbf)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[65], s[1], 0x9b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[65], s[1], 0x9d)) { return 0; }
	for (i = 0x9f; i <= 0xa5; i++) {
		if (!fsm_addedge_literal(fsm, s[65], s[1], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xb4; i++) {
		if (!fsm_addedge_literal(fsm, s[66], s[1], i)) { return 0; }
	}
	for (i = 0x8a; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[67], s[1], i)) { return 0; }
	}
	for (i = 0xa0; i <= 0xa8; i++) {
		if (!fsm_addedge_literal(fsm, s[68], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[69], s[1], 0x80)) { return 0; }
	for (i = 0xad; i <= 0xae; i++) {
		if (!fsm_addedge_literal(fsm, s[70], s[1], i)) { return 0; }
	}
	for (i = 0x9b; i <= 0x9c; i++) {
		if (!fsm_addedge_literal(fsm, s[71], s[1], i)) { return 0; }
	}
	for (i = 0xab; i <= 0xad; i++) {
		if (!fsm_addedge_literal(fsm, s[72], s[1], i)) { return 0; }
	}
	for (i = 0xb5; i <= 0xb6; i++) {
		if (!fsm_addedge_literal(fsm, s[73], s[1], i)) { return 0; }
	}
	for (i = 0x94; i <= 0x96; i++) {
		if (!fsm_addedge_literal(fsm, s[74], s[1], i)) { return 0; }
	}
	for (i = 0x98; i <= 0x9a; i++) {
		if (!fsm_addedge_literal(fsm, s[74], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x8a; i++) {
		if (!fsm_addedge_literal(fsm, s[75], s[1], i)) { return 0; }
	}
	for (i = 0x84; i <= 0x85; i++) {
		if (!fsm_addedge_literal(fsm, s[76], s[1], i)) { return 0; }
	}
	for (i = 0xa0; i <= 0xa6; i++) {
		if (!fsm_addedge_literal(fsm, s[77], s[1], i)) { return 0; }
	}
	for (i = 0xa8; i <= 0xad; i++) {
		if (!fsm_addedge_literal(fsm, s[77], s[1], i)) { return 0; }
	}
	for (i = 0x9a; i <= 0xa0; i++) {
		if (!fsm_addedge_literal(fsm, s[78], s[1], i)) { return 0; }
	}
	for (i = 0xbc; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[79], s[1], i)) { return 0; }
	}
	for (i = 0xbb; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[80], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x87; i++) {
		if (!fsm_addedge_literal(fsm, s[81], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[81], s[1], 0x93)) { return 0; }
	for (i = 0x87; i <= 0x8d; i++) {
		if (!fsm_addedge_literal(fsm, s[82], s[1], i)) { return 0; }
	}
	for (i = 0xbb; i <= 0xbc; i++) {
		if (!fsm_addedge_literal(fsm, s[83], s[1], i)) { return 0; }
	}
	for (i = 0xbe; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[83], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x81; i++) {
		if (!fsm_addedge_literal(fsm, s[84], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[85], s[1], i)) { return 0; }
	}
	for (i = 0xb4; i <= 0xb5; i++) {
		if (!fsm_addedge_literal(fsm, s[85], s[1], i)) { return 0; }
	}
	for (i = 0x85; i <= 0x89; i++) {
		if (!fsm_addedge_literal(fsm, s[86], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[86], s[1], 0x8d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[86], s[1], 0x9b)) { return 0; }
	for (i = 0x9d; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[86], s[1], i)) { return 0; }
	}
	for (i = 0xb8; i <= 0xbd; i++) {
		if (!fsm_addedge_literal(fsm, s[87], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[88], s[1], 0xa9)) { return 0; }
	for (i = 0x8b; i <= 0x8f; i++) {
		if (!fsm_addedge_literal(fsm, s[89], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[89], s[1], 0x9b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[89], s[1], 0x9d)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[90], s[1], 0x86)) { return 0; }
	for (i = 0x81; i <= 0x97; i++) {
		if (!fsm_addedge_literal(fsm, s[91], s[1], i)) { return 0; }
	}
	for (i = 0x81; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[92], s[1], i)) { return 0; }
	}
	for (i = 0xa0; i <= 0xac; i++) {
		if (!fsm_addedge_literal(fsm, s[92], s[1], i)) { return 0; }
	}
	for (i = 0xbc; i <= 0xbe; i++) {
		if (!fsm_addedge_literal(fsm, s[93], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[94], s[1], 0xbf)) { return 0; }
	for (i = 0x80; i <= 0x86; i++) {
		if (!fsm_addedge_literal(fsm, s[95], s[1], i)) { return 0; }
	}
	for (i = 0x9a; i <= 0x9c; i++) {
		if (!fsm_addedge_literal(fsm, s[96], s[1], i)) { return 0; }
	}
	for (i = 0x9e; i <= 0xa2; i++) {
		if (!fsm_addedge_literal(fsm, s[96], s[1], i)) { return 0; }
	}
	for (i = 0x81; i <= 0x85; i++) {
		if (!fsm_addedge_literal(fsm, s[97], s[1], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xb1; i++) {
		if (!fsm_addedge_literal(fsm, s[97], s[1], i)) { return 0; }
	}
	for (i = 0x90; i <= 0xa7; i++) {
		if (!fsm_addedge_literal(fsm, s[98], s[1], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[98], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[99], s[1], i)) { return 0; }
	}
	for (i = 0x85; i <= 0x91; i++) {
		if (!fsm_addedge_literal(fsm, s[99], s[1], i)) { return 0; }
	}
	for (i = 0x93; i <= 0x9e; i++) {
		if (!fsm_addedge_literal(fsm, s[99], s[1], i)) { return 0; }
	}
	for (i = 0xbd; i <= 0xbe; i++) {
		if (!fsm_addedge_literal(fsm, s[99], s[1], i)) { return 0; }
	}
	for (i = 0x8d; i <= 0x8e; i++) {
		if (!fsm_addedge_literal(fsm, s[100], s[1], i)) { return 0; }
	}
	for (i = 0x88; i <= 0x8b; i++) {
		if (!fsm_addedge_literal(fsm, s[101], s[1], i)) { return 0; }
	}
	for (i = 0xa9; i <= 0xaa; i++) {
		if (!fsm_addedge_literal(fsm, s[101], s[1], i)) { return 0; }
	}
	for (i = 0xa8; i <= 0xb5; i++) {
		if (!fsm_addedge_literal(fsm, s[102], s[1], i)) { return 0; }
	}
	for (i = 0x85; i <= 0x86; i++) {
		if (!fsm_addedge_literal(fsm, s[103], s[1], i)) { return 0; }
	}
	for (i = 0xa6; i <= 0xaf; i++) {
		if (!fsm_addedge_literal(fsm, s[103], s[1], i)) { return 0; }
	}
	for (i = 0x83; i <= 0x98; i++) {
		if (!fsm_addedge_literal(fsm, s[104], s[1], i)) { return 0; }
	}
	for (i = 0x98; i <= 0x9b; i++) {
		if (!fsm_addedge_literal(fsm, s[105], s[1], i)) { return 0; }
	}
	for (i = 0xbc; i <= 0xbd; i++) {
		if (!fsm_addedge_literal(fsm, s[105], s[1], i)) { return 0; }
	}
	for (i = 0xb9; i <= 0xbc; i++) {
		if (!fsm_addedge_literal(fsm, s[106], s[1], i)) { return 0; }
	}
	for (i = 0xbe; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[106], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0xae; i++) {
		if (!fsm_addedge_literal(fsm, s[107], s[1], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[107], s[1], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x89; i++) {
		if (!fsm_addedge_literal(fsm, s[108], s[1], i)) { return 0; }
	}
	for (i = 0x87; i <= 0x8b; i++) {
		if (!fsm_addedge_literal(fsm, s[109], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[110], s[1], 0xb5)) { return 0; }
	for (i = 0xb7; i <= 0xbb; i++) {
		if (!fsm_addedge_literal(fsm, s[111], s[1], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[112], s[1], 0x84)) { return 0; }


	return 1;
}


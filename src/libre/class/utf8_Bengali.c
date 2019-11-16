/* Generated by libfsm */

#include LF_HEADER

#include <assert.h>
#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Bengali_fsm(struct fsm *fsm, struct fsm_state *x, struct fsm_state *y)
{
	struct fsm_state *s[5];
	size_t i;

	assert(x != NULL);
	assert(y != NULL);

	for (i = 0; i < 5; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 4) {
			s[4] = y;
			continue;
		}

		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			return 0;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xe0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[2], 0xa6)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[3], 0xa7)) { return 0; }
	for (i = 0x80; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x85; i <= 0x8c; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x8f; i <= 0x90; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x93; i <= 0xa8; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0xaa; i <= 0xb0; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0xb2)) { return 0; }
	for (i = 0xb6; i <= 0xb9; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0xbc; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[2], s[4], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x84; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0x87; i <= 0x88; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0x8b; i <= 0x8e; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	if (!fsm_addedge_literal(fsm, s[3], s[4], 0x97)) { return 0; }
	for (i = 0x9c; i <= 0x9d; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0x9f; i <= 0xa3; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}
	for (i = 0xa6; i <= 0xbd; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[4], i)) { return 0; }
	}


	return 1;
}


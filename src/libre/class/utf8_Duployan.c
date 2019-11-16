/* Generated by libfsm */

#include LF_HEADER

#include <assert.h>
#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Duployan_fsm(struct fsm *fsm, struct fsm_state *x, struct fsm_state *y)
{
	struct fsm_state *s[7];
	size_t i;

	assert(x != NULL);
	assert(y != NULL);

	for (i = 0; i < 7; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 6) {
			s[6] = y;
			continue;
		}

		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			return 0;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xf0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[2], 0x9b)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[3], 0xb0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0xb1)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[5], 0xb2)) { return 0; }
	for (i = 0x80; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[6], i)) { return 0; }
	}
	for (i = 0x80; i <= 0xaa; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[6], i)) { return 0; }
	}
	for (i = 0xb0; i <= 0xbc; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[6], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x88; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[6], i)) { return 0; }
	}
	for (i = 0x90; i <= 0x99; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[6], i)) { return 0; }
	}
	for (i = 0x9c; i <= 0x9f; i++) {
		if (!fsm_addedge_literal(fsm, s[5], s[6], i)) { return 0; }
	}


	return 1;
}


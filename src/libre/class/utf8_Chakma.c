/* Generated by libfsm */

#include LF_HEADER

#include <assert.h>
#include <stddef.h>

#include <fsm/fsm.h>

int
utf8_Chakma_fsm(struct fsm *fsm, struct fsm_state *x, struct fsm_state *y)
{
	struct fsm_state *s[6];
	size_t i;

	assert(x != NULL);
	assert(y != NULL);

	for (i = 0; i < 6; i++) {
		if (i == 0) {
			s[0] = x;
			continue;
		}

		if (i == 5) {
			s[5] = y;
			continue;
		}

		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			return 0;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xf0)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[1], s[2], 0x91)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[3], 0x84)) { return 0; }
	if (!fsm_addedge_literal(fsm, s[2], s[4], 0x85)) { return 0; }
	for (i = 0x80; i <= 0xb4; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[5], i)) { return 0; }
	}
	for (i = 0xb6; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[3], s[5], i)) { return 0; }
	}
	for (i = 0x80; i <= 0x83; i++) {
		if (!fsm_addedge_literal(fsm, s[4], s[5], i)) { return 0; }
	}


	return 1;
}


/* Generated by libfsm */

#include LF_HEADER

#include <assert.h>
#include <stddef.h>

#include <fsm/fsm.h>

int
class_notvspace_fsm(struct fsm *fsm, struct fsm_state *x, struct fsm_state *y)
{
	struct fsm_state *s[2];
	size_t i;

	assert(x != NULL);
	assert(y != NULL);

	for (i = 0; i < 2; i++) {
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

	for (i = 0x00; i <= 0x09; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}
	for (i = 0x0e; i <= 0xff; i++) {
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { return 0; }
	}


	return 1;
}


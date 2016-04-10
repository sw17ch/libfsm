/* Generated by lx */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include LX_HEADER

static enum lx_token z1(struct lx *lx);
static enum lx_token z2(struct lx *lx);
static enum lx_token z3(struct lx *lx);
static enum lx_token z4(struct lx *lx);

static int
lx_getc(struct lx *lx)
{
	int c;

	assert(lx != NULL);
	assert(lx->lgetc != NULL);

	if (lx->c != EOF) {
		c = lx->c, lx->c = EOF;
	} else {
		c = lx->lgetc(lx);
		if (c == EOF) {
			return EOF;
		}
	}

	lx->end.byte++;
	lx->end.col++;

	if (c == '\n') {
		lx->end.line++;
		lx->end.col = 1;
	}

	return c;
}

static void
lx_ungetc(struct lx *lx, int c)
{
	assert(lx != NULL);
	assert(lx->c == EOF);

	lx->c = c;

	if (lx->pop != NULL) {
		lx->pop(lx);
	}

	lx->end.byte--;
	lx->end.col--;

	if (c == '\n') {
		lx->end.line--;
		lx->end.col = 0; /* XXX: lost information */
	}
}

int
lx_fgetc(struct lx *lx)
{
	assert(lx != NULL);
	assert(lx->opaque != NULL);

	return fgetc(lx->opaque);
}

int
lx_dynpush(struct lx *lx, char c)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);
	assert(c != EOF);

	t = lx->buf;

	assert(t != NULL);

	if (t->p == t->a + t->len) {
		size_t len;
		char *tmp;

		if (t->len == 0) {
			assert(LX_DYN_LOW > 0);
			len = LX_DYN_LOW;
		} else {
			len = t->len * LX_DYN_FACTOR;
			if (len < t->len) {
				errno = ERANGE;
				return -1;
			}
		}

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->p   = tmp + (t->p - t->a);
		t->a   = tmp;
		t->len = len;
	}

	assert(t->p != NULL);
	assert(t->a != NULL);

	*t->p++ = c;

	return 0;
}

void
lx_dynpop(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);
	assert(t->a != NULL);
	assert(t->p >= t->a);

	if (t->p == t->a) {
		return;
	}

	t->p--;
}

int
lx_dynclear(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	if (t->len > LX_DYN_HIGH) {
		size_t len;
		char *tmp;

		len = t->len / LX_DYN_FACTOR;

		tmp = realloc(t->a, len);
		if (tmp == NULL) {
			return -1;
		}

		t->a   = tmp;
		t->len = len;
	}

	t->p = t->a;

	return 0;
}

void
lx_dynfree(struct lx *lx)
{
	struct lx_dynbuf *t;

	assert(lx != NULL);

	t = lx->buf;

	assert(t != NULL);

	free(t->a);
}
static enum lx_token
z1(struct lx *lx)
{
	int c;

	enum {
		S1, S2, S3
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S3;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S1: /* e.g. "\'" */
			switch (c) {
			default:  lx_ungetc(lx, c); return lx->z = z4, TOK_LABEL;
			}

		case S2: /* e.g. "a" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_CHAR;
			}

		case S3: /* start */
			switch (c) {
			case '\'': state = S1;      continue;
			default:  state = S2;     continue;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_LABEL;
	case S2: return TOK_CHAR;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z2(struct lx *lx)
{
	int c;

	enum {
		S1, S2, S3, S4, S5, S6, S7, S8
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S8;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		if (lx->push != NULL) {
			if (-1 == lx->push(lx, c)) {
				return TOK_ERROR;
			}
		}

		switch (state) {
		case S1: /* e.g. "\\xa" */
			switch (c) {
			case '0':	          continue;
			case '1':	          continue;
			case '2':	          continue;
			case '3':	          continue;
			case '4':	          continue;
			case '5':	          continue;
			case '6':	          continue;
			case '7':	          continue;
			case '8':	          continue;
			case '9':	          continue;
			case 'A':	          continue;
			case 'B':	          continue;
			case 'C':	          continue;
			case 'D':	          continue;
			case 'E':	          continue;
			case 'F':	          continue;
			case 'a':	          continue;
			case 'b':	          continue;
			case 'c':	          continue;
			case 'd':	          continue;
			case 'e':	          continue;
			case 'f':	          continue;
			default:  lx_ungetc(lx, c); return TOK_HEX;
			}

		case S2: /* e.g. "\\x" */
			switch (c) {
			case '0': state = S1;      continue;
			case '1': state = S1;      continue;
			case '2': state = S1;      continue;
			case '3': state = S1;      continue;
			case '4': state = S1;      continue;
			case '5': state = S1;      continue;
			case '6': state = S1;      continue;
			case '7': state = S1;      continue;
			case '8': state = S1;      continue;
			case '9': state = S1;      continue;
			case 'A': state = S1;      continue;
			case 'B': state = S1;      continue;
			case 'C': state = S1;      continue;
			case 'D': state = S1;      continue;
			case 'E': state = S1;      continue;
			case 'F': state = S1;      continue;
			case 'a': state = S1;      continue;
			case 'b': state = S1;      continue;
			case 'c': state = S1;      continue;
			case 'd': state = S1;      continue;
			case 'e': state = S1;      continue;
			case 'f': state = S1;      continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S3: /* e.g. "\\0" */
			switch (c) {
			case '0':	          continue;
			case '1':	          continue;
			case '2':	          continue;
			case '3':	          continue;
			case '4':	          continue;
			case '5':	          continue;
			case '6':	          continue;
			case '7':	          continue;
			default:  lx_ungetc(lx, c); return TOK_OCT;
			}

		case S4: /* e.g. "\\f" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_ESC;
			}

		case S5: /* e.g. "\"" */
			switch (c) {
			default:  lx_ungetc(lx, c); return lx->z = z4, TOK_LABEL;
			}

		case S6: /* e.g. "\\" */
			switch (c) {
			case '\"': state = S4;      continue;
			case '0': state = S3;      continue;
			case '1': state = S3;      continue;
			case '2': state = S3;      continue;
			case '3': state = S3;      continue;
			case '4': state = S3;      continue;
			case '5': state = S3;      continue;
			case '6': state = S3;      continue;
			case '7': state = S3;      continue;
			case '\\': state = S4;      continue;
			case 'f': state = S4;      continue;
			case 'n': state = S4;      continue;
			case 'r': state = S4;      continue;
			case 't': state = S4;      continue;
			case 'v': state = S4;      continue;
			case 'x': state = S2;      continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S7: /* e.g. "a" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_CHAR;
			}

		case S8: /* start */
			switch (c) {
			case '\"': state = S5;      continue;
			case '\\': state = S6;      continue;
			default:  state = S7;     continue;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_HEX;
	case S3: return TOK_OCT;
	case S4: return TOK_ESC;
	case S5: return TOK_LABEL;
	case S7: return TOK_CHAR;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z3(struct lx *lx)
{
	int c;

	enum {
		S1, S2, S3
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S3;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		switch (state) {
		case S1:
		case S2:
		case S3:
			break;

		default:
			if (lx->push != NULL) {
				if (-1 == lx->push(lx, c)) {
					return TOK_ERROR;
				}
			}
			break;

		}

		switch (state) {
		case S1: /* e.g. "\n" */
			switch (c) {
			default:  lx_ungetc(lx, c); return lx->z = z4, lx->z(lx);
			}

		case S2: /* e.g. "a" */
			switch (c) {
			default:  lx_ungetc(lx, c); return lx->z(lx);
			}

		case S3: /* start */
			switch (c) {
			case '\n': state = S1;      continue;
			default:  state = S2;     continue;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_EOF;
	case S2: return TOK_EOF;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

static enum lx_token
z4(struct lx *lx)
{
	int c;

	enum {
		S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, 
		S11, S12, S13, S14, S15, S16, S17, S18, S19, S20, 
		S21
	} state;

	assert(lx != NULL);

	if (lx->clear != NULL) {
		lx->clear(lx);
	}

	state = S21;

	lx->start = lx->end;

	while (c = lx_getc(lx), c != EOF) {
		switch (state) {
		case S10:
		case S11:
		case S12:
		case S13:
			break;

		default:
			if (lx->push != NULL) {
				if (-1 == lx->push(lx, c)) {
					return TOK_ERROR;
				}
			}
			break;

		}

		switch (state) {
		case S1: /* e.g. "start:" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_START;
			}

		case S2: /* e.g. "start" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case ':': state = S1;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S20;      continue;
			case 't': state = S20;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S3: /* e.g. "star" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S20;      continue;
			case 't': state = S2;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S4: /* e.g. "sta" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S3;      continue;
			case 's': state = S20;      continue;
			case 't': state = S20;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S5: /* e.g. "st" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S4;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S20;      continue;
			case 't': state = S20;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S6: /* e.g. "end:" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_END;
			}

		case S7: /* e.g. "end" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case ':': state = S6;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S20;      continue;
			case 't': state = S20;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S8: /* e.g. "en" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S7;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S20;      continue;
			case 't': state = S20;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S9: /* e.g. "->" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_TO;
			}

		case S10: /* e.g. "\t" */
			switch (c) {
			case '\t':	          continue;
			case '\n':	          continue;
			case '\r':	          continue;
			case ' ':	          continue;
			default:  lx_ungetc(lx, c); return lx->z(lx);
			}

		case S11: /* e.g. "\"" */
			switch (c) {
			default:  lx_ungetc(lx, c); return lx->z = z2, lx->z(lx);
			}

		case S12: /* e.g. "#" */
			switch (c) {
			default:  lx_ungetc(lx, c); return lx->z = z3, lx->z(lx);
			}

		case S13: /* e.g. "\'" */
			switch (c) {
			default:  lx_ungetc(lx, c); return lx->z = z1, lx->z(lx);
			}

		case S14: /* e.g. "," */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_COMMA;
			}

		case S15: /* e.g. "-" */
			switch (c) {
			case '>': state = S9;      continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}

		case S16: /* e.g. ";" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_SEP;
			}

		case S17: /* e.g. "?" */
			switch (c) {
			default:  lx_ungetc(lx, c); return TOK_ANY;
			}

		case S18: /* e.g. "e" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S8;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S20;      continue;
			case 't': state = S20;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S19: /* e.g. "s" */
			switch (c) {
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S20;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S20;      continue;
			case 't': state = S5;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S20: /* e.g. "a" */
			switch (c) {
			case '0':	          continue;
			case '1':	          continue;
			case '2':	          continue;
			case '3':	          continue;
			case '4':	          continue;
			case '5':	          continue;
			case '6':	          continue;
			case '7':	          continue;
			case '8':	          continue;
			case '9':	          continue;
			case 'A':	          continue;
			case 'B':	          continue;
			case 'C':	          continue;
			case 'D':	          continue;
			case 'E':	          continue;
			case 'F':	          continue;
			case 'G':	          continue;
			case 'H':	          continue;
			case 'I':	          continue;
			case 'J':	          continue;
			case 'K':	          continue;
			case 'L':	          continue;
			case 'M':	          continue;
			case 'N':	          continue;
			case 'O':	          continue;
			case 'P':	          continue;
			case 'Q':	          continue;
			case 'R':	          continue;
			case 'S':	          continue;
			case 'T':	          continue;
			case 'U':	          continue;
			case 'V':	          continue;
			case 'W':	          continue;
			case 'X':	          continue;
			case 'Y':	          continue;
			case 'Z':	          continue;
			case '_':	          continue;
			case 'a':	          continue;
			case 'b':	          continue;
			case 'c':	          continue;
			case 'd':	          continue;
			case 'e':	          continue;
			case 'f':	          continue;
			case 'g':	          continue;
			case 'h':	          continue;
			case 'i':	          continue;
			case 'j':	          continue;
			case 'k':	          continue;
			case 'l':	          continue;
			case 'm':	          continue;
			case 'n':	          continue;
			case 'o':	          continue;
			case 'p':	          continue;
			case 'q':	          continue;
			case 'r':	          continue;
			case 's':	          continue;
			case 't':	          continue;
			case 'u':	          continue;
			case 'v':	          continue;
			case 'w':	          continue;
			case 'x':	          continue;
			case 'y':	          continue;
			case 'z':	          continue;
			default:  lx_ungetc(lx, c); return TOK_IDENT;
			}

		case S21: /* start */
			switch (c) {
			case '\t': state = S10;      continue;
			case '\n': state = S10;      continue;
			case '\r': state = S10;      continue;
			case ' ': state = S10;      continue;
			case '\"': state = S11;      continue;
			case '#': state = S12;      continue;
			case '\'': state = S13;      continue;
			case ',': state = S14;      continue;
			case '-': state = S15;      continue;
			case '0': state = S20;      continue;
			case '1': state = S20;      continue;
			case '2': state = S20;      continue;
			case '3': state = S20;      continue;
			case '4': state = S20;      continue;
			case '5': state = S20;      continue;
			case '6': state = S20;      continue;
			case '7': state = S20;      continue;
			case '8': state = S20;      continue;
			case '9': state = S20;      continue;
			case ';': state = S16;      continue;
			case '?': state = S17;      continue;
			case 'A': state = S20;      continue;
			case 'B': state = S20;      continue;
			case 'C': state = S20;      continue;
			case 'D': state = S20;      continue;
			case 'E': state = S20;      continue;
			case 'F': state = S20;      continue;
			case 'G': state = S20;      continue;
			case 'H': state = S20;      continue;
			case 'I': state = S20;      continue;
			case 'J': state = S20;      continue;
			case 'K': state = S20;      continue;
			case 'L': state = S20;      continue;
			case 'M': state = S20;      continue;
			case 'N': state = S20;      continue;
			case 'O': state = S20;      continue;
			case 'P': state = S20;      continue;
			case 'Q': state = S20;      continue;
			case 'R': state = S20;      continue;
			case 'S': state = S20;      continue;
			case 'T': state = S20;      continue;
			case 'U': state = S20;      continue;
			case 'V': state = S20;      continue;
			case 'W': state = S20;      continue;
			case 'X': state = S20;      continue;
			case 'Y': state = S20;      continue;
			case 'Z': state = S20;      continue;
			case '_': state = S20;      continue;
			case 'a': state = S20;      continue;
			case 'b': state = S20;      continue;
			case 'c': state = S20;      continue;
			case 'd': state = S20;      continue;
			case 'e': state = S18;      continue;
			case 'f': state = S20;      continue;
			case 'g': state = S20;      continue;
			case 'h': state = S20;      continue;
			case 'i': state = S20;      continue;
			case 'j': state = S20;      continue;
			case 'k': state = S20;      continue;
			case 'l': state = S20;      continue;
			case 'm': state = S20;      continue;
			case 'n': state = S20;      continue;
			case 'o': state = S20;      continue;
			case 'p': state = S20;      continue;
			case 'q': state = S20;      continue;
			case 'r': state = S20;      continue;
			case 's': state = S19;      continue;
			case 't': state = S20;      continue;
			case 'u': state = S20;      continue;
			case 'v': state = S20;      continue;
			case 'w': state = S20;      continue;
			case 'x': state = S20;      continue;
			case 'y': state = S20;      continue;
			case 'z': state = S20;      continue;
			default:  lx->lgetc = NULL; return TOK_UNKNOWN;
			}
		}
	}

	lx->lgetc = NULL;

	switch (state) {
	case S1: return TOK_START;
	case S2: return TOK_IDENT;
	case S3: return TOK_IDENT;
	case S4: return TOK_IDENT;
	case S5: return TOK_IDENT;
	case S6: return TOK_END;
	case S7: return TOK_IDENT;
	case S8: return TOK_IDENT;
	case S9: return TOK_TO;
	case S10: return TOK_EOF;
	case S11: return TOK_EOF;
	case S12: return TOK_EOF;
	case S13: return TOK_EOF;
	case S14: return TOK_COMMA;
	case S16: return TOK_SEP;
	case S17: return TOK_ANY;
	case S18: return TOK_IDENT;
	case S19: return TOK_IDENT;
	case S20: return TOK_IDENT;
	default: errno = EINVAL; return TOK_ERROR;
	}
}

const char *
lx_name(enum lx_token t)
{
	switch (t) {
	case TOK_COMMA: return "COMMA";
	case TOK_SEP: return "SEP";
	case TOK_ANY: return "ANY";
	case TOK_TO: return "TO";
	case TOK_IDENT: return "IDENT";
	case TOK_END: return "END";
	case TOK_START: return "START";
	case TOK_LABEL: return "LABEL";
	case TOK_CHAR: return "CHAR";
	case TOK_HEX: return "HEX";
	case TOK_OCT: return "OCT";
	case TOK_ESC: return "ESC";
	case TOK_EOF:     return "EOF";
	case TOK_ERROR:   return "ERROR";
	case TOK_UNKNOWN: return "UNKNOWN";
	default: return "?";
	}
}

const char *
lx_example(enum lx_token (*z)(struct lx *), enum lx_token t)
{
	assert(z != NULL);

	if (z == z1) {
		switch (t) {
		case TOK_LABEL: return "\'";
		case TOK_CHAR: return "a";
		default: goto error;
		}
	} else
	if (z == z2) {
		switch (t) {
		case TOK_LABEL: return "\"";
		case TOK_CHAR: return "a";
		case TOK_HEX: return "\\xa";
		case TOK_OCT: return "\\0";
		case TOK_ESC: return "\\f";
		default: goto error;
		}
	} else
	if (z == z3) {
		switch (t) {
		default: goto error;
		}
	} else
	if (z == z4) {
		switch (t) {
		case TOK_COMMA: return ",";
		case TOK_SEP: return ";";
		case TOK_ANY: return "?";
		case TOK_TO: return "->";
		case TOK_IDENT: return "e";
		case TOK_END: return "end:";
		case TOK_START: return "start:";
		default: goto error;
		}
	}

error:

	errno = EINVAL;
	return NULL;
}

void
lx_init(struct lx *lx)
{
	static const struct lx lx_default;

	assert(lx != NULL);

	*lx = lx_default;

	lx->c = EOF;
	lx->z = NULL;

	lx->end.byte = 0;
	lx->end.line = 1;
	lx->end.col  = 1;
}

enum lx_token
lx_next(struct lx *lx)
{
	enum lx_token t;

	assert(lx != NULL);

	if (lx->lgetc == NULL) {
		return TOK_EOF;
	}

	if (lx->z == NULL) {
		lx->z = z4;
	}

	t = lx->z(lx);

	if (lx->push != NULL) {
		if (-1 == lx->push(lx, '\0')) {
			return TOK_ERROR;
		}
	}

	if (lx->lgetc == NULL && lx->free != NULL) {
		lx->free(lx);
	}

	return t;
}


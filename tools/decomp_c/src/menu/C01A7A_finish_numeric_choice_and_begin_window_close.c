#include "som_c.h"

/* C01A7A finish_numeric_choice_and_begin_window_close   [class A, 28 bytes, 14 instructions]
 * Source: src/rom/finish_numeric_choice_and_begin_window_close.s
 * Documented in docs/event-dialogue-numeric-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void finish_numeric_choice_and_begin_window_close(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x1D04) |= 0x80;
    RAM8(0xA187) &= 0xFD;
    RAM8(0xA160) = 0;
    RAM8(0xA170) = 0;
    RAM8(0xA170) = 0x51;
    SET_A8(r, 0x51);
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01A7A, SOM_RTS, "gen", finish_numeric_choice_and_begin_window_close, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 28, 14)

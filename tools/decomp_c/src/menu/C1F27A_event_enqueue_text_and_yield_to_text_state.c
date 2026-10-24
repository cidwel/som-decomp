#include "som_c.h"

/* C1F27A event_enqueue_text_and_yield_to_text_state   [class A, 34 bytes, 17 instructions]
 * Source: src/rom/event_enqueue_text_and_yield_to_text_state.s
 * Documented in docs/event-vm-control.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_enqueue_text_and_yield_to_text_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x1D01) = RAM8(0x00D1);
    RAM8(0x1D02) = RAM8(0x00D2);
    RAM8(0x1D03) = RAM8(0x00D3);
    uint8_t value4 = RAM8(0x00B8);
    RAM8(0x1D05) = (uint8_t)(((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) << 1) | ((uint8_t)(value4 << 1) >> 7)) & 3;
    RAM8(0x0048) = 1;
    RAM8(0x00D0) = 0x81;
    SET_A8(r, 0x81);
    r->c = (uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) & 0x80;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F27A, SOM_RTS, "gen", event_enqueue_text_and_yield_to_text_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 34, 17)

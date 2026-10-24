#include "som_c.h"

/* 7ECC43 mark_timer_ready   [class A, 20 bytes, 14 instructions]
 * Source: src/boot/mark_timer_ready.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABYV.
 */
static void mark_timer_ready(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM8(0x10000 + x) = 1;
    r->a = (a >> 8 << 8) | 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECC43, SOM_RTS, "gen", mark_timer_ready, 0, L_A | L_B | L_Y | L_V, 5, 0, 0, 20, 14)

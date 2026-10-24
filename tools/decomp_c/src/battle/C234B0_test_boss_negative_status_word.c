#include "som_c.h"

/* C234B0 test_boss_negative_status_word   [class A, 9 bytes, 6 instructions]
 * Source: src/rom/test_boss_negative_status_word.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void test_boss_negative_status_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (RAM16(0x0190 + x) & 0x8000) {
        r->c = 1;
        RETURN_RTS(c);
    }
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC234B0, SOM_RTS, "gen", test_boss_negative_status_word, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 9, 6)

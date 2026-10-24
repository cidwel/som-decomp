#include "som_c.h"

/* C2302C advance_boss_xor_random_pool   [class A, 28 bytes, 11 instructions]
 * Source: src/rom/advance_boss_xor_random_pool.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0200.  Callers read: ABXYCV.
 */
static void advance_boss_xor_random_pool(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->x = 0;
    JSR(c, 0x3030, 0xC23048); /* advance_boss_random_pool_index */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x3033, 0xC23048); /* advance_boss_random_pool_index */
    RAM8(0x0246) = RAM8(0x0306 + RAM8(0x033E));
    uint8_t value3 = RAM8(0x033D);
    uint8_t value4 = RAM8(0x0306 + value3);
    uint8_t value5 = RAM8(0x0246);
    RAM8(0x0306 + value3) = value4 ^ value5;
    SET_A8(r, value4 ^ value5);
    r->x = value3;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2302C, SOM_RTS, "gen", advance_boss_xor_random_pool, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 28, 11)

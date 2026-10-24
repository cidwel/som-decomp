#include "som_c.h"

/* C23048 advance_boss_random_pool_index   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/advance_boss_random_pool_index.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0200.  Callers read: BXYCV.
 */
static void advance_boss_random_pool_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t x = r->x;
    RAM8(0x033D + x)++;
    uint8_t value = RAM8(0x033D + x);
    if (value == 0x37) {
        RAM8(0x033D + x) = 0;
    }
    r->x = (uint8_t)(x + 1);
    r->c = value >= 0x37;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23048, SOM_RTS, "gen", advance_boss_random_pool_index, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 15, 7)

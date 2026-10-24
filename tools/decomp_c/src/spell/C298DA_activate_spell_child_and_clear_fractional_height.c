#include "som_c.h"

/* C298DA activate_spell_child_and_clear_fractional_height   [class A, 28 bytes, 11 instructions]
 * Source: src/rom/activate_spell_child_and_clear_fractional_height.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void activate_spell_child_and_clear_fractional_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0000 + x, 1);
    RAM16_SET(0x0029 + x, 0);
    RAM16_SET(0x0030 + x, 0);
    RAM16_SET(0x0064 + x, 0);
    RAM16_SET(0x0066 + x, 0);
    RAM8(0x000B + x) = 1;
    r->a = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC298DA, SOM_RTS, "gen", activate_spell_child_and_clear_fractional_height, 0, L_B | L_Y | L_V, 1, 0, 0, 28, 11)

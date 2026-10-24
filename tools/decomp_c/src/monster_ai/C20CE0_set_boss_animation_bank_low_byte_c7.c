#include "som_c.h"

/* C20CE0 set_boss_animation_bank_low_byte_c7   [class A, 10 bytes, 5 instructions]
 * Source: src/rom/set_boss_animation_bank_low_byte_c7.s
 * Documented in docs/boss-descriptor-zero.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void set_boss_animation_bank_low_byte_c7(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0x00A2 + x) = 0xC7;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20CE0, SOM_RTS, "gen", set_boss_animation_bank_low_byte_c7, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 10, 5)

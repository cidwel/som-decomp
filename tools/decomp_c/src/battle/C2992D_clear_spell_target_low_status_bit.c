#include "som_c.h"

/* C2992D clear_spell_target_low_status_bit   [class A, 16 bytes, 7 instructions]
 * Source: src/rom/clear_spell_target_low_status_bit.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BX.
 */
static void clear_spell_target_low_status_bit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B2 + x);
    RAM8(0x0190 + value) &= 0xFE;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2992D, SOM_RTS, "gen", clear_spell_target_low_status_bit, 0, L_B | L_X, 1, 0, 0, 16, 7)

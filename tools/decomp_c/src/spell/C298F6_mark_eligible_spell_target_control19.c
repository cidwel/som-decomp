#include "som_c.h"

/* C298F6 mark_eligible_spell_target_control19   [class B, 26 bytes, 11 instructions]
 * Source: src/rom/mark_eligible_spell_target_control19.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXV.
 */
static void mark_eligible_spell_target_control19(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B2 + x);
    uint16_t value2 = RAM16(0x0190 + value);
    if ((value2 & 0xC568) == 0) {
        if (RAM8(0x0060 + value) == 0) {
            RAM8(0x01E5 + value) = 0x19;
        }
    }
    r->a = ((value2 & 0xC568) >> 8 << 8) | (uint8_t)a;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC298F6, SOM_RTS, "gen", mark_eligible_spell_target_control19, 0, L_B | L_X | L_V, 1, 0, 0, 26, 11)

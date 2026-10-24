#include "som_c.h"

/* C29910 set_eligible_spell_target_status_and_timer   [class A, 29 bytes, 12 instructions]
 * Source: src/rom/set_eligible_spell_target_status_and_timer.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void set_eligible_spell_target_status_and_timer(SomCtx *c)
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
        RAM8(0x0190 + value) |= 1;
        RAM8(0x01B4 + value) = 0x20;
    }
    r->a = ((value2 & 0xC568) >> 8 << 8) | (uint8_t)a;
    r->y = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29910, SOM_RTS, "gen", set_eligible_spell_target_status_and_timer, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 29, 12)

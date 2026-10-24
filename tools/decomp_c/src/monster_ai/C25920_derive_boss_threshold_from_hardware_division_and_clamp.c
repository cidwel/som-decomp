#include "som_c.h"

/* C25920 derive_boss_threshold_from_hardware_division_and_clamp   [class B, 49 bytes, 23 instructions]
 * Source: src/rom/derive_boss_threshold_from_hardware_division_and_clamp.s
 * Documented in docs/boss-native-target-animation.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void derive_boss_threshold_from_hardware_division_and_clamp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    BUS16_SET(c, 0x004204, RAM16(0x0184 + x));
    uint8_t value2 = RAM8(0x0042 + x);
    uint8_t a1;
    if (value2 != 0) {
        a1 = 6;
    } else {
        a1 = 2;
    }
    BUS8_SET(c, 0x004206, a1);
    uint16_t value3 = RAM16(0x0182 + x);
    uint16_t value4 = BUS16(c, 0x004214);
    uint8_t a2;
    uint8_t a_hi1;
    if (!((uint16_t)(value3 - value4) & 0x8000)) {
        a2 = (uint8_t)(value3 - value4);
        a_hi1 = (uint16_t)(value3 - value4) >> 8;
    } else {
        a2 = 0;
        a_hi1 = 0;
    }
    RAM16_SET(0x00BE + x, (a_hi1 << 8) | a2);
    r->a = (a_hi1 << 8) | a2;
    r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25920, SOM_RTS, "gen", derive_boss_threshold_from_hardware_division_and_clamp, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 49, 23)

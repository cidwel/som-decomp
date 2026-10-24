#include "som_c.h"

/* C2AB03 apply_map_header_transition_flags   [class B, 45 bytes, 21 instructions]
 * Source: src/rom/apply_map_header_transition_flags.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BX.
 */
static void apply_map_header_transition_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    RAM8(0x0080) = a & 0x1F;
    uint8_t value = RAM8(0x00E8);
    uint8_t a_hi4;
    if (value == 0x83) {
        a_hi4 = a;
    } else {
        uint8_t value2 = RAM8(0x011F);
        RAM16_SET(0x011E, (a << 8) | value2);
        uint8_t a_hi3;
        if ((((a << 8) | value2) & 0x2020) == 0) {
            a_hi3 = (((a << 8) | value2) & 0x2020) >> 8;
        } else {
            uint8_t a_hi2;
            if ((((a << 8) | value2) & 0x2020) == 0x2020) {
                a_hi2 = (((a << 8) | value2) & 0x2020) >> 8;
            } else {
                uint8_t a1;
                uint8_t a_hi1;
                if (((((a << 8) | value2) & 0x2020) ^ 0x20) == 0) {
                    a1 = (uint8_t)((((a << 8) | value2) & 0x2020) ^ 0x20);
                    a_hi1 = ((((a << 8) | value2) & 0x2020) ^ 0x20) >> 8;
                } else {
                    uint16_t value3 = RAM16(0x010E);
                    a1 = (uint8_t)value3;
                    a_hi1 = value3 >> 8;
                }
                RAM16_SET(0x0108, (a_hi1 << 8) | a1);
                a_hi2 = a_hi1;
            }
            a_hi3 = a_hi2;
        }
        a_hi4 = a_hi3;
    }
    r->a = (r->a & 0x00FF) | (a_hi4 << 8);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AB03, SOM_RTL, "gen", apply_map_header_transition_flags, 0, L_B | L_X, 1, 1, 1, 45, 21)

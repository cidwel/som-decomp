#include "som_c.h"

/* C75D17 format_five_native_saved_slot_decimal_digits_via_hardware_division   [class B, 81 bytes, 46 instructions]
 * Source: src/rom/format_five_native_saved_slot_decimal_digits_via_hardware_division.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void format_five_native_saved_slot_decimal_digits_via_hardware_division(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a1 = 0x0D;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    for (;;) {
        RAM8(0xA22F + x1) = 0;
        a1 = (uint8_t)(a1 - 1);
        x1 = (uint16_t)(x1 + 1);
        if (!(a1 != 0)) break;
    }
    uint8_t a4;
    uint8_t a_hi4;
    uint16_t y3;
    bool carry3;
    bool overflow3;
    if (y == 0) {
        RAM8(0xA239) = 0xB5;
        a4 = 0xB5;
        a_hi4 = a_hi1;
        y3 = y;
        carry3 = y >= 0;
        overflow3 = overflow;
    } else {
        uint8_t a2 = 5;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = 0x0B;
        uint16_t y1 = y;
        bool carry1 = y >= 0;
        bool overflow1 = overflow;
        for (;;) {
            BUS16_SET(c, 0x004204, y1);
            BUS8_SET(c, 0x004206, 0x0A);
            uint8_t a3;
            uint8_t a_hi3;
            uint16_t y2;
            bool carry2;
            bool overflow2;
            if (y1 == 0) {
                a3 = 0xB5;
                a_hi3 = a2;
                y2 = y1;
                carry2 = y1 >= 0;
                overflow2 = overflow1;
            } else {
                uint8_t value = BUS8(c, 0x004216);
                RAM8(0xA22F + (uint16_t)(x2 - 1)) = (uint8_t)(value + 0xB5);
                uint16_t value2 = BUS16(c, 0x004214);
                if ((uint8_t)(a2 - 1) != 0) {
                    a2 = (uint8_t)(a2 - 1);
                    a_hi2 = (uint8_t)(value + 0xB5);
                    x2 = (uint16_t)(x2 - 1);
                    y1 = value2;
                    carry1 = value + 0xB5 > 0xFF;
                    overflow1 = (((uint8_t)(value + 0xB5) ^ 0xB5) & (value ^ (uint8_t)(value + 0xB5)) & 0x80) != 0;
                    continue;
                }
                a3 = (uint8_t)(a2 - 1);
                a_hi3 = (uint8_t)(value + 0xB5);
                y2 = value2;
                carry2 = value + 0xB5 > 0xFF;
                overflow2 = (((uint8_t)(value + 0xB5) ^ 0xB5) & (value ^ (uint8_t)(value + 0xB5)) & 0x80) != 0;
            }
            a2 = a3;
            a_hi2 = a_hi3;
            x2 = (uint16_t)(x2 - 1);
            y1 = y2;
            carry1 = carry2;
            overflow1 = overflow2;
            break;
        }
        a4 = a2;
        a_hi4 = a_hi2;
        y3 = y1;
        carry3 = carry1;
        overflow3 = overflow1;
    }
    r->a = (a_hi4 << 8) | a4;
    r->x = x;
    r->y = y3;
    r->c = carry3;
    r->z = x == 0;
    r->v = overflow3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75D17, SOM_RTS, "gen", format_five_native_saved_slot_decimal_digits_via_hardware_division, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 4, 1, 0, 81, 46)

#include "som_c.h"

/* C09D0A advance_ui_sprite_coordinates_and_hardware_timed_phase   [class B, 93 bytes, 42 instructions]
 * Source: src/rom/advance_ui_sprite_coordinates_and_hardware_timed_phase.s
 * Documented in docs/ui-native-ui-frame-sprites.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_ui_sprite_coordinates_and_hardware_timed_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x004204, RAM8(0x00F4));
    BUS8_SET(c, 0x004205, 0);
    uint8_t value2 = RAM8(0x0043);
    uint8_t x1;
    if ((value2 & 0x0C) != 0) {
        x1 = 4;
    } else {
        x1 = 6;
    }
    BUS8_SET(c, 0x004206, x1);
    uint8_t a_hi1 = a_hi;
    uint8_t x2 = 5;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value3 = RAM8(0x0A46 + x2);
        uint8_t value4 = RAM8(0x0A4C + x2);
        bool carry3;
        bool overflow3;
        if (value3 == value4) {
            carry3 = value3 >= value4;
            overflow3 = overflow1;
        } else {
            uint8_t a3;
            bool carry2;
            bool overflow2;
            if (value3 < value4) {
                uint8_t a1;
                if ((uint8_t)(value3 + 2 + (value3 >= value4)) < value4) {
                    a1 = (uint8_t)(value3 + 2 + (value3 >= value4));
                } else {
                    a1 = value4;
                }
                a3 = a1;
                carry2 = (uint8_t)(value3 + 2 + (value3 >= value4)) >= value4;
                overflow2 = ((value3 ^ (uint8_t)(value3 + 2 + (value3 >= value4))) & ((uint8_t)(value3 + 2 + (value3 >= value4)) ^ 2) & 0x80) != 0;
            } else {
                uint8_t a2;
                if ((uint8_t)(value3 - 2 - (value3 >= value4 ^ 1)) >= value4) {
                    a2 = (uint8_t)(value3 - 2 - (value3 >= value4 ^ 1));
                } else {
                    a2 = value4;
                }
                a3 = a2;
                carry2 = (uint8_t)(value3 - 2 - (value3 >= value4 ^ 1)) >= value4;
                overflow2 = ((value3 ^ 2) & (value3 ^ (uint8_t)(value3 - 2 - (value3 >= value4 ^ 1))) & 0x80) != 0;
            }
            RAM8(0x0A46 + x2) = a3;
            carry3 = carry2;
            overflow3 = overflow2;
        }
        x2 = (uint8_t)(x2 - 1);
        carry1 = carry3;
        overflow1 = overflow3;
        if (!(!(x2 & 0x80))) break;
    }
    uint8_t value5 = BUS8(c, 0x004216);
    if (value5 == 0) {
        RAM8(0x0A40) = (uint8_t)(RAM8(0x0A40) + 1) & 0x0F;
        uint8_t a_hi2 = a_hi1;
        uint8_t x3 = 5;
        for (;;) {
            RAM8(0x0A40 + x3) = (uint8_t)(RAM8(0x0A40 + x3) - 1) & 0x0F;
            x3 = (uint8_t)(x3 - 1);
            if (!(x3 != 0)) break;
        }
        r->a = (a_hi2 << 8) | a;
        r->x = x3;
        r->y = y;
        r->c = carry1;
        r->v = overflow1;
        RETURN_RTS(c);
    }
    r->a = (a_hi1 << 8) | value5;
    r->x = x2;
    r->y = y;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09D0A, SOM_RTS, "gen", advance_ui_sprite_coordinates_and_hardware_timed_phase, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 93, 42)

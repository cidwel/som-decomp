#include "som_c.h"

/* C64556 divide_signed_scene_ratio_with_native_saturation   [class B, 70 bytes, 35 instructions]
 * Source: src/rom/divide_signed_scene_ratio_with_native_saturation.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=16 bit X=16 bit DB=$C6 D=$0000.  Callers read: ABYC.
 */
static void divide_signed_scene_ratio_with_native_saturation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xC6, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    RAM16_SET(0x0032, a);
    uint16_t value = RAM16(0x0030);
    uint8_t a1;
    uint8_t a_hi1;
    if (!(value & 0x8000)) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
    } else {
        a1 = (uint8_t)((value ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)((value ^ 0xFFFF) + 1) >> 8;
    }
    RAM16_SET(0x0036, (a_hi1 << 8) | a1);
    RAM16_SET(0x0034, 0);
    RAM16_SET(0x0038, 0);
    uint8_t a_hi2 = a_hi1;
    uint16_t x1 = 0x18;
    bool carry1 = carry;
    for (;;) {
        uint16_t value2 = RAM16(0x0034);
        RAM16_SET(0x0034, (uint16_t)((RAM16(0x0034) << 1) | carry1));
        uint16_t value3 = RAM16(0x0036);
        RAM16_SET(0x0036, (uint16_t)((RAM16(0x0036) << 1) | (value2 >> 0x0F)));
        uint16_t value4 = RAM16(0x0038);
        RAM16_SET(0x0038, (uint16_t)((RAM16(0x0038) << 1) | (value3 >> 0x0F)));
        uint16_t value5 = RAM16(0x0038);
        uint8_t a_hi4;
        bool carry3;
        if (!(value4 & 0x8000)) {
            uint16_t value6 = RAM16(0x0032);
            uint8_t a_hi3;
            bool carry2;
            if (value5 < value6) {
                a_hi3 = value5 >> 8;
                carry2 = value5 >= value6;
            } else {
                RAM16_SET(0x0038, (uint16_t)(value5 - value6 - (value5 >= value6 ^ 1)));
                a_hi3 = (uint16_t)(value5 - value6 - (value5 >= value6 ^ 1)) >> 8;
                carry2 = value5 - value6 >= (value5 >= value6 ^ 1);
            }
            a_hi4 = a_hi3;
            carry3 = carry2;
        } else {
            uint16_t value7 = RAM16(0x0032);
            RAM16_SET(0x0038, (uint16_t)(value5 - value7 - ((value4 >> 0x0F) ^ 1)));
            a_hi4 = (uint16_t)(value5 - value7 - ((value4 >> 0x0F) ^ 1)) >> 8;
            carry3 = 1;
        }
        a_hi2 = a_hi4;
        x1 = (uint16_t)(x1 - 1);
        carry1 = carry3;
        if (!(x1 != 0)) break;
    }
    uint16_t value8 = RAM16(0x0030);
    uint8_t a3;
    uint8_t a_hi6;
    bool carry4;
    if (!(value8 & 0x8000)) {
        uint16_t value9 = RAM16(0x0034);
        uint8_t a2;
        uint8_t a_hi5;
        if (value9 < 0x8000) {
            a2 = (uint8_t)value9;
            a_hi5 = value9 >> 8;
        } else {
            a2 = 0xFF;
            a_hi5 = 0x7F;
        }
        a3 = a2;
        a_hi6 = a_hi5;
        carry4 = value9 >= 0x8000;
    } else {
        uint16_t value10 = RAM16(0x0034);
        a3 = (uint8_t)((value10 ^ 0xFFFF) + 1);
        a_hi6 = (uint16_t)((value10 ^ 0xFFFF) + 1) >> 8;
        carry4 = carry1;
    }
    r->a = (a_hi6 << 8) | a3;
    r->y = y;
    r->c = carry4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC64556, SOM_RTS, "gen", divide_signed_scene_ratio_with_native_saturation, 0, L_A | L_B | L_Y | L_C, 1, 0, 0, 70, 35)

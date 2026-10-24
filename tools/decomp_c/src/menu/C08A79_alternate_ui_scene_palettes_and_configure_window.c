#include "som_c.h"

/* C08A79 alternate_ui_scene_palettes_and_configure_window   [class D, 127 bytes, 57 instructions]
 * Source: src/rom/alternate_ui_scene_palettes_and_configure_window.s
 * Documented in docs/ui-native-scene-interrupts.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: V.
 */
static void alternate_ui_scene_palettes_and_configure_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x00E3);
    uint8_t a_hi4;
    if (!(value & 0x40)) {
        a_hi4 = a >> 8;
    } else {
        uint8_t value2 = RAM8(0x00F5);
        uint8_t a_hi3;
        if ((value2 & 1) != 0) {
            a_hi3 = a >> 8;
        } else {
            uint8_t value3 = RAM8(0x00F4);
            uint8_t a_hi2;
            if (value3 & 0x80) {
                a_hi2 = a >> 8;
            } else {
                uint8_t a_hi1;
                if ((value3 & 0x22) != 0) {
                    BUS8_SET(c, 0x004374, 0);
                    BUS16_SET(c, 0x004372, 0x0600);
                    a_hi1 = 6;
                } else {
                    BUS8_SET(c, 0x004374, 0x7E);
                    BUS16_SET(c, 0x004372, 0xDE00);
                    a_hi1 = 0xDE;
                }
                BUS8_SET(c, 0x002121, 0);
                BUS16_SET(c, 0x004370, 0x2200);
                BUS16_SET(c, 0x004375, 0x0200);
                BUS8_SET(c, 0x00420B, 0x80);
                a_hi2 = 2;
            }
            a_hi3 = a_hi2;
        }
        a_hi4 = a_hi3;
    }
    uint8_t value4 = RAM8(0x002D);
    if (value4 == 0) {
        RAM8(0x002C) &= 0x7F;
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value4 & 0x01) {
        BUS8_SET(c, 0x002123, 2);
        BUS8_SET(c, 0x00212E, 1);
        RAM8(0x002D)++;
        RAM8(0x002C) |= 0x80;
        uint8_t a_hi5 = a_hi4;
        uint8_t x1 = 0;
        for (;;) {
            uint8_t value7 = BUS8(c, 0x008AF8 + x1);
            BUS8_SET(c, 0x004370 + x1, value7);
            x1 = (uint8_t)(x1 + 1);
            if (!(x1 < 8)) break;
        }
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x002D) = 0;
    BUS8_SET(c, 0x002123, 0);
    RAM8(0x002C) &= 0x7F;
    r->v = value & 0x40;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08A79, SOM_RTS, "gen", alternate_ui_scene_palettes_and_configure_window, 0, L_V, 1, 0, 1, 127, 57)

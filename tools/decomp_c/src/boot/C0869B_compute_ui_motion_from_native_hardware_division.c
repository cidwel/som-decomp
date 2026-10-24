#include "som_c.h"

/* C0869B compute_ui_motion_from_native_hardware_division   [class B, 222 bytes, 119 instructions]
 * Source: src/rom/compute_ui_motion_from_native_hardware_division.s
 * Documented in docs/ui-native-ui-frame-motion-division.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: XY.
 */
static void compute_ui_motion_from_native_hardware_division(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x0043);
    if ((value & 0x0C) != 0) {
        uint8_t value2 = RAM8(0x005F);
        uint8_t a_hi2;
        if ((value & 0x0C) == value2) {
            uint8_t value3 = RAM8(0x005D);
            uint8_t x1;
            if ((value & 4) != 0) {
                x1 = value3;
            } else {
                x1 = RAM8(0x005C);
            }
            RAM8(0x0000) = x1;
            uint8_t value5 = RAM8(0x005E);
            uint8_t value6 = RAM8(0x0000);
            if (value5 != value6) {
                uint8_t a1;
                if ((uint8_t)(value5 - 3) >= value6) {
                    a1 = (uint8_t)(value5 - 3);
                } else {
                    a1 = value6;
                }
                RAM8(0x005E) = a1;
            }
            a_hi2 = a_hi;
        } else {
            uint8_t value7 = RAM8(0x005E);
            uint8_t a_hi1;
            if (value7 == 0xFF) {
                RAM8(0x005F) = value & 0x0C;
                r->a = a_hi << 8 | (value & 0x0C);
                r->xf = 1;
                r->sp -= 1;
                JSR(c, 0x86DF, 0xC09D78); /* select_scene_color_targets_from_cursor_and_fade_flags */
                r->sp += 1;
                uint16_t a_all = r->a;
                uint8_t value8 = RAM8(0x005D);
                uint8_t x2;
                if ((value & 4) != 0) {
                    x2 = value8;
                } else {
                    x2 = RAM8(0x005C);
                }
                RAM8(0x0000) = x2;
                uint8_t value10 = RAM8(0x005E);
                uint8_t value11 = RAM8(0x0000);
                if (value10 != value11) {
                    uint8_t a2;
                    if ((uint8_t)(value10 - 3) >= value11) {
                        a2 = (uint8_t)(value10 - 3);
                    } else {
                        a2 = value11;
                    }
                    RAM8(0x005E) = a2;
                }
                a_hi1 = a_all >> 8;
            } else {
                uint8_t a3;
                if (value7 + 8 <= 0xFF) {
                    a3 = (uint8_t)(value7 + 8);
                } else {
                    a3 = 0xFF;
                }
                RAM8(0x005E) = a3;
                a_hi1 = a_hi;
            }
            a_hi2 = a_hi1;
        }
        BUS16_SET(c, 0x004204, (uint16_t)(RAM16(0x0064) + RAM16(0x0032)));
        uint8_t value14 = RAM8(0x005E);
        BUS8_SET(c, 0x004206, value14);
        uint16_t value15 = RAM16(0x0062);
        uint16_t value16 = RAM16(0x0030);
        uint8_t value17 = BUS8(c, 0x004214);
        uint16_t value18 = BUS16(c, 0x004216);
        RAM16_SET(0x0064, value18);
        BUS16_SET(c, 0x004204, (uint16_t)(value15 + value16));
        BUS8_SET(c, 0x004206, value14);
        uint16_t value19 = BUS16(c, 0x004214);
        uint16_t value20 = BUS16(c, 0x004216);
        RAM16_SET(0x0062, value20);
        uint16_t value21 = RAM16(0x00F6);
        if ((value21 & 0x0200) == 0) {
            if ((value21 & 0x0100) != 0) {
                RAM16_SET(0x0068, (uint16_t)((value17 ^ 0xFFFF) + 1));
                RAM16_SET(0x0066, value19);
                r->x = value19;
                r->y = value17;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            RAM16_SET(0x0068, value17);
            RAM16_SET(0x0066, value19);
            r->x = value19;
            r->y = value17;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((value21 & 0x0100) == 0) {
            RAM16_SET(0x0068, (uint16_t)((value17 ^ 0xFFFF) + 1));
            RAM16_SET(0x0066, (uint16_t)((value19 ^ 0xFFFF) + 1));
            r->x = value19;
            r->y = value17;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((value21 & 0x0100) != 0) {
            RAM16_SET(0x0068, value17);
            RAM16_SET(0x0066, (uint16_t)((value19 ^ 0xFFFF) + 1));
            r->x = value19;
            r->y = value17;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((value21 & 0x0100) != 0) {
            RAM16_SET(0x0068, (uint16_t)((value17 ^ 0xFFFF) + 1));
            RAM16_SET(0x0066, value19);
            r->x = value19;
            r->y = value17;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM16_SET(0x0068, value17);
        RAM16_SET(0x0066, value19);
        r->x = value19;
        r->y = value17;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value22 = RAM8(0x005E);
    if (value22 != 0xFF) {
        if (value22 + 4 <= 0xFF) {
            RAM8(0x005E) = (uint8_t)(value22 + 4);
            BUS16_SET(c, 0x004204, (uint16_t)(RAM16(0x0064) + RAM16(0x0032)));
            uint8_t value25 = RAM8(0x005E);
            BUS8_SET(c, 0x004206, value25);
            uint16_t value26 = RAM16(0x0062);
            uint16_t value27 = RAM16(0x0030);
            uint8_t value28 = BUS8(c, 0x004214);
            uint16_t value29 = BUS16(c, 0x004216);
            RAM16_SET(0x0064, value29);
            BUS16_SET(c, 0x004204, (uint16_t)(value26 + value27));
            BUS8_SET(c, 0x004206, value25);
            uint16_t value30 = BUS16(c, 0x004214);
            uint16_t value31 = BUS16(c, 0x004216);
            RAM16_SET(0x0062, value31);
            uint16_t value32 = RAM16(0x00F6);
            if ((value32 & 0x0200) == 0) {
                if ((value32 & 0x0100) != 0) {
                    RAM16_SET(0x0068, (uint16_t)((value28 ^ 0xFFFF) + 1));
                    RAM16_SET(0x0066, value30);
                    r->x = value30;
                    r->y = value28;
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                RAM16_SET(0x0068, value28);
                RAM16_SET(0x0066, value30);
                r->x = value30;
                r->y = value28;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((value32 & 0x0100) == 0) {
                RAM16_SET(0x0068, (uint16_t)((value28 ^ 0xFFFF) + 1));
                RAM16_SET(0x0066, (uint16_t)((value30 ^ 0xFFFF) + 1));
                r->x = value30;
                r->y = value28;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((value32 & 0x0100) != 0) {
                RAM16_SET(0x0068, value28);
                RAM16_SET(0x0066, (uint16_t)((value30 ^ 0xFFFF) + 1));
                r->x = value30;
                r->y = value28;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if ((value32 & 0x0100) != 0) {
                RAM16_SET(0x0068, (uint16_t)((value28 ^ 0xFFFF) + 1));
                RAM16_SET(0x0066, value30);
                r->x = value30;
                r->y = value28;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
            RAM16_SET(0x0068, value28);
            RAM16_SET(0x0066, value30);
            r->x = value30;
            r->y = value28;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0x005E) = 0xFF;
        RAM8(0x0066) = 0;
        RAM8(0x0067) = 0;
        RAM8(0x0068) = 0;
        RAM8(0x0069) = 0;
        r->x = (uint8_t)x;
        r->y = (uint8_t)y;
        r->xf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x0066) = 0;
    RAM8(0x0067) = 0;
    RAM8(0x0068) = 0;
    RAM8(0x0069) = 0;
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0869B, SOM_RTS, "gen", compute_ui_motion_from_native_hardware_division, 0, L_X | L_Y, 2, 1, -1, 222, 119)

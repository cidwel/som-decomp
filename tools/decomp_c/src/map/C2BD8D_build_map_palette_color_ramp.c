#include "som_c.h"

/* C2BD8D build_map_palette_color_ramp   [class B, 292 bytes, 163 instructions]
 * Source: src/rom/build_map_palette_color_ramp.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void build_map_palette_color_ramp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    RAM8(0x0005) = ((uint16_t)(RAM16(0x0000) << 3) >> 8) & 0x1F;
    RAM8(0x0004) = RAM8(0x0000) & 0x1F;
    RAM8(0x0006) = (RAM8(0x0001) >> 2) & 0x1F;
    uint16_t value4 = RAM16(0x0002);
    RAM8(0x0008) = ((uint16_t)(value4 << 3) >> 8) & 0x1F;
    RAM8(0x0007) = RAM8(0x0002) & 0x1F;
    RAM8(0x0009) = (RAM8(0x0003) >> 2) & 0x1F;
    RAM8(0x0000) = 0;
    uint8_t a_hi1 = (uint8_t)(value4 << 3);
    uint8_t y1 = (uint8_t)y;
    for (;;) {
        uint8_t value7 = RAM8(0x0003);
        uint8_t a_hi8;
        uint8_t y2;
        if (!(value7 & 0x80)) {
            uint8_t value8 = RAM8(0x0004);
            uint8_t value9 = RAM8(0x0000);
            uint8_t a_hi3;
            uint8_t x2;
            if (value9 != 0) {
                uint8_t a_hi2;
                uint8_t x1;
                if ((uint8_t)(value9 + 1) == 0) {
                    a_hi2 = a_hi1;
                    x1 = value8;
                } else {
                    BUS8_SET(c, 0x004202, value8);
                    BUS8_SET(c, 0x004203, (uint8_t)(value9 + 1));
                    uint8_t value10 = RAM8(0x0007);
                    uint16_t value11 = BUS16(c, 0x004216);
                    BUS16_SET(c, 0x004202, ((uint8_t)((value8 << 8) | (uint8_t)(((uint8_t)(value9 + 1) ^ 0xFF) + 1)) << 8) | value10);
                    uint16_t value12 = BUS16(c, 0x004216);
                    a_hi2 = (uint8_t)(value11 + value12);
                    x1 = (uint8_t)(((uint8_t)(value11 + value12) << 8) | ((uint16_t)(value11 + value12) >> 8));
                }
                a_hi3 = a_hi2;
                x2 = x1;
            } else {
                uint8_t value13 = RAM8(0x0007);
                a_hi3 = a_hi1;
                x2 = value13;
            }
            RAM8(0x0002) = x2;
            uint8_t value14 = RAM8(0x0006);
            uint8_t a_hi5;
            uint8_t x4;
            if (value9 != 0) {
                uint8_t a_hi4;
                uint8_t x3;
                if ((uint8_t)(value9 + 1) == 0) {
                    a_hi4 = a_hi3;
                    x3 = value14;
                } else {
                    BUS8_SET(c, 0x004202, value14);
                    BUS8_SET(c, 0x004203, (uint8_t)(value9 + 1));
                    uint8_t value15 = RAM8(0x0009);
                    uint16_t value16 = BUS16(c, 0x004216);
                    BUS16_SET(c, 0x004202, ((uint8_t)((value14 << 8) | (uint8_t)(((uint8_t)(value9 + 1) ^ 0xFF) + 1)) << 8) | value15);
                    uint16_t value17 = BUS16(c, 0x004216);
                    a_hi4 = (uint8_t)(value16 + value17);
                    x3 = (uint8_t)(((uint8_t)(value16 + value17) << 8) | ((uint16_t)(value16 + value17) >> 8));
                }
                a_hi5 = a_hi4;
                x4 = x3;
            } else {
                uint8_t value18 = RAM8(0x0009);
                a_hi5 = a_hi3;
                x4 = value18;
            }
            RAM8(0x0003) = x4;
            uint8_t value19 = RAM8(0x0005);
            uint8_t a_hi7;
            uint8_t x6;
            if (value9 != 0) {
                uint8_t a_hi6;
                uint8_t x5;
                if ((uint8_t)(value9 + 1) == 0) {
                    a_hi6 = a_hi5;
                    x5 = value19;
                } else {
                    BUS8_SET(c, 0x004202, value19);
                    BUS8_SET(c, 0x004203, (uint8_t)(value9 + 1));
                    uint8_t value20 = RAM8(0x0008);
                    uint16_t value21 = BUS16(c, 0x004216);
                    BUS16_SET(c, 0x004202, ((uint8_t)((value19 << 8) | (uint8_t)(((uint8_t)(value9 + 1) ^ 0xFF) + 1)) << 8) | value20);
                    uint16_t value22 = BUS16(c, 0x004216);
                    a_hi6 = (uint8_t)(value21 + value22);
                    x5 = (uint8_t)(((uint8_t)(value21 + value22) << 8) | ((uint16_t)(value21 + value22) >> 8));
                }
                a_hi7 = a_hi6;
                x6 = x5;
            } else {
                uint8_t value23 = RAM8(0x0008);
                a_hi7 = a_hi5;
                x6 = value23;
            }
            RAM8(0x0003) = (uint8_t)((RAM8(0x0003) << 1) | ((uint8_t)(x6 << 3) >> 7));
            RAM8(0x0003) = (uint8_t)((RAM8(0x0003) << 1) | ((uint8_t)(x6 << 4) >> 7));
            RAM8(0x0002) = (uint8_t)(x6 << 5) | RAM8(0x0002);
            a_hi8 = a_hi7;
            y2 = 0;
        } else {
            a_hi8 = a_hi1;
            y2 = y1;
        }
        BUS16_SET(c, RAM16(0x0018) + 0x7E0000 + y2, RAM16(0x0002));
        uint16_t value28 = RAM16(0x0018);
        RAM16_SET(0x0018, (uint16_t)(value28 + 0x1E));
        uint8_t value29 = RAM8(0x0000);
        RAM8(0x0000) = (uint8_t)(value29 + 0x11);
        if (value29 + 0x11 <= 0xFF) {
            a_hi1 = (uint16_t)(value28 + 0x1E) >> 8;
            y1 = y2;
            continue;
        }
        a_hi1 = (uint16_t)(value28 + 0x1E) >> 8;
        y1 = y2;
        break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2BD8D, SOM_RTS, "gen", build_map_palette_color_ramp, 0, L_B, 2, 0, 0, 292, 163)

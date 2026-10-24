#include "som_c.h"

/* C0AAD2 build_world_map_picker_row_geometry_with_hardware_division   [class D, 161 bytes, 78 instructions]
 * Source: src/rom/build_world_map_picker_row_geometry_with_hardware_division.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: XYV.
 */
static void build_world_map_picker_row_geometry_with_hardware_division(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    RAM16_SET(0x0004, 0);
    RAM16_SET(0x0008, 0x5100);
    uint8_t a_hi1 = 0x51;
    uint8_t x1 = x;
    uint8_t y1 = y;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value = RAM8(0x0005);
            uint8_t value2 = BUS8(c, 0x00AB73 + (uint8_t)((a_hi1 << 8) | ((value ^ 0x7E) >> 1)));
            uint16_t value3 = BUS16(c, 0x00FD22 + (((((a_hi1 << 8) | value2) & 0xFF) << 1) ^ 0x01FE));
            RAM16_SET(0x0032, value3);
            uint8_t value4 = RAM8(0x0033);
            uint8_t a1;
            if (value4 == 0) {
                a1 = RAM8(0x0032) >> 2;
            } else {
                a1 = 0x40;
            }
            RAM8(0x0007) = a1;
            RAM8(0x0006) = 0;
            RAM16_SET(0x15000 + value, RAM16(0x0008));
            RAM16_SET(0x15080 + value, RAM16(0x0007) & 0xFF);
            uint16_t value8 = RAM16(0x0008);
            BUS16_SET(c, 0x002181, value8);
            BUS8_SET(c, 0x002183, 1);
            uint8_t a_hi2 = value8 >> 8;
            uint8_t y2 = 0;
            bool first_pass2 = true;
            for (;;) {
                if (first_pass2) {
                    BUS16_SET(c, 0x004204, ((y2 << 8) | 0) >> 2);
                    uint8_t value9 = RAM8(0x0007);
                    BUS8_SET(c, 0x004206, value9);
                    if ((uint8_t)(y2 + 1) < value9) {
                        uint8_t value10 = BUS8(c, 0x004214);
                        uint8_t value11 = BUS8(c, 0x00A798 + value10);
                        BUS8_SET(c, 0x002180, value11);
                        BUS8_SET(c, 0x002180, 0);
                        uint8_t a_hi2_next = ((y2 << 8) | 0) >> 2 >> 8;
                        uint8_t y2_next = (uint8_t)(y2 + 1);
                        a_hi2 = a_hi2_next;
                        y2 = y2_next;
                        first_pass2 = false;
                        continue;
                    }
                    uint8_t a_hi2_next2 = ((y2 << 8) | 0) >> 2 >> 8;
                    uint8_t y2_next2 = (uint8_t)(y2 + 1);
                    a_hi2 = a_hi2_next2;
                    y2 = y2_next2;
                    break;
                } else {
                    BUS16_SET(c, 0x004204, ((y2 << 8) | 0) >> 2);
                    uint8_t value12 = RAM8(0x0007);
                    BUS8_SET(c, 0x004206, value12);
                    if ((uint8_t)(y2 + 1) < value12) {
                        uint8_t value13 = BUS8(c, 0x004214);
                        uint8_t value14 = BUS8(c, 0x00A798 + value13);
                        BUS8_SET(c, 0x002180, value14);
                        BUS8_SET(c, 0x002180, 0);
                        uint8_t a_hi2_next3 = ((y2 << 8) | 0) >> 2 >> 8;
                        uint8_t y2_next3 = (uint8_t)(y2 + 1);
                        a_hi2 = a_hi2_next3;
                        y2 = y2_next3;
                        continue;
                    }
                    uint8_t a_hi2_next4 = ((y2 << 8) | 0) >> 2 >> 8;
                    uint8_t y2_next4 = (uint8_t)(y2 + 1);
                    a_hi2 = a_hi2_next4;
                    y2 = y2_next4;
                    break;
                }
            }
            uint8_t value15 = BUS8(c, 0x00A798 + 0x3F);
            BUS8_SET(c, 0x002180, value15);
            BUS8_SET(c, 0x002180, 0);
            uint16_t value16 = RAM16(0x0007);
            uint16_t value17 = RAM16(0x0008);
            RAM16_SET(0x0008, (uint16_t)(((value16 & 0xFF) << 1) + value17));
            RAM8(0x0005)++;
            RAM8(0x0005)++;
            if (!(RAM8(0x0005) & 0x80)) {
                a_hi1 = (uint16_t)(((value16 & 0xFF) << 1) + value17) >> 8;
                x1 = 0x3F;
                y1 = y2;
                overflow1 = ((((value16 & 0xFF) << 1) ^ (uint16_t)(((value16 & 0xFF) << 1) + value17)) & (value17 ^ (uint16_t)(((value16 & 0xFF) << 1) + value17)) & 0x8000) != 0;
                first_pass = false;
                continue;
            }
            a_hi1 = (uint16_t)(((value16 & 0xFF) << 1) + value17) >> 8;
            x1 = 0x3F;
            y1 = y2;
            overflow1 = ((((value16 & 0xFF) << 1) ^ (uint16_t)(((value16 & 0xFF) << 1) + value17)) & (value17 ^ (uint16_t)(((value16 & 0xFF) << 1) + value17)) & 0x8000) != 0;
            break;
        } else {
            uint8_t value18 = RAM8(0x0005);
            uint8_t value19 = BUS8(c, 0x00AB73 + (uint8_t)((a_hi1 << 8) | ((value18 ^ 0x7E) >> 1)));
            uint16_t value20 = BUS16(c, 0x00FD22 + (((((a_hi1 << 8) | value19) & 0xFF) << 1) ^ 0x01FE));
            RAM16_SET(0x0032, value20);
            uint8_t value21 = RAM8(0x0033);
            uint8_t a2;
            if (value21 == 0) {
                a2 = RAM8(0x0032) >> 2;
            } else {
                a2 = 0x40;
            }
            RAM8(0x0007) = a2;
            RAM8(0x0006) = 0;
            RAM16_SET(0x15000 + value18, RAM16(0x0008));
            RAM16_SET(0x15080 + value18, RAM16(0x0007) & 0xFF);
            uint16_t value25 = RAM16(0x0008);
            BUS16_SET(c, 0x002181, value25);
            BUS8_SET(c, 0x002183, 1);
            uint8_t a_hi3 = value25 >> 8;
            uint8_t y3 = 0;
            bool first_pass3 = true;
            for (;;) {
                if (first_pass3) {
                    BUS16_SET(c, 0x004204, ((y3 << 8) | 0) >> 2);
                    uint8_t value26 = RAM8(0x0007);
                    BUS8_SET(c, 0x004206, value26);
                    if ((uint8_t)(y3 + 1) < value26) {
                        uint8_t value27 = BUS8(c, 0x004214);
                        uint8_t value28 = BUS8(c, 0x00A798 + value27);
                        BUS8_SET(c, 0x002180, value28);
                        BUS8_SET(c, 0x002180, 0);
                        uint8_t a_hi3_next = ((y3 << 8) | 0) >> 2 >> 8;
                        uint8_t y3_next = (uint8_t)(y3 + 1);
                        a_hi3 = a_hi3_next;
                        y3 = y3_next;
                        first_pass3 = false;
                        continue;
                    }
                    uint8_t a_hi3_next2 = ((y3 << 8) | 0) >> 2 >> 8;
                    uint8_t y3_next2 = (uint8_t)(y3 + 1);
                    a_hi3 = a_hi3_next2;
                    y3 = y3_next2;
                    break;
                } else {
                    BUS16_SET(c, 0x004204, ((y3 << 8) | 0) >> 2);
                    uint8_t value29 = RAM8(0x0007);
                    BUS8_SET(c, 0x004206, value29);
                    if ((uint8_t)(y3 + 1) < value29) {
                        uint8_t value30 = BUS8(c, 0x004214);
                        uint8_t value31 = BUS8(c, 0x00A798 + value30);
                        BUS8_SET(c, 0x002180, value31);
                        BUS8_SET(c, 0x002180, 0);
                        uint8_t a_hi3_next3 = ((y3 << 8) | 0) >> 2 >> 8;
                        uint8_t y3_next3 = (uint8_t)(y3 + 1);
                        a_hi3 = a_hi3_next3;
                        y3 = y3_next3;
                        continue;
                    }
                    uint8_t a_hi3_next4 = ((y3 << 8) | 0) >> 2 >> 8;
                    uint8_t y3_next4 = (uint8_t)(y3 + 1);
                    a_hi3 = a_hi3_next4;
                    y3 = y3_next4;
                    break;
                }
            }
            uint8_t value32 = BUS8(c, 0x00A798 + 0x3F);
            BUS8_SET(c, 0x002180, value32);
            BUS8_SET(c, 0x002180, 0);
            uint16_t value33 = RAM16(0x0007);
            uint16_t value34 = RAM16(0x0008);
            RAM16_SET(0x0008, (uint16_t)(((value33 & 0xFF) << 1) + value34));
            RAM8(0x0005)++;
            RAM8(0x0005)++;
            if (!(RAM8(0x0005) & 0x80)) {
                a_hi1 = (uint16_t)(((value33 & 0xFF) << 1) + value34) >> 8;
                x1 = 0x3F;
                y1 = y3;
                overflow1 = ((((value33 & 0xFF) << 1) ^ (uint16_t)(((value33 & 0xFF) << 1) + value34)) & (value34 ^ (uint16_t)(((value33 & 0xFF) << 1) + value34)) & 0x8000) != 0;
                continue;
            }
            a_hi1 = (uint16_t)(((value33 & 0xFF) << 1) + value34) >> 8;
            x1 = 0x3F;
            y1 = y3;
            overflow1 = ((((value33 & 0xFF) << 1) ^ (uint16_t)(((value33 & 0xFF) << 1) + value34)) & (value34 ^ (uint16_t)(((value33 & 0xFF) << 1) + value34)) & 0x8000) != 0;
            break;
        }
    }
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AAD2, SOM_RTS, "gen", build_world_map_picker_row_geometry_with_hardware_division, 0, L_X | L_Y | L_V, 1, 0, 1, 161, 78)

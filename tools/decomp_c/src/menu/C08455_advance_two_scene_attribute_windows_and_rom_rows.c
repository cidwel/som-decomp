#include "som_c.h"

/* C08455 advance_two_scene_attribute_windows_and_rom_rows   [class C, 273 bytes, 143 instructions]
 * Source: src/rom/advance_two_scene_attribute_windows_and_rom_rows.s
 * Documented in docs/ui-native-scene-tile-rows.md
 * Entry: M=any X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_two_scene_attribute_windows_and_rom_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    RAM8(0x0000) = x;
    RAM16_SET(0x0002, 0x0700);
    RAM16_SET(0x0004, 0x0500);
    if (y != 4) {
        RAM16_SET(0x0002, RAM16(0x0002) >> 1);
        RAM16_SET(0x0004, RAM16(0x0004) >> 1);
    }
    uint8_t value3 = RAM8(0x0000);
    uint8_t a_hi1;
    if (value3 != 0) {
        uint16_t value4 = RAM16(0x00A8);
        uint16_t value5 = RAM16(0x0002);
        RAM16_SET(0x00A8, (uint16_t)(value4 + value5));
        if (value4 + value5 > 0xFFFF) {
            RAM16_SET(0x00AA, (uint16_t)(RAM16(0x00AA) + 1));
        }
        a_hi1 = (uint16_t)(value4 + value5) >> 8;
    } else {
        uint16_t value6 = RAM16(0x00A8);
        uint16_t value7 = RAM16(0x0002);
        RAM16_SET(0x00A8, (uint16_t)(value6 - value7));
        if (value6 < value7) {
            RAM16_SET(0x00AA, (uint16_t)(RAM16(0x00AA) - 1));
        }
        a_hi1 = (uint16_t)(value6 - value7) >> 8;
    }
    uint16_t value8 = RAM16(0x00A9);
    uint16_t value9 = RAM16(0x00B0);
    uint8_t a_hi3;
    if ((value8 & 0x01F8) != value9) {
        RAM16_SET(0x00B0, value8 & 0x01F8);
        uint8_t a1;
        uint8_t a_hi2;
        if (((uint8_t)(((value8 & 0x01F8) >> 3) + value3) & 0x3F) < 0x20) {
            a1 = (uint8_t)(((uint8_t)(((value8 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5000);
            a_hi2 = (((uint8_t)(((value8 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5000) >> 8;
        } else {
            a1 = (uint8_t)(((((uint8_t)(((value8 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5000) & 0x1F) | 0x5400);
            a_hi2 = (((((uint8_t)(((value8 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5000) & 0x1F) | 0x5400) >> 8;
        }
        RAM16_SET(0x00B6, (a_hi2 << 8) | a1);
        uint8_t a5;
        if (value3 != 0) {
            uint8_t value10 = RAM8(0x00BC);
            uint8_t a2;
            if ((uint8_t)(value10 + 1) < 0xE0) {
                a2 = (uint8_t)(value10 + 1);
            } else {
                a2 = (uint8_t)((uint8_t)(value10 + 1) - 0xE0 - ((uint8_t)(value10 + 1) >= 0xE0 ^ 1));
            }
            RAM8(0x00BC) = a2;
            uint8_t a3;
            if ((uint8_t)(a2 + value3) < 0xE0) {
                a3 = (uint8_t)(a2 + value3);
            } else {
                a3 = (uint8_t)((uint8_t)(a2 + value3) - 0xE0 - ((uint8_t)(a2 + value3) >= 0xE0 ^ 1));
            }
            a5 = a3;
        } else {
            uint8_t value11 = RAM8(0x00BC);
            uint8_t a4;
            if (value11 >= 1) {
                a4 = (uint8_t)(value11 - 1);
            } else {
                a4 = (uint8_t)((uint8_t)(value11 - 1) + 0xE0 + (value11 >= 1));
            }
            RAM8(0x00BC) = a4;
            a5 = a4;
        }
        RAM16_SET(0x00B4, (uint16_t)(((((a_hi2 << 8) | a5) & 0xFF) << 1 << 1 << 1 << 1) + 0x5700 + ((((a_hi2 << 8) | a5) & 0xFF) << 1 << 1 << 1 >> 0x0F)));
        a_hi3 = (uint16_t)(((((a_hi2 << 8) | a5) & 0xFF) << 1 << 1 << 1 << 1) + 0x5700 + ((((a_hi2 << 8) | a5) & 0xFF) << 1 << 1 << 1 >> 0x0F)) >> 8;
    } else {
        RAM16_SET(0x00B4, 0);
        a_hi3 = (value8 & 0x01F8) >> 8;
    }
    BUS8_SET(c, 0x004203, 0xA0);
    uint8_t a_hi4;
    bool overflow1;
    if (value3 != 0) {
        uint16_t value12 = RAM16(0x00AC);
        uint16_t value13 = RAM16(0x0004);
        RAM16_SET(0x00AC, (uint16_t)(value12 + value13));
        if (value12 + value13 > 0xFFFF) {
            RAM16_SET(0x00AE, (uint16_t)(RAM16(0x00AE) + 1));
        }
        a_hi4 = (uint16_t)(value12 + value13) >> 8;
        overflow1 = ((value12 ^ (uint16_t)(value12 + value13)) & (value13 ^ (uint16_t)(value12 + value13)) & 0x8000) != 0;
    } else {
        uint16_t value14 = RAM16(0x00AC);
        uint16_t value15 = RAM16(0x0004);
        RAM16_SET(0x00AC, (uint16_t)(value14 - value15));
        if (value14 < value15) {
            RAM16_SET(0x00AE, (uint16_t)(RAM16(0x00AE) - 1));
        }
        a_hi4 = (uint16_t)(value14 - value15) >> 8;
        overflow1 = ((value14 ^ value15) & (value14 ^ (uint16_t)(value14 - value15)) & 0x8000) != 0;
    }
    uint16_t value16 = RAM16(0x00AD);
    uint16_t value17 = RAM16(0x00B2);
    if ((value16 & 0x01F8) != value17) {
        RAM16_SET(0x00B2, value16 & 0x01F8);
        uint8_t a6;
        uint8_t a_hi5;
        if (((uint8_t)(((value16 & 0x01F8) >> 3) + value3) & 0x3F) < 0x20) {
            a6 = (uint8_t)(((uint8_t)(((value16 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5800);
            a_hi5 = (((uint8_t)(((value16 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5800) >> 8;
        } else {
            a6 = (uint8_t)(((((uint8_t)(((value16 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5800) & 0x1F) | 0x5C00);
            a_hi5 = (((((uint8_t)(((value16 & 0x01F8) >> 3) + value3) & 0x3F) | 0x5800) & 0x1F) | 0x5C00) >> 8;
        }
        RAM16_SET(0x00BA, (a_hi5 << 8) | a6);
        uint8_t a10;
        if (value3 != 0) {
            uint8_t value18 = RAM8(0x00BD);
            uint8_t a7;
            if ((uint8_t)(value18 + 1) < 0xA0) {
                a7 = (uint8_t)(value18 + 1);
            } else {
                a7 = (uint8_t)((uint8_t)(value18 + 1) - 0xA0 - ((uint8_t)(value18 + 1) >= 0xA0 ^ 1));
            }
            RAM8(0x00BD) = a7;
            uint8_t a8;
            if ((uint8_t)(a7 + value3) < 0xA0) {
                a8 = (uint8_t)(a7 + value3);
            } else {
                a8 = (uint8_t)((uint8_t)(a7 + value3) - 0xA0 - ((uint8_t)(a7 + value3) >= 0xA0 ^ 1));
            }
            a10 = a8;
        } else {
            uint8_t value19 = RAM8(0x00BD);
            uint8_t a9;
            if (value19 >= 1) {
                a9 = (uint8_t)(value19 - 1);
            } else {
                a9 = (uint8_t)((uint8_t)(value19 - 1) + 0xA0 + (value19 >= 1));
            }
            RAM8(0x00BD) = a9;
            a10 = a9;
        }
        RAM16_SET(0x00B8, (uint16_t)(((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 << 1) + 0x4A00 + ((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 >> 0x0F)));
        r->a = (uint16_t)(((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 << 1) + 0x4A00 + ((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 >> 0x0F));
        r->x = value3;
        r->c = ((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 << 1) + 0x4A00 + ((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 >> 0x0F) > 0xFFFF;
        r->v = ((((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 << 1) ^ (uint16_t)(((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 << 1) + 0x4A00 + ((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 >> 0x0F))) & ((uint16_t)(((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 << 1) + 0x4A00 + ((((a_hi5 << 8) | a10) & 0xFF) << 1 << 1 << 1 >> 0x0F)) ^ 0x4A00) & 0x8000) != 0;
        r->mf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x00B8, 0);
    r->a = value16 & 0x01F8;
    r->x = value3;
    r->c = (value16 & 0x01F8) >= value17;
    r->v = overflow1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08455, SOM_RTS, "gen", advance_two_scene_attribute_windows_and_rom_rows, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, 1, 273, 143)

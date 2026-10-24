#include "som_c.h"

/* C083E7 advance_ui_horizontal_rotation_and_attribute_windows   [class B, 110 bytes, 56 instructions]
 * Source: src/rom/advance_ui_horizontal_rotation_and_attribute_windows.s
 * Documented in docs/ui-native-ui-frame-navigation.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_ui_horizontal_rotation_and_attribute_windows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x0043);
    if ((value & 3) == 0) {
        RAM8(0x007A) = 0;
        uint8_t value2 = RAM8(0x003D);
        if (value2 == 0) {
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value3 = RAM8(0x003C);
        RAM8(0x003C) = (uint8_t)(value3 + 8);
        if (((uint8_t)(value3 + 8) & value2) == 0) {
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->c = value3 + 8 > 0xFF;
            r->v = ((value3 ^ (uint8_t)(value3 + 8)) & ((uint8_t)(value3 + 8) ^ 8) & 0x80) != 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value4 = RAM8(0x003D);
        RAM8(0x003D) <<= 1;
        uint8_t value5 = RAM8(0x00F2);
        if (value5 & 0x80) {
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->c = value4 & 0x80;
            r->v = value5 & 0x40;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value6 = RAM8(0x003C);
        uint8_t a_hi1;
        uint8_t x1;
        bool carry1;
        bool overflow1;
        if ((value6 & 1) != 0) {
            RAM16_SET(0x00F6, (uint16_t)(RAM16(0x00F6) + 0xFFFE) & 0x03FF);
            RAM8(0x0001) = 2;
            r->x = 0x20;
            r->y = 2;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x842F, 0xC08455); GUARD_JSR(c, sp_call, 0x842F); } /* advance_two_scene_attribute_windows_and_rom_rows */
            uint16_t a_all = r->a;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            RAM8(0x007A) = 1;
            a_hi1 = a_all >> 8;
            x1 = 1;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        } else {
            RAM16_SET(0x00F6, (uint16_t)(RAM16(0x00F6) + 2) & 0x03FF);
            r->x = 0;
            r->y = 2;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8416, 0xC08455); GUARD_JSR(c, sp_call, 0x8416); } /* advance_two_scene_attribute_windows_and_rom_rows */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            RAM8(0x007A) = 0x80;
            a_hi1 = a_all2 >> 8;
            x1 = 0x80;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
        }
        r->a = (a_hi1 << 8) | a;
        r->x = x1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x003C) = value & 3;
    uint8_t value9 = RAM8(0x005F);
    uint8_t y1;
    if (value9 != 4) {
        y1 = 4;
    } else {
        y1 = 2;
    }
    if (RAM8(0x003D) == 0) {
        RAM8(0x003D) = 8;
    }
    uint8_t a_hi2;
    uint8_t x2;
    bool carry2;
    bool overflow2;
    if ((value & 1) != 0) {
        RAM16_SET(0x00F6, (uint16_t)((y1 ^ 0xFFFF) + RAM16(0x00F6) + 1) & 0x03FF);
        RAM8(0x0001) = y1;
        r->x = 0x20;
        r->y = y1;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x842F, 0xC08455); GUARD_JSR(c, sp_call, 0x842F); } /* advance_two_scene_attribute_windows_and_rom_rows */
        uint16_t a_all3 = r->a;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        RAM8(0x007A) = 1;
        a_hi2 = a_all3 >> 8;
        x2 = 1;
        carry2 = carry_ret3;
        overflow2 = overflow_ret3;
    } else {
        RAM16_SET(0x00F6, (uint16_t)(y1 + RAM16(0x00F6)) & 0x03FF);
        r->x = 0;
        r->y = y1;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8416, 0xC08455); GUARD_JSR(c, sp_call, 0x8416); } /* advance_two_scene_attribute_windows_and_rom_rows */
        uint16_t a_all4 = r->a;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        RAM8(0x007A) = 0x80;
        a_hi2 = a_all4 >> 8;
        x2 = 0x80;
        carry2 = carry_ret4;
        overflow2 = overflow_ret4;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC083E7, SOM_RTS, "gen", advance_ui_horizontal_rotation_and_attribute_windows, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 110, 56)

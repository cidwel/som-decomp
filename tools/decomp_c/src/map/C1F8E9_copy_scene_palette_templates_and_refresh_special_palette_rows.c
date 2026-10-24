#include "som_c.h"

/* C1F8E9 copy_scene_palette_templates_and_refresh_special_palette_rows   [class B, 91 bytes, 44 instructions]
 * Source: src/rom/copy_scene_palette_templates_and_refresh_special_palette_rows.s
 * Documented in docs/ui-native-music-palette-transition.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void copy_scene_palette_templates_and_refresh_special_palette_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    RAM16_SET(0x0000, 0x0F);
    uint16_t value = RAM16(0x00E2);
    uint16_t x1;
    if (!(value & 0x4000)) {
        x1 = 0x7E00;
    } else {
        x1 = 0x4840;
    }
    RAM16_SET(0x0600, 0);
    RAM16_SET(0xDE00, 0);
    uint8_t a_hi1 = 0;
    uint16_t x2 = x1;
    uint16_t y1 = 2;
    bool carry1 = carry;
    for (;;) {
        uint16_t value2 = BUS16(c, 0xC60000 + x2);
        RAM16_SET(0x0600 + y1, value2);
        RAM16_SET(0xDE00 + y1, value2 & 0xFFE0);
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        uint8_t a_hi2;
        uint16_t y2;
        if (RAM16(0x0000) != 0) {
            a_hi2 = (value2 & 0xFFE0) >> 8;
            y2 = (uint16_t)(y1 + 2);
        } else {
            RAM16_SET(0x0000, 0x0F);
            a_hi2 = 0;
            y2 = (uint16_t)(y1 + 4);
        }
        a_hi1 = a_hi2;
        x2 = (uint16_t)(x2 + 2);
        y1 = y2;
        carry1 = y2 >= 0x01E0;
        if (!(y1 < 0x01E0)) break;
    }
    RAM8(0x00F5) &= 0xFE;
    RAM8(0x00F4) &= 0x3F;
    uint8_t value5 = RAM8(0x008C);
    uint8_t a2;
    uint8_t a_hi4;
    uint16_t x4;
    uint16_t y4;
    bool zero2;
    bool negative2;
    if (value5 == 0) {
        a2 = value5;
        a_hi4 = a_hi1;
        x4 = x2;
        y4 = y1;
        zero2 = value5 == 0;
        negative2 = value5 & 0x80;
    } else {
        uint8_t value6 = RAM8(0x00E3);
        uint8_t a1;
        uint8_t a_hi3;
        uint16_t x3;
        uint16_t y3;
        bool zero1;
        bool negative1;
        if ((value6 & 0x0F) != 0) {
            a1 = value6 & 0x0F;
            a_hi3 = a_hi1;
            x3 = x2;
            y3 = y1;
            zero1 = (value6 & 0x0F) == 0;
            negative1 = value6 & 0x0F & 0x80;
        } else {
            r->c = carry1;
            r->v = value & 0x4000;
            r->xf = 0;
            JSR(c, 0xF942, 0xC1FCF7); /* copy_three_special_palette_rows_through_shared_tail */
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            bool zero_ret = r->z;
            bool negative_ret = r->n;
            a1 = (uint8_t)a_all;
            a_hi3 = a_all >> 8;
            x3 = x_ret;
            y3 = y_ret;
            zero1 = zero_ret;
            negative1 = negative_ret;
        }
        a2 = a1;
        a_hi4 = a_hi3;
        x4 = x3;
        y4 = y3;
        zero2 = zero1;
        negative2 = negative1;
    }
    r->a = (a_hi4 << 8) | a2;
    r->x = x4;
    r->y = y4;
    r->c = carry1;
    r->z = zero2;
    r->n = negative2;
    r->v = value & 0x4000;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F8E9, SOM_RTS, "gen", copy_scene_palette_templates_and_refresh_special_palette_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 1, 91, 44)

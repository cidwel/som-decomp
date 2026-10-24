#include "som_c.h"

/* C2ACAC append_or_retire_native_visual_effect_trail_points   [class B, 166 bytes, 86 instructions]
 * Source: src/rom/append_or_retire_native_visual_effect_trail_points.s
 * Documented in docs/actor-visual-effect-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void append_or_retire_native_visual_effect_trail_points(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    if (RAM8(0xE117 + x) != 0) {
        RAM16_SET(0x0000, x >> 1);
        uint16_t value2 = RAM16(0xE115 + x);
        uint16_t value3 = RAM16(0x0000);
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        RAM16_SET(0x0000, x);
        uint16_t value4 = RAM16(0xE126 + x);
        uint16_t value5 = RAM16(0x0000);
        RAM16_SET(0xE000 + (((value4 & 0xFF) << 1 << 1) + 0xD0 | value5), RAM16(0xC000 + ((value2 & 0xFF) | value3)));
        uint16_t value7 = RAM16(0xC002 + ((value2 & 0xFF) | value3));
        RAM16_SET(0xE002 + (((value4 & 0xFF) << 1 << 1) + 0xD0 | value5), value7);
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        uint8_t value10 = RAM8(0xE115 + ((value9 << 8) | value8));
        RAM8(0xE115 + ((value9 << 8) | value8)) = (uint8_t)(value10 + 4);
        uint8_t value11 = RAM8(0xE126 + ((value9 << 8) | value8));
        uint8_t a1;
        if ((uint8_t)(value11 + 1) < 0x0A) {
            a1 = (uint8_t)(value11 + 1);
        } else {
            a1 = 0;
        }
        RAM8(0xE126 + ((value9 << 8) | value8)) = a1;
        uint8_t value12 = RAM8(0xE116 + ((value9 << 8) | value8));
        uint8_t a2;
        if ((uint8_t)(value12 + 1) < 0x0B) {
            a2 = (uint8_t)(value12 + 1);
        } else {
            a2 = 0x0A;
        }
        RAM8(0xE116 + ((value9 << 8) | value8)) = a2;
        RAM8(0xE117 + ((value9 << 8) | value8))--;
        r->a = (value7 >> 8 << 8) | a2;
        r->x = (value9 << 8) | value8;
        r->y = (value2 & 0xFF) | value3;
        r->c = (uint8_t)(value12 + 1) >= 0x0B;
        r->v = ((value10 ^ (uint8_t)(value10 + 4)) & ((uint8_t)(value10 + 4) ^ 4) & 0x80) != 0;
        RETURN_RTS(c);
    }
    uint8_t value13 = RAM8(0xE116 + x);
    RAM8(0xE116 + x) = (uint8_t)(value13 - 1);
    if ((uint8_t)(value13 - 1) != 0) {
        RAM8(0x0000 + sp0) = (uint8_t)(value13 - 1);
        RAM16_SET(0x0000, x);
        RAM8(0x0000) = (uint8_t)((uint8_t)(value13 - 1) << 2);
        uint8_t value14 = RAM8(0xE115 + x);
        uint8_t value15 = RAM8(0x0000);
        RAM8(0x0000) = (uint8_t)(value14 - value15);
        uint8_t value16 = RAM8(0x0001);
        RAM8(0x0001) >>= 1;
        uint16_t value17 = RAM16(0x0000);
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        uint8_t a3 = ((a_hi << 8) | (uint8_t)(value13 - 1)) & 0xFF;
        uint8_t a_hi1 = 0;
        uint16_t x1 = x;
        uint16_t y1 = value17;
        for (;;) {
            RAM8(0x0000 + sp0 - 2) = a_hi1;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)((a_hi1 << 8) | a3);
            RAM16_SET(0xE0D0 + x1, RAM16(0xC000 + y1));
            RAM16_SET(0xE0D2 + x1, RAM16(0xC002 + y1));
            uint8_t value20 = RAM8(0x0000 + sp0 - 3);
            uint8_t value21 = RAM8(0x0000 + sp0 - 2);
            a3 = (uint8_t)(((value21 << 8) | value20) - 1);
            a_hi1 = (uint16_t)(((value21 << 8) | value20) - 1) >> 8;
            x1 = (uint16_t)(x1 + 4);
            y1 = (uint16_t)(y1 + 4);
            if (!((uint16_t)(((value21 << 8) | value20) - 1) != 0)) break;
        }
        uint8_t value22 = RAM8(0x0000 + sp0 - 1);
        uint8_t value23 = RAM8(0x0000 + sp0);
        r->a = (a_hi1 << 8) | a3;
        r->x = (value23 << 8) | value22;
        r->y = y1;
        r->c = value16 & 0x01;
        r->v = ((value14 ^ value15) & (value14 ^ (uint8_t)(value14 - value15)) & 0x80) != 0;
        r->mf = 0;
        RETURN_RTS(c);
    }
    RAM8(0xE114 + x) = 0;
    RAM8(0xE084 + x) = 0;
    SET_A8(r, (uint8_t)(value13 - 1));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2ACAC, SOM_RTS, "gen", append_or_retire_native_visual_effect_trail_points, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 166, 86)

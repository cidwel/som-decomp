#include "som_c.h"

/* C19017 prepare_merged_actor_effect_sprites   [class B, 160 bytes, 74 instructions]
 * Source: src/rom/prepare_merged_actor_effect_sprites.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void prepare_merged_actor_effect_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0014);
    uint8_t value2 = RAM8(0xE110 + value);
    uint8_t value3 = RAM8(0xE120 + value);
    uint8_t value4 = RAM8(0xE130 + value);
    if ((value2 | value3 | value4) == 3) {
        uint16_t value5 = RAM16(0xC06C + (value >> 1));
        RAM16_SET(0xC060 + (value >> 1), value5);
        RAM16_SET(0xC064 + (value >> 1), value5);
        RAM16_SET(0xC068 + (value >> 1), value5);
        uint8_t value6 = RAM8(0xE010 + value);
        uint8_t a3;
        uint8_t a_hi2;
        uint16_t y3;
        if (value6 == 0) {
            a3 = 0;
            a_hi2 = 0;
            y3 = 0xFFE8;
        } else {
            uint8_t a2;
            uint8_t a_hi1;
            uint16_t y2;
            if (value6 & 0x80) {
                a2 = 0xE8;
                a_hi1 = 0xFF;
                y2 = 0;
            } else {
                uint8_t a1;
                uint16_t y1;
                if ((uint16_t)(value6 - 1) == 0) {
                    a1 = 0;
                    y1 = 0x18;
                } else {
                    a1 = 0x18;
                    y1 = 0;
                }
                a2 = a1;
                a_hi1 = 0;
                y2 = y1;
            }
            a3 = a2;
            a_hi2 = a_hi1;
            y3 = y2;
        }
        RAM16_SET(0x0004, (uint16_t)(((a_hi2 << 8) | a3) + RAM16(0xE020 + value)));
        RAM16_SET(0x0006, y3);
        uint16_t value8 = RAM16(0xE074 + value);
        uint16_t value9 = RAM16(0xE045 + value);
        uint16_t value10 = RAM16(0x0006);
        uint16_t value11 = RAM16(0xE022 + value);
        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1) + value11));
        RAM16_SET(0x0002, 0);
        uint16_t value12 = RAM16(0x0014);
        r->x = (value12 >> 1) | 0x60;
        r->y = value12;
        r->v = (((uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1) + value11)) & (value11 ^ (uint16_t)((uint16_t)(((uint16_t)((value8 & 0x7F) + value9) ^ 0xFFFF) + value10 + 1) + value11)) & 0x8000) != 0;
        r->mf = 0;
        JSR(c, 0x9091, 0xC190B7); /* append_one_merged_actor_effect_piece */
        r->y = RAM16(0x0014) | 0x10;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x909C, 0xC190B7); /* append_one_merged_actor_effect_piece */
        r->y = RAM16(0x0014) | 0x20;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x90A7, 0xC190B7); /* append_one_merged_actor_effect_piece */
        uint16_t value15 = RAM16(0x0014);
        uint16_t value16 = RAM16(0x0002);
        r->a = value16;
        r->x = (value15 >> 1) | 0xC060;
        r->c = value16 >= 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTL(c);
    }
    SET_A8(r, value2 | value3 | value4);
    r->x = value;
    r->c = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC19017, SOM_RTL, "gen", prepare_merged_actor_effect_sprites, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 160, 74)

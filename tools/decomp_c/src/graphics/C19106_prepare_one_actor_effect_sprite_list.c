#include "som_c.h"

/* C19106 prepare_one_actor_effect_sprite_list   [class B, 132 bytes, 68 instructions]
 * Source: src/rom/prepare_one_actor_effect_sprite_list.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void prepare_one_actor_effect_sprite_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xE110 + y);
    if (value == 0) {
        SET_A8(r, value);
        r->c = 0;
        r->mf = 1;
        RETURN_RTL(c);
    }
    if (value >= 4) {
        uint16_t value2 = RAM16(0x0014);
        RAM16_SET(0x0002, RAM16(0xE084 + value2) & 0x0F);
        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + y) + RAM16(0xE020 + value2)));
        uint16_t value6 = RAM16(0xE074 + value2);
        uint16_t value7 = RAM16(0xE045 + value2);
        uint16_t value8 = RAM16(0xE11A + y);
        uint16_t value9 = RAM16(0xE022 + value2);
        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF)));
        uint8_t value10 = RAM8(0xE110 + y);
        if (value10 != 1) {
            if (value10 >= 4) {
                if (value10 != 4) {
                    r->a = (((value2 >> 1) | 0xC000) >> 8 << 8) | value10;
                    r->x = (value2 >> 1) | 0xC000;
                    r->c = 0;
                    r->v = (((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & 0x8000) != 0;
                    r->mf = 1;
                    RETURN_RTL(c);
                }
                uint16_t value11 = RAM16(0xE11C + y);
                uint8_t value12 = RAM8(0xE113 + y);
                RAM8(0x0002) = value12 >> 2;
                if (value12 >> 2 == 0) {
                    r->a = (((value2 >> 1) | value11 | 0xC000) >> 8 << 8) | (value12 >> 2);
                    r->x = (value2 >> 1) | value11 | 0xC000;
                    r->c = 0;
                    r->v = (((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & 0x8000) != 0;
                    r->mf = 1;
                    RETURN_RTL(c);
                }
                r->a = (((value2 >> 1) | value11 | 0xC000) >> 8 << 8) | (value12 >> 2);
                r->x = (value2 >> 1) | value11 | 0xC000;
                r->c = 1;
                r->v = (((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & 0x8000) != 0;
                r->mf = 1;
                RETURN_RTL(c);
            }
            RAM8(0x0002) = 3;
            r->a = (((value2 >> 1) | 0xC000) >> 8 << 8) | RAM8(0xE112 + y);
            r->x = (value2 >> 1) | 0xC000;
            r->v = (((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & 0x8000) != 0;
            r->mf = 1;
            JSR(c, 0x9168, 0xC1918A); /* select_actor_effect_direction_piece */
            r->c = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint8_t value14 = RAM8(0x0002);
        if (value14 == 0) {
            r->a = (((value2 >> 1) | 0xC000) >> 8 << 8) | value14;
            r->x = (value2 >> 1) | 0xC000;
            r->c = 0;
            r->v = (((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & 0x8000) != 0;
            r->mf = 1;
            RETURN_RTL(c);
        }
        r->a = (((value2 >> 1) | 0xC000) >> 8 << 8) | value14;
        r->x = (value2 >> 1) | 0xC000;
        r->c = 1;
        r->v = (((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & (value9 ^ (uint16_t)((uint16_t)(((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1) + value9 + (((uint16_t)((value6 & 0x7F) + value7) ^ 0xFFFF) + value8 + 1 > 0xFFFF))) & 0x8000) != 0;
        r->mf = 1;
        RETURN_RTL(c);
    }
    uint8_t value15 = RAM8(0xE114 + y);
    if (value15 == 0) {
        uint16_t value16 = RAM16(0x0014);
        RAM16_SET(0x0002, RAM16(0xE084 + value16) & 0x0F);
        RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + y) + RAM16(0xE020 + value16)));
        uint16_t value20 = RAM16(0xE074 + value16);
        uint16_t value21 = RAM16(0xE045 + value16);
        uint16_t value22 = RAM16(0xE11A + y);
        uint16_t value23 = RAM16(0xE022 + value16);
        RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF)));
        uint8_t value24 = RAM8(0xE110 + y);
        if (value24 != 1) {
            if (value24 >= 4) {
                if (value24 != 4) {
                    r->a = (((value16 >> 1) | 0xC000) >> 8 << 8) | value24;
                    r->x = (value16 >> 1) | 0xC000;
                    r->c = 0;
                    r->v = (((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & 0x8000) != 0;
                    r->mf = 1;
                    RETURN_RTL(c);
                }
                uint16_t value25 = RAM16(0xE11C + y);
                uint8_t value26 = RAM8(0xE113 + y);
                RAM8(0x0002) = value26 >> 2;
                if (value26 >> 2 == 0) {
                    r->a = (((value16 >> 1) | value25 | 0xC000) >> 8 << 8) | (value26 >> 2);
                    r->x = (value16 >> 1) | value25 | 0xC000;
                    r->c = 0;
                    r->v = (((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & 0x8000) != 0;
                    r->mf = 1;
                    RETURN_RTL(c);
                }
                r->a = (((value16 >> 1) | value25 | 0xC000) >> 8 << 8) | (value26 >> 2);
                r->x = (value16 >> 1) | value25 | 0xC000;
                r->c = 1;
                r->v = (((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & 0x8000) != 0;
                r->mf = 1;
                RETURN_RTL(c);
            }
            RAM8(0x0002) = 3;
            r->a = (((value16 >> 1) | 0xC000) >> 8 << 8) | RAM8(0xE112 + y);
            r->x = (value16 >> 1) | 0xC000;
            r->v = (((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & 0x8000) != 0;
            r->mf = 1;
            JSR(c, 0x9168, 0xC1918A); /* select_actor_effect_direction_piece */
            r->c = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint8_t value28 = RAM8(0x0002);
        if (value28 == 0) {
            r->a = (((value16 >> 1) | 0xC000) >> 8 << 8) | value28;
            r->x = (value16 >> 1) | 0xC000;
            r->c = 0;
            r->v = (((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & 0x8000) != 0;
            r->mf = 1;
            RETURN_RTL(c);
        }
        r->a = (((value16 >> 1) | 0xC000) >> 8 << 8) | value28;
        r->x = (value16 >> 1) | 0xC000;
        r->c = 1;
        r->v = (((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & (value23 ^ (uint16_t)((uint16_t)(((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1) + value23 + (((uint16_t)((value20 & 0x7F) + value21) ^ 0xFFFF) + value22 + 1 > 0xFFFF))) & 0x8000) != 0;
        r->mf = 1;
        RETURN_RTL(c);
    }
    SET_A8(r, value15);
    r->c = 0;
    r->mf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC19106, SOM_RTL, "gen", prepare_one_actor_effect_sprite_list, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 132, 68)

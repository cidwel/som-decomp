#include "som_c.h"

/* C0464F load_hero_level_attributes_and_controller_adjustments   [class B, 240 bytes, 106 instructions]
 * Source: src/rom/load_hero_level_attributes_and_controller_adjustments.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYV.
 */
static void load_hero_level_attributes_and_controller_adjustments(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE1E7 + x);
    RAM16_SET(BATTLE_TEMP_A4, 0x0318);
    uint8_t a1 = 0;
    uint8_t a_hi1 = 0;
    uint16_t y1 = ((a_hi << 8) | (uint8_t)(value - 0x80)) & 0xFF;
    for (;;) {
        if (!((uint16_t)(y1 - 1) & 0x8000)) {
            uint16_t battle_temp_a4 = RAM16(BATTLE_TEMP_A4);
            uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + battle_temp_a4);
            uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + battle_temp_a4) >> 8;
            uint16_t y1_next = (uint16_t)(y1 - 1);
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            y1 = y1_next;
            continue;
        }
        y1 = (uint16_t)(y1 - 1);
        break;
    }
    RAM16_SET(0x03B4, (a_hi1 << 8) | a1);
    uint16_t value2 = RAM16(ACTOR_LEVEL + x);
    uint16_t value3 = RAM16(0x03B4);
    uint16_t value4 = BUS16(c, 0xD04210 + (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3));
    RAM16_SET(ACTOR_MAX_HP + x, value4);
    uint8_t value5 = BUS8(c, 0xD04212 + (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3));
    RAM8(ACTOR_MAX_MP + x) = value5;
    uint8_t value6 = BUS8(c, 0xD04213 + (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3));
    RAM8(ACTOR_STRENGTH + x) = value6;
    uint8_t value7 = BUS8(c, 0xD04214 + (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3));
    RAM8(ACTOR_AGILITY + x) = value7;
    uint8_t value8 = BUS8(c, 0xD04215 + (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3));
    RAM8(ACTOR_CONSTITUTION + x) = value8;
    uint8_t value9 = BUS8(c, 0xD04216 + (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3));
    RAM8(ACTOR_INTELLIGENCE + x) = value9;
    uint8_t value10 = BUS8(c, 0xD04217 + (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3));
    RAM8(ACTOR_WISDOM + x) = value10;
    BUS8_SET(c, 0x004202, RAM8(ACTOR_LEVEL + x));
    BUS8_SET(c, 0x004203, 3);
    uint16_t value12 = BUS16(c, 0x004216);
    uint16_t value13 = BUS16(c, 0xD04B58 + value12);
    RAM16_SET(0xE17D + x, value13);
    uint8_t value14 = BUS8(c, 0xD04B5A + value12);
    RAM8(0xE17F + x) = value14;
    uint16_t value15 = RAM16(0x03BD);
    uint8_t value16 = RAM8(0x03BA);
    uint8_t a2;
    if ((uint8_t)(value16 + 1) != 3) {
        a2 = (uint8_t)(value16 + 1);
    } else {
        a2 = (uint8_t)(value16 + 2);
    }
    RAM8(BATTLE_TEMP_A4) = a2;
    uint8_t value17 = RAM8(0x00D9);
    uint8_t battle_temp_a42 = RAM8(BATTLE_TEMP_A4);
    if ((value17 & 0x0F) == battle_temp_a42) {
        r->a = value13 >> 8 << 8 | (value17 & 0x0F);
        r->x = value15;
        r->y = x;
        r->v = ((((value2 & 0xFF) << 1 << 1 << 1) ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & (value3 ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t value18 = RAM8(0x00DA);
    if ((value18 & 0x0F) == battle_temp_a42) {
        r->a = value13 >> 8 << 8 | (value18 & 0x0F);
        r->x = value15;
        r->y = x;
        r->v = ((((value2 & 0xFF) << 1 << 1 << 1) ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & (value3 ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t value19 = RAM8(0x00DB);
    if ((value19 & 0x0F) == battle_temp_a42) {
        r->a = value13 >> 8 << 8 | (value19 & 0x0F);
        r->x = value15;
        r->y = x;
        r->v = ((((value2 & 0xFF) << 1 << 1 << 1) ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & (value3 ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint8_t value21 = BUS8(c, 0xC0473F + RAM8(0xCC7A + value16));
    RAM8(BATTLE_TEMP_A4) = value21;
    RAM8(BATTLE_TEMP_A6) = 3;
    uint8_t a_hi2 = 0;
    uint16_t x1 = value15;
    do {
        uint8_t battle_temp_a43 = RAM8(BATTLE_TEMP_A4);
        if ((battle_temp_a43 & 3) != 0) {
            if ((battle_temp_a43 & 3) != 1) {
                if ((battle_temp_a43 & 3) != 2) {
                    RAM8(ACTOR_STRENGTH + x1)--;
                } else {
                    RAM8(ACTOR_STRENGTH + x1)++;
                    RAM8(ACTOR_STRENGTH + x1)++;
                }
            } else {
                RAM8(ACTOR_STRENGTH + x1)++;
            }
        }
        RAM8(BATTLE_TEMP_A4) >>= 1;
        RAM8(BATTLE_TEMP_A4) >>= 1;
        RAM8(BATTLE_TEMP_A6)--;
        x1 = (uint16_t)(x1 + 1);
    } while (RAM8(BATTLE_TEMP_A6) != 0);
    uint16_t value22 = RAM16(0x03BD);
    r->a = (a_hi2 << 8) | a;
    r->x = value22;
    r->y = value16;
    r->v = ((((value2 & 0xFF) << 1 << 1 << 1) ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & (value3 ^ (uint16_t)(((value2 & 0xFF) << 1 << 1 << 1) + value3)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0464F, SOM_RTS, "gen", load_hero_level_attributes_and_controller_adjustments, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 240, 106)

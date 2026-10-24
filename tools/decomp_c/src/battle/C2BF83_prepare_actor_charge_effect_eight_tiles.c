#include "som_c.h"

/* C2BF83 prepare_actor_charge_effect_eight_tiles   [class B, 125 bytes, 64 instructions]
 * Source: src/rom/prepare_actor_charge_effect_eight_tiles.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void prepare_actor_charge_effect_eight_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x000A, x);
    uint8_t value = RAM8(0xD000 + y);
    uint16_t value2 = RAM16(0xE06C + x);
    uint16_t x6;
    if (value != 1) {
        uint16_t x4;
        if (value != 2) {
            uint16_t x2;
            if (value == 3) {
                x2 = 0xFFE8;
            } else {
                uint16_t x1;
                if (value == 4) {
                    x1 = 0xFFF0;
                } else {
                    x1 = 0xFFF8;
                }
                x2 = x1;
            }
            x4 = x2;
        } else {
            uint8_t value3 = RAM8(0xE010 + x);
            uint16_t x3;
            if (value3 >= 2) {
                x3 = 0xFFD8;
            } else {
                x3 = 0xFFE0;
            }
            x4 = x3;
        }
        x6 = x4;
    } else {
        uint8_t value4 = RAM8(0xE010 + x);
        uint16_t x5;
        if (value4 >= 2) {
            x5 = 0xFFC8;
        } else {
            x5 = 0xFFD0;
        }
        x6 = x5;
    }
    uint16_t value5 = RAM16(0x000A);
    RAM16_SET(0x000A, (uint16_t)((uint16_t)(value5 << 3) + 0x2000));
    uint8_t a1 = 8;
    uint8_t a_hi1 = 0;
    uint16_t x7 = x6;
    uint16_t y1 = (uint16_t)(value2 + 0x40);
    bool overflow1 = (((uint16_t)(value5 << 3) ^ (uint16_t)((uint16_t)(value5 << 3) + 0x2000)) & ((uint16_t)((uint16_t)(value5 << 3) + 0x2000) ^ 0x2000) & 0x8000) != 0;
    for (;;) {
        uint16_t value6 = BUS16(c, 0xD40000 + x7);
        uint8_t a2;
        uint8_t a_hi2;
        bool overflow2;
        if ((value6 & 0xFF) != 0xFF) {
            uint16_t value7 = RAM16(0x000A);
            a2 = (uint8_t)(((value6 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value7 + ((value6 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F));
            a_hi2 = (uint16_t)(((value6 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value7 + ((value6 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F)) >> 8;
            overflow2 = ((((value6 & 0xFF) << 1 << 1 << 1 << 1 << 1) ^ (uint16_t)(((value6 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value7 + ((value6 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F))) & (value7 ^ (uint16_t)(((value6 & 0xFF) << 1 << 1 << 1 << 1 << 1) + value7 + ((value6 & 0xFF) << 1 << 1 << 1 << 1 >> 0x0F))) & 0x8000) != 0;
        } else {
            a2 = 0;
            a_hi2 = 0xCB;
            overflow2 = overflow1;
        }
        RAM16_SET(0x0000 + y1, (a_hi2 << 8) | a2);
        bool again = (uint16_t)(((a_hi1 << 8) | a1) - 1) != 0;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - 1);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
        uint16_t x7_next = (uint16_t)(x7 + 1);
        uint16_t y1_next = (uint16_t)(y1 + 2);
        bool overflow1_next = overflow2;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x7 = x7_next;
        y1 = y1_next;
        overflow1 = overflow1_next;
        if (!again) break;
    }
    r->x = x;
    r->y = y;
    r->v = overflow1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2BF83, SOM_RTS, "gen", prepare_actor_charge_effect_eight_tiles, 0, L_X | L_Y | L_V, 6, 1, 0, 125, 64)

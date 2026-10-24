#include "som_c.h"

/* C2274C update_boss_palette_transition_object   [class B, 117 bytes, 61 instructions]
 * Source: src/rom/update_boss_palette_transition_object.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void update_boss_palette_transition_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x009A + x);
    if (value == 0) {
        uint16_t value2 = RAM16(0x009E + x);
        if (!(value2 & 0x8000)) {
            RAM16_SET(0x0276, ((((value2 & 0x0F) << 8) | 0) >> 3) + 0x0600);
            uint16_t value3 = RAM16(0x009C + x);
            RAM16_SET(0x027A, 0xC200);
            uint16_t value4 = BUS16(c, 0xD0BB24 + (uint16_t)(value3 << 1));
            RAM16_SET(0x0279, value4);
            uint8_t a1 = (uint8_t)value4;
            uint8_t a_hi1 = value4 >> 8;
            uint16_t y1 = 0;
            for (;;) {
                uint16_t value5 = BUS16(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + y1);
                BUS16_SET(c, RAM16(0x0276) + 0x7E0000 + y1, value5);
                a1 = (uint8_t)value5;
                a_hi1 = value5 >> 8;
                y1 = (uint16_t)(y1 + 2);
                if (!(y1 != 0x20)) break;
            }
            uint16_t value6 = RAM16(0x0287);
            r->a = (a_hi1 << 8) | a1;
            r->x = value6;
            r->y = y1;
            r->c = 1;
            r->z = value6 == 0;
            r->n = value6 & 0x8000;
            r->v = ((((((value2 & 0x0F) << 8) | 0) >> 3) ^ ((((value2 & 0x0F) << 8) | 0) >> 3) + 0x0600) & (((((value2 & 0x0F) << 8) | 0) >> 3) + 0x0600 ^ 0x0600) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        RAM16_SET(0x0266, (uint16_t)((((uint8_t)(value2 & 0x0F00) << 8) | ((value2 & 0x0F00) >> 8)) << 1));
        uint16_t value7 = RAM16(0x009C + x);
        uint16_t value8 = RAM16(0x0266);
        uint16_t value9 = BUS16(c, 0xD0BB24 + (uint16_t)(value7 << 1));
        RAM16_SET(0x0276, (uint16_t)(value8 + value9));
        uint16_t value10 = RAM16(0x0287);
        uint16_t value11 = RAM16(0x009E + value10);
        RAM16_SET(0x0279, (uint16_t)(((((value11 & 0x0F) << 8) | 0) >> 3) + 0x0600 + value8 + (((((value11 & 0x0F) << 8) | 0) >> 3) + 0x0600 > 0xFFFF)));
        RAM8(0x0278) = 0xC2;
        uint16_t value12 = BUS16(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276));
        BUS16_SET(c, RAM16(0x0279) + 0x7E0000, value12);
        r->a = value12;
        r->x = value10;
        r->c = 1;
        r->z = value12 == 0;
        r->n = value12 & 0x8000;
        r->v = ((((((value11 & 0x0F) << 8) | 0) >> 3) + 0x0600 ^ (uint16_t)(((((value11 & 0x0F) << 8) | 0) >> 3) + 0x0600 + value8 + (((((value11 & 0x0F) << 8) | 0) >> 3) + 0x0600 > 0xFFFF))) & (value8 ^ (uint16_t)(((((value11 & 0x0F) << 8) | 0) >> 3) + 0x0600 + value8 + (((((value11 & 0x0F) << 8) | 0) >> 3) + 0x0600 > 0xFFFF))) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    TAIL_CALL(c, 0xC227C1, SOM_RTS); /* dispatch_full_boss_palette_transition_phase */
}
SOM_REGISTER(0xC2274C, SOM_RTS, "gen", update_boss_palette_transition_object, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 117, 61)

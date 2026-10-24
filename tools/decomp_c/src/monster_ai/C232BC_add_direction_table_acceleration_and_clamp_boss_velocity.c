#include "som_c.h"

/* C232BC add_direction_table_acceleration_and_clamp_boss_velocity   [class B, 87 bytes, 43 instructions]
 * Source: src/rom/add_direction_table_acceleration_and_clamp_boss_velocity.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void add_direction_table_acceleration_and_clamp_boss_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x021C, (uint16_t)((RAM16(0x021A) ^ 0xFFFF) + 1));
    uint16_t value2 = RAM16(0x00AB + x);
    uint16_t value3 = BUS16_RDL(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + (uint16_t)(value2 << 2), RAM8(0x020E));
    RAM16_SET(0x0295, value3);
    uint16_t value4 = BUS16_RDL(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + (uint16_t)((uint16_t)(value2 << 2) + 2), RAM8(0x020E));
    RAM16_SET(0x0297, value4);
    uint16_t value5 = RAM16(0x0295);
    uint16_t value6 = RAM16(0x003C + x);
    RAM16_SET(0x003C + x, (uint16_t)(value5 + value6));
    uint8_t a_hi3;
    if ((uint16_t)(value5 + value6) & 0x8000) {
        uint16_t value7 = RAM16(0x021C);
        uint8_t a_hi1;
        if ((uint16_t)(value5 + value6) >= value7) {
            a_hi1 = (uint16_t)(value5 + value6) >> 8;
        } else {
            RAM16_SET(0x003C + x, value7);
            a_hi1 = value7 >> 8;
        }
        a_hi3 = a_hi1;
    } else {
        uint16_t value8 = RAM16(0x021A);
        uint8_t a_hi2;
        if ((uint16_t)(value5 + value6) < value8) {
            a_hi2 = (uint16_t)(value5 + value6) >> 8;
        } else {
            RAM16_SET(0x003C + x, value8);
            a_hi2 = value8 >> 8;
        }
        a_hi3 = a_hi2;
    }
    uint16_t value9 = RAM16(0x0297);
    uint16_t value10 = RAM16(0x0040 + x);
    RAM16_SET(0x0040 + x, (uint16_t)(value9 + value10));
    uint8_t a_hi6;
    bool carry1;
    if ((uint16_t)(value9 + value10) & 0x8000) {
        uint16_t value11 = RAM16(0x021C);
        uint8_t a_hi4;
        if ((uint16_t)(value9 + value10) >= value11) {
            a_hi4 = (uint16_t)(value9 + value10) >> 8;
        } else {
            RAM16_SET(0x0040 + x, value11);
            a_hi4 = value11 >> 8;
        }
        a_hi6 = a_hi4;
        carry1 = (uint16_t)(value9 + value10) >= value11;
    } else {
        uint16_t value12 = RAM16(0x021A);
        uint8_t a_hi5;
        if ((uint16_t)(value9 + value10) < value12) {
            a_hi5 = (uint16_t)(value9 + value10) >> 8;
        } else {
            RAM16_SET(0x0040 + x, value12);
            a_hi5 = value12 >> 8;
        }
        a_hi6 = a_hi5;
        carry1 = (uint16_t)(value9 + value10) >= value12;
    }
    r->a = (a_hi6 << 8) | (uint8_t)a;
    r->y = (uint16_t)((uint16_t)(value2 << 2) + 2);
    r->c = carry1;
    r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC232BC, SOM_RTS, "gen", add_direction_table_acceleration_and_clamp_boss_velocity, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 87, 43)

#include "som_c.h"

/* C224F1 expand_boss_loader_resource_to_bus   [class B, 67 bytes, 36 instructions]
 * Source: src/rom/expand_boss_loader_resource_to_bus.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void expand_boss_loader_resource_to_bus(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0068 + dp);
    RAM16_SET(0x0068 + dp, (uint16_t)(value + 7) >> 3);
    uint8_t a_hi1 = (uint16_t)(value + 7) >> 3 >> 8;
    uint8_t x1 = (uint8_t)x;
    uint8_t y1 = (uint8_t)y;
    bool carry1 = (uint16_t)(value + 7) >> 2 & 0x01;
    bool overflow1 = ((value ^ (uint16_t)(value + 7)) & ((uint16_t)(value + 7) ^ 7) & 0x8000) != 0;
    do {
        uint16_t value2;
        BUS16_OK(c, (RAM8(0x007B + dp) << 0x10) + RAM16(0x0079 + dp), value2);
        RAM16_SET(0x006E + dp, ((uint8_t)value2 << 8) | (value2 >> 8));
        RAM16_SET(0x0079 + dp, (uint16_t)(RAM16(0x0079 + dp) + 1));
        uint8_t a_hi2 = (uint8_t)value2;
        uint8_t x2 = 8;
        uint8_t y2 = y1;
        for (;;) {
            uint16_t value3 = RAM16(0x006E + dp);
            RAM16_SET(0x006E + dp, (uint16_t)(RAM16(0x006E + dp) << 1));
            uint8_t a1;
            uint8_t a_hi3;
            if (!(value3 & 0x8000)) {
                uint16_t value4 = RAM16(0x006C + dp);
                a1 = (uint8_t)value4;
                a_hi3 = value4 >> 8;
            } else {
                uint16_t value5;
                BUS16_OK(c, (RAM8(0x007B + dp) << 0x10) + RAM16(0x0079 + dp), value5);
                RAM16_SET(0x0079 + dp, (uint16_t)(RAM16(0x0079 + dp) + 1));
                a1 = (uint8_t)value5;
                a_hi3 = value5 >> 8;
            }
            uint8_t value6 = RAM8(0x006A + dp);
            RAM8(0x006C + dp) = value6;
            RAM16_SET(0x006A + dp, (a_hi3 << 8) | a1);
            BUS16_SET(c, (RAM8(0x007E + dp) << 0x10) + RAM16(0x007C + dp), (a_hi3 << 8) | a1);
            RAM16_SET(0x007C + dp, (uint16_t)(RAM16(0x007C + dp) + 1));
            a_hi2 = a_hi3;
            x2 = (uint8_t)(x2 - 1);
            y2 = value6;
            if (!(x2 != 0)) break;
        }
        uint16_t value7 = RAM16(0x007C + dp);
        uint8_t a_hi4;
        bool carry2;
        bool overflow2;
        if (value7 != 0x4000) {
            a_hi4 = value7 >> 8;
            carry2 = value7 >= 0x4000;
            overflow2 = overflow1;
        } else {
            RAM16_SET(0x007C + dp, (uint16_t)(value7 + 0x2000));
            a_hi4 = (uint16_t)(value7 + 0x2000) >> 8;
            carry2 = value7 + 0x2000 > 0xFFFF;
            overflow2 = ((value7 ^ (uint16_t)(value7 + 0x2000)) & ((uint16_t)(value7 + 0x2000) ^ 0x2000) & 0x8000) != 0;
        }
        RAM16_SET(0x0068 + dp, (uint16_t)(RAM16(0x0068 + dp) - 1));
        a_hi1 = a_hi4;
        x1 = x2;
        y1 = y2;
        carry1 = carry2;
        overflow1 = overflow2;
    } while (RAM16(0x0068 + dp) != 0);
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC224F1, SOM_RTS, "hand", expand_boss_loader_resource_to_bus, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 67, 36)

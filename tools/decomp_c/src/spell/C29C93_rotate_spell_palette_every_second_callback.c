#include "som_c.h"

/* C29C93 rotate_spell_palette_every_second_callback   [class B, 35 bytes, 15 instructions]
 * Source: src/rom/rotate_spell_palette_every_second_callback.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void rotate_spell_palette_every_second_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0xBA + x);
    BUS16_RMW_SET(c, (db << 0x10) + 0xBA + x, (uint16_t)(value + 1));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xBA + x);
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t x2;
    bool zero1;
    bool negative1;
    if ((value2 & 1) != 0) {
        a1 = (uint8_t)value2;
        a_hi2 = value2 >> 8;
        x2 = x;
        zero1 = (value2 & 1) == 0;
        negative1 = value2 & 0x8000;
    } else {
        uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x07FE);
        BUS16_SET(c, (uint16_t)(dp + 0x95), value3);
        uint8_t a_hi1 = value3 >> 8;
        uint16_t x1 = 0x1C;
        for (;;) {
            uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x07E0 + x1);
            BUS16_SET(c, (db << 0x10) + 0x07E2 + x1, value4);
            a_hi1 = value4 >> 8;
            x1 = (uint16_t)(x1 - 2);
            if (!(x1 != 0)) break;
        }
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x95));
        BUS16_SET(c, (db << 0x10) + 0x07E2, value5);
        a1 = (uint8_t)value5;
        a_hi2 = value5 >> 8;
        x2 = x1;
        zero1 = value5 == 0;
        negative1 = value5 & 0x8000;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x2;
    r->y = y;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29C93, SOM_RTS, "gen", rotate_spell_palette_every_second_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 35, 15)

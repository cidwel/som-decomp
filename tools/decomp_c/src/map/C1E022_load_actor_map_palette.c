#include "som_c.h"

/* C1E022 load_actor_map_palette   [class B, 77 bytes, 38 instructions]
 * Source: src/rom/load_actor_map_palette.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void load_actor_map_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a2;
    bool carry2;
    bool overflow2;
    if (x >= 0x0600) {
        uint8_t value = RAM8(0xE180 + x);
        RAM8(0xE100 + x) = 0;
        a2 = value;
        carry2 = x >= 0x0600;
        overflow2 = overflow;
    } else {
        uint8_t value2 = RAM8(ACTOR_STATUS_HIGH + x);
        uint8_t a1;
        bool carry1;
        bool overflow1;
        if ((value2 & 0x20) == 0) {
            uint8_t value3 = RAM8(0xE180 + x);
            RAM8(0xE100 + x) = 0;
            a1 = value3;
            carry1 = x >= 0x0600;
            overflow1 = overflow;
        } else {
            a1 = (uint8_t)((x >> 9) + 0xE7);
            carry1 = (x >> 9) + 0xE7 > 0xFF;
            overflow1 = (((x >> 9) ^ (uint8_t)((x >> 9) + 0xE7)) & ((uint8_t)((x >> 9) + 0xE7) ^ 0xE7) & 0x80) != 0;
        }
        a2 = a1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    BUS8_SET(c, 0x004202, a2);
    BUS8_SET(c, 0x004203, 0x1E);
    uint16_t value4 = RAM16(0xE0F8 + x);
    RAM16_SET(0x0000, 0x0F);
    uint16_t value5 = BUS16(c, 0x004216);
    uint8_t a3 = (uint8_t)value5;
    uint8_t a_hi1 = value5 >> 8;
    uint16_t x1 = value5;
    uint16_t y1 = value4;
    do {
        uint16_t value6 = BUS16(c, 0xC81000 + x1);
        RAM16_SET(0x0700 + y1, value6);
        RAM16_SET(0xDF00 + y1, value6);
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        a3 = (uint8_t)value6;
        a_hi1 = value6 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM16(0x0000) != 0);
    r->a = (a_hi1 << 8) | a3;
    r->x = x;
    r->y = y;
    r->c = carry2;
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E022, SOM_RTS, "gen", load_actor_map_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 77, 38)

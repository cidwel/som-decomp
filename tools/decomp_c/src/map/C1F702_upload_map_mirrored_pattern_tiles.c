#include "som_c.h"

/* C1F702 upload_map_mirrored_pattern_tiles   [class D, 101 bytes, 49 instructions]
 * Source: src/rom/upload_map_mirrored_pattern_tiles.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void upload_map_mirrored_pattern_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002115, 0x80);
    RAM16_SET(0x0002, 0x6000);
    uint8_t a1 = 0;
    uint8_t a_hi1 = 0x60;
    uint8_t x1 = 0;
    uint8_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x0002);
        BUS16_SET(c, 0x002116, value);
        uint8_t a_hi2 = value >> 8;
        uint8_t x2 = x1;
        uint8_t y2 = 8;
        for (;;) {
            uint16_t value2 = BUS16(c, 0xD1F5B0 + x2);
            BUS16_SET(c, 0x002118, value2 & 0xFF);
            a_hi2 = 0;
            x2 = (uint8_t)(x2 + 1);
            y2 = (uint8_t)(y2 - 1);
            if (!(y2 != a_hi2)) break;
        }
        uint8_t y3 = 8;
        for (;;) {
            BUS16_SET(c, 0x002118, 0);
            y3 = (uint8_t)(y3 - 1);
            if (!(y3 != 0)) break;
        }
        uint16_t value3 = RAM16(0x0002);
        BUS16_SET(c, 0x002116, (uint16_t)(value3 + 0x0100));
        uint8_t a_hi3 = (uint16_t)(value3 + 0x0100) >> 8;
        uint8_t x3 = (uint8_t)(x2 - 1);
        uint8_t y4 = 8;
        for (;;) {
            uint16_t value4 = BUS16(c, 0xD1F5B0 + x3);
            BUS16_SET(c, 0x002118, value4 & 0xFF);
            a_hi3 = 0;
            x3 = (uint8_t)(x3 - 1);
            y4 = (uint8_t)(y4 - 1);
            if (!(y4 != a_hi3)) break;
        }
        uint8_t y5 = 8;
        for (;;) {
            BUS16_SET(c, 0x002118, 0);
            y5 = (uint8_t)(y5 - 1);
            if (!(y5 != 0)) break;
        }
        uint16_t value5 = RAM16(0x0002);
        RAM16_SET(0x0002, (uint16_t)(value5 + 0x10));
        a1 = (uint8_t)(value5 + 0x10);
        a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
        x1 = (uint8_t)(x3 + 9);
        y1 = y5;
        carry1 = (uint8_t)(x3 + 9) >= 0x50;
        overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
        if (!(x1 < 0x50)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F702, SOM_RTS, "gen", upload_map_mirrored_pattern_tiles, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 101, 49)

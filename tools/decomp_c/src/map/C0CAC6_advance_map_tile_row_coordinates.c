#include "som_c.h"

/* C0CAC6 advance_map_tile_row_coordinates   [class B, 57 bytes, 29 instructions]
 * Source: src/rom/advance_map_tile_row_coordinates.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void advance_map_tile_row_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x00AA);
    uint16_t value2 = RAM16(0x00C2);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value + 0x10) < value2) {
        a1 = (uint8_t)(value + 0x10);
        a_hi1 = (uint16_t)(value + 0x10) >> 8;
    } else {
        a1 = (uint8_t)((uint16_t)(value + 0x10) - value2 - ((uint16_t)(value + 0x10) >= value2 ^ 1));
        a_hi1 = (uint16_t)((uint16_t)(value + 0x10) - value2 - ((uint16_t)(value + 0x10) >= value2 ^ 1)) >> 8;
    }
    RAM16_SET(0x00AA, (a_hi1 << 8) | a1);
    uint16_t value3 = RAM16(0x00B2);
    RAM16_SET(0x00B2, (uint16_t)(value3 + 0x10));
    uint8_t value4 = RAM8(0x00B9);
    bool m_flag;
    uint8_t a_hi3;
    bool carry1;
    bool overflow1;
    if (value4 == 0) {
        m_flag = 1;
        a_hi3 = (uint16_t)(value3 + 0x10) >> 8;
        carry1 = value3 + 0x10 > 0xFFFF;
        overflow1 = ((value3 ^ (uint16_t)(value3 + 0x10)) & ((uint16_t)(value3 + 0x10) ^ 0x10) & 0x8000) != 0;
    } else {
        uint16_t value5 = RAM16(0x00AE);
        uint16_t value6 = RAM16(0x00C6);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)(value5 + 0x10) < value6) {
            a2 = (uint8_t)(value5 + 0x10);
            a_hi2 = (uint16_t)(value5 + 0x10) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)(value5 + 0x10) - value6 - ((uint16_t)(value5 + 0x10) >= value6 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)(value5 + 0x10) - value6 - ((uint16_t)(value5 + 0x10) >= value6 ^ 1)) >> 8;
        }
        RAM16_SET(0x00AE, (a_hi2 << 8) | a2);
        uint16_t value7 = RAM16(0x00B6);
        RAM16_SET(0x00B6, (uint16_t)(value7 + 0x10));
        m_flag = 0;
        a_hi3 = (uint16_t)(value7 + 0x10) >> 8;
        carry1 = value7 + 0x10 > 0xFFFF;
        overflow1 = ((value7 ^ (uint16_t)(value7 + 0x10)) & ((uint16_t)(value7 + 0x10) ^ 0x10) & 0x8000) != 0;
    }
    r->a = (a_hi3 << 8) | a;
    r->y = (uint8_t)y;
    r->c = carry1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0CAC6, SOM_RTS, "gen", advance_map_tile_row_coordinates, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 57, 29)

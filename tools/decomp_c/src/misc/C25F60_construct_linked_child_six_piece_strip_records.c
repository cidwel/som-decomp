#include "som_c.h"

/* C25F60 construct_linked_child_six_piece_strip_records   [class B, 128 bytes, 65 instructions]
 * Source: src/rom/construct_linked_child_six_piece_strip_records.s
 * Documented in docs/boss-native-linked-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void construct_linked_child_six_piece_strip_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value2 = RAM16(0x007A + RAM16(0x0287));
    RAM16_SET(0x0206, (uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1));
    uint16_t value3 = RAM16(0x0289);
    RAM16_SET(0x0000 + value3, 6);
    RAM16_SET(0x0000 + (uint16_t)(value3 + 1), 0xF7F8);
    RAM16_SET(0x0002 + (uint16_t)(value3 + 1), 0x1AA0);
    RAM16_SET(0x0208, 3);
    uint8_t a_hi1 = 0;
    uint16_t x1 = (uint16_t)(value3 + 5);
    do {
        RAM16_SET(0x0204, (uint16_t)(RAM16(0x00B6 + RAM16(0x0287)) << 2));
        uint16_t value6 = RAM16(0x0208);
        uint16_t value7 = RAM16(0x0204);
        uint16_t value8 = RAM16(0x0206);
        RAM8(0x0000 + x1) = (uint8_t)(RAM8(0xF501 + (uint16_t)((uint16_t)(((((uint8_t)value6 << 8) | (value6 >> 8)) >> 2) + value7) + value8 + (((((uint8_t)value6 << 8) | (value6 >> 8)) >> 2) + value7 > 0xFFFF))) - 8);
        RAM8(0x0001 + x1) = (uint8_t)(RAM8(0xF503 + (uint16_t)((uint16_t)(((((uint8_t)value6 << 8) | (value6 >> 8)) >> 2) + value7) + value8 + (((((uint8_t)value6 << 8) | (value6 >> 8)) >> 2) + value7 > 0xFFFF))) - 8);
        RAM16_SET(0x0002 + x1, 0x1AA0);
        RAM16_SET(0x0208, (uint16_t)(RAM16(0x0208) - 1));
        a_hi1 = 0x1A;
        x1 = (uint16_t)(x1 + 4);
    } while (!(RAM16(0x0208) & 0x8000));
    uint16_t value11 = RAM16(0x0287);
    RAM8(0x0000 + x1) = (uint8_t)(RAM8(0x00B9 + value11) - 0x10);
    uint8_t value13 = RAM8(0x00BB + value11);
    RAM8(0x0001 + x1) = (uint8_t)(value13 - 0x10);
    uint16_t value14 = RAM16(0x00B4 + value11);
    RAM16_SET(0x0002 + x1, value14);
    uint16_t value15 = RAM16(0x0287);
    r->a = value14;
    r->x = value15;
    r->y = value11;
    r->c = value13 >= 0x10;
    r->v = ((value13 ^ 0x10) & (value13 ^ (uint8_t)(value13 - 0x10)) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25F60, SOM_RTS, "gen", construct_linked_child_six_piece_strip_records, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 128, 65)

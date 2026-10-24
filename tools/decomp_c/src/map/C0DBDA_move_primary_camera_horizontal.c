#include "som_c.h"

/* C0DBDA move_primary_camera_horizontal   [class B, 62 bytes, 33 instructions]
 * Source: src/rom/move_primary_camera_horizontal.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void move_primary_camera_horizontal(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x0084);
    if (value & 0x80) {
        RAM16_SET(0x0000, ((a_hi << 8) | value) & 0x7F);
        uint16_t value2 = RAM16(0x00B0);
        uint16_t value3 = RAM16(0x0000);
        RAM16_SET(0x00B0, (uint16_t)(value2 - value3) & 0x01FF);
        uint16_t value4 = RAM16(0x00A8);
        uint8_t a1;
        uint8_t a_hi1;
        bool carry1;
        bool overflow1;
        if (value4 >= value3) {
            a1 = (uint8_t)(value4 - value3);
            a_hi1 = (uint16_t)(value4 - value3) >> 8;
            carry1 = value4 >= value3;
            overflow1 = ((value4 ^ value3) & (value4 ^ (uint16_t)(value4 - value3)) & 0x8000) != 0;
        } else {
            uint16_t value5 = RAM16(0x00C0);
            a1 = (uint8_t)((uint16_t)(value4 - value3) + value5 + (value4 >= value3));
            a_hi1 = (uint16_t)((uint16_t)(value4 - value3) + value5 + (value4 >= value3)) >> 8;
            carry1 = (uint16_t)(value4 - value3) + value5 + (value4 >= value3) > 0xFFFF;
            overflow1 = (((uint16_t)(value4 - value3) ^ (uint16_t)((uint16_t)(value4 - value3) + value5 + (value4 >= value3))) & (value5 ^ (uint16_t)((uint16_t)(value4 - value3) + value5 + (value4 >= value3))) & 0x8000) != 0;
        }
        RAM16_SET(0x00A8, (a_hi1 << 8) | a1);
        r->a = (a_hi1 << 8) | a1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x00A8);
    uint16_t value7 = RAM16(0x00C0);
    uint8_t a2;
    uint8_t a_hi2;
    if ((uint16_t)((((a_hi << 8) | value) & 0x0F) + value6) < value7) {
        a2 = (uint8_t)((((a_hi << 8) | value) & 0x0F) + value6);
        a_hi2 = (uint16_t)((((a_hi << 8) | value) & 0x0F) + value6) >> 8;
    } else {
        a2 = (uint8_t)((uint16_t)((((a_hi << 8) | value) & 0x0F) + value6) - value7 - ((uint16_t)((((a_hi << 8) | value) & 0x0F) + value6) >= value7 ^ 1));
        a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | value) & 0x0F) + value6) - value7 - ((uint16_t)((((a_hi << 8) | value) & 0x0F) + value6) >= value7 ^ 1)) >> 8;
    }
    RAM16_SET(0x00A8, (a_hi2 << 8) | a2);
    uint16_t value8 = RAM16(0x00B0);
    RAM16_SET(0x00B0, (uint16_t)((((a_hi << 8) | value) & 0x0F) + value8) & 0x01FF);
    r->a = (uint16_t)((((a_hi << 8) | value) & 0x0F) + value8) & 0x01FF;
    r->c = (((a_hi << 8) | value) & 0x0F) + value8 > 0xFFFF;
    r->v = (((((a_hi << 8) | value) & 0x0F) ^ (uint16_t)((((a_hi << 8) | value) & 0x0F) + value8)) & (value8 ^ (uint16_t)((((a_hi << 8) | value) & 0x0F) + value8)) & 0x8000) != 0;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DBDA, SOM_RTS, "gen", move_primary_camera_horizontal, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 62, 33)

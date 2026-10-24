#include "som_c.h"

/* C0DC99 move_secondary_camera_vertical   [class B, 67 bytes, 36 instructions]
 * Source: src/rom/move_secondary_camera_vertical.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void move_secondary_camera_vertical(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x00B9);
    if (value != 0) {
        uint8_t value2 = RAM8(0x0086);
        if (value2 & 0x80) {
            RAM16_SET(0x0000, ((a_hi << 8) | value2) & 0x0F);
            uint16_t value3 = RAM16(0x00B6);
            uint16_t value4 = RAM16(0x0000);
            RAM16_SET(0x00B6, (uint16_t)(value3 - value4) & 0x01FF);
            uint16_t value5 = RAM16(0x00AE);
            uint8_t a1;
            uint8_t a_hi1;
            bool carry1;
            bool zero1;
            bool negative1;
            bool overflow1;
            if (value5 >= value4) {
                a1 = (uint8_t)(value5 - value4);
                a_hi1 = (uint16_t)(value5 - value4) >> 8;
                carry1 = value5 >= value4;
                zero1 = (uint16_t)(value5 - value4) == 0;
                negative1 = (uint16_t)(value5 - value4) & 0x8000;
                overflow1 = ((value5 ^ value4) & (value5 ^ (uint16_t)(value5 - value4)) & 0x8000) != 0;
            } else {
                uint16_t value6 = RAM16(0x00C6);
                a1 = (uint8_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4));
                a_hi1 = (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4)) >> 8;
                carry1 = (uint16_t)(value5 - value4) + value6 + (value5 >= value4) > 0xFFFF;
                zero1 = (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4)) == 0;
                negative1 = (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4)) & 0x8000;
                overflow1 = (((uint16_t)(value5 - value4) ^ (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4))) & (value6 ^ (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4))) & 0x8000) != 0;
            }
            RAM16_SET(0x00AE, (a_hi1 << 8) | a1);
            r->a = (a_hi1 << 8) | a1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value7 = RAM16(0x00AE);
        uint16_t value8 = RAM16(0x00C6);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) < value8) {
            a2 = (uint8_t)((((a_hi << 8) | value2) & 0x0F) + value7);
            a_hi2 = (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) - value8 - ((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) >= value8 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) - value8 - ((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) >= value8 ^ 1)) >> 8;
        }
        RAM16_SET(0x00AE, (a_hi2 << 8) | a2);
        uint16_t value9 = RAM16(0x00B6);
        RAM16_SET(0x00B6, (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9) & 0x01FF);
        r->a = (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9) & 0x01FF;
        r->c = (((a_hi << 8) | value2) & 0x0F) + value9 > 0xFFFF;
        r->z = ((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9) & 0x01FF) == 0;
        r->n = (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9) & 0x01FF & 0x8000;
        r->v = (((((a_hi << 8) | value2) & 0x0F) ^ (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9)) & (value9 ^ (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9)) & 0x8000) != 0;
        r->mf = 0;
        RETURN_RTS(c);
    }
    SET_A8(r, value);
    r->z = value == 0;
    r->n = value & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DC99, SOM_RTS, "gen", move_secondary_camera_vertical, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 1, 67, 36)

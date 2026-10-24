#include "som_c.h"

/* C0DC56 move_secondary_camera_horizontal   [class B, 67 bytes, 36 instructions]
 * Source: src/rom/move_secondary_camera_horizontal.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void move_secondary_camera_horizontal(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    if (RAM8(0x00B9) != 0) {
        uint8_t value2 = RAM8(0x0084);
        if (value2 & 0x80) {
            RAM16_SET(0x0000, ((a_hi << 8) | value2) & 0x0F);
            uint16_t value3 = RAM16(0x00B4);
            uint16_t value4 = RAM16(0x0000);
            RAM16_SET(0x00B4, (uint16_t)(value3 - value4) & 0x01FF);
            uint16_t value5 = RAM16(0x00AC);
            uint8_t a1;
            uint8_t a_hi1;
            bool carry1;
            bool overflow1;
            if (value5 >= value4) {
                a1 = (uint8_t)(value5 - value4);
                a_hi1 = (uint16_t)(value5 - value4) >> 8;
                carry1 = value5 >= value4;
                overflow1 = ((value5 ^ value4) & (value5 ^ (uint16_t)(value5 - value4)) & 0x8000) != 0;
            } else {
                uint16_t value6 = RAM16(0x00C4);
                a1 = (uint8_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4));
                a_hi1 = (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4)) >> 8;
                carry1 = (uint16_t)(value5 - value4) + value6 + (value5 >= value4) > 0xFFFF;
                overflow1 = (((uint16_t)(value5 - value4) ^ (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4))) & (value6 ^ (uint16_t)((uint16_t)(value5 - value4) + value6 + (value5 >= value4))) & 0x8000) != 0;
            }
            RAM16_SET(0x00AC, (a_hi1 << 8) | a1);
            r->a = (a_hi1 << 8) | a1;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 0;
            RETURN_RTS(c);
        }
        uint16_t value7 = RAM16(0x00AC);
        uint16_t value8 = RAM16(0x00C4);
        uint8_t a2;
        uint8_t a_hi2;
        if ((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) < value8) {
            a2 = (uint8_t)((((a_hi << 8) | value2) & 0x0F) + value7);
            a_hi2 = (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) >> 8;
        } else {
            a2 = (uint8_t)((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) - value8 - ((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) >= value8 ^ 1));
            a_hi2 = (uint16_t)((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) - value8 - ((uint16_t)((((a_hi << 8) | value2) & 0x0F) + value7) >= value8 ^ 1)) >> 8;
        }
        RAM16_SET(0x00AC, (a_hi2 << 8) | a2);
        uint16_t value9 = RAM16(0x00B4);
        RAM16_SET(0x00B4, (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9) & 0x01FF);
        r->a = (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9) & 0x01FF;
        r->c = (((a_hi << 8) | value2) & 0x0F) + value9 > 0xFFFF;
        r->v = (((((a_hi << 8) | value2) & 0x0F) ^ (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9)) & (value9 ^ (uint16_t)((((a_hi << 8) | value2) & 0x0F) + value9)) & 0x8000) != 0;
        r->mf = 0;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DC56, SOM_RTS, "gen", move_secondary_camera_horizontal, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 67, 36)

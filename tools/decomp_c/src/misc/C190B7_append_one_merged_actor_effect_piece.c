#include "som_c.h"

/* C190B7 append_one_merged_actor_effect_piece   [class B, 79 bytes, 40 instructions]
 * Source: src/rom/append_one_merged_actor_effect_piece.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void append_one_merged_actor_effect_piece(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    if (RAM8(0xE114 + y) != 0) {
        RETURN_RTS(c);
    }
    if (RAM8(0xE110 + y) == 3) {
        if (RAM8(0xE113 + y) >= 0x50) {
            RETURN_RTS(c);
        }
        uint8_t a2;
        bool overflow2;
        if ((uint8_t)y == 0) {
            uint8_t value4 = RAM8(0xC001 + x);
            a2 = (uint8_t)(value4 - 8);
            overflow2 = ((value4 ^ 8) & (value4 ^ (uint8_t)(value4 - 8)) & 0x80) != 0;
        } else {
            uint8_t a1;
            bool overflow1;
            if ((uint8_t)y == 0x10) {
                RAM8(0xC000 + x) = (uint8_t)(RAM8(0xC000 + x) + 8);
                uint8_t value6 = RAM8(0xC001 + x);
                a1 = (uint8_t)(value6 + 5);
                overflow1 = ((value6 ^ (uint8_t)(value6 + 5)) & ((uint8_t)(value6 + 5) ^ 5) & 0x80) != 0;
            } else {
                RAM8(0xC000 + x) = (uint8_t)(RAM8(0xC000 + x) - 8);
                uint8_t value8 = RAM8(0xC001 + x);
                a1 = (uint8_t)(value8 + 8);
                overflow1 = ((value8 ^ (uint8_t)(value8 + 8)) & ((uint8_t)(value8 + 8) ^ 8) & 0x80) != 0;
            }
            a2 = a1;
            overflow2 = overflow1;
        }
        RAM8(0xC001 + x) = a2;
        RAM8(0x0002)++;
        r->x = (uint16_t)(x + 4);
        r->v = overflow2;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC190B7, SOM_RTS, "gen", append_one_merged_actor_effect_piece, 0, L_X | L_Y | L_V, 1, 1, 0, 79, 40)

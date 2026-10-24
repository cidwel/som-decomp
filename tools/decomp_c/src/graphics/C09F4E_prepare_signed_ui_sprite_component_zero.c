#include "som_c.h"

/* C09F4E prepare_signed_ui_sprite_component_zero   [class C, 276 bytes, 133 instructions]
 * Source: src/rom/prepare_signed_ui_sprite_component_zero.s
 * Documented in docs/ui-native-ui-frame-sprites.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void prepare_signed_ui_sprite_component_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0x005F);
    uint8_t a_hi1;
    if (value != 4) {
        a_hi1 = 0xE0;
    } else {
        a_hi1 = 8;
    }
    RAM16_SET(0x0008, (a_hi1 << 8) | 0xF8);
    uint16_t value3 = BUS16(c, 0x00A2BE + RAM8(0x0010));
    uint8_t a1 = (uint8_t)value3;
    uint8_t a_hi2 = value3 >> 8;
    uint8_t y1 = 0;
    for (;;) {
        RAM16_SET(0x0000, (a_hi2 << 8) | a1);
        uint8_t value5 = BUS8(c, 0x00A072 + RAM8(0x0A40 + y1));
        uint8_t value6 = RAM8(0x005F);
        uint8_t a4;
        uint8_t x1;
        if (value6 == 4) {
            a4 = value5;
            x1 = value6;
        } else {
            uint8_t value7 = RAM8(0x007A);
            uint8_t a3;
            if (value7 == 0) {
                a3 = value5;
            } else {
                uint8_t a2;
                if (!(value7 & 0x80)) {
                    a2 = value5;
                } else {
                    a2 = (uint8_t)((value5 ^ 0xFF) + 1);
                }
                a3 = a2;
            }
            a4 = a3;
            x1 = value7;
        }
        RAM8(0x0008) = (uint8_t)((uint8_t)(a4 + RAM8(0x0A46 + y1)) + RAM8(0x0008));
        uint8_t value10 = RAM8(0x0009);
        RAM8(0x0009) = (uint8_t)(value10 + 0x70);
        r->a = (a_hi2 << 8) | (uint8_t)(value10 + 0x70);
        r->x = x1;
        r->y = y1;
        r->c = 0;
        r->v = (((uint8_t)(value10 + 0x70) ^ 0x70) & (value10 ^ (uint8_t)(value10 + 0x70)) & 0x80) != 0;
        TAIL_CALL(c, 0xC09C2B, SOM_RTS); /* emit_ui_sprite_tile_grid */
    }
}
SOM_REGISTER(0xC09F4E, SOM_RTS, "gen", prepare_signed_ui_sprite_component_zero, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 276, 133)

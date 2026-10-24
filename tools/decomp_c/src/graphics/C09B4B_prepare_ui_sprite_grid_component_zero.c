#include "som_c.h"

/* C09B4B prepare_ui_sprite_grid_component_zero   [class C, 208 bytes, 100 instructions]
 * Source: src/rom/prepare_ui_sprite_grid_component_zero.s
 * Documented in docs/ui-native-ui-frame-sprites.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void prepare_ui_sprite_grid_component_zero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x0008, 0xF0F4);
    uint16_t value2 = BUS16(c, 0x00A082 + RAM8(0x0010));
    uint8_t a1 = (uint8_t)value2;
    uint8_t a_hi1 = value2 >> 8;
    uint8_t y1 = 0;
    for (;;) {
        RAM16_SET(0x0000, (a_hi1 << 8) | a1);
        uint8_t value4 = BUS8(c, 0x009CD9 + RAM8(0x0A40 + y1));
        RAM8(0x0009) = (uint8_t)((uint8_t)((uint8_t)(value4 + 0x50) - RAM8(0x00CF)) + RAM8(0x0009));
        uint8_t value7 = RAM8(0x0A46 + y1);
        uint8_t value8 = RAM8(0x005F);
        uint8_t a2;
        if (value8 != 4) {
            a2 = value7;
        } else {
            a2 = (uint8_t)((((uint8_t)(value7 - 0x80) >> 1) | (((uint8_t)(value7 - 0x80) >= 0x80) << 7)) + 0x80);
        }
        uint8_t value9 = RAM8(0x0008);
        RAM8(0x0008) = (uint8_t)(a2 + value9);
        RAM8(0x0012) = 0;
        r->a = (a_hi1 << 8) | (uint8_t)(a2 + value9);
        r->x = value8;
        r->y = y1;
        r->c = a2 + value9 > 0xFF;
        r->v = ((a2 ^ (uint8_t)(a2 + value9)) & (value9 ^ (uint8_t)(a2 + value9)) & 0x80) != 0;
        TAIL_CALL(c, 0xC09C2B, SOM_RTS); /* emit_ui_sprite_tile_grid */
    }
}
SOM_REGISTER(0xC09B4B, SOM_RTS, "gen", prepare_ui_sprite_grid_component_zero, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 208, 100)

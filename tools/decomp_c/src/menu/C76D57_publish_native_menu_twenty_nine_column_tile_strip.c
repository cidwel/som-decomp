#include "som_c.h"

/* C76D57 publish_native_menu_twenty_nine_column_tile_strip   [class B, 52 bytes, 25 instructions]
 * Source: src/rom/publish_native_menu_twenty_nine_column_tile_strip.s
 * Documented in docs/event-menu-page-sprites.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void publish_native_menu_twenty_nine_column_tile_strip(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA171, 0x1D);
    uint8_t a1 = 0x90;
    uint8_t a_hi1 = 0x20;
    uint16_t x1 = 0x42;
    do {
        RAM16_SET(0x9000 + x1, (a_hi1 << 8) | a1);
        RAM16_SET(0x9040 + x1, (uint16_t)(((a_hi1 << 8) | a1) + 2));
        RAM16_SET(0xA171, (uint16_t)(RAM16(0xA171) - 1));
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + 4);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 2);
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
    } while (RAM16(0xA171) != 0);
    RAM16_SET(0x9000 + x1, 0);
    RAM16_SET(0x9040 + x1, 0);
    RAM8(0xA20A) |= 2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76D57, SOM_RTL, "gen", publish_native_menu_twenty_nine_column_tile_strip, 0, 0, 2, 1, 0, 52, 25)

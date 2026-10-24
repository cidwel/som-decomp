#include "som_c.h"

/* C025C8 select_rom_source_for_native_menu_tile_dma   [class D, 47 bytes, 17 instructions]
 * Source: src/rom/select_rom_source_for_native_menu_tile_dma.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void select_rom_source_for_native_menu_tile_dma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS8_SET(c, 0x004374, 0xC7);
    BUS16_SET(c, 0x004375, RAM16(0xA191));
    uint16_t value2 = RAM16(0xA194);
    BUS16_SET(c, 0x004372, value2);
    BUS8_SET(c, 0x004370, 1);
    BUS8_SET(c, 0x004371, 0x18);
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = (value2 >> 8 << 8) | 0x80;
    r->z = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC025C8, SOM_RTS, "gen", select_rom_source_for_native_menu_tile_dma, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 47, 17)

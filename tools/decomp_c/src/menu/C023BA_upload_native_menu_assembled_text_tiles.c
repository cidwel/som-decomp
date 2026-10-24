#include "som_c.h"

/* C023BA upload_native_menu_assembled_text_tiles   [class D, 21 bytes, 8 instructions]
 * Source: src/rom/upload_native_menu_assembled_text_tiles.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void upload_native_menu_assembled_text_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x002116, RAM16(0xA18C));
    RAM16_SET(0xA194, 0x9400);
    JSR(c, 0x23CD, 0xC025CC); /* select_wram_source_for_native_menu_tile_dma */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC023BA, SOM_RTS, "gen", upload_native_menu_assembled_text_tiles, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 21, 8)

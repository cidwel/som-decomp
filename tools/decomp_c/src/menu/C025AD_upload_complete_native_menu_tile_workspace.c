#include "som_c.h"

/* C025AD upload_complete_native_menu_tile_workspace   [class D, 27 bytes, 10 instructions]
 * Source: src/rom/upload_complete_native_menu_tile_workspace.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void upload_complete_native_menu_tile_workspace(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    BUS16_SET(c, 0x002116, 0x5800);
    RAM16_SET(0xA191, 0x0800);
    RAM16_SET(0xA194, 0x9000);
    r->mf = 1;
    JSR(c, 0x25C6, 0xC025CC); /* select_wram_source_for_native_menu_tile_dma */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC025AD, SOM_RTS, "gen", upload_complete_native_menu_tile_workspace, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, -1, 0, 27, 10)

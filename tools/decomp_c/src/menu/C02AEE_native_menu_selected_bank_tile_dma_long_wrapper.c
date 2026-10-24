#include "som_c.h"

/* C02AEE native_menu_selected_bank_tile_dma_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/native_menu_selected_bank_tile_dma_long_wrapper.s
 * Documented in docs/event-menu-page-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void native_menu_selected_bank_tile_dma_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x2AF0, 0xC025CE); /* transfer_native_menu_tiles_from_selected_bank */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02AEE, SOM_RTL, "gen", native_menu_selected_bank_tile_dma_long_wrapper, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 4, 2)

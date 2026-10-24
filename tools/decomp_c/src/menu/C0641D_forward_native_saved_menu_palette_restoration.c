#include "som_c.h"

/* C0641D forward_native_saved_menu_palette_restoration   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_saved_menu_palette_restoration.s
 * Documented in docs/event-menu-state-api.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void forward_native_saved_menu_palette_restoration(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC06474, SOM_RTL); /* restore_existing_native_menu_palette_with_saved_context */
}
SOM_REGISTER(0xC0641D, SOM_RTL, "gen", forward_native_saved_menu_palette_restoration, 0, 0, 1, 1, 0, 3, 1)

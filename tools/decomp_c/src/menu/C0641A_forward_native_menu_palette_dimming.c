#include "som_c.h"

/* C0641A forward_native_menu_palette_dimming   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_menu_palette_dimming.s
 * Documented in docs/event-menu-state-api.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: nothing.
 */
static void forward_native_menu_palette_dimming(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    TAIL_CALL(c, 0xC06460, SOM_RTL); /* dim_existing_native_menu_palette_with_saved_context */
}
SOM_REGISTER(0xC0641A, SOM_RTL, "gen", forward_native_menu_palette_dimming, 0, 0, 1, 1, 0, 3, 1)

#include "som_c.h"

/* C0642E call_native_one_tile_menu_icon_conversion_long   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/call_native_one_tile_menu_icon_conversion_long.s
 * Documented in docs/event-menu-single-icon.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void call_native_one_tile_menu_icon_conversion_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x6431, 0xD0CA10); GUARD_JSL(c, sp_call, 0x6431); } /* convert_one_original_three_plane_menu_tile_to_output_with_saved_context */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0642E, SOM_RTL, "gen", call_native_one_tile_menu_icon_conversion_long, 0, 0, 1, 1, 0, 5, 2)

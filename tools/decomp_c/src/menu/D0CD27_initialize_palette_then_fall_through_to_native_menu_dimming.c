#include "som_c.h"

/* D0CD27 initialize_palette_then_fall_through_to_native_menu_dimming   [class B, 14 bytes, 5 instructions]
 * Source: src/rom/initialize_palette_then_fall_through_to_native_menu_dimming.s
 * Documented in docs/event-menu-vblank.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_palette_then_fall_through_to_native_menu_dimming(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD29, 0xD0CD8E); GUARD_JSR(c, sp_call, 0xCD29); } /* initialize_menu_actor_palette_or_default_palette */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD2C, 0xD0CD35); GUARD_JSR(c, sp_call, 0xCD2C); } /* dim_menu_palette_preserving_first_actor_row_when_requested */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD2F, 0xD0CDA9); GUARD_JSR(c, sp_call, 0xCD2F); } /* request_menu_palette_upload */
    { const uint16_t sp_call = r->sp; JSL(c, 0xCD33, 0xC0693F); GUARD_JSL(c, sp_call, 0xCD33); } /* wait_menu_vblank_through_native_long_wrapper */
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0CD27, SOM_RTL, "gen", initialize_palette_then_fall_through_to_native_menu_dimming, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 14, 5)

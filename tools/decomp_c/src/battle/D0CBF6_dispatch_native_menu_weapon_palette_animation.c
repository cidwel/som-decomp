#include "som_c.h"

/* D0CBF6 dispatch_native_menu_weapon_palette_animation   [class B, 27 bytes, 12 instructions]
 * Source: src/rom/dispatch_native_menu_weapon_palette_animation.s
 * Documented in docs/event-menu-ring-palette.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void dispatch_native_menu_weapon_palette_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if ((uint16_t)((RAM16(RING_CATEGORY) & 0xFF) - 1) != 0) {
        RETURN_RTL(c);
    }
    if ((RAM16(0x1803) & 0x80) == 0) {
        JSR(c, 0xCC0F, 0xD0CC11); /* cycle_native_weapon_palette_every_third_menu_frame */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTL(c);
    }
    JSR(c, 0xCC0B, 0xD0CC79); /* rotate_native_packed_equipment_palettes_and_blink_rows */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0CBF6, SOM_RTL, "gen", dispatch_native_menu_weapon_palette_animation, 0, 0, 1, 0, 0, 27, 12)

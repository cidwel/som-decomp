#include "som_c.h"

/* C01EFD highlight_native_menu_actor_sprite_palette   [class A, 27 bytes, 15 instructions]
 * Source: src/rom/highlight_native_menu_actor_sprite_palette.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void highlight_native_menu_actor_sprite_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    r->a = a_hi;
    JSR(c, 0x1F02, 0xC01F18); /* select_native_menu_actor_sprite_span */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x_ret;
    uint16_t y1 = y_ret;
    for (;;) {
        RAM8(0x9C03 + x1) |= 0x30;
        x1 = (uint16_t)(x1 + 4);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    RAM8(0xA20A) |= 4;
    r->a = (a_hi1 << 8) | 4;
    r->x = x1;
    r->y = y1;
    r->c = carry_ret;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01EFD, SOM_RTS, "gen", highlight_native_menu_actor_sprite_palette, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 27, 15)

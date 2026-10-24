#include "som_c.h"

/* C029A5 render_native_selected_actor_page_caption   [class B, 45 bytes, 17 instructions]
 * Source: src/rom/render_native_selected_actor_page_caption.s
 * Documented in docs/ui-native-spell-item-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void render_native_selected_actor_page_caption(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x9C00) = 0x57;
    RAM8(0x9C01) = RAM8(0x19FE);
    RAM16_SET(0xA18C, 0x6360);
    RAM16_SET(0xA191, 0x0180);
    RAM16_SET(0xA199, 0xC0);
    RAM8(0xA171) = 1;
    r->a = (a_hi << 8) | 1;
    r->x = 2;
    r->z = 0;
    JSL(c, 0x29D0, 0xC75D96); /* long_call_native_rendered_text_row_publication */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC029A5, SOM_RTL, "gen", render_native_selected_actor_page_caption, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 45, 17)

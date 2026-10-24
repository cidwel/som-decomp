#include "som_c.h"

/* C09D67 copy_selected_scene_color_targets_to_current_values   [class A, 17 bytes, 8 instructions]
 * Source: src/rom/copy_selected_scene_color_targets_to_current_values.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void copy_selected_scene_color_targets_to_current_values(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    JSR(c, 0x9D69, 0xC09D78); /* select_scene_color_targets_from_cursor_and_fade_flags */
    uint16_t a_all = r->a;
    uint8_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t a_hi1 = a_all >> 8;
    uint8_t x1 = 5;
    for (;;) {
        RAM8(0x0A46 + x1) = RAM8(0x0A4C + x1);
        x1 = (uint8_t)(x1 - 1);
        if (!(!(x1 & 0x80))) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y_ret;
    r->c = carry_ret;
    r->v = overflow_ret;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09D67, SOM_RTS, "gen", copy_selected_scene_color_targets_to_current_values, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 17, 8)

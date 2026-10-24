#include "som_c.h"

/* C09CEF initialize_scene_object_cursor_control_words   [class A, 27 bytes, 13 instructions]
 * Source: src/rom/initialize_scene_object_cursor_control_words.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BCV.
 */
static void initialize_scene_object_cursor_control_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x9CF1, 0xC09CAB); /* clear_scene_oam_and_initialize_color_targets */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t a_hi1 = a_all >> 8;
    uint8_t x1 = 0;
    bool carry1 = carry_ret;
    for (;;) {
        uint16_t value = BUS16(c, 0x009CE9 + x1);
        RAM16_SET(0x0A40 + x1, value);
        uint8_t a_hi1_next = value >> 8;
        uint8_t x1_next = (uint8_t)(x1 + 2);
        bool carry1_next = (uint8_t)(x1 + 2) >= 6;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        carry1 = carry1_next;
        if (!(x1 < 6)) break;
    }
    RAM16_SET(0x007A, 0);
    r->a = 0;
    r->c = carry1;
    r->v = overflow_ret;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09CEF, SOM_RTS, "gen", initialize_scene_object_cursor_control_words, 0, L_B | L_C | L_V, 1, 1, 1, 27, 13)

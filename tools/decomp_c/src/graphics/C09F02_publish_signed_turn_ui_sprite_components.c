#include "som_c.h"

/* C09F02 publish_signed_turn_ui_sprite_components   [class B, 76 bytes, 35 instructions]
 * Source: src/rom/publish_signed_turn_ui_sprite_components.s
 * Documented in docs/ui-native-ui-frame-sprites.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void publish_signed_turn_ui_sprite_components(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x0012) = 0;
    uint8_t value = RAM8(0x005F);
    uint8_t a4;
    if ((value & 4) == 0) {
        uint8_t value2 = RAM8(0x007A);
        uint8_t a3;
        if (value2 == 0) {
            a3 = 0;
        } else {
            uint8_t a2;
            if (!(value2 & 0x80)) {
                RAM8(0x0012) = 1;
                a2 = 4;
            } else {
                uint8_t a1;
                if (value2 & 0x80) {
                    RAM8(0x0012) = 0xFF;
                    a1 = 2;
                } else {
                    a1 = 0;
                }
                a2 = a1;
            }
            a3 = a2;
        }
        a4 = a3;
    } else {
        a4 = 6;
    }
    RAM8(0x0010) = a4;
    if (RAM8(0x00F4) & 0x01) {
        JSR(c, 0x9F43, 0xC09FA6); /* prepare_signed_ui_sprite_component_one */
        r->mf = 1;
        r->xf = 1;
        JSR(c, 0x9F46, 0xC09F4E); /* prepare_signed_ui_sprite_component_zero */
        r->mf = 1;
        r->xf = 1;
        TAIL_CALL(c, 0xC09DE9, SOM_RTS); /* hide_unused_ui_sprite_slots */
    }
    RAM8(0x007C) = 0;
    RAM8(RING_OPEN) = 0;
    JSR(c, 0x9F37, 0xC0A02C); /* prepare_signed_ui_sprite_component_five */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x9F3A, 0xC09F81); /* prepare_signed_ui_sprite_component_four */
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x9F3D, 0xC09F68); /* prepare_signed_ui_sprite_component_three */
    r->mf = 1;
    r->xf = 1;
    TAIL_CALL(c, 0xC09FD3, SOM_RTS); /* prepare_signed_ui_sprite_component_two */
}
SOM_REGISTER(0xC09F02, SOM_RTS, "gen", publish_signed_turn_ui_sprite_components, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 76, 35)

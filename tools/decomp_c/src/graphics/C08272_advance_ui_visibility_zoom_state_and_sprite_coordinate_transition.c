#include "som_c.h"

/* C08272 advance_ui_visibility_zoom_state_and_sprite_coordinate_transition   [class D, 82 bytes, 46 instructions]
 * Source: src/rom/advance_ui_visibility_zoom_state_and_sprite_coordinate_transition.s
 * Documented in docs/ui-native-ui-frame-lifecycle.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYC.
 */
static void advance_ui_visibility_zoom_state_and_sprite_coordinate_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x00F2);
    if ((value & 3) != 0) {
        if (value & 3 & 0x01) {
            uint8_t value2 = RAM8(0x0051);
            if (value2 >= 2) {
                RAM8(0x0051) = (uint8_t)(value2 - 2);
                r->x = (uint8_t)x;
                r->y = (uint8_t)y;
                r->c = value2 >= 2;
                r->xf = 1;
                RETURN_RTS(c);
            }
            RAM8(0x00F2) = value ^ 0x83;
            if ((value ^ 0x83) & RAM8(0x00BE) & 0x80) {
                RAM8(0x00BE) &= 0x7F;
            }
            r->y = (uint8_t)y;
            r->c = value2 >= 2;
            r->v = ((value2 ^ 2) & (value2 ^ (uint8_t)(value2 - 2)) & 0x80) != 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82C2, 0xC09D67); GUARD_JSR(c, sp_call, 0x82C2); } /* copy_selected_scene_color_targets_to_current_values */
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value5 = RAM8(0x0051);
        if ((uint8_t)(value5 + 1) < 0x10) {
            RAM8(0x0051) = (uint8_t)(value5 + 1);
            r->x = (uint8_t)x;
            r->y = (uint8_t)y;
            r->c = (uint8_t)(value5 + 1) >= 0x10;
            r->xf = 1;
            RETURN_RTS(c);
        }
        RAM8(0x00F2) = value ^ 2;
        BUS8_SET(c, 0x002106, 0);
        r->x = (uint8_t)x;
        r->y = (uint8_t)y;
        r->c = (uint8_t)(value5 + 1) >= 0x10;
        r->xf = 1;
        RETURN_RTS(c);
    }
    uint8_t value6 = RAM8(0x00F8);
    RAM8(0x0000) = ((uint8_t)(value6 + 0x1F) ^ 0xFF) >> 3;
    uint8_t value7 = RAM8(0x0000);
    RAM8(0x0F04) = (uint8_t)((uint8_t)((((uint8_t)(value6 + 0x1F) ^ 0xFF) >> 4) + value7) + 8 + ((((uint8_t)(value6 + 0x1F) ^ 0xFF) >> 4) + value7 > 0xFF));
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->c = (uint8_t)((((uint8_t)(value6 + 0x1F) ^ 0xFF) >> 4) + value7) + 8 + ((((uint8_t)(value6 + 0x1F) ^ 0xFF) >> 4) + value7 > 0xFF) > 0xFF;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08272, SOM_RTS, "gen", advance_ui_visibility_zoom_state_and_sprite_coordinate_transition, 0, L_B | L_X | L_Y | L_C, 1, 1, 0, 82, 46)

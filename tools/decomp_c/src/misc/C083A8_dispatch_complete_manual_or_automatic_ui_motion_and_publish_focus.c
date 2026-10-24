#include "som_c.h"

/* C083A8 dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus   [class B, 63 bytes, 29 instructions]
 * Source: src/rom/dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus.s
 * Documented in docs/ui-native-ui-frame-motion-chain.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    if (RAM8(0x008C) == 0) {
        uint8_t value2 = RAM8(0x00FE);
        uint8_t value3 = RAM8(0x00BF);
        if (((value2 & 0xC0) | value3) == 0) {
            r->a = (a_hi << 8) | ((value2 & 0xC0) | value3);
            JSR(c, 0x83BE, 0xC08598); /* advance_complete_ui_scale_input_and_boundary_transitions */
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0x83C1, 0xC083E7); /* advance_ui_horizontal_rotation_and_attribute_windows */
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0x83C4, 0xC08638); /* advance_ui_coordinates_and_request_changed_tile_edges */
            r->mf = 0;
            r->xf = 1;
            JSR(c, 0x83C7, 0xC08779); /* consume_ui_scene_buttons_and_restart_after_world_map_picker */
            r->mf = 0; /* rep */
            uint16_t x_ret4 = r->x;
            uint16_t y_ret4 = r->y;
            RAM16_SET(0x003A, RAM16(0x003E));
            RAM16_SET(0x003E, (uint16_t)((RAM16(0x00FA) & 0x03FF) - 0x80));
            uint16_t value6 = RAM16(0x00FC);
            RAM16_SET(0x0040, (uint16_t)((value6 & 0x03FF) - 0x70));
            r->a = (uint16_t)((value6 & 0x03FF) - 0x70);
            r->x = (uint8_t)x_ret4;
            r->y = (uint8_t)y_ret4;
            r->c = (value6 & 0x03FF) >= 0x70;
            r->v = (((value6 & 0x03FF) ^ 0x70) & ((value6 & 0x03FF) ^ (uint16_t)((value6 & 0x03FF) - 0x70)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        SET_A8(r, (value2 & 0xC0) | value3);
        RETURN_RTS(c);
    }
    JSR(c, 0x83B0, 0xC08C78); /* advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition */
    RAM16_SET(0x003A, RAM16(0x003E));
    RAM16_SET(0x003E, (uint16_t)((RAM16(0x00FA) & 0x03FF) - 0x80));
    uint16_t value9 = RAM16(0x00FC);
    RAM16_SET(0x0040, (uint16_t)((value9 & 0x03FF) - 0x70));
    r->a = (uint16_t)((value9 & 0x03FF) - 0x70);
    r->x &= 0xFF; /* SEP #$10 in calculate_scene_camera_centers clears the index high bytes */
    r->y &= 0xFF;
    r->c = (value9 & 0x03FF) >= 0x70;
    r->v = (((value9 & 0x03FF) ^ 0x70) & ((value9 & 0x03FF) ^ (uint16_t)((value9 & 0x03FF) - 0x70)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC083A8, SOM_RTS, "hand", dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 63, 29)

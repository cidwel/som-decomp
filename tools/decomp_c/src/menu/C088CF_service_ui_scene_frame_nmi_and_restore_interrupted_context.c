#include "som_c.h"

/* C088CF service_ui_scene_frame_nmi_and_restore_interrupted_context   [class D, 60 bytes, 33 instructions]
 * Source: src/rom/service_ui_scene_frame_nmi_and_restore_interrupted_context.s
 * Documented in docs/ui-native-scene-interrupts.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void service_ui_scene_frame_nmi_and_restore_interrupted_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    RAM8(0x0000 + sp0) = a_hi;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = x;
    RAM8(0x0000 + sp0 - 4) = 0;
    RAM8(0x0000 + sp0 - 5) = y;
    RAM8(0x0000 + sp0 - 6) = 0;
    RAM8(0x0000 + sp0 - 7) = 0;
    RAM8(0x0000 + sp0 - 8) = 0;
    RAM8(0x0000 + sp0 - 9) = 0;
    uint8_t value = BUS8(c, 0x004210);
    BUS16_SET(c, 0x00212E, 0);
    BUS8_SET(c, 0x002100, RAM8(0x00E6));
    RAM16_SET(0x00F4, (uint16_t)(RAM16(0x00F4) + 1));
    r->mf = 0;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x88F2, 0xC0882B); GUARD_JSR(c, sp_call, 0x88F2); } /* upload_scene_oam_and_attribute_frame_buffers */
    r->sp += 9;
    r->mf = 0;
    r->xf = 1;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x88F5, 0xC09840); GUARD_JSR(c, sp_call, 0x88F5); } /* publish_requested_ui_scene_tile_rows */
    r->sp += 9;
    r->xf = 1;
    r->sp -= 9;
    { const uint16_t sp_call = r->sp; JSR(c, 0x88F8, 0xC08A79); GUARD_JSR(c, sp_call, 0x88F8); } /* alternate_ui_scene_palettes_and_configure_window */
    r->sp += 9;
    uint8_t value4 = RAM8(0x00EC);
    if (value4 & 0x01) {
        r->c = value4 & 0x01;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8902, 0xC0890B); GUARD_JSR(c, sp_call, 0x8902); } /* publish_requested_ui_scene_mode_and_scroll_state */
        r->sp += 9;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 8);
    uint8_t value6 = RAM8(0x0000 + sp0 - 7);
    uint8_t value7 = RAM8(0x0000 + sp0 - 6);
    uint8_t value8 = RAM8(0x0000 + sp0 - 5);
    uint8_t value9 = RAM8(0x0000 + sp0 - 4);
    uint8_t value10 = RAM8(0x0000 + sp0 - 3);
    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
    r->a = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
    r->x = (value11 << 8) | value10;
    r->y = (value9 << 8) | value8;
    r->db = value5;
    r->dp = (value7 << 8) | value6;
    RETURN_RTI(c);
}
SOM_REGISTER(0xC088CF, SOM_RTI, "gen", service_ui_scene_frame_nmi_and_restore_interrupted_context, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, 1, 1, 60, 33)

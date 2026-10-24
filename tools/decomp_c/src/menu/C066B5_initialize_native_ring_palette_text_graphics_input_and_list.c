#include "som_c.h"

/* C066B5 initialize_native_ring_palette_text_graphics_input_and_list   [class B, 62 bytes, 22 instructions]
 * Source: src/rom/initialize_native_ring_palette_text_graphics_input_and_list.s
 * Documented in docs/event-menu-ring-lifecycle.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_native_ring_palette_text_graphics_input_and_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x66B8, 0xD0CD27); GUARD_JSL(c, sp_call, 0x66B8); } /* initialize_palette_then_fall_through_to_native_menu_dimming */
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x66BC, 0xD0D576); GUARD_JSL(c, sp_call, 0x66BC); } /* await_prior_dialogue_or_start_native_menu_window_open */
    { const uint16_t sp_call = r->sp; JSL(c, 0x66C0, 0xD0CDF9); GUARD_JSL(c, sp_call, 0x66C0); } /* upload_ten_menu_graphics_blocks_with_dma5 */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x66C3, 0xC0692D); GUARD_JSR(c, sp_call, 0x66C3); } /* request_event_menu_loop_and_initialize_input_state */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x66C6, 0xC06961); GUARD_JSR(c, sp_call, 0x66C6); } /* poll_native_menu_controller_and_publish_input_word */
    uint8_t db_ret3 = r->db;
    uint16_t a_all5 = r->a;
    if (((a_all5 >> 8) & 0x40) != 0) {
        uint8_t value = BUS8_RDP(c, (db_ret3 << 0x10) + 0x1804);
        BUS8_SET(c, (db_ret3 << 0x10) + 0x1804, value | 8);
    }
    BUS16_SET(c, (db_ret3 << 0x10) + 0x1812, 5);
    BUS16_SET(c, (db_ret3 << 0x10) + 0x1814, 0xFFFF);
    BUS16_SET(c, (db_ret3 << 0x10) + 0x1830, 0);
    uint16_t value2 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1870);
    BUS16_SET(c, (db_ret3 << 0x10) + 0x1860, value2);
    uint16_t value3 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1872);
    BUS16_SET(c, (db_ret3 << 0x10) + 0x1862, value3);
    r->a = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xC06F72, SOM_RTS); /* build_native_menu_ring_list_without_initial_category_step */
}
SOM_REGISTER(0xC066B5, SOM_RTS, "gen", initialize_native_ring_palette_text_graphics_input_and_list, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 62, 22)

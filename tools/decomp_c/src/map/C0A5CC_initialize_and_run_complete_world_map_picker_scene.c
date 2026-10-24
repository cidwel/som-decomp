#include "som_c.h"

/* C0A5CC initialize_and_run_complete_world_map_picker_scene   [class C, 73 bytes, 34 instructions]
 * Source: src/rom/initialize_and_run_complete_world_map_picker_scene.s
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void initialize_and_run_complete_world_map_picker_scene(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA5CE, 0xC087C4); GUARD_JSR(c, sp_call, 0xA5CE); } /* blank_display_disable_interrupts_and_clear_windows_for_map_entry */
    uint16_t a_all = r->a;
    RAM8(0x0000 + sp0) = RAM8(0x0100);
    RAM8(0x0000 + sp0 - 1) = RAM8(0x0101);
    uint8_t value3 = RAM8(0x0102);
    RAM8(0x0000 + sp0 - 2) = value3;
    r->a = (a_all >> 8 << 8) | value3;
    r->z = value3 == 0;
    r->n = value3 & 0x80;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA5DF, 0xC0A841); GUARD_JSR(c, sp_call, 0xA5DF); } /* initialize_world_map_picker_background_and_hdma_records */
    r->sp += 3;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xA5E3, 0x02ADEE); GUARD_JSL(c, sp_call, 0xA5E3); } /* initialize_complete_world_map_picker_cursor_resources */
    r->sp += 3;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA5E6, 0xC09985); GUARD_JSR(c, sp_call, 0xA5E6); } /* install_relocated_scene_row_rle_decoder */
    r->sp += 3;
    r->mf = 0;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA5E9, 0xC0AAD2); GUARD_JSR(c, sp_call, 0xA5E9); } /* build_world_map_picker_row_geometry_with_hardware_division */
    r->sp += 3;
    RAM16_SET(0x0008, RAM16(0x00FA) >> 3);
    uint16_t value5 = RAM16(0x00FC);
    RAM16_SET(0x000A, value5 >> 3);
    RAM16_SET(0x001E, 0);
    r->a = value5 >> 3;
    r->c = value5 >> 2 & 0x01;
    r->z = value5 >> 3 == 0;
    r->n = value5 >> 3 & 0x8000;
    r->mf = 0;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA600, 0xC0A638); GUARD_JSR(c, sp_call, 0xA600); } /* install_temporary_world_map_picker_nmi_vector */
    r->sp += 3;
    RAM16_SET(0x000E, 0);
    RAM16_SET(0x000C, 1);
    r->a = 1;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA60E, 0xC0A615); GUARD_JSR(c, sp_call, 0xA60E); } /* clear_world_map_picker_image_and_prepare_matrix */
    r->sp += 3;
    r->mf = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA611, 0xC0AA14); GUARD_JSR(c, sp_call, 0xA611); } /* construct_all_world_map_picker_image_rows */
    r->sp += 3;
    r->mf = 1;
    r->xf = 1;
    TAIL_CALL_FRAME(c, 0xC0A733, SOM_RTS, 3); /* run_world_map_picker_vblank_input_and_redraw_loop */
}
SOM_REGISTER(0xC0A5CC, SOM_RTS, "gen", initialize_and_run_complete_world_map_picker_scene, 0, L_B | L_X | L_Y | L_C | L_V, 3, 1, -1, 73, 34)

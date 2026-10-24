#include "som_c.h"
/* SOM_POLL_HOOK */

/* C0ABB3 initialize_and_run_confirmed_world_map_survey_scene   [class D, 97 bytes, 44 instructions]
 * Source: src/rom/initialize_and_run_confirmed_world_map_survey_scene.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void initialize_and_run_confirmed_world_map_survey_scene(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint8_t a = r->a & 0xFF;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0xABB5, 0xC087C4); GUARD_JSR(c, sp_call, 0xABB5); } /* blank_display_disable_interrupts_and_clear_windows_for_map_entry */
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
    { const uint16_t sp_call = r->sp; JSR(c, 0xABC6, 0xC0AD17); GUARD_JSR(c, sp_call, 0xABC6); } /* initialize_complete_world_map_survey_background_and_color_planes */
    r->sp += 3;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xABCA, 0x02ADEE); GUARD_JSL(c, sp_call, 0xABCA); } /* initialize_complete_world_map_picker_cursor_resources */
    r->sp += 3;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xABCD, 0xC09985); GUARD_JSR(c, sp_call, 0xABCD); } /* install_relocated_scene_row_rle_decoder */
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
    { const uint16_t sp_call = r->sp; JSR(c, 0xABE4, 0xC0AC14); GUARD_JSR(c, sp_call, 0xABE4); } /* install_world_map_survey_temporary_nmi_vector */
    r->sp += 3;
    uint8_t x_ret5 = r->x;
    uint8_t y_ret5 = r->y;
    RAM16_SET(0x000C, 0x0F00);
    RAM16_SET(0x000E, 0);
    uint8_t a_hi1 = 0x0F;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value6 = BUS8(c, 0x004210);
        if (!(!(value6 & 0x80))) break;
    }
    uint8_t a_hi2 = a_hi1;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value7 = BUS8(c, 0x004210);
        if (!(value7 & 0x80)) break;
    }
    BUS8_SET(c, 0x004200, 0x81);
    r->a = (a_hi2 << 8) | 0x81;
    r->x = x_ret5;
    r->y = y_ret5;
    r->c = value5 >> 2 & 0x01;
    r->z = 0;
    r->n = 1;
    r->v = overflow;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAC01, 0xC0AFAE); GUARD_JSR(c, sp_call, 0xAC01); } /* construct_and_save_both_world_map_survey_vram_pages */
    r->sp += 3;
    uint16_t dp_ret = r->dp;
    bool overflow_ret = r->v;
    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x0A));
    bool m_flag;
    uint8_t a_hi3;
    bool carry1;
    bool overflow1;
    if ((value8 & 0x01FE) < 0x0180) {
        m_flag = 0;
        a_hi3 = (value8 & 0x01FE) >> 8;
        carry1 = (value8 & 0x01FE) >= 0x0180;
        overflow1 = overflow_ret;
    } else {
        r->a = value8 & 0x01FE;
        r->c = (value8 & 0x01FE) >= 0x0180;
        r->z = (value8 & 0x01FE) == 0x0180;
        r->n = (uint16_t)((value8 & 0x01FE) - 0x0180) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xAC10, 0xC0ADE3); GUARD_JSR(c, sp_call, 0xAC10); } /* switch_world_map_survey_visible_vram_page_and_scroll */
        r->sp += 3;
        uint16_t a_all7 = r->a;
        bool carry_ret4 = r->c;
        bool overflow_ret2 = r->v;
        m_flag = 1;
        a_hi3 = a_all7 >> 8;
        carry1 = carry_ret4;
        overflow1 = overflow_ret2;
    }
    r->a = (a_hi3 << 8) | a;
    r->c = carry1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = 0;
    TAIL_CALL_FRAME(c, 0xC0AC5E, SOM_RTS, 3); /* run_world_map_survey_input_cancel_and_reentry_loop */
}
SOM_REGISTER(0xC0ABB3, SOM_RTS, "gen", initialize_and_run_confirmed_world_map_survey_scene, 0, L_B | L_X | L_Y | L_C | L_V, 3, 1, 0, 97, 44)

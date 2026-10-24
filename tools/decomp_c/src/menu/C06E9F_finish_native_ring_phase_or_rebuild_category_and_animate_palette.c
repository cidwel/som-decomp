#include "som_c.h"

/* C06E9F finish_native_ring_phase_or_rebuild_category_and_animate_palette   [class B, 74 bytes, 29 instructions]
 * Source: src/rom/finish_native_ring_phase_or_rebuild_category_and_animate_palette.s
 * Documented in docs/event-menu-ring-phase.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void finish_native_ring_phase_or_rebuild_category_and_animate_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if (RAM16(0x180C) == 0) {
        { const uint16_t sp_call = r->sp; JSL(c, 0x6EE7, 0xD0CBF6); GUARD_JSL(c, sp_call, 0x6EE7); } /* dispatch_native_menu_weapon_palette_animation */
        RETURN_RTS(c);
    }
    { const uint16_t sp_call = r->sp; JSL(c, 0x6EA7, 0xC06B4C); GUARD_JSL(c, sp_call, 0x6EA7); } /* persist_native_menu_category_row_and_equipment_rank */
    uint16_t value2 = RAM16(0x1812);
    if (value2 == 3) {
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6EE7, 0xD0CBF6); GUARD_JSL(c, sp_call, 0x6EE7); } /* dispatch_native_menu_weapon_palette_animation */
        RETURN_RTS(c);
    }
    uint16_t value3 = BUS16(c, 0xC00000 + (uint16_t)(value2 + 0x6EE9));
    uint16_t value4 = RAM16(0x181E);
    if (value2 != 5) {
        if (value2 != 6) {
            RAM16_SET(0x1812, value3 & 0xFF);
            r->a = value4;
            r->x = value3 & 0xFF;
            r->y = value2;
            r->c = value2 >= 6;
            r->z = value2 == 6;
            r->v = ((value2 ^ (uint16_t)(value2 + 0x6EE9)) & ((uint16_t)(value2 + 0x6EE9) ^ 0x6EE9) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x6EE3, 0xC06F77); GUARD_JSR(c, sp_call, 0x6EE3); } /* step_category_then_build_native_menu_ring_list */
            { const uint16_t sp_call = r->sp; JSL(c, 0x6EE7, 0xD0CBF6); GUARD_JSL(c, sp_call, 0x6EE7); } /* dispatch_native_menu_weapon_palette_animation */
            RETURN_RTS(c);
        }
        r->a = value4;
        r->y = value2;
        r->v = ((value2 ^ (uint16_t)(value2 + 0x6EE9)) & ((uint16_t)(value2 + 0x6EE9) ^ 0x6EE9) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x6ED7, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6ED7); } /* hide_native_menu_icon_oam_objects */
        RAM16_SET(0x1812, 0);
        r->mf = 0;
        r->xf = 0;
        TAIL_CALL(c, 0xC06943, SOM_RTS); /* await_vblank_edge_and_run_complete_menu_text_frame */
    }
    bool m_flag;
    bool x_flag;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if (value4 == 0x24) {
        RAM16_SET(0x1812, value3 & 0xFF);
        r->a = value4;
        r->x = value3 & 0xFF;
        r->y = value2;
        r->c = value4 >= 0x24;
        r->z = value4 == 0x24;
        r->v = ((value2 ^ (uint16_t)(value2 + 0x6EE9)) & ((uint16_t)(value2 + 0x6EE9) ^ 0x6EE9) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6EE3, 0xC06F77); GUARD_JSR(c, sp_call, 0x6EE3); } /* step_category_then_build_native_menu_ring_list */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret5 = r->mf;
        bool x_ret11 = r->xf;
        bool overflow_ret6 = r->v;
        m_flag = m_ret5;
        x_flag = x_ret11;
        overflow1 = overflow_ret6;
        data_bank = db_ret2;
        direct_page = dp_ret2;
    } else {
        m_flag = 0;
        x_flag = 0;
        overflow1 = ((value2 ^ (uint16_t)(value2 + 0x6EE9)) & ((uint16_t)(value2 + 0x6EE9) ^ 0x6EE9) & 0x8000) != 0;
        data_bank = 0;
        direct_page = 0;
    }
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6EE7, 0xD0CBF6); GUARD_JSL(c, sp_call, 0x6EE7); } /* dispatch_native_menu_weapon_palette_animation */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06E9F, SOM_RTS, "gen", finish_native_ring_phase_or_rebuild_category_and_animate_palette, 0, 0, 1, 0, 0, 74, 29)

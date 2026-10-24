#include "som_c.h"

static void select_event_menu_oam_palette_attribute(SomCtx *c);

/* C06F72 build_native_menu_ring_list_without_initial_category_step   [class C, 307 bytes, 131 instructions]
 * Source: src/rom/build_native_menu_ring_list_without_initial_category_step.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void build_native_menu_ring_list_without_initial_category_step(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    uint64_t loop_guard = 0;
    const uint16_t a = r->a;
    uint8_t a_hi_6f7d = 0;
    uint8_t x_6f7d = 0;
    uint8_t y_6f7d = 0;
    bool carry_6f7d = 0;
    bool zero_6f7d = 0;
    bool overflow_6f7d = 0;
    uint16_t direct_page_6f7d = 0;
    uint8_t data_bank_6f7d = 0;
    uint8_t a_hi_6f7d2 = 0;
    uint16_t x_6f7d2 = 0;
    uint16_t y_6f7d2 = 0;
    bool carry_6f7d2 = 0;
    bool zero_6f7d2 = 0;
    bool overflow_6f7d2 = 0;
    uint16_t direct_page_6f7d2 = 0;
    uint8_t data_bank_6f7d2 = 0;
    uint8_t a_hi_6f7d3 = 0;
    uint8_t x_6f7d3 = 0;
    uint8_t y_6f7d3 = 0;
    bool carry_6f7d3 = 0;
    bool zero_6f7d3 = 0;
    bool overflow_6f7d3 = 0;
    uint16_t direct_page_6f7d3 = 0;
    uint8_t data_bank_6f7d3 = 0;
    uint8_t a_hi_6f7d4 = 0;
    uint16_t x_6f7d4 = 0;
    uint16_t y_6f7d4 = 0;
    bool carry_6f7d4 = 0;
    bool zero_6f7d4 = 0;
    bool overflow_6f7d4 = 0;
    uint16_t direct_page_6f7d4 = 0;
    uint8_t data_bank_6f7d4 = 0;
    uint8_t a_hi_6f7a = 0;
    uint16_t x_6f7a = 0;
    uint16_t y_6f7a = 0;
    bool carry_6f7a = 0;
    bool zero_6f7a = 0;
    bool overflow_6f7a = 0;
    uint16_t direct_page_6f7a = 0;
    uint8_t data_bank_6f7a = 0;
    uint8_t a_hi_6fae = 0;
    uint16_t x_6fae = 0;
    uint16_t y_6fae = 0;
    bool carry_6fae = 0;
    bool overflow_6fae = 0;
    uint16_t direct_page_6fae = 0;
    uint8_t data_bank_6fae = 0;
    uint8_t a_7029 = 0;
    uint8_t a_hi_7029 = 0;
    uint16_t x_7029 = 0;
    uint16_t y_7029 = 0;
    uint16_t direct_page_7029 = 0;
    uint8_t data_bank_7029 = 0;
    uint8_t a_7041 = 0;
    uint8_t a_hi_7041 = 0;
    uint16_t x_7041 = 0;
    uint16_t y_7041 = 0;
    uint16_t direct_page_7041 = 0;
    uint8_t data_bank_7041 = 0;
    uint8_t a_7051 = 0;
    uint8_t a_hi_7051 = 0;
    uint16_t x_7051 = 0;
    uint16_t y_7051 = 0;
    uint16_t direct_page_7051 = 0;
    uint8_t data_bank_7051 = 0;
    uint8_t a_hi_7077 = 0;
    uint16_t x_7077 = 0;
    uint16_t y_7077 = 0;
    uint16_t direct_page_7077 = 0;
    uint8_t data_bank_7077 = 0;
    uint8_t a_70eb = 0;
    uint8_t a_hi_70eb = 0;
    uint16_t x_70eb = 0;
    uint16_t y_70eb = 0;
    bool carry_70eb = 0;
    bool zero_70eb = 0;
    bool negative_70eb = 0;
    bool overflow_70eb = 0;
    uint16_t direct_page_70eb = 0;
    uint8_t data_bank_70eb = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F74, 0xC06F5E); GUARD_JSR(c, sp_call, 0x6F74); } /* play_native_menu_ring_open_or_change_sound */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool overflow_ret = r->v;
    if (m_ret) {
        if (x_ret) {
            a_hi_6f7d = a_all >> 8;
            x_6f7d = (uint8_t)x_ret2;
            y_6f7d = (uint8_t)y_ret;
            carry_6f7d = carry_ret;
            zero_6f7d = zero_ret;
            overflow_6f7d = overflow_ret;
            direct_page_6f7d = 0;
            data_bank_6f7d = 0;
            goto shared_6F7D;
        } else {
            a_hi_6f7d2 = a_all >> 8;
            x_6f7d2 = x_ret2;
            y_6f7d2 = y_ret;
            carry_6f7d2 = carry_ret;
            zero_6f7d2 = zero_ret;
            overflow_6f7d2 = overflow_ret;
            direct_page_6f7d2 = 0;
            data_bank_6f7d2 = 0;
            goto shared_6F7D_1;
        }
    } else {
        if (x_ret) {
            a_hi_6f7d3 = a_all >> 8;
            x_6f7d3 = (uint8_t)x_ret2;
            y_6f7d3 = (uint8_t)y_ret;
            carry_6f7d3 = carry_ret;
            zero_6f7d3 = zero_ret;
            overflow_6f7d3 = overflow_ret;
            direct_page_6f7d3 = 0;
            data_bank_6f7d3 = 0;
            goto shared_6F7D_2;
        } else {
            a_hi_6f7d4 = a_all >> 8;
            x_6f7d4 = x_ret2;
            y_6f7d4 = y_ret;
            carry_6f7d4 = carry_ret;
            zero_6f7d4 = zero_ret;
            overflow_6f7d4 = overflow_ret;
            direct_page_6f7d4 = 0;
            data_bank_6f7d4 = 0;
            goto shared_6F7D_3;
        }
    }
    shared_6F7D:;
    LOOP_GUARD(loop_guard);
    BUS8_SET(c, (data_bank_6f7d << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7d << 0x10) + 0x1806, 0);
    r->x = x_6f7d;
    r->y = y_6f7d;
    r->c = carry_6f7d;
    r->z = zero_6f7d;
    r->v = overflow_6f7d;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_6f7d;
    r->dp = direct_page_6f7d;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all5 = r->a;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret5 = r->c;
    bool zero_ret5 = r->z;
    bool overflow_ret4 = r->v;
    if (zero_ret5) {
        a_hi_6f7a = a_all5 >> 8;
        x_6f7a = x_ret7;
        y_6f7a = y_ret4;
        carry_6f7a = carry_ret5;
        zero_6f7a = zero_ret5;
        overflow_6f7a = overflow_ret4;
        direct_page_6f7a = dp_ret2;
        data_bank_6f7a = db_ret2;
        goto shared_6F7A;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool overflow_ret5 = r->v;
    uint16_t value = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1812);
    if (value == 1) {
        a_hi_6fae = value >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value >= 1;
        overflow_6fae = overflow_ret5;
        direct_page_6fae = dp_ret3;
        data_bank_6fae = db_ret3;
        goto shared_6FAE;
    }
    a_hi_6fae = value >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value >= 1;
    overflow_6fae = overflow_ret5;
    direct_page_6fae = dp_ret3;
    data_bank_6fae = db_ret3;
    goto shared_6FAE;
    shared_6F7D_1:;
    LOOP_GUARD(loop_guard);
    BUS8_SET(c, (data_bank_6f7d2 << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7d2 << 0x10) + 0x1806, 0);
    r->x = x_6f7d2;
    r->y = y_6f7d2;
    r->c = carry_6f7d2;
    r->z = zero_6f7d2;
    r->v = overflow_6f7d2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_6f7d2;
    r->dp = direct_page_6f7d2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all10 = r->a;
    uint16_t x_ret14 = r->x;
    uint16_t y_ret8 = r->y;
    bool carry_ret10 = r->c;
    bool zero_ret10 = r->z;
    bool overflow_ret8 = r->v;
    if (zero_ret10) {
        a_hi_6f7a = a_all10 >> 8;
        x_6f7a = x_ret14;
        y_6f7a = y_ret8;
        carry_6f7a = carry_ret10;
        zero_6f7a = zero_ret10;
        overflow_6f7a = overflow_ret8;
        direct_page_6f7a = dp_ret5;
        data_bank_6f7a = db_ret5;
        goto shared_6F7A;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool overflow_ret9 = r->v;
    uint16_t value2 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x1812);
    if (value2 == 1) {
        a_hi_6fae = value2 >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value2 >= 1;
        overflow_6fae = overflow_ret9;
        direct_page_6fae = dp_ret6;
        data_bank_6fae = db_ret6;
        goto shared_6FAE;
    }
    a_hi_6fae = value2 >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value2 >= 1;
    overflow_6fae = overflow_ret9;
    direct_page_6fae = dp_ret6;
    data_bank_6fae = db_ret6;
    goto shared_6FAE;
    shared_6F7D_2:;
    LOOP_GUARD(loop_guard);
    BUS8_SET(c, (data_bank_6f7d3 << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7d3 << 0x10) + 0x1806, 0);
    r->x = x_6f7d3;
    r->y = y_6f7d3;
    r->c = carry_6f7d3;
    r->z = zero_6f7d3;
    r->v = overflow_6f7d3;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_6f7d3;
    r->dp = direct_page_6f7d3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all15 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret12 = r->y;
    bool carry_ret15 = r->c;
    bool zero_ret15 = r->z;
    bool overflow_ret12 = r->v;
    if (zero_ret15) {
        a_hi_6f7a = a_all15 >> 8;
        x_6f7a = x_ret21;
        y_6f7a = y_ret12;
        carry_6f7a = carry_ret15;
        zero_6f7a = zero_ret15;
        overflow_6f7a = overflow_ret12;
        direct_page_6f7a = dp_ret8;
        data_bank_6f7a = db_ret8;
        goto shared_6F7A;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret9 = r->db;
    bool overflow_ret13 = r->v;
    uint16_t value3 = BUS16_RDP(c, (db_ret9 << 0x10) + 0x1812);
    if (value3 == 1) {
        a_hi_6fae = value3 >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value3 >= 1;
        overflow_6fae = overflow_ret13;
        direct_page_6fae = dp_ret9;
        data_bank_6fae = db_ret9;
        goto shared_6FAE;
    }
    a_hi_6fae = value3 >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value3 >= 1;
    overflow_6fae = overflow_ret13;
    direct_page_6fae = dp_ret9;
    data_bank_6fae = db_ret9;
    goto shared_6FAE;
    shared_6F7D_3:;
    LOOP_GUARD(loop_guard);
    BUS8_SET(c, (data_bank_6f7d4 << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7d4 << 0x10) + 0x1806, 0);
    r->x = x_6f7d4;
    r->y = y_6f7d4;
    r->c = carry_6f7d4;
    r->z = zero_6f7d4;
    r->v = overflow_6f7d4;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_6f7d4;
    r->dp = direct_page_6f7d4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all20 = r->a;
    uint16_t x_ret28 = r->x;
    uint16_t y_ret16 = r->y;
    bool carry_ret20 = r->c;
    bool zero_ret20 = r->z;
    bool overflow_ret16 = r->v;
    if (zero_ret20) {
        a_hi_6f7a = a_all20 >> 8;
        x_6f7a = x_ret28;
        y_6f7a = y_ret16;
        carry_6f7a = carry_ret20;
        zero_6f7a = zero_ret20;
        overflow_6f7a = overflow_ret16;
        direct_page_6f7a = dp_ret11;
        data_bank_6f7a = db_ret11;
        goto shared_6F7A;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    bool overflow_ret17 = r->v;
    uint16_t value4 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x1812);
    if (value4 == 1) {
        a_hi_6fae = value4 >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value4 >= 1;
        overflow_6fae = overflow_ret17;
        direct_page_6fae = dp_ret12;
        data_bank_6fae = db_ret12;
        goto shared_6FAE;
    }
    a_hi_6fae = value4 >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value4 >= 1;
    overflow_6fae = overflow_ret17;
    direct_page_6fae = dp_ret12;
    data_bank_6fae = db_ret12;
    goto shared_6FAE;
    shared_6F7A:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_6f7a << 8) | (uint8_t)a;
    r->x = x_6f7a;
    r->y = y_6f7a;
    r->c = carry_6f7a;
    r->z = zero_6f7a;
    r->v = overflow_6f7a;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_6f7a;
    r->dp = direct_page_6f7a;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F7C, 0xC06EF0); GUARD_JSR(c, sp_call, 0x6F7C); } /* step_native_menu_ring_category_across_shop_and_hero_constraints */
    uint16_t a_all22 = r->a;
    uint8_t x_ret31 = r->x;
    uint8_t y_ret18 = r->y;
    bool carry_ret22 = r->c;
    bool zero_ret22 = r->z;
    bool overflow_ret18 = r->v;
    a_hi_6f7d3 = a_all22 >> 8;
    x_6f7d3 = x_ret31;
    y_6f7d3 = y_ret18;
    carry_6f7d3 = carry_ret22;
    zero_6f7d3 = zero_ret22;
    overflow_6f7d3 = overflow_ret18;
    direct_page_6f7d3 = direct_page_6f7a;
    data_bank_6f7d3 = data_bank_6f7a;
    goto shared_6F7D_2;
    shared_6FAE:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (data_bank_6fae << 0x10) + 0x181E, x_6fae);
    BUS16_SET(c, (data_bank_6fae << 0x10) + 0x1816, y_6fae);
    BUS16_SET(c, (data_bank_6fae << 0x10) + 0x1822, 0);
    r->x = x_6fae;
    r->y = y_6fae;
    r->c = carry_6fae;
    r->v = overflow_6fae;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_6fae;
    r->dp = direct_page_6fae;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6FBA, 0xC0793D); GUARD_JSL(c, sp_call, 0x6FBA); } /* hide_shop_hero_markers_before_price_selection */
    r->a = 1;
    r->x = 0x082C;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x6FC3, select_event_menu_oam_palette_attribute, sp_in, 2); GUARD_JSR(c, sp_call, 0x6FC3); }
    uint16_t dp_ret13 = r->dp;
    uint16_t a_all24 = r->a;
    uint16_t x_ret32 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret13 + 2 + x_ret32), (uint16_t)(a_all24 + 0x010A));
    r->a = 2;
    r->c = a_all24 + 0x010A > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((a_all24 ^ (uint16_t)(a_all24 + 0x010A)) & ((uint16_t)(a_all24 + 0x010A) ^ 0x010A) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x6FCF, select_event_menu_oam_palette_attribute, sp_in, 2); GUARD_JSR(c, sp_call, 0x6FCF); }
    uint16_t dp_ret14 = r->dp;
    uint16_t a_all25 = r->a;
    uint16_t x_ret33 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret14 + 6 + x_ret33), (uint16_t)(a_all25 + 0x010C));
    r->a = 3;
    r->c = a_all25 + 0x010C > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((a_all25 ^ (uint16_t)(a_all25 + 0x010C)) & ((uint16_t)(a_all25 + 0x010C) ^ 0x010C) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x6FDB, select_event_menu_oam_palette_attribute, sp_in, 2); GUARD_JSR(c, sp_call, 0x6FDB); }
    uint16_t dp_ret15 = r->dp;
    uint8_t db_ret15 = r->db;
    uint16_t a_all26 = r->a;
    uint16_t x_ret34 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0A + x_ret34), (uint16_t)(a_all26 + 0x010E));
    uint16_t value5 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x181A);
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0838), (uint16_t)(((value5 & 0xFF) | 0xE800) - 8));
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0840), (uint16_t)(((value5 & 0xFF) | 0xE800) - 8));
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x083C), (uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10));
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0844), (uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10));
    uint16_t value6 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x1808);
    r->a = (value6 & 0xFF) + 1;
    r->x = 0x0838;
    r->c = (uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10 > 0xFFFF;
    r->z = (value6 & 0xFF) + 1 == 0;
    r->n = (value6 & 0xFF) + 1 & 0x8000;
    r->v = (((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) ^ (uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10)) & ((uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10) ^ 0x10) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x7007, select_event_menu_oam_palette_attribute, sp_in, 2); GUARD_JSR(c, sp_call, 0x7007); }
    uint16_t dp_ret16 = r->dp;
    uint8_t db_ret16 = r->db;
    uint16_t a_all27 = r->a;
    uint16_t x_ret35 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret16 + 2 + x_ret35), (uint16_t)(a_all27 + 0x0108));
    BUS16_SET(c, (uint16_t)(dp_ret16 + 6 + x_ret35), (uint16_t)(a_all27 + 0x0108) | 0x4000);
    BUS16_SET(c, (uint16_t)(dp_ret16 + 0x0E + x_ret35), (uint16_t)(a_all27 + 0x0108) | 0x4000 | 0x8000);
    BUS16_SET(c, (uint16_t)(dp_ret16 + 0x0A + x_ret35), ((uint16_t)(a_all27 + 0x0108) | 0x4000 | 0x8000) & 0xBFFF);
    uint16_t value7 = BUS16_RDP(c, (db_ret16 << 0x10) + 0x180B);
    a_7029 = value7 & 0xFF;
    a_hi_7029 = 0;
    x_7029 = 0x18C0;
    y_7029 = 0;
    direct_page_7029 = dp_ret16;
    data_bank_7029 = db_ret16;
    goto shared_7029;
    shared_7029:;
    LOOP_GUARD(loop_guard);
    RAM8(0x0000 + sp0) = a_hi_7029;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi_7029 << 8) | a_7029);
    BUS16_SET(c, (uint16_t)(direct_page_7029 + x_7029), 0);
    BUS16_SET(c, (uint16_t)(direct_page_7029 + 2 + x_7029), 0);
    BUS16_SET(c, (uint16_t)(direct_page_7029 + 4 + x_7029), 0xE8);
    r->a = 0xE8;
    r->x = x_7029;
    r->y = y_7029;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7029;
    r->dp = direct_page_7029;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7035, 0xC070A3); GUARD_JSR(c, sp_call, 0x7035); } /* bind_native_menu_list_row_to_active_hero_oam_marker */
    r->sp += 2;
    uint16_t x_ret36 = r->x;
    if (y_7029 < 8) {
        a_7041 = (uint8_t)(y_7029 << 1);
        a_hi_7041 = (uint16_t)(y_7029 << 1) >> 8;
        x_7041 = x_ret36;
        y_7041 = y_7029;
        direct_page_7041 = direct_page_7029;
        data_bank_7041 = data_bank_7029;
        goto shared_7041;
    }
    a_7041 = (uint8_t)((uint16_t)(y_7029 << 1) + 0x10);
    a_hi_7041 = (uint16_t)((uint16_t)(y_7029 << 1) + 0x10) >> 8;
    x_7041 = x_ret36;
    y_7041 = y_7029;
    direct_page_7041 = direct_page_7029;
    data_bank_7041 = data_bank_7029;
    goto shared_7041;
    shared_7041:;
    LOOP_GUARD(loop_guard);
    RAM8(0x0000 + sp0 - 2) = (uint16_t)(((a_hi_7041 << 8) | a_7041) + 0xE0) >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)(((a_hi_7041 << 8) | a_7041) + 0xE0);
    uint16_t value8 = BUS16_RDP(c, (data_bank_7041 << 0x10) + 0x1802);
    if ((value8 & 1) == 0) {
        a_7051 = value8 & 1;
        a_hi_7051 = 0;
        x_7051 = x_7041;
        y_7051 = y_7041;
        direct_page_7051 = direct_page_7041;
        data_bank_7051 = data_bank_7041;
        goto shared_7051;
    }
    a_7051 = 0;
    a_hi_7051 = 8;
    x_7051 = x_7041;
    y_7051 = y_7041;
    direct_page_7051 = direct_page_7041;
    data_bank_7051 = data_bank_7041;
    goto shared_7051;
    shared_7051:;
    LOOP_GUARD(loop_guard);
    uint16_t value9 = RAM16(0x0000 + sp0 - 3);
    r->a = (uint16_t)(((a_hi_7051 << 8) | a_7051) + value9) | 0x3000;
    r->x = x_7051;
    r->y = y_7051;
    r->c = y_7051 >= 3;
    r->z = y_7051 == 3;
    r->n = (uint16_t)(y_7051 - 3) & 0x8000;
    r->v = ((((a_hi_7051 << 8) | a_7051) ^ (uint16_t)(((a_hi_7051 << 8) | a_7051) + value9)) & (value9 ^ (uint16_t)(((a_hi_7051 << 8) | a_7051) + value9)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7051;
    r->dp = direct_page_7051;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x705C, 0xC0709C); GUARD_JSR(c, sp_call, 0x705C); } /* add_native_menu_row_tile_segment_when_comparison_carries */
    r->sp += 4;
    r->c = y_7051 >= 6;
    r->z = y_7051 == 6;
    r->n = (uint16_t)(y_7051 - 6) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7062, 0xC0709C); GUARD_JSR(c, sp_call, 0x7062); } /* add_native_menu_row_tile_segment_when_comparison_carries */
    r->sp += 4;
    r->c = y_7051 >= 9;
    r->z = y_7051 == 9;
    r->n = (uint16_t)(y_7051 - 9) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7068, 0xC0709C); GUARD_JSR(c, sp_call, 0x7068); } /* add_native_menu_row_tile_segment_when_comparison_carries */
    r->sp += 4;
    uint16_t a_all31 = r->a;
    BUS16_SET(c, (uint16_t)(direct_page_7051 + 6 + x_7051), a_all31);
    uint16_t value10 = BUS16_RDP(c, (data_bank_7051 << 0x10) + 0x1810);
    if (!(value10 & 0x8000)) {
        a_hi_7077 = value10 >> 8;
        x_7077 = x_7051;
        y_7077 = y_7051;
        direct_page_7077 = direct_page_7051;
        data_bank_7077 = data_bank_7051;
        goto shared_7077;
    }
    uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page_7051 + x_7051));
    BUS16_SET(c, (uint16_t)(direct_page_7051 + x_7051), value11 | 0x8000);
    a_hi_7077 = (value11 | 0x8000) >> 8;
    x_7077 = x_7051;
    y_7077 = y_7051;
    direct_page_7077 = direct_page_7051;
    data_bank_7077 = data_bank_7051;
    goto shared_7077;
    shared_7077:;
    LOOP_GUARD(loop_guard);
    uint16_t value14 = BUS16_RDP(c, (data_bank_7077 << 0x10) + 0x180E);
    RAM8(0x0000 + sp0 - 2) = x_7077 >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x_7077;
    uint16_t value15 = BUS16(c, 0xD80000 + (uint16_t)((uint16_t)(y_7077 << 1) + value14));
    uint16_t value16 = BUS16_RDP(c, (data_bank_7077 << 0x10) + 0x1816);
    BUS16_SET(c, (uint16_t)(direct_page_7077 + 8 + x_7077), (uint16_t)(value15 + value16) & 0x03FF);
    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
    uint8_t value18 = RAM8(0x0000 + sp0);
    if ((uint16_t)(((value18 << 8) | value17) - 1) == 0) {
        a_70eb = (uint8_t)(((value18 << 8) | value17) - 1);
        a_hi_70eb = (uint16_t)(((value18 << 8) | value17) - 1) >> 8;
        x_70eb = (uint16_t)(x_7077 + 0x10);
        y_70eb = (uint16_t)(y_7077 + 1);
        carry_70eb = x_7077 + 0x10 > 0xFFFF;
        zero_70eb = (uint16_t)(((value18 << 8) | value17) - 1) == 0;
        negative_70eb = (uint16_t)(((value18 << 8) | value17) - 1) & 0x8000;
        overflow_70eb = ((x_7077 ^ (uint16_t)(x_7077 + 0x10)) & ((uint16_t)(x_7077 + 0x10) ^ 0x10) & 0x8000) != 0;
        direct_page_70eb = direct_page_7077;
        data_bank_70eb = data_bank_7077;
        goto shared_70EB;
    }
    a_7029 = (uint8_t)(((value18 << 8) | value17) - 1);
    a_hi_7029 = (uint16_t)(((value18 << 8) | value17) - 1) >> 8;
    x_7029 = (uint16_t)(x_7077 + 0x10);
    y_7029 = (uint16_t)(y_7077 + 1);
    direct_page_7029 = direct_page_7077;
    data_bank_7029 = data_bank_7077;
    goto shared_7029;
    shared_70EB:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_70eb << 8) | a_70eb;
    r->x = x_70eb;
    r->y = y_70eb;
    r->c = carry_70eb;
    r->z = zero_70eb;
    r->n = negative_70eb;
    r->v = overflow_70eb;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_70eb;
    r->dp = direct_page_70eb;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06F72, SOM_RTS, "gen", build_native_menu_ring_list_without_initial_category_step, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 8, 0, 0, 378, 131)

/* C070E3 select_event_menu_oam_palette_attribute   [class A, 9 bytes, 5 instructions]
 * Source: src/rom/build_native_menu_ring_list_without_initial_category_step.s
 * Subroutine of build_native_menu_ring_list_without_initial_category_step, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void select_event_menu_oam_palette_attribute(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x70E5, 0xC070EC); GUARD_JSR(c, sp_call, 0x70E5); } /* select_event_menu_palette_slot */
    uint16_t a_all = r->a;
    r->a = (uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) | 0x3000;
    r->c = (((uint8_t)a_all << 8) | (a_all >> 8)) & 0x8000;
    r->z = ((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) | 0x3000) == 0;
    r->n = ((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) | 0x3000) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* C06F77 step_category_then_build_native_menu_ring_list   [class C, 294 bytes, 125 instructions]
 * Source: src/rom/build_native_menu_ring_list_without_initial_category_step.s
 * Interior entry C06F77 of build_native_menu_ring_list_without_initial_category_step, same file.
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void build_native_menu_ring_list_without_initial_category_step_at_C06F77(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    uint8_t a_hi_6f7a = 0;
    uint8_t x_6f7a = 0;
    uint8_t y_6f7a = 0;
    bool carry_6f7a = 0;
    bool zero_6f7a = 0;
    bool overflow_6f7a = 0;
    uint16_t direct_page_6f7a = 0;
    uint8_t data_bank_6f7a = 0;
    uint8_t a_hi_6f7a2 = 0;
    uint16_t x_6f7a2 = 0;
    uint16_t y_6f7a2 = 0;
    bool carry_6f7a2 = 0;
    bool zero_6f7a2 = 0;
    bool overflow_6f7a2 = 0;
    uint16_t direct_page_6f7a2 = 0;
    uint8_t data_bank_6f7a2 = 0;
    uint8_t a_hi_6f7a3 = 0;
    uint8_t x_6f7a3 = 0;
    uint8_t y_6f7a3 = 0;
    bool carry_6f7a3 = 0;
    bool zero_6f7a3 = 0;
    bool overflow_6f7a3 = 0;
    uint16_t direct_page_6f7a3 = 0;
    uint8_t data_bank_6f7a3 = 0;
    uint8_t a_hi_6f7a4 = 0;
    uint16_t x_6f7a4 = 0;
    uint16_t y_6f7a4 = 0;
    bool carry_6f7a4 = 0;
    bool zero_6f7a4 = 0;
    bool overflow_6f7a4 = 0;
    uint16_t direct_page_6f7a4 = 0;
    uint8_t data_bank_6f7a4 = 0;
    uint8_t a_hi_6fae = 0;
    uint16_t x_6fae = 0;
    uint16_t y_6fae = 0;
    bool carry_6fae = 0;
    bool overflow_6fae = 0;
    uint16_t direct_page_6fae = 0;
    uint8_t data_bank_6fae = 0;
    uint8_t a_7029 = 0;
    uint8_t a_hi_7029 = 0;
    uint16_t x_7029 = 0;
    uint16_t y_7029 = 0;
    uint16_t direct_page_7029 = 0;
    uint8_t data_bank_7029 = 0;
    uint8_t a_7041 = 0;
    uint8_t a_hi_7041 = 0;
    uint16_t x_7041 = 0;
    uint16_t y_7041 = 0;
    uint16_t direct_page_7041 = 0;
    uint8_t data_bank_7041 = 0;
    uint8_t a_7051 = 0;
    uint8_t a_hi_7051 = 0;
    uint16_t x_7051 = 0;
    uint16_t y_7051 = 0;
    uint16_t direct_page_7051 = 0;
    uint8_t data_bank_7051 = 0;
    uint8_t a_hi_7077 = 0;
    uint16_t x_7077 = 0;
    uint16_t y_7077 = 0;
    uint16_t direct_page_7077 = 0;
    uint8_t data_bank_7077 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F79, 0xC06F5E); GUARD_JSR(c, sp_call, 0x6F79); } /* play_native_menu_ring_open_or_change_sound */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool overflow_ret = r->v;
    if (m_ret) {
        if (x_ret) {
            a_hi_6f7a = a_all >> 8;
            x_6f7a = (uint8_t)x_ret2;
            y_6f7a = (uint8_t)y_ret;
            carry_6f7a = carry_ret;
            zero_6f7a = zero_ret;
            overflow_6f7a = overflow_ret;
            direct_page_6f7a = dp;
            data_bank_6f7a = 0x7E;
            goto shared_6F7A;
        } else {
            a_hi_6f7a2 = a_all >> 8;
            x_6f7a2 = x_ret2;
            y_6f7a2 = y_ret;
            carry_6f7a2 = carry_ret;
            zero_6f7a2 = zero_ret;
            overflow_6f7a2 = overflow_ret;
            direct_page_6f7a2 = dp;
            data_bank_6f7a2 = 0x7E;
            goto shared_6F7A_1;
        }
    } else {
        if (x_ret) {
            a_hi_6f7a3 = a_all >> 8;
            x_6f7a3 = (uint8_t)x_ret2;
            y_6f7a3 = (uint8_t)y_ret;
            carry_6f7a3 = carry_ret;
            zero_6f7a3 = zero_ret;
            overflow_6f7a3 = overflow_ret;
            direct_page_6f7a3 = dp;
            data_bank_6f7a3 = 0x7E;
            goto shared_6F7A_2;
        } else {
            a_hi_6f7a4 = a_all >> 8;
            x_6f7a4 = x_ret2;
            y_6f7a4 = y_ret;
            carry_6f7a4 = carry_ret;
            zero_6f7a4 = zero_ret;
            overflow_6f7a4 = overflow_ret;
            direct_page_6f7a4 = dp;
            data_bank_6f7a4 = 0x7E;
            goto shared_6F7A_3;
        }
    }
    shared_6F7A:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_6f7a << 8) | a;
    r->x = x_6f7a;
    r->y = y_6f7a;
    r->c = carry_6f7a;
    r->z = zero_6f7a;
    r->v = overflow_6f7a;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_6f7a;
    r->dp = direct_page_6f7a;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F7C, 0xC06EF0); GUARD_JSR(c, sp_call, 0x6F7C); } /* step_native_menu_ring_category_across_shop_and_hero_constraints */
    BUS8_SET(c, (data_bank_6f7a << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7a << 0x10) + 0x1806, 0);
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all6 = r->a;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret5 = r->y;
    bool carry_ret6 = r->c;
    bool zero_ret6 = r->z;
    bool overflow_ret5 = r->v;
    if (zero_ret6) {
        a_hi_6f7a4 = a_all6 >> 8;
        x_6f7a4 = x_ret8;
        y_6f7a4 = y_ret5;
        carry_6f7a4 = carry_ret6;
        zero_6f7a4 = zero_ret6;
        overflow_6f7a4 = overflow_ret5;
        direct_page_6f7a4 = dp_ret2;
        data_bank_6f7a4 = db_ret2;
        goto shared_6F7A_3;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool overflow_ret6 = r->v;
    uint16_t value = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1812);
    if (value == 1) {
        a_hi_6fae = value >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value >= 1;
        overflow_6fae = overflow_ret6;
        direct_page_6fae = dp_ret3;
        data_bank_6fae = db_ret3;
        goto shared_6FAE;
    }
    a_hi_6fae = value >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value >= 1;
    overflow_6fae = overflow_ret6;
    direct_page_6fae = dp_ret3;
    data_bank_6fae = db_ret3;
    goto shared_6FAE;
    shared_6F7A_1:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_6f7a2 << 8) | a;
    r->x = x_6f7a2;
    r->y = y_6f7a2;
    r->c = carry_6f7a2;
    r->z = zero_6f7a2;
    r->v = overflow_6f7a2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_6f7a2;
    r->dp = direct_page_6f7a2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F7C, 0xC06EF0); GUARD_JSR(c, sp_call, 0x6F7C); } /* step_native_menu_ring_category_across_shop_and_hero_constraints */
    BUS8_SET(c, (data_bank_6f7a2 << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7a2 << 0x10) + 0x1806, 0);
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all12 = r->a;
    uint16_t x_ret16 = r->x;
    uint16_t y_ret10 = r->y;
    bool carry_ret12 = r->c;
    bool zero_ret12 = r->z;
    bool overflow_ret10 = r->v;
    if (zero_ret12) {
        a_hi_6f7a4 = a_all12 >> 8;
        x_6f7a4 = x_ret16;
        y_6f7a4 = y_ret10;
        carry_6f7a4 = carry_ret12;
        zero_6f7a4 = zero_ret12;
        overflow_6f7a4 = overflow_ret10;
        direct_page_6f7a4 = dp_ret5;
        data_bank_6f7a4 = db_ret5;
        goto shared_6F7A_3;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool overflow_ret11 = r->v;
    uint16_t value2 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x1812);
    if (value2 == 1) {
        a_hi_6fae = value2 >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value2 >= 1;
        overflow_6fae = overflow_ret11;
        direct_page_6fae = dp_ret6;
        data_bank_6fae = db_ret6;
        goto shared_6FAE;
    }
    a_hi_6fae = value2 >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value2 >= 1;
    overflow_6fae = overflow_ret11;
    direct_page_6fae = dp_ret6;
    data_bank_6fae = db_ret6;
    goto shared_6FAE;
    shared_6F7A_2:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_6f7a3 << 8) | a;
    r->x = x_6f7a3;
    r->y = y_6f7a3;
    r->c = carry_6f7a3;
    r->z = zero_6f7a3;
    r->v = overflow_6f7a3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_6f7a3;
    r->dp = direct_page_6f7a3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F7C, 0xC06EF0); GUARD_JSR(c, sp_call, 0x6F7C); } /* step_native_menu_ring_category_across_shop_and_hero_constraints */
    BUS8_SET(c, (data_bank_6f7a3 << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7a3 << 0x10) + 0x1806, 0);
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all18 = r->a;
    uint16_t x_ret24 = r->x;
    uint16_t y_ret15 = r->y;
    bool carry_ret18 = r->c;
    bool zero_ret18 = r->z;
    bool overflow_ret15 = r->v;
    if (zero_ret18) {
        a_hi_6f7a4 = a_all18 >> 8;
        x_6f7a4 = x_ret24;
        y_6f7a4 = y_ret15;
        carry_6f7a4 = carry_ret18;
        zero_6f7a4 = zero_ret18;
        overflow_6f7a4 = overflow_ret15;
        direct_page_6f7a4 = dp_ret8;
        data_bank_6f7a4 = db_ret8;
        goto shared_6F7A_3;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret9 = r->db;
    bool overflow_ret16 = r->v;
    uint16_t value3 = BUS16_RDP(c, (db_ret9 << 0x10) + 0x1812);
    if (value3 == 1) {
        a_hi_6fae = value3 >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value3 >= 1;
        overflow_6fae = overflow_ret16;
        direct_page_6fae = dp_ret9;
        data_bank_6fae = db_ret9;
        goto shared_6FAE;
    }
    a_hi_6fae = value3 >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value3 >= 1;
    overflow_6fae = overflow_ret16;
    direct_page_6fae = dp_ret9;
    data_bank_6fae = db_ret9;
    goto shared_6FAE;
    shared_6F7A_3:;
    LOOP_GUARD(loop_guard);
    r->a = (a_hi_6f7a4 << 8) | a;
    r->x = x_6f7a4;
    r->y = y_6f7a4;
    r->c = carry_6f7a4;
    r->z = zero_6f7a4;
    r->v = overflow_6f7a4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_6f7a4;
    r->dp = direct_page_6f7a4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F7C, 0xC06EF0); GUARD_JSR(c, sp_call, 0x6F7C); } /* step_native_menu_ring_category_across_shop_and_hero_constraints */
    BUS8_SET(c, (data_bank_6f7a4 << 0x10) + 0x1848, 0);
    BUS8_SET(c, (data_bank_6f7a4 << 0x10) + 0x1806, 0);
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F87, 0xC06A41); GUARD_JSR(c, sp_call, 0x6F87); } /* read_selected_menu_actor_direction_flag */
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8B, 0xD0C83F); GUARD_JSL(c, sp_call, 0x6F8B); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6F8F, 0xD0CF48); GUARD_JSL(c, sp_call, 0x6F8F); } /* build_native_menu_descriptor_source_for_shop_or_inventory */
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F92, 0xC07108); GUARD_JSR(c, sp_call, 0x6F92); } /* select_native_menu_ring_hero_and_shop_geometry */
    uint16_t a_all24 = r->a;
    uint16_t x_ret32 = r->x;
    uint16_t y_ret20 = r->y;
    bool carry_ret24 = r->c;
    bool zero_ret24 = r->z;
    bool overflow_ret20 = r->v;
    if (zero_ret24) {
        a_hi_6f7a4 = a_all24 >> 8;
        x_6f7a4 = x_ret32;
        y_6f7a4 = y_ret20;
        carry_6f7a4 = carry_ret24;
        zero_6f7a4 = zero_ret24;
        overflow_6f7a4 = overflow_ret20;
        direct_page_6f7a4 = dp_ret11;
        data_bank_6f7a4 = db_ret11;
        goto shared_6F7A_3;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F97, 0xC06977); GUARD_JSR(c, sp_call, 0x6F97); } /* publish_native_menu_icons_and_palette_between_real_vblank_frames */
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    bool overflow_ret21 = r->v;
    uint16_t value4 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x1812);
    if (value4 == 1) {
        a_hi_6fae = value4 >> 8;
        x_6fae = 0;
        y_6fae = 0x48;
        carry_6fae = value4 >= 1;
        overflow_6fae = overflow_ret21;
        direct_page_6fae = dp_ret12;
        data_bank_6fae = db_ret12;
        goto shared_6FAE;
    }
    a_hi_6fae = value4 >> 8;
    x_6fae = 0xE8;
    y_6fae = 0xFE98;
    carry_6fae = value4 >= 1;
    overflow_6fae = overflow_ret21;
    direct_page_6fae = dp_ret12;
    data_bank_6fae = db_ret12;
    goto shared_6FAE;
    shared_6FAE:;
    LOOP_GUARD(loop_guard);
    BUS16_SET(c, (data_bank_6fae << 0x10) + 0x181E, x_6fae);
    BUS16_SET(c, (data_bank_6fae << 0x10) + 0x1816, y_6fae);
    BUS16_SET(c, (data_bank_6fae << 0x10) + 0x1822, 0);
    r->x = x_6fae;
    r->y = y_6fae;
    r->c = carry_6fae;
    r->v = overflow_6fae;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_6fae;
    r->dp = direct_page_6fae;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6FBA, 0xC0793D); GUARD_JSL(c, sp_call, 0x6FBA); } /* hide_shop_hero_markers_before_price_selection */
    r->a = 1;
    r->x = 0x082C;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6FC3, 0xC070E3); GUARD_JSR(c, sp_call, 0x6FC3); } /* select_event_menu_oam_palette_attribute */
    uint16_t dp_ret13 = r->dp;
    uint16_t a_all27 = r->a;
    uint16_t x_ret35 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret13 + 2 + x_ret35), (uint16_t)(a_all27 + 0x010A));
    r->a = 2;
    r->c = a_all27 + 0x010A > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((a_all27 ^ (uint16_t)(a_all27 + 0x010A)) & ((uint16_t)(a_all27 + 0x010A) ^ 0x010A) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6FCF, 0xC070E3); GUARD_JSR(c, sp_call, 0x6FCF); } /* select_event_menu_oam_palette_attribute */
    uint16_t dp_ret14 = r->dp;
    uint16_t a_all28 = r->a;
    uint16_t x_ret36 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret14 + 6 + x_ret36), (uint16_t)(a_all28 + 0x010C));
    r->a = 3;
    r->c = a_all28 + 0x010C > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((a_all28 ^ (uint16_t)(a_all28 + 0x010C)) & ((uint16_t)(a_all28 + 0x010C) ^ 0x010C) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6FDB, 0xC070E3); GUARD_JSR(c, sp_call, 0x6FDB); } /* select_event_menu_oam_palette_attribute */
    uint16_t dp_ret15 = r->dp;
    uint8_t db_ret15 = r->db;
    uint16_t a_all29 = r->a;
    uint16_t x_ret37 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0A + x_ret37), (uint16_t)(a_all29 + 0x010E));
    uint16_t value5 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x181A);
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0838), (uint16_t)(((value5 & 0xFF) | 0xE800) - 8));
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0840), (uint16_t)(((value5 & 0xFF) | 0xE800) - 8));
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x083C), (uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10));
    BUS16_SET(c, (uint16_t)(dp_ret15 + 0x0844), (uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10));
    uint16_t value6 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x1808);
    r->a = (value6 & 0xFF) + 1;
    r->x = 0x0838;
    r->c = (uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10 > 0xFFFF;
    r->z = (value6 & 0xFF) + 1 == 0;
    r->n = (value6 & 0xFF) + 1 & 0x8000;
    r->v = (((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) ^ (uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10)) & ((uint16_t)((uint16_t)(((value5 & 0xFF) | 0xE800) - 8) + 0x10) ^ 0x10) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7007, 0xC070E3); GUARD_JSR(c, sp_call, 0x7007); } /* select_event_menu_oam_palette_attribute */
    uint16_t dp_ret16 = r->dp;
    uint8_t db_ret16 = r->db;
    uint16_t a_all30 = r->a;
    uint16_t x_ret38 = r->x;
    BUS16_SET(c, (uint16_t)(dp_ret16 + 2 + x_ret38), (uint16_t)(a_all30 + 0x0108));
    BUS16_SET(c, (uint16_t)(dp_ret16 + 6 + x_ret38), (uint16_t)(a_all30 + 0x0108) | 0x4000);
    BUS16_SET(c, (uint16_t)(dp_ret16 + 0x0E + x_ret38), (uint16_t)(a_all30 + 0x0108) | 0x4000 | 0x8000);
    BUS16_SET(c, (uint16_t)(dp_ret16 + 0x0A + x_ret38), ((uint16_t)(a_all30 + 0x0108) | 0x4000 | 0x8000) & 0xBFFF);
    uint16_t value7 = BUS16_RDP(c, (db_ret16 << 0x10) + 0x180B);
    a_7029 = value7 & 0xFF;
    a_hi_7029 = 0;
    x_7029 = 0x18C0;
    y_7029 = 0;
    direct_page_7029 = dp_ret16;
    data_bank_7029 = db_ret16;
    goto shared_7029;
    shared_7029:;
    LOOP_GUARD(loop_guard);
    RAM8(0x0000 + sp0) = a_hi_7029;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi_7029 << 8) | a_7029);
    BUS16_SET(c, (uint16_t)(direct_page_7029 + x_7029), 0);
    BUS16_SET(c, (uint16_t)(direct_page_7029 + 2 + x_7029), 0);
    BUS16_SET(c, (uint16_t)(direct_page_7029 + 4 + x_7029), 0xE8);
    r->a = 0xE8;
    r->x = x_7029;
    r->y = y_7029;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7029;
    r->dp = direct_page_7029;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7035, 0xC070A3); GUARD_JSR(c, sp_call, 0x7035); } /* bind_native_menu_list_row_to_active_hero_oam_marker */
    r->sp += 2;
    uint16_t x_ret39 = r->x;
    if (y_7029 < 8) {
        a_7041 = (uint8_t)(y_7029 << 1);
        a_hi_7041 = (uint16_t)(y_7029 << 1) >> 8;
        x_7041 = x_ret39;
        y_7041 = y_7029;
        direct_page_7041 = direct_page_7029;
        data_bank_7041 = data_bank_7029;
        goto shared_7041;
    }
    a_7041 = (uint8_t)((uint16_t)(y_7029 << 1) + 0x10);
    a_hi_7041 = (uint16_t)((uint16_t)(y_7029 << 1) + 0x10) >> 8;
    x_7041 = x_ret39;
    y_7041 = y_7029;
    direct_page_7041 = direct_page_7029;
    data_bank_7041 = data_bank_7029;
    goto shared_7041;
    shared_7041:;
    LOOP_GUARD(loop_guard);
    RAM8(0x0000 + sp0 - 2) = (uint16_t)(((a_hi_7041 << 8) | a_7041) + 0xE0) >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)(((a_hi_7041 << 8) | a_7041) + 0xE0);
    uint16_t value8 = BUS16_RDP(c, (data_bank_7041 << 0x10) + 0x1802);
    if ((value8 & 1) == 0) {
        a_7051 = value8 & 1;
        a_hi_7051 = 0;
        x_7051 = x_7041;
        y_7051 = y_7041;
        direct_page_7051 = direct_page_7041;
        data_bank_7051 = data_bank_7041;
        goto shared_7051;
    }
    a_7051 = 0;
    a_hi_7051 = 8;
    x_7051 = x_7041;
    y_7051 = y_7041;
    direct_page_7051 = direct_page_7041;
    data_bank_7051 = data_bank_7041;
    goto shared_7051;
    shared_7051:;
    LOOP_GUARD(loop_guard);
    uint16_t value9 = RAM16(0x0000 + sp0 - 3);
    r->a = (uint16_t)(((a_hi_7051 << 8) | a_7051) + value9) | 0x3000;
    r->x = x_7051;
    r->y = y_7051;
    r->c = y_7051 >= 3;
    r->z = y_7051 == 3;
    r->n = (uint16_t)(y_7051 - 3) & 0x8000;
    r->v = ((((a_hi_7051 << 8) | a_7051) ^ (uint16_t)(((a_hi_7051 << 8) | a_7051) + value9)) & (value9 ^ (uint16_t)(((a_hi_7051 << 8) | a_7051) + value9)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7051;
    r->dp = direct_page_7051;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x705C, 0xC0709C); GUARD_JSR(c, sp_call, 0x705C); } /* add_native_menu_row_tile_segment_when_comparison_carries */
    r->sp += 4;
    r->c = y_7051 >= 6;
    r->z = y_7051 == 6;
    r->n = (uint16_t)(y_7051 - 6) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7062, 0xC0709C); GUARD_JSR(c, sp_call, 0x7062); } /* add_native_menu_row_tile_segment_when_comparison_carries */
    r->sp += 4;
    r->c = y_7051 >= 9;
    r->z = y_7051 == 9;
    r->n = (uint16_t)(y_7051 - 9) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7068, 0xC0709C); GUARD_JSR(c, sp_call, 0x7068); } /* add_native_menu_row_tile_segment_when_comparison_carries */
    r->sp += 4;
    uint16_t a_all34 = r->a;
    BUS16_SET(c, (uint16_t)(direct_page_7051 + 6 + x_7051), a_all34);
    uint16_t value10 = BUS16_RDP(c, (data_bank_7051 << 0x10) + 0x1810);
    if (!(value10 & 0x8000)) {
        a_hi_7077 = value10 >> 8;
        x_7077 = x_7051;
        y_7077 = y_7051;
        direct_page_7077 = direct_page_7051;
        data_bank_7077 = data_bank_7051;
        goto shared_7077;
    }
    uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page_7051 + x_7051));
    BUS16_SET(c, (uint16_t)(direct_page_7051 + x_7051), value11 | 0x8000);
    a_hi_7077 = (value11 | 0x8000) >> 8;
    x_7077 = x_7051;
    y_7077 = y_7051;
    direct_page_7077 = direct_page_7051;
    data_bank_7077 = data_bank_7051;
    goto shared_7077;
    shared_7077:;
    LOOP_GUARD(loop_guard);
    uint16_t value14 = BUS16_RDP(c, (data_bank_7077 << 0x10) + 0x180E);
    RAM8(0x0000 + sp0 - 2) = x_7077 >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x_7077;
    uint16_t value15 = BUS16(c, 0xD80000 + (uint16_t)((uint16_t)(y_7077 << 1) + value14));
    uint16_t value16 = BUS16_RDP(c, (data_bank_7077 << 0x10) + 0x1816);
    BUS16_SET(c, (uint16_t)(direct_page_7077 + 8 + x_7077), (uint16_t)(value15 + value16) & 0x03FF);
    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
    uint8_t value18 = RAM8(0x0000 + sp0);
    if ((uint16_t)(((value18 << 8) | value17) - 1) != 0) {
        a_7029 = (uint8_t)(((value18 << 8) | value17) - 1);
        a_hi_7029 = (uint16_t)(((value18 << 8) | value17) - 1) >> 8;
        x_7029 = (uint16_t)(x_7077 + 0x10);
        y_7029 = (uint16_t)(y_7077 + 1);
        direct_page_7029 = direct_page_7077;
        data_bank_7029 = data_bank_7077;
        goto shared_7029;
    }
    r->a = (uint16_t)(((value18 << 8) | value17) - 1);
    r->x = (uint16_t)(x_7077 + 0x10);
    r->y = (uint16_t)(y_7077 + 1);
    r->c = x_7077 + 0x10 > 0xFFFF;
    r->z = (uint16_t)(((value18 << 8) | value17) - 1) == 0;
    r->n = (uint16_t)(((value18 << 8) | value17) - 1) & 0x8000;
    r->v = ((x_7077 ^ (uint16_t)(x_7077 + 0x10)) & ((uint16_t)(x_7077 + 0x10) ^ 0x10) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7077;
    r->dp = direct_page_7077;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06F77, SOM_RTS, "gen", build_native_menu_ring_list_without_initial_category_step_at_C06F77, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 373, 125)

/* C070E3 select_event_menu_oam_palette_attribute   [class C, 9 bytes, 5 instructions]
 * Source: src/rom/build_native_menu_ring_list_without_initial_category_step.s
 * Interior entry C070E3 of build_native_menu_ring_list_without_initial_category_step, same file.
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void build_native_menu_ring_list_without_initial_category_step_at_C070E3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x70E5, 0xC070EC); GUARD_JSR(c, sp_call, 0x70E5); } /* select_event_menu_palette_slot */
    uint16_t a_all = r->a;
    r->a = (uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) | 0x3000;
    r->c = (((uint8_t)a_all << 8) | (a_all >> 8)) & 0x8000;
    r->z = ((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) | 0x3000) == 0;
    r->n = ((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) | 0x3000) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC070E3, SOM_RTS, "gen", build_native_menu_ring_list_without_initial_category_step_at_C070E3, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 5)

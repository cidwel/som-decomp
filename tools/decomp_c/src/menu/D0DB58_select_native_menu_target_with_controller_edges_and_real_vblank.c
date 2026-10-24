#include "som_c.h"

static void advance_native_target_cursor_and_skip_unavailable_entries(SomCtx *c);
static void publish_native_single_or_blinking_multi_target_markers(SomCtx *c);
static void publish_native_single_or_blinking_multi_target_markers_v2(SomCtx *c);
static void publish_native_single_or_blinking_multi_target_markers_v3(SomCtx *c);
static void publish_native_single_or_blinking_multi_target_markers_v4(SomCtx *c);

/* D0DB58 select_native_menu_target_with_controller_edges_and_real_vblank   [class C, 284 bytes, 117 instructions]
 * Source: src/rom/select_native_menu_target_with_controller_edges_and_real_vblank.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void select_native_menu_target_with_controller_edges_and_real_vblank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    uint8_t a_hi_db7a = 0;
    uint8_t y_db7a = 0;
    bool carry_db7a = 0;
    bool overflow_db7a = 0;
    uint16_t direct_page_db7a = 0;
    uint8_t data_bank_db7a = 0;
    uint8_t a_db8f = 0;
    uint8_t a_hi_db8f = 0;
    uint16_t x_db8f = 0;
    uint16_t y_db8f = 0;
    bool carry_db8f = 0;
    bool overflow_db8f = 0;
    uint16_t direct_page_db8f = 0;
    uint8_t data_bank_db8f = 0;
    uint8_t a_hi_db7a2 = 0;
    uint16_t y_db7a2 = 0;
    bool carry_db7a2 = 0;
    bool overflow_db7a2 = 0;
    uint16_t direct_page_db7a2 = 0;
    uint8_t data_bank_db7a2 = 0;
    uint8_t a_dba7 = 0;
    uint8_t a_hi_dba7 = 0;
    uint8_t x_dba7 = 0;
    uint8_t y_dba7 = 0;
    bool carry_dba7 = 0;
    bool zero_dba7 = 0;
    bool negative_dba7 = 0;
    bool overflow_dba7 = 0;
    uint16_t direct_page_dba7 = 0;
    uint8_t data_bank_dba7 = 0;
    uint8_t a_dba72 = 0;
    uint8_t a_hi_dba72 = 0;
    uint16_t x_dba72 = 0;
    uint16_t y_dba72 = 0;
    bool carry_dba72 = 0;
    bool zero_dba72 = 0;
    bool negative_dba72 = 0;
    bool overflow_dba72 = 0;
    uint16_t direct_page_dba72 = 0;
    uint8_t data_bank_dba72 = 0;
    uint8_t a_dba73 = 0;
    uint8_t a_hi_dba73 = 0;
    uint8_t x_dba73 = 0;
    uint8_t y_dba73 = 0;
    bool carry_dba73 = 0;
    bool zero_dba73 = 0;
    bool negative_dba73 = 0;
    bool overflow_dba73 = 0;
    uint16_t direct_page_dba73 = 0;
    uint8_t data_bank_dba73 = 0;
    uint8_t a_dba74 = 0;
    uint8_t a_hi_dba74 = 0;
    uint16_t x_dba74 = 0;
    uint16_t y_dba74 = 0;
    bool carry_dba74 = 0;
    bool zero_dba74 = 0;
    bool negative_dba74 = 0;
    bool overflow_dba74 = 0;
    uint16_t direct_page_dba74 = 0;
    uint8_t data_bank_dba74 = 0;
    uint8_t a_dbb5 = 0;
    uint8_t a_hi_dbb5 = 0;
    uint8_t x_dbb5 = 0;
    uint8_t y_dbb5 = 0;
    bool carry_dbb5 = 0;
    bool zero_dbb5 = 0;
    bool negative_dbb5 = 0;
    bool overflow_dbb5 = 0;
    uint16_t direct_page_dbb5 = 0;
    uint8_t data_bank_dbb5 = 0;
    uint8_t a_dbb52 = 0;
    uint8_t a_hi_dbb52 = 0;
    uint16_t x_dbb52 = 0;
    uint16_t y_dbb52 = 0;
    bool carry_dbb52 = 0;
    bool zero_dbb52 = 0;
    bool negative_dbb52 = 0;
    bool overflow_dbb52 = 0;
    uint16_t direct_page_dbb52 = 0;
    uint8_t data_bank_dbb52 = 0;
    uint8_t a_dbcb = 0;
    uint8_t a_hi_dbcb = 0;
    uint8_t x_dbcb = 0;
    uint8_t y_dbcb = 0;
    bool carry_dbcb = 0;
    bool overflow_dbcb = 0;
    uint16_t direct_page_dbcb = 0;
    uint8_t data_bank_dbcb = 0;
    uint8_t a_dbcb2 = 0;
    uint8_t a_hi_dbcb2 = 0;
    uint16_t x_dbcb2 = 0;
    uint16_t y_dbcb2 = 0;
    bool carry_dbcb2 = 0;
    bool overflow_dbcb2 = 0;
    uint16_t direct_page_dbcb2 = 0;
    uint8_t data_bank_dbcb2 = 0;
    uint8_t a_dbf3 = 0;
    uint8_t a_hi_dbf3 = 0;
    uint16_t x_dbf3 = 0;
    uint16_t y_dbf3 = 0;
    bool carry_dbf3 = 0;
    bool zero_dbf3 = 0;
    bool negative_dbf3 = 0;
    bool overflow_dbf3 = 0;
    uint16_t direct_page_dbf3 = 0;
    uint8_t data_bank_dbf3 = 0;
    uint8_t a_dc12 = 0;
    uint8_t a_hi_dc12 = 0;
    uint16_t x_dc12 = 0;
    uint16_t y_dc12 = 0;
    bool carry_dc12 = 0;
    bool zero_dc12 = 0;
    bool negative_dc12 = 0;
    bool overflow_dc12 = 0;
    uint16_t direct_page_dc12 = 0;
    uint8_t data_bank_dc12 = 0;
    uint8_t a_dbdf = 0;
    uint8_t a_hi_dbdf = 0;
    uint8_t x_dbdf = 0;
    uint8_t y_dbdf = 0;
    bool carry_dbdf = 0;
    bool zero_dbdf = 0;
    bool negative_dbdf = 0;
    bool overflow_dbdf = 0;
    uint16_t direct_page_dbdf = 0;
    uint8_t data_bank_dbdf = 0;
    uint8_t a_dbdf2 = 0;
    uint8_t a_hi_dbdf2 = 0;
    uint8_t x_dbdf2 = 0;
    uint8_t y_dbdf2 = 0;
    bool carry_dbdf2 = 0;
    bool zero_dbdf2 = 0;
    bool negative_dbdf2 = 0;
    bool overflow_dbdf2 = 0;
    uint16_t direct_page_dbdf2 = 0;
    uint8_t data_bank_dbdf2 = 0;
    bool irq_disable_dbdf = 0;
    bool decimal_dbdf = 0;
    uint8_t a_dbdf3 = 0;
    uint8_t a_hi_dbdf3 = 0;
    uint16_t x_dbdf3 = 0;
    uint16_t y_dbdf3 = 0;
    bool carry_dbdf3 = 0;
    bool zero_dbdf3 = 0;
    bool negative_dbdf3 = 0;
    bool overflow_dbdf3 = 0;
    uint16_t direct_page_dbdf3 = 0;
    uint8_t data_bank_dbdf3 = 0;
    bool irq_disable_dbdf2 = 0;
    bool decimal_dbdf2 = 0;
    uint8_t a_dbdf4 = 0;
    uint8_t a_hi_dbdf4 = 0;
    uint16_t x_dbdf4 = 0;
    uint16_t y_dbdf4 = 0;
    bool carry_dbdf4 = 0;
    bool zero_dbdf4 = 0;
    bool negative_dbdf4 = 0;
    bool overflow_dbdf4 = 0;
    uint16_t direct_page_dbdf4 = 0;
    uint8_t data_bank_dbdf4 = 0;
    bool irq_disable_dbdf3 = 0;
    bool decimal_dbdf3 = 0;
    uint8_t a_dc02 = 0;
    uint8_t a_hi_dc02 = 0;
    uint8_t x_dc02 = 0;
    uint8_t y_dc02 = 0;
    bool carry_dc02 = 0;
    bool zero_dc02 = 0;
    bool negative_dc02 = 0;
    bool overflow_dc02 = 0;
    uint16_t direct_page_dc02 = 0;
    uint8_t data_bank_dc02 = 0;
    uint8_t a_dc022 = 0;
    uint8_t a_hi_dc022 = 0;
    uint16_t x_dc022 = 0;
    uint16_t y_dc022 = 0;
    bool carry_dc022 = 0;
    bool zero_dc022 = 0;
    bool negative_dc022 = 0;
    bool overflow_dc022 = 0;
    uint16_t direct_page_dc022 = 0;
    uint8_t data_bank_dc022 = 0;
    uint8_t a_dc023 = 0;
    uint8_t a_hi_dc023 = 0;
    uint8_t x_dc023 = 0;
    uint8_t y_dc023 = 0;
    bool carry_dc023 = 0;
    bool zero_dc023 = 0;
    bool negative_dc023 = 0;
    bool overflow_dc023 = 0;
    uint16_t direct_page_dc023 = 0;
    uint8_t data_bank_dc023 = 0;
    uint8_t a_dc024 = 0;
    uint8_t a_hi_dc024 = 0;
    uint16_t x_dc024 = 0;
    uint16_t y_dc024 = 0;
    bool carry_dc024 = 0;
    bool zero_dc024 = 0;
    bool negative_dc024 = 0;
    bool overflow_dc024 = 0;
    uint16_t direct_page_dc024 = 0;
    uint8_t data_bank_dc024 = 0;
    uint8_t a_dbb53 = 0;
    uint8_t a_hi_dbb53 = 0;
    uint16_t x_dbb53 = 0;
    uint16_t y_dbb53 = 0;
    bool carry_dbb53 = 0;
    bool zero_dbb53 = 0;
    bool negative_dbb53 = 0;
    bool overflow_dbb53 = 0;
    uint16_t direct_page_dbb53 = 0;
    uint8_t data_bank_dbb53 = 0;
    uint8_t a_dc122 = 0;
    uint8_t a_hi_dc122 = 0;
    uint8_t x_dc122 = 0;
    uint8_t y_dc122 = 0;
    bool carry_dc122 = 0;
    bool zero_dc122 = 0;
    bool negative_dc122 = 0;
    bool overflow_dc122 = 0;
    uint16_t direct_page_dc122 = 0;
    uint8_t data_bank_dc122 = 0;
    uint8_t a_dbb54 = 0;
    uint8_t a_hi_dbb54 = 0;
    uint8_t x_dbb54 = 0;
    uint8_t y_dbb54 = 0;
    bool carry_dbb54 = 0;
    bool zero_dbb54 = 0;
    bool negative_dbb54 = 0;
    bool overflow_dbb54 = 0;
    uint16_t direct_page_dbb54 = 0;
    uint8_t data_bank_dbb54 = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDB5B, 0xD0CF08); GUARD_JSL(c, sp_call, 0xDB5B); } /* request_native_menu_audio_0e */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDB5F, 0xD0C83F); GUARD_JSL(c, sp_call, 0xDB5F); } /* hide_native_menu_icon_oam_objects */
    uint16_t a_all2 = r->a;
    bool carry_ret2 = r->c;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0x1842);
    if (value & 0x80) {
        a_hi_db7a = a_all2 >> 8;
        y_db7a = (uint8_t)y_ret;
        carry_db7a = carry_ret2;
        overflow_db7a = overflow_ret;
        direct_page_db7a = dp_ret;
        data_bank_db7a = db_ret;
        goto shared_DB7A;
    }
    uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x1808);
    uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0x1812 + (uint8_t)((a_all2 >> 8 << 8) | (uint8_t)(value2 << 1)));
    RAM8(0x0000 + sp0) = (((((value3 >> 0x0F << 7) | (overflow_ret << 6)) | (d_entry << 3)) | (i_entry << 2)) | ((value3 == 0) << 1)) | (value2 >> 7);
    if (value3 != 0) {
        a_db8f = (uint8_t)((uint8_t)((a_all2 >> 8 << 8) | (uint8_t)(value2 << 1)) + 0x1812);
        a_hi_db8f = (uint8_t)((a_all2 >> 8 << 8) | (uint8_t)(value2 << 1)) + 0x1812 >> 8;
        x_db8f = (uint8_t)((a_all2 >> 8 << 8) | (uint8_t)(value2 << 1));
        y_db8f = (uint8_t)y_ret;
        carry_db8f = value2 & 0x80;
        overflow_db8f = overflow_ret;
        direct_page_db8f = dp_ret;
        data_bank_db8f = db_ret;
        goto shared_DB8F;
    }
    a_hi_db7a2 = (uint8_t)((a_all2 >> 8 << 8) | (uint8_t)(value2 << 1)) + 0x1812 >> 8;
    y_db7a2 = (uint8_t)y_ret;
    carry_db7a2 = value2 & 0x80;
    overflow_db7a2 = overflow_ret;
    direct_page_db7a2 = dp_ret;
    data_bank_db7a2 = db_ret;
    uint16_t value8 = BUS16_RDP(c, (data_bank_db7a2 << 0x10) + 0x1812);
    if (value8 != 0) {
        a_db8f = 0x12;
        a_hi_db8f = 0x18;
        x_db8f = value8;
        y_db8f = y_db7a2;
        carry_db8f = carry_db7a2;
        overflow_db8f = overflow_db7a2;
        direct_page_db8f = direct_page_db7a2;
        data_bank_db8f = data_bank_db7a2;
        goto shared_DB8F;
    }
    uint16_t value9 = BUS16_RDP(c, (data_bank_db7a2 << 0x10) + 0x1814);
    if (value9 != 0) {
        a_db8f = 0x14;
        a_hi_db8f = 0x18;
        x_db8f = value9;
        y_db8f = y_db7a2;
        carry_db8f = carry_db7a2;
        overflow_db8f = overflow_db7a2;
        direct_page_db8f = direct_page_db7a2;
        data_bank_db8f = data_bank_db7a2;
        goto shared_DB8F;
    }
    a_db8f = 0x16;
    a_hi_db8f = 0x18;
    x_db8f = value9;
    y_db8f = y_db7a2;
    carry_db8f = carry_db7a2;
    overflow_db8f = overflow_db7a2;
    direct_page_db8f = direct_page_db7a2;
    data_bank_db8f = data_bank_db7a2;
    goto shared_DB8F;
    shared_DB7A:;
    uint16_t value4 = BUS16_RDP(c, (data_bank_db7a << 0x10) + 0x1812);
    if (value4 != 0) {
        a_db8f = 0x12;
        a_hi_db8f = 0x18;
        x_db8f = value4;
        y_db8f = y_db7a;
        carry_db8f = carry_db7a;
        overflow_db8f = overflow_db7a;
        direct_page_db8f = direct_page_db7a;
        data_bank_db8f = data_bank_db7a;
        goto shared_DB8F;
    }
    uint16_t value5 = BUS16_RDP(c, (data_bank_db7a << 0x10) + 0x1814);
    if (value5 != 0) {
        a_db8f = 0x14;
        a_hi_db8f = 0x18;
        x_db8f = value5;
        y_db8f = y_db7a;
        carry_db8f = carry_db7a;
        overflow_db8f = overflow_db7a;
        direct_page_db8f = direct_page_db7a;
        data_bank_db8f = data_bank_db7a;
        goto shared_DB8F;
    }
    a_db8f = 0x16;
    a_hi_db8f = 0x18;
    x_db8f = value5;
    y_db8f = y_db7a;
    carry_db8f = carry_db7a;
    overflow_db8f = overflow_db7a;
    direct_page_db8f = direct_page_db7a;
    data_bank_db8f = data_bank_db7a;
    goto shared_DB8F;
    shared_DB8F:;
    BUS16_SET(c, (data_bank_db8f << 0x10) + 0x1822, (a_hi_db8f << 8) | a_db8f);
    BUS16_SET(c, (data_bank_db8f << 0x10) + 0x183E, (a_hi_db8f << 8) | a_db8f);
    BUS16_SET(c, (data_bank_db8f << 0x10) + 0x1840, 0);
    r->a = (a_hi_db8f << 8) | a_db8f;
    r->x = x_db8f;
    r->y = y_db8f;
    r->c = carry_db8f;
    r->v = overflow_db8f;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_db8f;
    r->dp = direct_page_db8f;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDB9A, advance_native_target_cursor_and_skip_unavailable_entries, sp_in, 3); GUARD_JSR(c, sp_call, 0xDB9A); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool x_ret4 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value6 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x1803);
    BUS8_SET(c, (db_ret2 << 0x10) + 0x1803, value6 | 0x20);
    uint8_t value7 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret2 << 0x10) + 0x1802, value7 | 4);
    if (x_ret4) {
        a_dba7 = 4;
        a_hi_dba7 = a_all3 >> 8;
        x_dba7 = (uint8_t)x_ret5;
        y_dba7 = (uint8_t)y_ret2;
        carry_dba7 = carry_ret3;
        zero_dba7 = (value7 & 4) == 0;
        negative_dba7 = 0;
        overflow_dba7 = overflow_ret2;
        direct_page_dba7 = dp_ret2;
        data_bank_dba7 = db_ret2;
        goto shared_DBA7;
    } else {
        a_dba72 = 4;
        a_hi_dba72 = a_all3 >> 8;
        x_dba72 = x_ret5;
        y_dba72 = y_ret2;
        carry_dba72 = carry_ret3;
        zero_dba72 = (value7 & 4) == 0;
        negative_dba72 = 0;
        overflow_dba72 = overflow_ret2;
        direct_page_dba72 = dp_ret2;
        data_bank_dba72 = db_ret2;
        goto shared_DBA7_1;
    }
    shared_DBA7:;
    r->a = (a_hi_dba7 << 8) | a_dba7;
    r->x = x_dba7;
    r->y = y_dba7;
    r->c = carry_dba7;
    r->z = zero_dba7;
    r->n = negative_dba7;
    r->v = overflow_dba7;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_dba7;
    r->dp = direct_page_dba7;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBAA, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBAA); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); }
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool x_ret8 = r->xf;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret4 = r->v;
    uint16_t value10 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x1800);
    if (value10 & 0x8000) {
        if (x_ret8) {
            a_dba73 = (uint8_t)value10;
            a_hi_dba73 = value10 >> 8;
            x_dba73 = (uint8_t)x_ret9;
            y_dba73 = (uint8_t)y_ret4;
            carry_dba73 = carry_ret5;
            zero_dba73 = value10 == 0;
            negative_dba73 = value10 & 0x8000;
            overflow_dba73 = overflow_ret4;
            direct_page_dba73 = dp_ret4;
            data_bank_dba73 = db_ret4;
            goto shared_DBA7_2;
        } else {
            a_dba74 = (uint8_t)value10;
            a_hi_dba74 = value10 >> 8;
            x_dba74 = x_ret9;
            y_dba74 = y_ret4;
            carry_dba74 = carry_ret5;
            zero_dba74 = value10 == 0;
            negative_dba74 = value10 & 0x8000;
            overflow_dba74 = overflow_ret4;
            direct_page_dba74 = dp_ret4;
            data_bank_dba74 = db_ret4;
            goto shared_DBA7_3;
        }
    }
    if (x_ret8) {
        a_dbb5 = (uint8_t)value10;
        a_hi_dbb5 = value10 >> 8;
        x_dbb5 = (uint8_t)x_ret9;
        y_dbb5 = (uint8_t)y_ret4;
        carry_dbb5 = carry_ret5;
        zero_dbb5 = value10 == 0;
        negative_dbb5 = value10 & 0x8000;
        overflow_dbb5 = overflow_ret4;
        direct_page_dbb5 = dp_ret4;
        data_bank_dbb5 = db_ret4;
        goto shared_DBB5;
    } else {
        a_dbb52 = (uint8_t)value10;
        a_hi_dbb52 = value10 >> 8;
        x_dbb52 = x_ret9;
        y_dbb52 = y_ret4;
        carry_dbb52 = carry_ret5;
        zero_dbb52 = value10 == 0;
        negative_dbb52 = value10 & 0x8000;
        overflow_dbb52 = overflow_ret4;
        direct_page_dbb52 = dp_ret4;
        data_bank_dbb52 = db_ret4;
        goto shared_DBB5_1;
    }
    shared_DBA7_1:;
    r->a = (a_hi_dba72 << 8) | a_dba72;
    r->x = x_dba72;
    r->y = y_dba72;
    r->c = carry_dba72;
    r->z = zero_dba72;
    r->n = negative_dba72;
    r->v = overflow_dba72;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dba72;
    r->dp = direct_page_dba72;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBAA, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBAA); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); }
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool x_ret12 = r->xf;
    uint16_t x_ret13 = r->x;
    uint16_t y_ret6 = r->y;
    bool carry_ret7 = r->c;
    bool overflow_ret6 = r->v;
    uint16_t value11 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x1800);
    if (value11 & 0x8000) {
        if (x_ret12) {
            a_dba73 = (uint8_t)value11;
            a_hi_dba73 = value11 >> 8;
            x_dba73 = (uint8_t)x_ret13;
            y_dba73 = (uint8_t)y_ret6;
            carry_dba73 = carry_ret7;
            zero_dba73 = value11 == 0;
            negative_dba73 = value11 & 0x8000;
            overflow_dba73 = overflow_ret6;
            direct_page_dba73 = dp_ret6;
            data_bank_dba73 = db_ret6;
            goto shared_DBA7_2;
        } else {
            a_dba74 = (uint8_t)value11;
            a_hi_dba74 = value11 >> 8;
            x_dba74 = x_ret13;
            y_dba74 = y_ret6;
            carry_dba74 = carry_ret7;
            zero_dba74 = value11 == 0;
            negative_dba74 = value11 & 0x8000;
            overflow_dba74 = overflow_ret6;
            direct_page_dba74 = dp_ret6;
            data_bank_dba74 = db_ret6;
            goto shared_DBA7_3;
        }
    }
    if (x_ret12) {
        a_dbb5 = (uint8_t)value11;
        a_hi_dbb5 = value11 >> 8;
        x_dbb5 = (uint8_t)x_ret13;
        y_dbb5 = (uint8_t)y_ret6;
        carry_dbb5 = carry_ret7;
        zero_dbb5 = value11 == 0;
        negative_dbb5 = value11 & 0x8000;
        overflow_dbb5 = overflow_ret6;
        direct_page_dbb5 = dp_ret6;
        data_bank_dbb5 = db_ret6;
        goto shared_DBB5;
    } else {
        a_dbb52 = (uint8_t)value11;
        a_hi_dbb52 = value11 >> 8;
        x_dbb52 = x_ret13;
        y_dbb52 = y_ret6;
        carry_dbb52 = carry_ret7;
        zero_dbb52 = value11 == 0;
        negative_dbb52 = value11 & 0x8000;
        overflow_dbb52 = overflow_ret6;
        direct_page_dbb52 = dp_ret6;
        data_bank_dbb52 = db_ret6;
        goto shared_DBB5_1;
    }
    shared_DBA7_2:;
    r->a = (a_hi_dba73 << 8) | a_dba73;
    r->x = x_dba73;
    r->y = y_dba73;
    r->c = carry_dba73;
    r->z = zero_dba73;
    r->n = negative_dba73;
    r->v = overflow_dba73;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dba73;
    r->dp = direct_page_dba73;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBAA, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBAA); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); }
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    bool x_ret16 = r->xf;
    uint16_t x_ret17 = r->x;
    uint16_t y_ret8 = r->y;
    bool carry_ret9 = r->c;
    bool overflow_ret8 = r->v;
    uint16_t value12 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x1800);
    if (value12 & 0x8000) {
        if (x_ret16) {
            a_dba73 = (uint8_t)value12;
            a_hi_dba73 = value12 >> 8;
            x_dba73 = (uint8_t)x_ret17;
            y_dba73 = (uint8_t)y_ret8;
            carry_dba73 = carry_ret9;
            zero_dba73 = value12 == 0;
            negative_dba73 = value12 & 0x8000;
            overflow_dba73 = overflow_ret8;
            direct_page_dba73 = dp_ret8;
            data_bank_dba73 = db_ret8;
            goto shared_DBA7_2;
        } else {
            a_dba74 = (uint8_t)value12;
            a_hi_dba74 = value12 >> 8;
            x_dba74 = x_ret17;
            y_dba74 = y_ret8;
            carry_dba74 = carry_ret9;
            zero_dba74 = value12 == 0;
            negative_dba74 = value12 & 0x8000;
            overflow_dba74 = overflow_ret8;
            direct_page_dba74 = dp_ret8;
            data_bank_dba74 = db_ret8;
            goto shared_DBA7_3;
        }
    }
    if (x_ret16) {
        a_dbb5 = (uint8_t)value12;
        a_hi_dbb5 = value12 >> 8;
        x_dbb5 = (uint8_t)x_ret17;
        y_dbb5 = (uint8_t)y_ret8;
        carry_dbb5 = carry_ret9;
        zero_dbb5 = value12 == 0;
        negative_dbb5 = value12 & 0x8000;
        overflow_dbb5 = overflow_ret8;
        direct_page_dbb5 = dp_ret8;
        data_bank_dbb5 = db_ret8;
        goto shared_DBB5;
    } else {
        a_dbb52 = (uint8_t)value12;
        a_hi_dbb52 = value12 >> 8;
        x_dbb52 = x_ret17;
        y_dbb52 = y_ret8;
        carry_dbb52 = carry_ret9;
        zero_dbb52 = value12 == 0;
        negative_dbb52 = value12 & 0x8000;
        overflow_dbb52 = overflow_ret8;
        direct_page_dbb52 = dp_ret8;
        data_bank_dbb52 = db_ret8;
        goto shared_DBB5_1;
    }
    shared_DBA7_3:;
    r->a = (a_hi_dba74 << 8) | a_dba74;
    r->x = x_dba74;
    r->y = y_dba74;
    r->c = carry_dba74;
    r->z = zero_dba74;
    r->n = negative_dba74;
    r->v = overflow_dba74;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dba74;
    r->dp = direct_page_dba74;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBAA, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBAA); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBAD, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBAD); }
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret10 = r->db;
    bool x_ret20 = r->xf;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret10 = r->y;
    bool carry_ret11 = r->c;
    bool overflow_ret10 = r->v;
    uint16_t value13 = BUS16_RDP(c, (db_ret10 << 0x10) + 0x1800);
    if (value13 & 0x8000) {
        if (x_ret20) {
            a_dba73 = (uint8_t)value13;
            a_hi_dba73 = value13 >> 8;
            x_dba73 = (uint8_t)x_ret21;
            y_dba73 = (uint8_t)y_ret10;
            carry_dba73 = carry_ret11;
            zero_dba73 = value13 == 0;
            negative_dba73 = value13 & 0x8000;
            overflow_dba73 = overflow_ret10;
            direct_page_dba73 = dp_ret10;
            data_bank_dba73 = db_ret10;
            goto shared_DBA7_2;
        } else {
            a_dba74 = (uint8_t)value13;
            a_hi_dba74 = value13 >> 8;
            x_dba74 = x_ret21;
            y_dba74 = y_ret10;
            carry_dba74 = carry_ret11;
            zero_dba74 = value13 == 0;
            negative_dba74 = value13 & 0x8000;
            overflow_dba74 = overflow_ret10;
            direct_page_dba74 = dp_ret10;
            data_bank_dba74 = db_ret10;
            goto shared_DBA7_3;
        }
    }
    if (x_ret20) {
        a_dbb5 = (uint8_t)value13;
        a_hi_dbb5 = value13 >> 8;
        x_dbb5 = (uint8_t)x_ret21;
        y_dbb5 = (uint8_t)y_ret10;
        carry_dbb5 = carry_ret11;
        zero_dbb5 = value13 == 0;
        negative_dbb5 = value13 & 0x8000;
        overflow_dbb5 = overflow_ret10;
        direct_page_dbb5 = dp_ret10;
        data_bank_dbb5 = db_ret10;
        goto shared_DBB5;
    } else {
        a_dbb52 = (uint8_t)value13;
        a_hi_dbb52 = value13 >> 8;
        x_dbb52 = x_ret21;
        y_dbb52 = y_ret10;
        carry_dbb52 = carry_ret11;
        zero_dbb52 = value13 == 0;
        negative_dbb52 = value13 & 0x8000;
        overflow_dbb52 = overflow_ret10;
        direct_page_dbb52 = dp_ret10;
        data_bank_dbb52 = db_ret10;
        goto shared_DBB5_1;
    }
    shared_DBB5:;
    r->a = (a_hi_dbb5 << 8) | a_dbb5;
    r->x = x_dbb5;
    r->y = y_dbb5;
    r->c = carry_dbb5;
    r->z = zero_dbb5;
    r->n = negative_dbb5;
    r->v = overflow_dbb5;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dbb5;
    r->dp = direct_page_dbb5;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBB8, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBB8); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); }
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    bool x_ret24 = r->xf;
    uint16_t a_all13 = r->a;
    uint16_t x_ret25 = r->x;
    uint16_t y_ret12 = r->y;
    bool carry_ret13 = r->c;
    bool overflow_ret12 = r->v;
    uint8_t value14 = BUS8_RDP(c, (db_ret12 << 0x10) + 0x1801);
    if ((value14 & 0x40) != 0) {
        if (x_ret24) {
            a_dbcb = value14;
            a_hi_dbcb = a_all13 >> 8;
            x_dbcb = (uint8_t)x_ret25;
            y_dbcb = (uint8_t)y_ret12;
            carry_dbcb = carry_ret13;
            overflow_dbcb = overflow_ret12;
            direct_page_dbcb = dp_ret12;
            data_bank_dbcb = db_ret12;
            goto shared_DBCB;
        } else {
            a_dbcb2 = value14;
            a_hi_dbcb2 = a_all13 >> 8;
            x_dbcb2 = x_ret25;
            y_dbcb2 = y_ret12;
            carry_dbcb2 = carry_ret13;
            overflow_dbcb2 = overflow_ret12;
            direct_page_dbcb2 = dp_ret12;
            data_bank_dbcb2 = db_ret12;
            goto shared_DBCB_1;
        }
    }
    if ((value14 & 0x80) == 0) {
        uint8_t value15 = BUS8_RDP(c, (db_ret12 << 0x10) + 0x1801);
        if (x_ret24) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if ((value15 & 0x0A) != 0) {
                a_dbf3 = value15;
                a_hi_dbf3 = a_all13 >> 8;
                x_dbf3 = 0xFFFE;
                y_dbf3 = y_ret12;
                carry_dbf3 = carry_ret13;
                zero_dbf3 = (value15 & 0x0A) == 0;
                negative_dbf3 = 1;
                overflow_dbf3 = overflow_ret12;
                direct_page_dbf3 = dp_ret12;
                data_bank_dbf3 = db_ret12;
                goto shared_DBF3;
            }
            if ((value15 & 5) == 0) {
                a_dc12 = value15;
                a_hi_dc12 = a_all13 >> 8;
                x_dc12 = 2;
                y_dc12 = y_ret12;
                carry_dc12 = carry_ret13;
                zero_dc12 = (value15 & 5) == 0;
                negative_dc12 = 0;
                overflow_dc12 = overflow_ret12;
                direct_page_dc12 = dp_ret12;
                data_bank_dc12 = db_ret12;
                goto shared_DC12;
            }
            a_dbf3 = value15;
            a_hi_dbf3 = a_all13 >> 8;
            x_dbf3 = 2;
            y_dbf3 = y_ret12;
            carry_dbf3 = carry_ret13;
            zero_dbf3 = (value15 & 5) == 0;
            negative_dbf3 = 0;
            overflow_dbf3 = overflow_ret12;
            direct_page_dbf3 = dp_ret12;
            data_bank_dbf3 = db_ret12;
            goto shared_DBF3;
        }
    }
    if (x_ret24) {
        a_dbcb = 0;
        a_hi_dbcb = a_all13 >> 8;
        x_dbcb = (uint8_t)x_ret25;
        y_dbcb = (uint8_t)y_ret12;
        carry_dbcb = carry_ret13;
        overflow_dbcb = overflow_ret12;
        direct_page_dbcb = dp_ret12;
        data_bank_dbcb = db_ret12;
        goto shared_DBCB;
    } else {
        a_dbcb2 = 0;
        a_hi_dbcb2 = a_all13 >> 8;
        x_dbcb2 = x_ret25;
        y_dbcb2 = y_ret12;
        carry_dbcb2 = carry_ret13;
        overflow_dbcb2 = overflow_ret12;
        direct_page_dbcb2 = dp_ret12;
        data_bank_dbcb2 = db_ret12;
        goto shared_DBCB_1;
    }
    shared_DBB5_1:;
    r->a = (a_hi_dbb52 << 8) | a_dbb52;
    r->x = x_dbb52;
    r->y = y_dbb52;
    r->c = carry_dbb52;
    r->z = zero_dbb52;
    r->n = negative_dbb52;
    r->v = overflow_dbb52;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dbb52;
    r->dp = direct_page_dbb52;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBB8, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBB8); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); }
    uint16_t dp_ret14 = r->dp;
    uint8_t db_ret14 = r->db;
    bool x_ret28 = r->xf;
    uint16_t a_all15 = r->a;
    uint16_t x_ret29 = r->x;
    uint16_t y_ret14 = r->y;
    bool carry_ret15 = r->c;
    bool overflow_ret14 = r->v;
    uint8_t value16 = BUS8_RDP(c, (db_ret14 << 0x10) + 0x1801);
    if ((value16 & 0x40) != 0) {
        if (x_ret28) {
            a_dbcb = value16;
            a_hi_dbcb = a_all15 >> 8;
            x_dbcb = (uint8_t)x_ret29;
            y_dbcb = (uint8_t)y_ret14;
            carry_dbcb = carry_ret15;
            overflow_dbcb = overflow_ret14;
            direct_page_dbcb = dp_ret14;
            data_bank_dbcb = db_ret14;
            goto shared_DBCB;
        } else {
            a_dbcb2 = value16;
            a_hi_dbcb2 = a_all15 >> 8;
            x_dbcb2 = x_ret29;
            y_dbcb2 = y_ret14;
            carry_dbcb2 = carry_ret15;
            overflow_dbcb2 = overflow_ret14;
            direct_page_dbcb2 = dp_ret14;
            data_bank_dbcb2 = db_ret14;
            goto shared_DBCB_1;
        }
    }
    if ((value16 & 0x80) == 0) {
        uint8_t value17 = BUS8_RDP(c, (db_ret14 << 0x10) + 0x1801);
        if (x_ret28) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if ((value17 & 0x0A) != 0) {
                a_dbf3 = value17;
                a_hi_dbf3 = a_all15 >> 8;
                x_dbf3 = 0xFFFE;
                y_dbf3 = y_ret14;
                carry_dbf3 = carry_ret15;
                zero_dbf3 = (value17 & 0x0A) == 0;
                negative_dbf3 = 1;
                overflow_dbf3 = overflow_ret14;
                direct_page_dbf3 = dp_ret14;
                data_bank_dbf3 = db_ret14;
                goto shared_DBF3;
            }
            if ((value17 & 5) == 0) {
                a_dc12 = value17;
                a_hi_dc12 = a_all15 >> 8;
                x_dc12 = 2;
                y_dc12 = y_ret14;
                carry_dc12 = carry_ret15;
                zero_dc12 = (value17 & 5) == 0;
                negative_dc12 = 0;
                overflow_dc12 = overflow_ret14;
                direct_page_dc12 = dp_ret14;
                data_bank_dc12 = db_ret14;
                goto shared_DC12;
            }
            a_dbf3 = value17;
            a_hi_dbf3 = a_all15 >> 8;
            x_dbf3 = 2;
            y_dbf3 = y_ret14;
            carry_dbf3 = carry_ret15;
            zero_dbf3 = (value17 & 5) == 0;
            negative_dbf3 = 0;
            overflow_dbf3 = overflow_ret14;
            direct_page_dbf3 = dp_ret14;
            data_bank_dbf3 = db_ret14;
            goto shared_DBF3;
        }
    }
    if (x_ret28) {
        a_dbcb = 0;
        a_hi_dbcb = a_all15 >> 8;
        x_dbcb = (uint8_t)x_ret29;
        y_dbcb = (uint8_t)y_ret14;
        carry_dbcb = carry_ret15;
        overflow_dbcb = overflow_ret14;
        direct_page_dbcb = dp_ret14;
        data_bank_dbcb = db_ret14;
        goto shared_DBCB;
    } else {
        a_dbcb2 = 0;
        a_hi_dbcb2 = a_all15 >> 8;
        x_dbcb2 = x_ret29;
        y_dbcb2 = y_ret14;
        carry_dbcb2 = carry_ret15;
        overflow_dbcb2 = overflow_ret14;
        direct_page_dbcb2 = dp_ret14;
        data_bank_dbcb2 = db_ret14;
        goto shared_DBCB_1;
    }
    shared_DBCB:;
    RAM8(0x0000 + sp0) = a_dbcb;
    uint8_t value18 = BUS8_RDP(c, (data_bank_dbcb << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_dbcb << 0x10) + 0x1803, value18 & 0xDF);
    uint8_t value19 = RAM8(0x0000 + sp0);
    if ((((a_hi_dbcb << 8) | value19) & 0x40) == 0) {
        a_dbdf = value19;
        a_hi_dbdf = a_hi_dbcb;
        x_dbdf = x_dbcb;
        y_dbdf = y_dbcb;
        carry_dbdf = carry_dbcb;
        zero_dbdf = (((a_hi_dbcb << 8) | value19) & 0x40) == 0;
        negative_dbdf = value19 & 0x80;
        overflow_dbdf = overflow_dbcb;
        direct_page_dbdf = direct_page_dbcb;
        data_bank_dbdf = data_bank_dbcb;
        goto shared_DBDF;
    }
    RAM8(0x0000 + sp0) = ((((value19 >> 7 << 7) | (overflow_dbcb << 6) | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (((((a_hi_dbcb << 8) | value19) & 0x40) == 0) << 1) | carry_dbcb;
    r->a = (a_hi_dbcb << 8) | value19;
    r->x = x_dbcb;
    r->y = y_dbcb;
    r->c = carry_dbcb;
    r->z = (((a_hi_dbcb << 8) | value19) & 0x40) == 0;
    r->n = value19 & 0x80;
    r->v = overflow_dbcb;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dbcb;
    r->dp = direct_page_dbcb;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBDD, 0xC068EA); GUARD_JSL(c, sp_call, 0xDBDD); } /* open_native_menu_ring_and_wait_for_phase_zero_public */
    r->sp += 1;
    uint16_t dp_ret15 = r->dp;
    uint8_t db_ret15 = r->db;
    uint16_t a_all16 = r->a;
    uint16_t x_ret30 = r->x;
    uint16_t y_ret15 = r->y;
    uint8_t value20 = RAM8(0x0000 + sp0);
    if (value20 & 0x20) {
        if (value20 & 0x10) {
            a_dbdf2 = (uint8_t)a_all16;
            a_hi_dbdf2 = a_all16 >> 8;
            x_dbdf2 = (uint8_t)x_ret30;
            y_dbdf2 = (uint8_t)y_ret15;
            carry_dbdf2 = value20 & 0x01;
            zero_dbdf2 = value20 & 0x02;
            negative_dbdf2 = value20 & 0x80;
            overflow_dbdf2 = value20 & 0x40;
            direct_page_dbdf2 = dp_ret15;
            data_bank_dbdf2 = db_ret15;
            irq_disable_dbdf = value20 & 0x04;
            decimal_dbdf = value20 & 0x08;
            goto shared_DBDF_1;
        } else {
            a_dbdf3 = (uint8_t)a_all16;
            a_hi_dbdf3 = a_all16 >> 8;
            x_dbdf3 = x_ret30;
            y_dbdf3 = y_ret15;
            carry_dbdf3 = value20 & 0x01;
            zero_dbdf3 = value20 & 0x02;
            negative_dbdf3 = value20 & 0x80;
            overflow_dbdf3 = value20 & 0x40;
            direct_page_dbdf3 = dp_ret15;
            data_bank_dbdf3 = db_ret15;
            irq_disable_dbdf2 = value20 & 0x04;
            decimal_dbdf2 = value20 & 0x08;
            goto shared_DBDF_2;
        }
    } else {
        if (value20 & 0x10) {
            a_dbdf = (uint8_t)a_all16;
            a_hi_dbdf = a_all16 >> 8;
            x_dbdf = (uint8_t)x_ret30;
            y_dbdf = (uint8_t)y_ret15;
            carry_dbdf = value20 & 0x01;
            zero_dbdf = value20 & 0x02;
            negative_dbdf = value20 & 0x80;
            overflow_dbdf = value20 & 0x40;
            direct_page_dbdf = dp_ret15;
            data_bank_dbdf = db_ret15;
            goto shared_DBDF;
        } else {
            a_dbdf4 = (uint8_t)a_all16;
            a_hi_dbdf4 = a_all16 >> 8;
            x_dbdf4 = x_ret30;
            y_dbdf4 = y_ret15;
            carry_dbdf4 = value20 & 0x01;
            zero_dbdf4 = value20 & 0x02;
            negative_dbdf4 = value20 & 0x80;
            overflow_dbdf4 = value20 & 0x40;
            direct_page_dbdf4 = dp_ret15;
            data_bank_dbdf4 = db_ret15;
            irq_disable_dbdf3 = value20 & 0x04;
            decimal_dbdf3 = value20 & 0x08;
            goto shared_DBDF_3;
        }
    }
    shared_DBCB_1:;
    RAM8(0x0000 + sp0) = a_dbcb2;
    uint8_t value21 = BUS8_RDP(c, (data_bank_dbcb2 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_dbcb2 << 0x10) + 0x1803, value21 & 0xDF);
    uint8_t value22 = RAM8(0x0000 + sp0);
    if ((((a_hi_dbcb2 << 8) | value22) & 0x40) == 0) {
        a_dbdf4 = value22;
        a_hi_dbdf4 = a_hi_dbcb2;
        x_dbdf4 = x_dbcb2;
        y_dbdf4 = y_dbcb2;
        carry_dbdf4 = carry_dbcb2;
        zero_dbdf4 = (((a_hi_dbcb2 << 8) | value22) & 0x40) == 0;
        negative_dbdf4 = value22 & 0x80;
        overflow_dbdf4 = overflow_dbcb2;
        direct_page_dbdf4 = direct_page_dbcb2;
        data_bank_dbdf4 = data_bank_dbcb2;
        irq_disable_dbdf3 = i_entry;
        decimal_dbdf3 = d_entry;
        goto shared_DBDF_3;
    }
    RAM8(0x0000 + sp0) = ((((value22 >> 7 << 7) | (overflow_dbcb2 << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((((a_hi_dbcb2 << 8) | value22) & 0x40) == 0) << 1) | carry_dbcb2;
    r->a = (a_hi_dbcb2 << 8) | value22;
    r->x = x_dbcb2;
    r->y = y_dbcb2;
    r->c = carry_dbcb2;
    r->z = (((a_hi_dbcb2 << 8) | value22) & 0x40) == 0;
    r->n = value22 & 0x80;
    r->v = overflow_dbcb2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dbcb2;
    r->dp = direct_page_dbcb2;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBDD, 0xC068EA); GUARD_JSL(c, sp_call, 0xDBDD); } /* open_native_menu_ring_and_wait_for_phase_zero_public */
    r->sp += 1;
    uint16_t dp_ret16 = r->dp;
    uint8_t db_ret16 = r->db;
    uint16_t a_all17 = r->a;
    uint16_t x_ret31 = r->x;
    uint16_t y_ret16 = r->y;
    uint8_t value23 = RAM8(0x0000 + sp0);
    if (value23 & 0x20) {
        if (value23 & 0x10) {
            a_dbdf2 = (uint8_t)a_all17;
            a_hi_dbdf2 = a_all17 >> 8;
            x_dbdf2 = (uint8_t)x_ret31;
            y_dbdf2 = (uint8_t)y_ret16;
            carry_dbdf2 = value23 & 0x01;
            zero_dbdf2 = value23 & 0x02;
            negative_dbdf2 = value23 & 0x80;
            overflow_dbdf2 = value23 & 0x40;
            direct_page_dbdf2 = dp_ret16;
            data_bank_dbdf2 = db_ret16;
            irq_disable_dbdf = value23 & 0x04;
            decimal_dbdf = value23 & 0x08;
            goto shared_DBDF_1;
        } else {
            a_dbdf3 = (uint8_t)a_all17;
            a_hi_dbdf3 = a_all17 >> 8;
            x_dbdf3 = x_ret31;
            y_dbdf3 = y_ret16;
            carry_dbdf3 = value23 & 0x01;
            zero_dbdf3 = value23 & 0x02;
            negative_dbdf3 = value23 & 0x80;
            overflow_dbdf3 = value23 & 0x40;
            direct_page_dbdf3 = dp_ret16;
            data_bank_dbdf3 = db_ret16;
            irq_disable_dbdf2 = value23 & 0x04;
            decimal_dbdf2 = value23 & 0x08;
            goto shared_DBDF_2;
        }
    } else {
        if (value23 & 0x10) {
            a_dbdf = (uint8_t)a_all17;
            a_hi_dbdf = a_all17 >> 8;
            x_dbdf = (uint8_t)x_ret31;
            y_dbdf = (uint8_t)y_ret16;
            carry_dbdf = value23 & 0x01;
            zero_dbdf = value23 & 0x02;
            negative_dbdf = value23 & 0x80;
            overflow_dbdf = value23 & 0x40;
            direct_page_dbdf = dp_ret16;
            data_bank_dbdf = db_ret16;
            goto shared_DBDF;
        } else {
            a_dbdf4 = (uint8_t)a_all17;
            a_hi_dbdf4 = a_all17 >> 8;
            x_dbdf4 = x_ret31;
            y_dbdf4 = y_ret16;
            carry_dbdf4 = value23 & 0x01;
            zero_dbdf4 = value23 & 0x02;
            negative_dbdf4 = value23 & 0x80;
            overflow_dbdf4 = value23 & 0x40;
            direct_page_dbdf4 = dp_ret16;
            data_bank_dbdf4 = db_ret16;
            irq_disable_dbdf3 = value23 & 0x04;
            decimal_dbdf3 = value23 & 0x08;
            goto shared_DBDF_3;
        }
    }
    shared_DBF3:;
    r->a = (a_hi_dbf3 << 8) | a_dbf3;
    r->x = x_dbf3;
    r->y = y_dbf3;
    r->c = carry_dbf3;
    r->z = zero_dbf3;
    r->n = negative_dbf3;
    r->v = overflow_dbf3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dbf3;
    r->dp = direct_page_dbf3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBF6, 0xD0CEF8); GUARD_JSL(c, sp_call, 0xDBF6); } /* request_native_menu_audio_0c */
    uint8_t db_ret17 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret32 = r->xf;
    uint16_t a_all18 = r->a;
    uint16_t x_ret33 = r->x;
    uint16_t y_ret17 = r->y;
    uint8_t value24 = BUS8_RDP(c, (db_ret17 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret17 << 0x10) + 0x1802, value24 | 4);
    if (x_ret32) {
        BUS8_SET(c, (db_ret17 << 0x10) + 0x1840, (uint8_t)x_ret33);
        r->a = (a_all18 >> 8 << 8) | 4;
        r->x = (uint8_t)x_ret33;
        r->y = (uint8_t)y_ret17;
        r->z = (value24 & 4) == 0;
        r->n = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC01, advance_native_target_cursor_and_skip_unavailable_entries, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC01); }
        uint16_t dp_ret18 = r->dp;
        uint8_t db_ret18 = r->db;
        bool m_ret15 = r->mf;
        bool x_ret34 = r->xf;
        uint16_t a_all19 = r->a;
        uint16_t x_ret35 = r->x;
        uint16_t y_ret18 = r->y;
        bool carry_ret19 = r->c;
        bool zero_ret19 = r->z;
        bool negative_ret19 = r->n;
        bool overflow_ret18 = r->v;
        if (m_ret15) {
            if (x_ret34) {
                a_dc02 = (uint8_t)a_all19;
                a_hi_dc02 = a_all19 >> 8;
                x_dc02 = (uint8_t)x_ret35;
                y_dc02 = (uint8_t)y_ret18;
                carry_dc02 = carry_ret19;
                zero_dc02 = zero_ret19;
                negative_dc02 = negative_ret19;
                overflow_dc02 = overflow_ret18;
                direct_page_dc02 = dp_ret18;
                data_bank_dc02 = db_ret18;
                goto shared_DC02;
            } else {
                a_dc022 = (uint8_t)a_all19;
                a_hi_dc022 = a_all19 >> 8;
                x_dc022 = x_ret35;
                y_dc022 = y_ret18;
                carry_dc022 = carry_ret19;
                zero_dc022 = zero_ret19;
                negative_dc022 = negative_ret19;
                overflow_dc022 = overflow_ret18;
                direct_page_dc022 = dp_ret18;
                data_bank_dc022 = db_ret18;
                goto shared_DC02_1;
            }
        } else {
            if (x_ret34) {
                a_dc023 = (uint8_t)a_all19;
                a_hi_dc023 = a_all19 >> 8;
                x_dc023 = (uint8_t)x_ret35;
                y_dc023 = (uint8_t)y_ret18;
                carry_dc023 = carry_ret19;
                zero_dc023 = zero_ret19;
                negative_dc023 = negative_ret19;
                overflow_dc023 = overflow_ret18;
                direct_page_dc023 = dp_ret18;
                data_bank_dc023 = db_ret18;
                goto shared_DC02_2;
            } else {
                a_dc024 = (uint8_t)a_all19;
                a_hi_dc024 = a_all19 >> 8;
                x_dc024 = x_ret35;
                y_dc024 = y_ret18;
                carry_dc024 = carry_ret19;
                zero_dc024 = zero_ret19;
                negative_dc024 = negative_ret19;
                overflow_dc024 = overflow_ret18;
                direct_page_dc024 = dp_ret18;
                data_bank_dc024 = db_ret18;
                goto shared_DC02_3;
            }
        }
    } else {
        BUS16_SET(c, (db_ret17 << 0x10) + 0x1840, x_ret33);
        r->a = (a_all18 >> 8 << 8) | 4;
        r->z = (value24 & 4) == 0;
        r->n = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC01, advance_native_target_cursor_and_skip_unavailable_entries, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC01); }
        uint16_t dp_ret19 = r->dp;
        uint8_t db_ret19 = r->db;
        bool m_ret16 = r->mf;
        bool x_ret36 = r->xf;
        uint16_t a_all20 = r->a;
        uint16_t x_ret37 = r->x;
        uint16_t y_ret19 = r->y;
        bool carry_ret20 = r->c;
        bool zero_ret20 = r->z;
        bool negative_ret20 = r->n;
        bool overflow_ret19 = r->v;
        if (m_ret16) {
            if (x_ret36) {
                a_dc02 = (uint8_t)a_all20;
                a_hi_dc02 = a_all20 >> 8;
                x_dc02 = (uint8_t)x_ret37;
                y_dc02 = (uint8_t)y_ret19;
                carry_dc02 = carry_ret20;
                zero_dc02 = zero_ret20;
                negative_dc02 = negative_ret20;
                overflow_dc02 = overflow_ret19;
                direct_page_dc02 = dp_ret19;
                data_bank_dc02 = db_ret19;
                goto shared_DC02;
            } else {
                a_dc022 = (uint8_t)a_all20;
                a_hi_dc022 = a_all20 >> 8;
                x_dc022 = x_ret37;
                y_dc022 = y_ret19;
                carry_dc022 = carry_ret20;
                zero_dc022 = zero_ret20;
                negative_dc022 = negative_ret20;
                overflow_dc022 = overflow_ret19;
                direct_page_dc022 = dp_ret19;
                data_bank_dc022 = db_ret19;
                goto shared_DC02_1;
            }
        } else {
            if (x_ret36) {
                a_dc023 = (uint8_t)a_all20;
                a_hi_dc023 = a_all20 >> 8;
                x_dc023 = (uint8_t)x_ret37;
                y_dc023 = (uint8_t)y_ret19;
                carry_dc023 = carry_ret20;
                zero_dc023 = zero_ret20;
                negative_dc023 = negative_ret20;
                overflow_dc023 = overflow_ret19;
                direct_page_dc023 = dp_ret19;
                data_bank_dc023 = db_ret19;
                goto shared_DC02_2;
            } else {
                a_dc024 = (uint8_t)a_all20;
                a_hi_dc024 = a_all20 >> 8;
                x_dc024 = x_ret37;
                y_dc024 = y_ret19;
                carry_dc024 = carry_ret20;
                zero_dc024 = zero_ret20;
                negative_dc024 = negative_ret20;
                overflow_dc024 = overflow_ret19;
                direct_page_dc024 = dp_ret19;
                data_bank_dc024 = db_ret19;
                goto shared_DC02_3;
            }
        }
    }
    shared_DC12:;
    a_dbb53 = a_dc12;
    a_hi_dbb53 = a_hi_dc12;
    x_dbb53 = x_dc12;
    y_dbb53 = y_dc12;
    carry_dbb53 = carry_dc12;
    zero_dbb53 = zero_dc12;
    negative_dbb53 = negative_dc12;
    overflow_dbb53 = overflow_dc12;
    direct_page_dbb53 = direct_page_dc12;
    data_bank_dbb53 = data_bank_dc12;
    goto shared_DBB5_2;
    shared_DBDF:;
    r->a = (a_hi_dbdf << 8) | a_dbdf;
    r->x = x_dbdf;
    r->y = y_dbdf;
    r->c = carry_dbdf;
    r->z = zero_dbdf;
    r->n = negative_dbdf;
    r->v = overflow_dbdf;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dbdf;
    r->dp = direct_page_dbdf;
    RETURN_RTL(c);
    shared_DBDF_1:;
    r->a = (a_hi_dbdf2 << 8) | a_dbdf2;
    r->x = x_dbdf2;
    r->y = y_dbdf2;
    r->c = carry_dbdf2;
    r->z = zero_dbdf2;
    r->n = negative_dbdf2;
    r->v = overflow_dbdf2;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_dbdf2;
    r->dp = direct_page_dbdf2;
    r->i = irq_disable_dbdf;
    r->d = decimal_dbdf;
    RETURN_RTL(c);
    shared_DBDF_2:;
    r->a = (a_hi_dbdf3 << 8) | a_dbdf3;
    r->x = x_dbdf3;
    r->y = y_dbdf3;
    r->c = carry_dbdf3;
    r->z = zero_dbdf3;
    r->n = negative_dbdf3;
    r->v = overflow_dbdf3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dbdf3;
    r->dp = direct_page_dbdf3;
    r->i = irq_disable_dbdf2;
    r->d = decimal_dbdf2;
    RETURN_RTL(c);
    shared_DBDF_3:;
    r->a = (a_hi_dbdf4 << 8) | a_dbdf4;
    r->x = x_dbdf4;
    r->y = y_dbdf4;
    r->c = carry_dbdf4;
    r->z = zero_dbdf4;
    r->n = negative_dbdf4;
    r->v = overflow_dbdf4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dbdf4;
    r->dp = direct_page_dbdf4;
    r->i = irq_disable_dbdf3;
    r->d = decimal_dbdf3;
    RETURN_RTL(c);
    shared_DC02:;
    r->a = (a_hi_dc02 << 8) | a_dc02;
    r->x = x_dc02;
    r->y = y_dc02;
    r->c = carry_dc02;
    r->z = zero_dc02;
    r->n = negative_dc02;
    r->v = overflow_dc02;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_dc02;
    r->dp = direct_page_dc02;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret21 = r->dp;
    uint8_t db_ret21 = r->db;
    bool x_ret40 = r->xf;
    uint16_t a_all22 = r->a;
    uint16_t x_ret41 = r->x;
    uint16_t y_ret21 = r->y;
    bool carry_ret22 = r->c;
    bool overflow_ret21 = r->v;
    uint8_t value25 = BUS8_RDP(c, (db_ret21 << 0x10) + 0x1801);
    if ((value25 & 0x8F) != 0) {
        if (x_ret40) {
            a_dc02 = value25 & 0x8F;
            a_hi_dc02 = a_all22 >> 8;
            x_dc02 = (uint8_t)x_ret41;
            y_dc02 = (uint8_t)y_ret21;
            carry_dc02 = carry_ret22;
            zero_dc02 = (value25 & 0x8F) == 0;
            negative_dc02 = value25 & 0x8F & 0x80;
            overflow_dc02 = overflow_ret21;
            direct_page_dc02 = dp_ret21;
            data_bank_dc02 = db_ret21;
            goto shared_DC02;
        } else {
            a_dc022 = value25 & 0x8F;
            a_hi_dc022 = a_all22 >> 8;
            x_dc022 = x_ret41;
            y_dc022 = y_ret21;
            carry_dc022 = carry_ret22;
            zero_dc022 = (value25 & 0x8F) == 0;
            negative_dc022 = value25 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret21;
            direct_page_dc022 = dp_ret21;
            data_bank_dc022 = db_ret21;
            goto shared_DC02_1;
        }
    }
    if (x_ret40) {
        a_dc122 = value25 & 0x8F;
        a_hi_dc122 = a_all22 >> 8;
        x_dc122 = (uint8_t)x_ret41;
        y_dc122 = (uint8_t)y_ret21;
        carry_dc122 = carry_ret22;
        zero_dc122 = (value25 & 0x8F) == 0;
        negative_dc122 = value25 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret21;
        direct_page_dc122 = dp_ret21;
        data_bank_dc122 = db_ret21;
        goto shared_DC12_1;
    } else {
        a_dc12 = value25 & 0x8F;
        a_hi_dc12 = a_all22 >> 8;
        x_dc12 = x_ret41;
        y_dc12 = y_ret21;
        carry_dc12 = carry_ret22;
        zero_dc12 = (value25 & 0x8F) == 0;
        negative_dc12 = value25 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret21;
        direct_page_dc12 = dp_ret21;
        data_bank_dc12 = db_ret21;
        goto shared_DC12;
    }
    shared_DC02_1:;
    r->a = (a_hi_dc022 << 8) | a_dc022;
    r->x = x_dc022;
    r->y = y_dc022;
    r->c = carry_dc022;
    r->z = zero_dc022;
    r->n = negative_dc022;
    r->v = overflow_dc022;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dc022;
    r->dp = direct_page_dc022;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret23 = r->dp;
    uint8_t db_ret23 = r->db;
    bool x_ret44 = r->xf;
    uint16_t a_all24 = r->a;
    uint16_t x_ret45 = r->x;
    uint16_t y_ret23 = r->y;
    bool carry_ret24 = r->c;
    bool overflow_ret23 = r->v;
    uint8_t value26 = BUS8_RDP(c, (db_ret23 << 0x10) + 0x1801);
    if ((value26 & 0x8F) != 0) {
        if (x_ret44) {
            a_dc02 = value26 & 0x8F;
            a_hi_dc02 = a_all24 >> 8;
            x_dc02 = (uint8_t)x_ret45;
            y_dc02 = (uint8_t)y_ret23;
            carry_dc02 = carry_ret24;
            zero_dc02 = (value26 & 0x8F) == 0;
            negative_dc02 = value26 & 0x8F & 0x80;
            overflow_dc02 = overflow_ret23;
            direct_page_dc02 = dp_ret23;
            data_bank_dc02 = db_ret23;
            goto shared_DC02;
        } else {
            a_dc022 = value26 & 0x8F;
            a_hi_dc022 = a_all24 >> 8;
            x_dc022 = x_ret45;
            y_dc022 = y_ret23;
            carry_dc022 = carry_ret24;
            zero_dc022 = (value26 & 0x8F) == 0;
            negative_dc022 = value26 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret23;
            direct_page_dc022 = dp_ret23;
            data_bank_dc022 = db_ret23;
            goto shared_DC02_1;
        }
    }
    if (x_ret44) {
        a_dc122 = value26 & 0x8F;
        a_hi_dc122 = a_all24 >> 8;
        x_dc122 = (uint8_t)x_ret45;
        y_dc122 = (uint8_t)y_ret23;
        carry_dc122 = carry_ret24;
        zero_dc122 = (value26 & 0x8F) == 0;
        negative_dc122 = value26 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret23;
        direct_page_dc122 = dp_ret23;
        data_bank_dc122 = db_ret23;
        goto shared_DC12_1;
    } else {
        a_dc12 = value26 & 0x8F;
        a_hi_dc12 = a_all24 >> 8;
        x_dc12 = x_ret45;
        y_dc12 = y_ret23;
        carry_dc12 = carry_ret24;
        zero_dc12 = (value26 & 0x8F) == 0;
        negative_dc12 = value26 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret23;
        direct_page_dc12 = dp_ret23;
        data_bank_dc12 = db_ret23;
        goto shared_DC12;
    }
    shared_DC02_2:;
    r->a = (a_hi_dc023 << 8) | a_dc023;
    r->x = x_dc023;
    r->y = y_dc023;
    r->c = carry_dc023;
    r->z = zero_dc023;
    r->n = negative_dc023;
    r->v = overflow_dc023;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dc023;
    r->dp = direct_page_dc023;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret25 = r->dp;
    uint8_t db_ret25 = r->db;
    bool x_ret48 = r->xf;
    uint16_t a_all26 = r->a;
    uint16_t x_ret49 = r->x;
    uint16_t y_ret25 = r->y;
    bool carry_ret26 = r->c;
    bool overflow_ret25 = r->v;
    uint8_t value27 = BUS8_RDP(c, (db_ret25 << 0x10) + 0x1801);
    if ((value27 & 0x8F) != 0) {
        if (x_ret48) {
            a_dc02 = value27 & 0x8F;
            a_hi_dc02 = a_all26 >> 8;
            x_dc02 = (uint8_t)x_ret49;
            y_dc02 = (uint8_t)y_ret25;
            carry_dc02 = carry_ret26;
            zero_dc02 = (value27 & 0x8F) == 0;
            negative_dc02 = value27 & 0x8F & 0x80;
            overflow_dc02 = overflow_ret25;
            direct_page_dc02 = dp_ret25;
            data_bank_dc02 = db_ret25;
            goto shared_DC02;
        } else {
            a_dc022 = value27 & 0x8F;
            a_hi_dc022 = a_all26 >> 8;
            x_dc022 = x_ret49;
            y_dc022 = y_ret25;
            carry_dc022 = carry_ret26;
            zero_dc022 = (value27 & 0x8F) == 0;
            negative_dc022 = value27 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret25;
            direct_page_dc022 = dp_ret25;
            data_bank_dc022 = db_ret25;
            goto shared_DC02_1;
        }
    }
    if (x_ret48) {
        a_dc122 = value27 & 0x8F;
        a_hi_dc122 = a_all26 >> 8;
        x_dc122 = (uint8_t)x_ret49;
        y_dc122 = (uint8_t)y_ret25;
        carry_dc122 = carry_ret26;
        zero_dc122 = (value27 & 0x8F) == 0;
        negative_dc122 = value27 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret25;
        direct_page_dc122 = dp_ret25;
        data_bank_dc122 = db_ret25;
        goto shared_DC12_1;
    } else {
        a_dc12 = value27 & 0x8F;
        a_hi_dc12 = a_all26 >> 8;
        x_dc12 = x_ret49;
        y_dc12 = y_ret25;
        carry_dc12 = carry_ret26;
        zero_dc12 = (value27 & 0x8F) == 0;
        negative_dc12 = value27 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret25;
        direct_page_dc12 = dp_ret25;
        data_bank_dc12 = db_ret25;
        goto shared_DC12;
    }
    shared_DC02_3:;
    r->a = (a_hi_dc024 << 8) | a_dc024;
    r->x = x_dc024;
    r->y = y_dc024;
    r->c = carry_dc024;
    r->z = zero_dc024;
    r->n = negative_dc024;
    r->v = overflow_dc024;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dc024;
    r->dp = direct_page_dc024;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret27 = r->dp;
    uint8_t db_ret27 = r->db;
    bool x_ret52 = r->xf;
    uint16_t a_all28 = r->a;
    uint16_t x_ret53 = r->x;
    uint16_t y_ret27 = r->y;
    bool carry_ret28 = r->c;
    bool overflow_ret27 = r->v;
    uint8_t value28 = BUS8_RDP(c, (db_ret27 << 0x10) + 0x1801);
    if ((value28 & 0x8F) != 0) {
        if (x_ret52) {
            a_dc02 = value28 & 0x8F;
            a_hi_dc02 = a_all28 >> 8;
            x_dc02 = (uint8_t)x_ret53;
            y_dc02 = (uint8_t)y_ret27;
            carry_dc02 = carry_ret28;
            zero_dc02 = (value28 & 0x8F) == 0;
            negative_dc02 = value28 & 0x8F & 0x80;
            overflow_dc02 = overflow_ret27;
            direct_page_dc02 = dp_ret27;
            data_bank_dc02 = db_ret27;
            goto shared_DC02;
        } else {
            a_dc022 = value28 & 0x8F;
            a_hi_dc022 = a_all28 >> 8;
            x_dc022 = x_ret53;
            y_dc022 = y_ret27;
            carry_dc022 = carry_ret28;
            zero_dc022 = (value28 & 0x8F) == 0;
            negative_dc022 = value28 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret27;
            direct_page_dc022 = dp_ret27;
            data_bank_dc022 = db_ret27;
            goto shared_DC02_1;
        }
    }
    if (x_ret52) {
        a_dc122 = value28 & 0x8F;
        a_hi_dc122 = a_all28 >> 8;
        x_dc122 = (uint8_t)x_ret53;
        y_dc122 = (uint8_t)y_ret27;
        carry_dc122 = carry_ret28;
        zero_dc122 = (value28 & 0x8F) == 0;
        negative_dc122 = value28 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret27;
        direct_page_dc122 = dp_ret27;
        data_bank_dc122 = db_ret27;
        goto shared_DC12_1;
    } else {
        a_dc12 = value28 & 0x8F;
        a_hi_dc12 = a_all28 >> 8;
        x_dc12 = x_ret53;
        y_dc12 = y_ret27;
        carry_dc12 = carry_ret28;
        zero_dc12 = (value28 & 0x8F) == 0;
        negative_dc12 = value28 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret27;
        direct_page_dc12 = dp_ret27;
        data_bank_dc12 = db_ret27;
        goto shared_DC12;
    }
    shared_DBB5_2:;
    r->a = (a_hi_dbb53 << 8) | a_dbb53;
    r->x = x_dbb53;
    r->y = y_dbb53;
    r->c = carry_dbb53;
    r->z = zero_dbb53;
    r->n = negative_dbb53;
    r->v = overflow_dbb53;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dbb53;
    r->dp = direct_page_dbb53;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBB8, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBB8); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); }
    uint16_t dp_ret29 = r->dp;
    uint8_t db_ret29 = r->db;
    bool x_ret56 = r->xf;
    uint16_t a_all30 = r->a;
    uint16_t x_ret57 = r->x;
    uint16_t y_ret29 = r->y;
    bool carry_ret30 = r->c;
    bool overflow_ret29 = r->v;
    uint8_t value29 = BUS8_RDP(c, (db_ret29 << 0x10) + 0x1801);
    if ((value29 & 0x40) != 0) {
        if (x_ret56) {
            a_dbcb = value29;
            a_hi_dbcb = a_all30 >> 8;
            x_dbcb = (uint8_t)x_ret57;
            y_dbcb = (uint8_t)y_ret29;
            carry_dbcb = carry_ret30;
            overflow_dbcb = overflow_ret29;
            direct_page_dbcb = dp_ret29;
            data_bank_dbcb = db_ret29;
            goto shared_DBCB;
        } else {
            a_dbcb2 = value29;
            a_hi_dbcb2 = a_all30 >> 8;
            x_dbcb2 = x_ret57;
            y_dbcb2 = y_ret29;
            carry_dbcb2 = carry_ret30;
            overflow_dbcb2 = overflow_ret29;
            direct_page_dbcb2 = dp_ret29;
            data_bank_dbcb2 = db_ret29;
            goto shared_DBCB_1;
        }
    }
    if ((value29 & 0x80) == 0) {
        uint8_t value30 = BUS8_RDP(c, (db_ret29 << 0x10) + 0x1801);
        if (x_ret56) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if ((value30 & 0x0A) != 0) {
                a_dbf3 = value30;
                a_hi_dbf3 = a_all30 >> 8;
                x_dbf3 = 0xFFFE;
                y_dbf3 = y_ret29;
                carry_dbf3 = carry_ret30;
                zero_dbf3 = (value30 & 0x0A) == 0;
                negative_dbf3 = 1;
                overflow_dbf3 = overflow_ret29;
                direct_page_dbf3 = dp_ret29;
                data_bank_dbf3 = db_ret29;
                goto shared_DBF3;
            }
            if ((value30 & 5) == 0) {
                a_dc12 = value30;
                a_hi_dc12 = a_all30 >> 8;
                x_dc12 = 2;
                y_dc12 = y_ret29;
                carry_dc12 = carry_ret30;
                zero_dc12 = (value30 & 5) == 0;
                negative_dc12 = 0;
                overflow_dc12 = overflow_ret29;
                direct_page_dc12 = dp_ret29;
                data_bank_dc12 = db_ret29;
                goto shared_DC12;
            }
            a_dbf3 = value30;
            a_hi_dbf3 = a_all30 >> 8;
            x_dbf3 = 2;
            y_dbf3 = y_ret29;
            carry_dbf3 = carry_ret30;
            zero_dbf3 = (value30 & 5) == 0;
            negative_dbf3 = 0;
            overflow_dbf3 = overflow_ret29;
            direct_page_dbf3 = dp_ret29;
            data_bank_dbf3 = db_ret29;
            goto shared_DBF3;
        }
    }
    if (x_ret56) {
        a_dbcb = 0;
        a_hi_dbcb = a_all30 >> 8;
        x_dbcb = (uint8_t)x_ret57;
        y_dbcb = (uint8_t)y_ret29;
        carry_dbcb = carry_ret30;
        overflow_dbcb = overflow_ret29;
        direct_page_dbcb = dp_ret29;
        data_bank_dbcb = db_ret29;
        goto shared_DBCB;
    } else {
        a_dbcb2 = 0;
        a_hi_dbcb2 = a_all30 >> 8;
        x_dbcb2 = x_ret57;
        y_dbcb2 = y_ret29;
        carry_dbcb2 = carry_ret30;
        overflow_dbcb2 = overflow_ret29;
        direct_page_dbcb2 = dp_ret29;
        data_bank_dbcb2 = db_ret29;
        goto shared_DBCB_1;
    }
    shared_DC12_1:;
    a_dbb54 = a_dc122;
    a_hi_dbb54 = a_hi_dc122;
    x_dbb54 = x_dc122;
    y_dbb54 = y_dc122;
    carry_dbb54 = carry_dc122;
    zero_dbb54 = zero_dc122;
    negative_dbb54 = negative_dc122;
    overflow_dbb54 = overflow_dc122;
    direct_page_dbb54 = direct_page_dc122;
    data_bank_dbb54 = data_bank_dc122;
    goto shared_DBB5_3;
    shared_DBB5_3:;
    r->a = (a_hi_dbb54 << 8) | a_dbb54;
    r->x = x_dbb54;
    r->y = y_dbb54;
    r->c = carry_dbb54;
    r->z = zero_dbb54;
    r->n = negative_dbb54;
    r->v = overflow_dbb54;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_dbb54;
    r->dp = direct_page_dbb54;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBB8, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBB8); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 3); GUARD_JSR(c, sp_call, 0xDBBB); }
    uint16_t dp_ret31 = r->dp;
    uint8_t db_ret31 = r->db;
    bool x_ret60 = r->xf;
    uint16_t a_all32 = r->a;
    uint16_t x_ret61 = r->x;
    uint16_t y_ret31 = r->y;
    bool carry_ret32 = r->c;
    bool overflow_ret31 = r->v;
    uint8_t value31 = BUS8_RDP(c, (db_ret31 << 0x10) + 0x1801);
    if ((value31 & 0x40) != 0) {
        if (x_ret60) {
            a_dbcb = value31;
            a_hi_dbcb = a_all32 >> 8;
            x_dbcb = (uint8_t)x_ret61;
            y_dbcb = (uint8_t)y_ret31;
            carry_dbcb = carry_ret32;
            overflow_dbcb = overflow_ret31;
            direct_page_dbcb = dp_ret31;
            data_bank_dbcb = db_ret31;
            goto shared_DBCB;
        } else {
            a_dbcb2 = value31;
            a_hi_dbcb2 = a_all32 >> 8;
            x_dbcb2 = x_ret61;
            y_dbcb2 = y_ret31;
            carry_dbcb2 = carry_ret32;
            overflow_dbcb2 = overflow_ret31;
            direct_page_dbcb2 = dp_ret31;
            data_bank_dbcb2 = db_ret31;
            goto shared_DBCB_1;
        }
    }
    if ((value31 & 0x80) == 0) {
        uint8_t value32 = BUS8_RDP(c, (db_ret31 << 0x10) + 0x1801);
        if (x_ret60) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if ((value32 & 0x0A) != 0) {
                a_dbf3 = value32;
                a_hi_dbf3 = a_all32 >> 8;
                x_dbf3 = 0xFFFE;
                y_dbf3 = y_ret31;
                carry_dbf3 = carry_ret32;
                zero_dbf3 = (value32 & 0x0A) == 0;
                negative_dbf3 = 1;
                overflow_dbf3 = overflow_ret31;
                direct_page_dbf3 = dp_ret31;
                data_bank_dbf3 = db_ret31;
                goto shared_DBF3;
            }
            if ((value32 & 5) == 0) {
                a_dc12 = value32;
                a_hi_dc12 = a_all32 >> 8;
                x_dc12 = 2;
                y_dc12 = y_ret31;
                carry_dc12 = carry_ret32;
                zero_dc12 = (value32 & 5) == 0;
                negative_dc12 = 0;
                overflow_dc12 = overflow_ret31;
                direct_page_dc12 = dp_ret31;
                data_bank_dc12 = db_ret31;
                goto shared_DC12;
            }
            a_dbf3 = value32;
            a_hi_dbf3 = a_all32 >> 8;
            x_dbf3 = 2;
            y_dbf3 = y_ret31;
            carry_dbf3 = carry_ret32;
            zero_dbf3 = (value32 & 5) == 0;
            negative_dbf3 = 0;
            overflow_dbf3 = overflow_ret31;
            direct_page_dbf3 = dp_ret31;
            data_bank_dbf3 = db_ret31;
            goto shared_DBF3;
        }
    }
    if (x_ret60) {
        a_dbcb = 0;
        a_hi_dbcb = a_all32 >> 8;
        x_dbcb = (uint8_t)x_ret61;
        y_dbcb = (uint8_t)y_ret31;
        carry_dbcb = carry_ret32;
        overflow_dbcb = overflow_ret31;
        direct_page_dbcb = dp_ret31;
        data_bank_dbcb = db_ret31;
        goto shared_DBCB;
    } else {
        a_dbcb2 = 0;
        a_hi_dbcb2 = a_all32 >> 8;
        x_dbcb2 = x_ret61;
        y_dbcb2 = y_ret31;
        carry_dbcb2 = carry_ret32;
        overflow_dbcb2 = overflow_ret31;
        direct_page_dbcb2 = dp_ret31;
        data_bank_dbcb2 = db_ret31;
        goto shared_DBCB_1;
    }
}
SOM_REGISTER(0xD0DB58, SOM_RTL, "gen", select_native_menu_target_with_controller_edges_and_real_vblank, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 21, -1, 0, 284, 117)

/* D0DC14 advance_native_target_cursor_and_skip_unavailable_entries   [class A, 191 bytes, 79 instructions]
 * Source: src/rom/select_native_menu_target_with_controller_edges_and_real_vblank.s
 * Subroutine of select_native_menu_target_with_controller_edges_and_real_vblank, translated in place.
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_native_target_cursor_and_skip_unavailable_entries(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t a_hi_dc2e = 0;
    uint16_t x_dc2e = 0;
    uint16_t y_dc2e = 0;
    bool overflow_dc2e = 0;
    uint8_t a_dc02 = 0;
    uint8_t a_hi_dc02 = 0;
    uint16_t x_dc02 = 0;
    uint16_t y_dc02 = 0;
    bool carry_dc02 = 0;
    bool zero_dc02 = 0;
    bool negative_dc02 = 0;
    bool overflow_dc02 = 0;
    uint16_t direct_page_dc02 = 0;
    uint8_t data_bank_dc02 = 0;
    uint8_t a_dc022 = 0;
    uint8_t a_hi_dc022 = 0;
    uint8_t x_dc022 = 0;
    uint8_t y_dc022 = 0;
    bool carry_dc022 = 0;
    bool zero_dc022 = 0;
    bool negative_dc022 = 0;
    bool overflow_dc022 = 0;
    uint16_t direct_page_dc022 = 0;
    uint8_t data_bank_dc022 = 0;
    uint8_t a_dc023 = 0;
    uint8_t a_hi_dc023 = 0;
    uint16_t x_dc023 = 0;
    uint16_t y_dc023 = 0;
    bool carry_dc023 = 0;
    bool zero_dc023 = 0;
    bool negative_dc023 = 0;
    bool overflow_dc023 = 0;
    uint16_t direct_page_dc023 = 0;
    uint8_t data_bank_dc023 = 0;
    uint8_t a_dc12 = 0;
    uint8_t a_hi_dc12 = 0;
    uint8_t x_dc12 = 0;
    uint8_t y_dc12 = 0;
    bool carry_dc12 = 0;
    bool zero_dc12 = 0;
    bool negative_dc12 = 0;
    bool overflow_dc12 = 0;
    uint16_t direct_page_dc12 = 0;
    uint8_t data_bank_dc12 = 0;
    uint8_t a_dc122 = 0;
    uint8_t a_hi_dc122 = 0;
    uint16_t x_dc122 = 0;
    uint16_t y_dc122 = 0;
    bool carry_dc122 = 0;
    bool zero_dc122 = 0;
    bool negative_dc122 = 0;
    bool overflow_dc122 = 0;
    uint16_t direct_page_dc122 = 0;
    uint8_t data_bank_dc122 = 0;
    uint8_t a_dbcb = 0;
    uint8_t a_hi_dbcb = 0;
    uint8_t x_dbcb = 0;
    uint8_t y_dbcb = 0;
    bool carry_dbcb = 0;
    bool overflow_dbcb = 0;
    uint16_t direct_page_dbcb = 0;
    uint8_t data_bank_dbcb = 0;
    uint8_t a_dbcb2 = 0;
    uint8_t a_hi_dbcb2 = 0;
    uint16_t x_dbcb2 = 0;
    uint16_t y_dbcb2 = 0;
    bool carry_dbcb2 = 0;
    bool overflow_dbcb2 = 0;
    uint16_t direct_page_dbcb2 = 0;
    uint8_t data_bank_dbcb2 = 0;
    uint8_t a_dbf3 = 0;
    uint8_t a_hi_dbf3 = 0;
    uint16_t x_dbf3 = 0;
    uint16_t y_dbf3 = 0;
    bool carry_dbf3 = 0;
    bool zero_dbf3 = 0;
    bool negative_dbf3 = 0;
    bool overflow_dbf3 = 0;
    uint16_t direct_page_dbf3 = 0;
    uint8_t data_bank_dbf3 = 0;
    uint8_t a_dbdf = 0;
    uint8_t a_hi_dbdf = 0;
    uint8_t x_dbdf = 0;
    uint8_t y_dbdf = 0;
    bool carry_dbdf = 0;
    bool zero_dbdf = 0;
    bool negative_dbdf = 0;
    bool overflow_dbdf = 0;
    uint16_t direct_page_dbdf = 0;
    uint8_t data_bank_dbdf = 0;
    uint8_t a_dbdf2 = 0;
    uint8_t a_hi_dbdf2 = 0;
    uint8_t x_dbdf2 = 0;
    uint8_t y_dbdf2 = 0;
    bool carry_dbdf2 = 0;
    bool zero_dbdf2 = 0;
    bool negative_dbdf2 = 0;
    bool overflow_dbdf2 = 0;
    uint16_t direct_page_dbdf2 = 0;
    uint8_t data_bank_dbdf2 = 0;
    bool irq_disable_dbdf = 0;
    bool decimal_dbdf = 0;
    uint8_t a_dbdf3 = 0;
    uint8_t a_hi_dbdf3 = 0;
    uint16_t x_dbdf3 = 0;
    uint16_t y_dbdf3 = 0;
    bool carry_dbdf3 = 0;
    bool zero_dbdf3 = 0;
    bool negative_dbdf3 = 0;
    bool overflow_dbdf3 = 0;
    uint16_t direct_page_dbdf3 = 0;
    uint8_t data_bank_dbdf3 = 0;
    bool irq_disable_dbdf2 = 0;
    bool decimal_dbdf2 = 0;
    uint8_t a_dbdf4 = 0;
    uint8_t a_hi_dbdf4 = 0;
    uint16_t x_dbdf4 = 0;
    uint16_t y_dbdf4 = 0;
    bool carry_dbdf4 = 0;
    bool zero_dbdf4 = 0;
    bool negative_dbdf4 = 0;
    bool overflow_dbdf4 = 0;
    uint16_t direct_page_dbdf4 = 0;
    uint8_t data_bank_dbdf4 = 0;
    bool irq_disable_dbdf3 = 0;
    bool decimal_dbdf3 = 0;
    uint8_t a_dc024 = 0;
    uint8_t a_hi_dc024 = 0;
    uint8_t x_dc024 = 0;
    uint8_t y_dc024 = 0;
    bool carry_dc024 = 0;
    bool zero_dc024 = 0;
    bool negative_dc024 = 0;
    bool overflow_dc024 = 0;
    uint16_t direct_page_dc024 = 0;
    uint8_t data_bank_dc024 = 0;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x1840);
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x1822);
    if ((uint16_t)(value + value2) >= 0x181A) {
        a_hi_dc2e = (uint16_t)(value + value2) >> 8;
        x_dc2e = 0x1812;
        y_dc2e = y;
        overflow_dc2e = ((value ^ (uint16_t)(value + value2)) & (value2 ^ (uint16_t)(value + value2)) & 0x8000) != 0;
        goto shared_DC2E;
    }
    if ((uint16_t)(value + value2) >= 0x1812) {
        a_hi_dc2e = (uint16_t)(value + value2) >> 8;
        x_dc2e = (uint16_t)(value + value2);
        y_dc2e = y;
        overflow_dc2e = ((value ^ (uint16_t)(value + value2)) & (value2 ^ (uint16_t)(value + value2)) & 0x8000) != 0;
        goto shared_DC2E;
    }
    a_hi_dc2e = (uint16_t)(value + value2) >> 8;
    x_dc2e = 0x1818;
    y_dc2e = y;
    overflow_dc2e = ((value ^ (uint16_t)(value + value2)) & (value2 ^ (uint16_t)(value + value2)) & 0x8000) != 0;
    shared_DC2E:;
    BUS16_SET(c, (db << 0x10) + 0x1822, x_dc2e);
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + x_dc2e));
    if (value3 != 0) {
        if (value3 == 0xFFFE) {
            uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x1840);
            uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x1822);
            if ((uint16_t)(value4 + value5) >= 0x181A) {
                a_hi_dc2e = (uint16_t)(value4 + value5) >> 8;
                x_dc2e = 0x1812;
                overflow_dc2e = ((value4 ^ (uint16_t)(value4 + value5)) & (value5 ^ (uint16_t)(value4 + value5)) & 0x8000) != 0;
                goto shared_DC2E;
            }
            if ((uint16_t)(value4 + value5) >= 0x1812) {
                a_hi_dc2e = (uint16_t)(value4 + value5) >> 8;
                x_dc2e = (uint16_t)(value4 + value5);
                overflow_dc2e = ((value4 ^ (uint16_t)(value4 + value5)) & (value5 ^ (uint16_t)(value4 + value5)) & 0x8000) != 0;
                goto shared_DC2E;
            }
            a_hi_dc2e = (uint16_t)(value4 + value5) >> 8;
            x_dc2e = 0x1818;
            overflow_dc2e = ((value4 ^ (uint16_t)(value4 + value5)) & (value5 ^ (uint16_t)(value4 + value5)) & 0x8000) != 0;
            goto shared_DC2E;
        }
        r->a = value3;
        r->x = x_dc2e;
        r->y = y_dc2e;
        r->c = value3 >= 0xFFFE;
        r->z = value3 == 0xFFFE;
        r->n = (uint16_t)(value3 - 0xFFFE) & 0x8000;
        r->v = overflow_dc2e;
        r->mf = 0;
        r->xf = 0;
        r->db = db;
        r->dp = dp;
        publish_native_single_or_blinking_multi_target_markers(c); return;
    }
    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x1822);
    uint16_t value7 = BUS16_RDP(c, (db << 0x10) + 0x183E);
    if (value6 == value7) {
        a_dc02 = (uint8_t)value6;
        a_hi_dc02 = value6 >> 8;
        x_dc02 = x_dc2e;
        y_dc02 = y_dc2e;
        carry_dc02 = value6 >= value7;
        zero_dc02 = value6 == value7;
        negative_dc02 = (uint16_t)(value6 - value7) & 0x8000;
        overflow_dc02 = overflow_dc2e;
        direct_page_dc02 = dp;
        data_bank_dc02 = db;
        goto shared_DC02;
    }
    uint16_t value8 = BUS16_RDP(c, (db << 0x10) + 0x1840);
    uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0x1822);
    if ((uint16_t)(value8 + value9) >= 0x181A) {
        a_hi_dc2e = (uint16_t)(value8 + value9) >> 8;
        x_dc2e = 0x1812;
        overflow_dc2e = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
        goto shared_DC2E;
    }
    if ((uint16_t)(value8 + value9) >= 0x1812) {
        a_hi_dc2e = (uint16_t)(value8 + value9) >> 8;
        x_dc2e = (uint16_t)(value8 + value9);
        overflow_dc2e = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
        goto shared_DC2E;
    }
    a_hi_dc2e = (uint16_t)(value8 + value9) >> 8;
    x_dc2e = 0x1818;
    overflow_dc2e = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
    goto shared_DC2E;
    shared_DC02:;
    r->a = (a_hi_dc02 << 8) | a_dc02;
    r->x = x_dc02;
    r->y = y_dc02;
    r->c = carry_dc02;
    r->z = zero_dc02;
    r->n = negative_dc02;
    r->v = overflow_dc02;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dc02;
    r->dp = direct_page_dc02;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    uint8_t value10 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x1801);
    if ((value10 & 0x8F) != 0) {
        if (x_ret3) {
            a_dc022 = value10 & 0x8F;
            a_hi_dc022 = a_all2 >> 8;
            x_dc022 = (uint8_t)x_ret4;
            y_dc022 = (uint8_t)y_ret2;
            carry_dc022 = carry_ret2;
            zero_dc022 = (value10 & 0x8F) == 0;
            negative_dc022 = value10 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret2;
            direct_page_dc022 = dp_ret2;
            data_bank_dc022 = db_ret2;
            goto shared_DC02_1;
        } else {
            a_dc023 = value10 & 0x8F;
            a_hi_dc023 = a_all2 >> 8;
            x_dc023 = x_ret4;
            y_dc023 = y_ret2;
            carry_dc023 = carry_ret2;
            zero_dc023 = (value10 & 0x8F) == 0;
            negative_dc023 = value10 & 0x8F & 0x80;
            overflow_dc023 = overflow_ret2;
            direct_page_dc023 = dp_ret2;
            data_bank_dc023 = db_ret2;
            goto shared_DC02_2;
        }
    }
    if (x_ret3) {
        a_dc12 = value10 & 0x8F;
        a_hi_dc12 = a_all2 >> 8;
        x_dc12 = (uint8_t)x_ret4;
        y_dc12 = (uint8_t)y_ret2;
        carry_dc12 = carry_ret2;
        zero_dc12 = (value10 & 0x8F) == 0;
        negative_dc12 = value10 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret2;
        direct_page_dc12 = dp_ret2;
        data_bank_dc12 = db_ret2;
        goto shared_DC12;
    } else {
        a_dc122 = value10 & 0x8F;
        a_hi_dc122 = a_all2 >> 8;
        x_dc122 = x_ret4;
        y_dc122 = y_ret2;
        carry_dc122 = carry_ret2;
        zero_dc122 = (value10 & 0x8F) == 0;
        negative_dc122 = value10 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret2;
        direct_page_dc122 = dp_ret2;
        data_bank_dc122 = db_ret2;
        goto shared_DC12_1;
    }
    shared_DC02_1:;
    r->a = (a_hi_dc022 << 8) | a_dc022;
    r->x = x_dc022;
    r->y = y_dc022;
    r->c = carry_dc022;
    r->z = zero_dc022;
    r->n = negative_dc022;
    r->v = overflow_dc022;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_dc022;
    r->dp = direct_page_dc022;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool x_ret7 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret4 = r->c;
    bool overflow_ret4 = r->v;
    uint8_t value11 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x1801);
    if ((value11 & 0x8F) != 0) {
        if (x_ret7) {
            a_dc022 = value11 & 0x8F;
            a_hi_dc022 = a_all4 >> 8;
            x_dc022 = (uint8_t)x_ret8;
            y_dc022 = (uint8_t)y_ret4;
            carry_dc022 = carry_ret4;
            zero_dc022 = (value11 & 0x8F) == 0;
            negative_dc022 = value11 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret4;
            direct_page_dc022 = dp_ret4;
            data_bank_dc022 = db_ret4;
            goto shared_DC02_1;
        } else {
            a_dc023 = value11 & 0x8F;
            a_hi_dc023 = a_all4 >> 8;
            x_dc023 = x_ret8;
            y_dc023 = y_ret4;
            carry_dc023 = carry_ret4;
            zero_dc023 = (value11 & 0x8F) == 0;
            negative_dc023 = value11 & 0x8F & 0x80;
            overflow_dc023 = overflow_ret4;
            direct_page_dc023 = dp_ret4;
            data_bank_dc023 = db_ret4;
            goto shared_DC02_2;
        }
    }
    if (x_ret7) {
        a_dc12 = value11 & 0x8F;
        a_hi_dc12 = a_all4 >> 8;
        x_dc12 = (uint8_t)x_ret8;
        y_dc12 = (uint8_t)y_ret4;
        carry_dc12 = carry_ret4;
        zero_dc12 = (value11 & 0x8F) == 0;
        negative_dc12 = value11 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret4;
        direct_page_dc12 = dp_ret4;
        data_bank_dc12 = db_ret4;
        goto shared_DC12;
    } else {
        a_dc122 = value11 & 0x8F;
        a_hi_dc122 = a_all4 >> 8;
        x_dc122 = x_ret8;
        y_dc122 = y_ret4;
        carry_dc122 = carry_ret4;
        zero_dc122 = (value11 & 0x8F) == 0;
        negative_dc122 = value11 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret4;
        direct_page_dc122 = dp_ret4;
        data_bank_dc122 = db_ret4;
        goto shared_DC12_1;
    }
    shared_DC02_2:;
    r->a = (a_hi_dc023 << 8) | a_dc023;
    r->x = x_dc023;
    r->y = y_dc023;
    r->c = carry_dc023;
    r->z = zero_dc023;
    r->n = negative_dc023;
    r->v = overflow_dc023;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dc023;
    r->dp = direct_page_dc023;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool x_ret11 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t x_ret12 = r->x;
    uint16_t y_ret6 = r->y;
    bool carry_ret6 = r->c;
    bool overflow_ret6 = r->v;
    uint8_t value12 = BUS8_RDP(c, (db_ret6 << 0x10) + 0x1801);
    if ((value12 & 0x8F) != 0) {
        if (x_ret11) {
            a_dc022 = value12 & 0x8F;
            a_hi_dc022 = a_all6 >> 8;
            x_dc022 = (uint8_t)x_ret12;
            y_dc022 = (uint8_t)y_ret6;
            carry_dc022 = carry_ret6;
            zero_dc022 = (value12 & 0x8F) == 0;
            negative_dc022 = value12 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret6;
            direct_page_dc022 = dp_ret6;
            data_bank_dc022 = db_ret6;
            goto shared_DC02_1;
        } else {
            a_dc023 = value12 & 0x8F;
            a_hi_dc023 = a_all6 >> 8;
            x_dc023 = x_ret12;
            y_dc023 = y_ret6;
            carry_dc023 = carry_ret6;
            zero_dc023 = (value12 & 0x8F) == 0;
            negative_dc023 = value12 & 0x8F & 0x80;
            overflow_dc023 = overflow_ret6;
            direct_page_dc023 = dp_ret6;
            data_bank_dc023 = db_ret6;
            goto shared_DC02_2;
        }
    }
    if (x_ret11) {
        a_dc12 = value12 & 0x8F;
        a_hi_dc12 = a_all6 >> 8;
        x_dc12 = (uint8_t)x_ret12;
        y_dc12 = (uint8_t)y_ret6;
        carry_dc12 = carry_ret6;
        zero_dc12 = (value12 & 0x8F) == 0;
        negative_dc12 = value12 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret6;
        direct_page_dc12 = dp_ret6;
        data_bank_dc12 = db_ret6;
        goto shared_DC12;
    } else {
        a_dc122 = value12 & 0x8F;
        a_hi_dc122 = a_all6 >> 8;
        x_dc122 = x_ret12;
        y_dc122 = y_ret6;
        carry_dc122 = carry_ret6;
        zero_dc122 = (value12 & 0x8F) == 0;
        negative_dc122 = value12 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret6;
        direct_page_dc122 = dp_ret6;
        data_bank_dc122 = db_ret6;
        goto shared_DC12_1;
    }
    shared_DC12:;
    r->a = (a_hi_dc12 << 8) | a_dc12;
    r->x = x_dc12;
    r->y = y_dc12;
    r->c = carry_dc12;
    r->z = zero_dc12;
    r->n = negative_dc12;
    r->v = overflow_dc12;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_dc12;
    r->dp = direct_page_dc12;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBB8, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBB8); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); }
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    bool x_ret15 = r->xf;
    uint16_t a_all8 = r->a;
    uint16_t x_ret16 = r->x;
    uint16_t y_ret8 = r->y;
    bool carry_ret8 = r->c;
    bool overflow_ret8 = r->v;
    uint8_t value13 = BUS8_RDP(c, (db_ret8 << 0x10) + 0x1801);
    if ((value13 & 0x40) != 0) {
        if (x_ret15) {
            a_dbcb = value13;
            a_hi_dbcb = a_all8 >> 8;
            x_dbcb = (uint8_t)x_ret16;
            y_dbcb = (uint8_t)y_ret8;
            carry_dbcb = carry_ret8;
            overflow_dbcb = overflow_ret8;
            direct_page_dbcb = dp_ret8;
            data_bank_dbcb = db_ret8;
            goto shared_DBCB;
        } else {
            a_dbcb2 = value13;
            a_hi_dbcb2 = a_all8 >> 8;
            x_dbcb2 = x_ret16;
            y_dbcb2 = y_ret8;
            carry_dbcb2 = carry_ret8;
            overflow_dbcb2 = overflow_ret8;
            direct_page_dbcb2 = dp_ret8;
            data_bank_dbcb2 = db_ret8;
            goto shared_DBCB_1;
        }
    }
    if ((value13 & 0x80) == 0) {
        uint8_t value14 = BUS8_RDP(c, (db_ret8 << 0x10) + 0x1801);
        if (x_ret15) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if ((value14 & 0x0A) != 0) {
                a_dbf3 = value14;
                a_hi_dbf3 = a_all8 >> 8;
                x_dbf3 = 0xFFFE;
                y_dbf3 = y_ret8;
                carry_dbf3 = carry_ret8;
                zero_dbf3 = (value14 & 0x0A) == 0;
                negative_dbf3 = 1;
                overflow_dbf3 = overflow_ret8;
                direct_page_dbf3 = dp_ret8;
                data_bank_dbf3 = db_ret8;
                goto shared_DBF3;
            }
            if ((value14 & 5) == 0) {
                a_dc122 = value14;
                a_hi_dc122 = a_all8 >> 8;
                x_dc122 = 2;
                y_dc122 = y_ret8;
                carry_dc122 = carry_ret8;
                zero_dc122 = (value14 & 5) == 0;
                negative_dc122 = 0;
                overflow_dc122 = overflow_ret8;
                direct_page_dc122 = dp_ret8;
                data_bank_dc122 = db_ret8;
                goto shared_DC12_1;
            }
            a_dbf3 = value14;
            a_hi_dbf3 = a_all8 >> 8;
            x_dbf3 = 2;
            y_dbf3 = y_ret8;
            carry_dbf3 = carry_ret8;
            zero_dbf3 = (value14 & 5) == 0;
            negative_dbf3 = 0;
            overflow_dbf3 = overflow_ret8;
            direct_page_dbf3 = dp_ret8;
            data_bank_dbf3 = db_ret8;
            goto shared_DBF3;
        }
    }
    if (x_ret15) {
        a_dbcb = 0;
        a_hi_dbcb = a_all8 >> 8;
        x_dbcb = (uint8_t)x_ret16;
        y_dbcb = (uint8_t)y_ret8;
        carry_dbcb = carry_ret8;
        overflow_dbcb = overflow_ret8;
        direct_page_dbcb = dp_ret8;
        data_bank_dbcb = db_ret8;
        goto shared_DBCB;
    } else {
        a_dbcb2 = 0;
        a_hi_dbcb2 = a_all8 >> 8;
        x_dbcb2 = x_ret16;
        y_dbcb2 = y_ret8;
        carry_dbcb2 = carry_ret8;
        overflow_dbcb2 = overflow_ret8;
        direct_page_dbcb2 = dp_ret8;
        data_bank_dbcb2 = db_ret8;
        goto shared_DBCB_1;
    }
    shared_DC12_1:;
    r->a = (a_hi_dc122 << 8) | a_dc122;
    r->x = x_dc122;
    r->y = y_dc122;
    r->c = carry_dc122;
    r->z = zero_dc122;
    r->n = negative_dc122;
    r->v = overflow_dc122;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dc122;
    r->dp = direct_page_dc122;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBB8, 0xC0695A); GUARD_JSL(c, sp_call, 0xDBB8); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDBBB, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xDBBB); }
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret10 = r->db;
    bool x_ret19 = r->xf;
    uint16_t a_all10 = r->a;
    uint16_t x_ret20 = r->x;
    uint16_t y_ret10 = r->y;
    bool carry_ret10 = r->c;
    bool overflow_ret10 = r->v;
    uint8_t value15 = BUS8_RDP(c, (db_ret10 << 0x10) + 0x1801);
    if ((value15 & 0x40) != 0) {
        if (x_ret19) {
            a_dbcb = value15;
            a_hi_dbcb = a_all10 >> 8;
            x_dbcb = (uint8_t)x_ret20;
            y_dbcb = (uint8_t)y_ret10;
            carry_dbcb = carry_ret10;
            overflow_dbcb = overflow_ret10;
            direct_page_dbcb = dp_ret10;
            data_bank_dbcb = db_ret10;
            goto shared_DBCB;
        } else {
            a_dbcb2 = value15;
            a_hi_dbcb2 = a_all10 >> 8;
            x_dbcb2 = x_ret20;
            y_dbcb2 = y_ret10;
            carry_dbcb2 = carry_ret10;
            overflow_dbcb2 = overflow_ret10;
            direct_page_dbcb2 = dp_ret10;
            data_bank_dbcb2 = db_ret10;
            goto shared_DBCB_1;
        }
    }
    if ((value15 & 0x80) == 0) {
        uint8_t value16 = BUS8_RDP(c, (db_ret10 << 0x10) + 0x1801);
        if (x_ret19) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            if ((value16 & 0x0A) != 0) {
                a_dbf3 = value16;
                a_hi_dbf3 = a_all10 >> 8;
                x_dbf3 = 0xFFFE;
                y_dbf3 = y_ret10;
                carry_dbf3 = carry_ret10;
                zero_dbf3 = (value16 & 0x0A) == 0;
                negative_dbf3 = 1;
                overflow_dbf3 = overflow_ret10;
                direct_page_dbf3 = dp_ret10;
                data_bank_dbf3 = db_ret10;
                goto shared_DBF3;
            }
            if ((value16 & 5) == 0) {
                a_dc122 = value16;
                a_hi_dc122 = a_all10 >> 8;
                x_dc122 = 2;
                y_dc122 = y_ret10;
                carry_dc122 = carry_ret10;
                zero_dc122 = (value16 & 5) == 0;
                negative_dc122 = 0;
                overflow_dc122 = overflow_ret10;
                direct_page_dc122 = dp_ret10;
                data_bank_dc122 = db_ret10;
                goto shared_DC12_1;
            }
            a_dbf3 = value16;
            a_hi_dbf3 = a_all10 >> 8;
            x_dbf3 = 2;
            y_dbf3 = y_ret10;
            carry_dbf3 = carry_ret10;
            zero_dbf3 = (value16 & 5) == 0;
            negative_dbf3 = 0;
            overflow_dbf3 = overflow_ret10;
            direct_page_dbf3 = dp_ret10;
            data_bank_dbf3 = db_ret10;
            goto shared_DBF3;
        }
    }
    if (x_ret19) {
        a_dbcb = 0;
        a_hi_dbcb = a_all10 >> 8;
        x_dbcb = (uint8_t)x_ret20;
        y_dbcb = (uint8_t)y_ret10;
        carry_dbcb = carry_ret10;
        overflow_dbcb = overflow_ret10;
        direct_page_dbcb = dp_ret10;
        data_bank_dbcb = db_ret10;
        goto shared_DBCB;
    } else {
        a_dbcb2 = 0;
        a_hi_dbcb2 = a_all10 >> 8;
        x_dbcb2 = x_ret20;
        y_dbcb2 = y_ret10;
        carry_dbcb2 = carry_ret10;
        overflow_dbcb2 = overflow_ret10;
        direct_page_dbcb2 = dp_ret10;
        data_bank_dbcb2 = db_ret10;
        goto shared_DBCB_1;
    }
    shared_DBCB:;
    RAM8(0x0000 + sp0) = a_dbcb;
    uint8_t value17 = BUS8_RDP(c, (data_bank_dbcb << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_dbcb << 0x10) + 0x1803, value17 & 0xDF);
    uint8_t value18 = RAM8(0x0000 + sp0);
    if ((((a_hi_dbcb << 8) | value18) & 0x40) == 0) {
        a_dbdf = value18;
        a_hi_dbdf = a_hi_dbcb;
        x_dbdf = x_dbcb;
        y_dbdf = y_dbcb;
        carry_dbdf = carry_dbcb;
        zero_dbdf = (((a_hi_dbcb << 8) | value18) & 0x40) == 0;
        negative_dbdf = value18 & 0x80;
        overflow_dbdf = overflow_dbcb;
        direct_page_dbdf = direct_page_dbcb;
        data_bank_dbdf = data_bank_dbcb;
        goto shared_DBDF;
    }
    RAM8(0x0000 + sp0) = ((((value18 >> 7 << 7) | (overflow_dbcb << 6) | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (((((a_hi_dbcb << 8) | value18) & 0x40) == 0) << 1) | carry_dbcb;
    r->a = (a_hi_dbcb << 8) | value18;
    r->x = x_dbcb;
    r->y = y_dbcb;
    r->c = carry_dbcb;
    r->z = (((a_hi_dbcb << 8) | value18) & 0x40) == 0;
    r->n = value18 & 0x80;
    r->v = overflow_dbcb;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dbcb;
    r->dp = direct_page_dbcb;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBDD, 0xC068EA); GUARD_JSL(c, sp_call, 0xDBDD); } /* open_native_menu_ring_and_wait_for_phase_zero_public */
    r->sp += 1;
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    uint16_t a_all11 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret11 = r->y;
    uint8_t value19 = RAM8(0x0000 + sp0);
    if (value19 & 0x20) {
        if (value19 & 0x10) {
            a_dbdf2 = (uint8_t)a_all11;
            a_hi_dbdf2 = a_all11 >> 8;
            x_dbdf2 = (uint8_t)x_ret21;
            y_dbdf2 = (uint8_t)y_ret11;
            carry_dbdf2 = value19 & 0x01;
            zero_dbdf2 = value19 & 0x02;
            negative_dbdf2 = value19 & 0x80;
            overflow_dbdf2 = value19 & 0x40;
            direct_page_dbdf2 = dp_ret11;
            data_bank_dbdf2 = db_ret11;
            irq_disable_dbdf = value19 & 0x04;
            decimal_dbdf = value19 & 0x08;
            goto shared_DBDF_1;
        } else {
            a_dbdf3 = (uint8_t)a_all11;
            a_hi_dbdf3 = a_all11 >> 8;
            x_dbdf3 = x_ret21;
            y_dbdf3 = y_ret11;
            carry_dbdf3 = value19 & 0x01;
            zero_dbdf3 = value19 & 0x02;
            negative_dbdf3 = value19 & 0x80;
            overflow_dbdf3 = value19 & 0x40;
            direct_page_dbdf3 = dp_ret11;
            data_bank_dbdf3 = db_ret11;
            irq_disable_dbdf2 = value19 & 0x04;
            decimal_dbdf2 = value19 & 0x08;
            goto shared_DBDF_2;
        }
    } else {
        if (value19 & 0x10) {
            a_dbdf = (uint8_t)a_all11;
            a_hi_dbdf = a_all11 >> 8;
            x_dbdf = (uint8_t)x_ret21;
            y_dbdf = (uint8_t)y_ret11;
            carry_dbdf = value19 & 0x01;
            zero_dbdf = value19 & 0x02;
            negative_dbdf = value19 & 0x80;
            overflow_dbdf = value19 & 0x40;
            direct_page_dbdf = dp_ret11;
            data_bank_dbdf = db_ret11;
            goto shared_DBDF;
        } else {
            a_dbdf4 = (uint8_t)a_all11;
            a_hi_dbdf4 = a_all11 >> 8;
            x_dbdf4 = x_ret21;
            y_dbdf4 = y_ret11;
            carry_dbdf4 = value19 & 0x01;
            zero_dbdf4 = value19 & 0x02;
            negative_dbdf4 = value19 & 0x80;
            overflow_dbdf4 = value19 & 0x40;
            direct_page_dbdf4 = dp_ret11;
            data_bank_dbdf4 = db_ret11;
            irq_disable_dbdf3 = value19 & 0x04;
            decimal_dbdf3 = value19 & 0x08;
            goto shared_DBDF_3;
        }
    }
    shared_DBCB_1:;
    RAM8(0x0000 + sp0) = a_dbcb2;
    uint8_t value20 = BUS8_RDP(c, (data_bank_dbcb2 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_dbcb2 << 0x10) + 0x1803, value20 & 0xDF);
    uint8_t value21 = RAM8(0x0000 + sp0);
    if ((((a_hi_dbcb2 << 8) | value21) & 0x40) == 0) {
        a_dbdf4 = value21;
        a_hi_dbdf4 = a_hi_dbcb2;
        x_dbdf4 = x_dbcb2;
        y_dbdf4 = y_dbcb2;
        carry_dbdf4 = carry_dbcb2;
        zero_dbdf4 = (((a_hi_dbcb2 << 8) | value21) & 0x40) == 0;
        negative_dbdf4 = value21 & 0x80;
        overflow_dbdf4 = overflow_dbcb2;
        direct_page_dbdf4 = direct_page_dbcb2;
        data_bank_dbdf4 = data_bank_dbcb2;
        irq_disable_dbdf3 = i_entry;
        decimal_dbdf3 = d_entry;
        goto shared_DBDF_3;
    }
    RAM8(0x0000 + sp0) = ((((value21 >> 7 << 7) | (overflow_dbcb2 << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((((a_hi_dbcb2 << 8) | value21) & 0x40) == 0) << 1) | carry_dbcb2;
    r->a = (a_hi_dbcb2 << 8) | value21;
    r->x = x_dbcb2;
    r->y = y_dbcb2;
    r->c = carry_dbcb2;
    r->z = (((a_hi_dbcb2 << 8) | value21) & 0x40) == 0;
    r->n = value21 & 0x80;
    r->v = overflow_dbcb2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dbcb2;
    r->dp = direct_page_dbcb2;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBDD, 0xC068EA); GUARD_JSL(c, sp_call, 0xDBDD); } /* open_native_menu_ring_and_wait_for_phase_zero_public */
    r->sp += 1;
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    uint16_t a_all12 = r->a;
    uint16_t x_ret22 = r->x;
    uint16_t y_ret12 = r->y;
    uint8_t value22 = RAM8(0x0000 + sp0);
    if (value22 & 0x20) {
        if (value22 & 0x10) {
            a_dbdf2 = (uint8_t)a_all12;
            a_hi_dbdf2 = a_all12 >> 8;
            x_dbdf2 = (uint8_t)x_ret22;
            y_dbdf2 = (uint8_t)y_ret12;
            carry_dbdf2 = value22 & 0x01;
            zero_dbdf2 = value22 & 0x02;
            negative_dbdf2 = value22 & 0x80;
            overflow_dbdf2 = value22 & 0x40;
            direct_page_dbdf2 = dp_ret12;
            data_bank_dbdf2 = db_ret12;
            irq_disable_dbdf = value22 & 0x04;
            decimal_dbdf = value22 & 0x08;
            goto shared_DBDF_1;
        } else {
            a_dbdf3 = (uint8_t)a_all12;
            a_hi_dbdf3 = a_all12 >> 8;
            x_dbdf3 = x_ret22;
            y_dbdf3 = y_ret12;
            carry_dbdf3 = value22 & 0x01;
            zero_dbdf3 = value22 & 0x02;
            negative_dbdf3 = value22 & 0x80;
            overflow_dbdf3 = value22 & 0x40;
            direct_page_dbdf3 = dp_ret12;
            data_bank_dbdf3 = db_ret12;
            irq_disable_dbdf2 = value22 & 0x04;
            decimal_dbdf2 = value22 & 0x08;
            goto shared_DBDF_2;
        }
    } else {
        if (value22 & 0x10) {
            a_dbdf = (uint8_t)a_all12;
            a_hi_dbdf = a_all12 >> 8;
            x_dbdf = (uint8_t)x_ret22;
            y_dbdf = (uint8_t)y_ret12;
            carry_dbdf = value22 & 0x01;
            zero_dbdf = value22 & 0x02;
            negative_dbdf = value22 & 0x80;
            overflow_dbdf = value22 & 0x40;
            direct_page_dbdf = dp_ret12;
            data_bank_dbdf = db_ret12;
            goto shared_DBDF;
        } else {
            a_dbdf4 = (uint8_t)a_all12;
            a_hi_dbdf4 = a_all12 >> 8;
            x_dbdf4 = x_ret22;
            y_dbdf4 = y_ret12;
            carry_dbdf4 = value22 & 0x01;
            zero_dbdf4 = value22 & 0x02;
            negative_dbdf4 = value22 & 0x80;
            overflow_dbdf4 = value22 & 0x40;
            direct_page_dbdf4 = dp_ret12;
            data_bank_dbdf4 = db_ret12;
            irq_disable_dbdf3 = value22 & 0x04;
            decimal_dbdf3 = value22 & 0x08;
            goto shared_DBDF_3;
        }
    }
    shared_DBF3:;
    r->a = (a_hi_dbf3 << 8) | a_dbf3;
    r->x = x_dbf3;
    r->y = y_dbf3;
    r->c = carry_dbf3;
    r->z = zero_dbf3;
    r->n = negative_dbf3;
    r->v = overflow_dbf3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dbf3;
    r->dp = direct_page_dbf3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDBF6, 0xD0CEF8); GUARD_JSL(c, sp_call, 0xDBF6); } /* request_native_menu_audio_0c */
    uint8_t db_ret13 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret23 = r->xf;
    uint16_t a_all13 = r->a;
    uint16_t x_ret24 = r->x;
    uint16_t y_ret13 = r->y;
    uint8_t value23 = BUS8_RDP(c, (db_ret13 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret13 << 0x10) + 0x1802, value23 | 4);
    if (x_ret23) {
        BUS8_SET(c, (db_ret13 << 0x10) + 0x1840, (uint8_t)x_ret24);
        r->a = (a_all13 >> 8 << 8) | 4;
        r->x = (uint8_t)x_ret24;
        r->y = (uint8_t)y_ret13;
        r->z = (value23 & 4) == 0;
        r->n = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC01, advance_native_target_cursor_and_skip_unavailable_entries, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC01); }
        uint16_t dp_ret14 = r->dp;
        uint8_t db_ret14 = r->db;
        bool m_ret11 = r->mf;
        bool x_ret25 = r->xf;
        uint16_t a_all14 = r->a;
        uint16_t x_ret26 = r->x;
        uint16_t y_ret14 = r->y;
        bool carry_ret14 = r->c;
        bool zero_ret14 = r->z;
        bool negative_ret14 = r->n;
        bool overflow_ret14 = r->v;
        if (m_ret11) {
            if (x_ret25) {
                a_dc022 = (uint8_t)a_all14;
                a_hi_dc022 = a_all14 >> 8;
                x_dc022 = (uint8_t)x_ret26;
                y_dc022 = (uint8_t)y_ret14;
                carry_dc022 = carry_ret14;
                zero_dc022 = zero_ret14;
                negative_dc022 = negative_ret14;
                overflow_dc022 = overflow_ret14;
                direct_page_dc022 = dp_ret14;
                data_bank_dc022 = db_ret14;
                goto shared_DC02_1;
            } else {
                a_dc023 = (uint8_t)a_all14;
                a_hi_dc023 = a_all14 >> 8;
                x_dc023 = x_ret26;
                y_dc023 = y_ret14;
                carry_dc023 = carry_ret14;
                zero_dc023 = zero_ret14;
                negative_dc023 = negative_ret14;
                overflow_dc023 = overflow_ret14;
                direct_page_dc023 = dp_ret14;
                data_bank_dc023 = db_ret14;
                goto shared_DC02_2;
            }
        } else {
            if (x_ret25) {
                a_dc024 = (uint8_t)a_all14;
                a_hi_dc024 = a_all14 >> 8;
                x_dc024 = (uint8_t)x_ret26;
                y_dc024 = (uint8_t)y_ret14;
                carry_dc024 = carry_ret14;
                zero_dc024 = zero_ret14;
                negative_dc024 = negative_ret14;
                overflow_dc024 = overflow_ret14;
                direct_page_dc024 = dp_ret14;
                data_bank_dc024 = db_ret14;
                goto shared_DC02_3;
            } else {
                a_dc02 = (uint8_t)a_all14;
                a_hi_dc02 = a_all14 >> 8;
                x_dc02 = x_ret26;
                y_dc02 = y_ret14;
                carry_dc02 = carry_ret14;
                zero_dc02 = zero_ret14;
                negative_dc02 = negative_ret14;
                overflow_dc02 = overflow_ret14;
                direct_page_dc02 = dp_ret14;
                data_bank_dc02 = db_ret14;
                goto shared_DC02;
            }
        }
    } else {
        BUS16_SET(c, (db_ret13 << 0x10) + 0x1840, x_ret24);
        r->a = (a_all13 >> 8 << 8) | 4;
        r->z = (value23 & 4) == 0;
        r->n = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC01, advance_native_target_cursor_and_skip_unavailable_entries, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC01); }
        uint16_t dp_ret15 = r->dp;
        uint8_t db_ret15 = r->db;
        bool m_ret12 = r->mf;
        bool x_ret27 = r->xf;
        uint16_t a_all15 = r->a;
        uint16_t x_ret28 = r->x;
        uint16_t y_ret15 = r->y;
        bool carry_ret15 = r->c;
        bool zero_ret15 = r->z;
        bool negative_ret15 = r->n;
        bool overflow_ret15 = r->v;
        if (m_ret12) {
            if (x_ret27) {
                a_dc022 = (uint8_t)a_all15;
                a_hi_dc022 = a_all15 >> 8;
                x_dc022 = (uint8_t)x_ret28;
                y_dc022 = (uint8_t)y_ret15;
                carry_dc022 = carry_ret15;
                zero_dc022 = zero_ret15;
                negative_dc022 = negative_ret15;
                overflow_dc022 = overflow_ret15;
                direct_page_dc022 = dp_ret15;
                data_bank_dc022 = db_ret15;
                goto shared_DC02_1;
            } else {
                a_dc023 = (uint8_t)a_all15;
                a_hi_dc023 = a_all15 >> 8;
                x_dc023 = x_ret28;
                y_dc023 = y_ret15;
                carry_dc023 = carry_ret15;
                zero_dc023 = zero_ret15;
                negative_dc023 = negative_ret15;
                overflow_dc023 = overflow_ret15;
                direct_page_dc023 = dp_ret15;
                data_bank_dc023 = db_ret15;
                goto shared_DC02_2;
            }
        } else {
            if (x_ret27) {
                a_dc024 = (uint8_t)a_all15;
                a_hi_dc024 = a_all15 >> 8;
                x_dc024 = (uint8_t)x_ret28;
                y_dc024 = (uint8_t)y_ret15;
                carry_dc024 = carry_ret15;
                zero_dc024 = zero_ret15;
                negative_dc024 = negative_ret15;
                overflow_dc024 = overflow_ret15;
                direct_page_dc024 = dp_ret15;
                data_bank_dc024 = db_ret15;
                goto shared_DC02_3;
            } else {
                a_dc02 = (uint8_t)a_all15;
                a_hi_dc02 = a_all15 >> 8;
                x_dc02 = x_ret28;
                y_dc02 = y_ret15;
                carry_dc02 = carry_ret15;
                zero_dc02 = zero_ret15;
                negative_dc02 = negative_ret15;
                overflow_dc02 = overflow_ret15;
                direct_page_dc02 = dp_ret15;
                data_bank_dc02 = db_ret15;
                goto shared_DC02;
            }
        }
    }
    shared_DBDF:;
    r->a = (a_hi_dbdf << 8) | a_dbdf;
    r->x = x_dbdf;
    r->y = y_dbdf;
    r->c = carry_dbdf;
    r->z = zero_dbdf;
    r->n = negative_dbdf;
    r->v = overflow_dbdf;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dbdf;
    r->dp = direct_page_dbdf;
    RETURN_RTL(c);
    shared_DBDF_1:;
    r->a = (a_hi_dbdf2 << 8) | a_dbdf2;
    r->x = x_dbdf2;
    r->y = y_dbdf2;
    r->c = carry_dbdf2;
    r->z = zero_dbdf2;
    r->n = negative_dbdf2;
    r->v = overflow_dbdf2;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_dbdf2;
    r->dp = direct_page_dbdf2;
    r->i = irq_disable_dbdf;
    r->d = decimal_dbdf;
    RETURN_RTL(c);
    shared_DBDF_2:;
    r->a = (a_hi_dbdf3 << 8) | a_dbdf3;
    r->x = x_dbdf3;
    r->y = y_dbdf3;
    r->c = carry_dbdf3;
    r->z = zero_dbdf3;
    r->n = negative_dbdf3;
    r->v = overflow_dbdf3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_dbdf3;
    r->dp = direct_page_dbdf3;
    r->i = irq_disable_dbdf2;
    r->d = decimal_dbdf2;
    RETURN_RTL(c);
    shared_DBDF_3:;
    r->a = (a_hi_dbdf4 << 8) | a_dbdf4;
    r->x = x_dbdf4;
    r->y = y_dbdf4;
    r->c = carry_dbdf4;
    r->z = zero_dbdf4;
    r->n = negative_dbdf4;
    r->v = overflow_dbdf4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_dbdf4;
    r->dp = direct_page_dbdf4;
    r->i = irq_disable_dbdf3;
    r->d = decimal_dbdf3;
    RETURN_RTL(c);
    shared_DC02_3:;
    r->a = (a_hi_dc024 << 8) | a_dc024;
    r->x = x_dc024;
    r->y = y_dc024;
    r->c = carry_dc024;
    r->z = zero_dc024;
    r->n = negative_dc024;
    r->v = overflow_dc024;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_dc024;
    r->dp = direct_page_dc024;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC05, 0xC0695A); GUARD_JSL(c, sp_call, 0xDC05); } /* wait_vblank_and_poll_menu_through_native_long_wrapper */
    if (r->mf == 0 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 0 && r->xf == 1) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else if (r->mf == 1 && r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v3, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xDC08, publish_native_single_or_blinking_multi_target_markers_v4, sp_in, 2); GUARD_JSR(c, sp_call, 0xDC08); }
    uint16_t dp_ret17 = r->dp;
    uint8_t db_ret17 = r->db;
    bool x_ret31 = r->xf;
    uint16_t a_all17 = r->a;
    uint16_t x_ret32 = r->x;
    uint16_t y_ret17 = r->y;
    bool carry_ret17 = r->c;
    bool overflow_ret17 = r->v;
    uint8_t value24 = BUS8_RDP(c, (db_ret17 << 0x10) + 0x1801);
    if ((value24 & 0x8F) != 0) {
        if (x_ret31) {
            a_dc022 = value24 & 0x8F;
            a_hi_dc022 = a_all17 >> 8;
            x_dc022 = (uint8_t)x_ret32;
            y_dc022 = (uint8_t)y_ret17;
            carry_dc022 = carry_ret17;
            zero_dc022 = (value24 & 0x8F) == 0;
            negative_dc022 = value24 & 0x8F & 0x80;
            overflow_dc022 = overflow_ret17;
            direct_page_dc022 = dp_ret17;
            data_bank_dc022 = db_ret17;
            goto shared_DC02_1;
        } else {
            a_dc023 = value24 & 0x8F;
            a_hi_dc023 = a_all17 >> 8;
            x_dc023 = x_ret32;
            y_dc023 = y_ret17;
            carry_dc023 = carry_ret17;
            zero_dc023 = (value24 & 0x8F) == 0;
            negative_dc023 = value24 & 0x8F & 0x80;
            overflow_dc023 = overflow_ret17;
            direct_page_dc023 = dp_ret17;
            data_bank_dc023 = db_ret17;
            goto shared_DC02_2;
        }
    }
    if (x_ret31) {
        a_dc12 = value24 & 0x8F;
        a_hi_dc12 = a_all17 >> 8;
        x_dc12 = (uint8_t)x_ret32;
        y_dc12 = (uint8_t)y_ret17;
        carry_dc12 = carry_ret17;
        zero_dc12 = (value24 & 0x8F) == 0;
        negative_dc12 = value24 & 0x8F & 0x80;
        overflow_dc12 = overflow_ret17;
        direct_page_dc12 = dp_ret17;
        data_bank_dc12 = db_ret17;
        goto shared_DC12;
    } else {
        a_dc122 = value24 & 0x8F;
        a_hi_dc122 = a_all17 >> 8;
        x_dc122 = x_ret32;
        y_dc122 = y_ret17;
        carry_dc122 = carry_ret17;
        zero_dc122 = (value24 & 0x8F) == 0;
        negative_dc122 = value24 & 0x8F & 0x80;
        overflow_dc122 = overflow_ret17;
        direct_page_dc122 = dp_ret17;
        data_bank_dc122 = db_ret17;
        goto shared_DC12_1;
    }
}

/* D0DC44 publish_native_single_or_blinking_multi_target_markers   [class A, 48 bytes, 19 instructions]
 * Source: src/rom/select_native_menu_target_with_controller_edges_and_real_vblank.s
 * Subroutine of select_native_menu_target_with_controller_edges_and_real_vblank, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void publish_native_single_or_blinking_multi_target_markers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    BUS16_SET(c, (db << 0x10) + 0x1832, 0x082C);
    r->a = 0x082C;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC4D, 0xC0793D); GUARD_JSL(c, sp_call, 0xDC4D); } /* hide_shop_hero_markers_before_price_selection */
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x1822);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + value));
    bool m_flag2;
    bool x_flag2;
    uint8_t a3;
    uint8_t a_hi3;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero3;
    bool negative3;
    bool overflow2;
    if ((uint16_t)(value2 + 1) != 0) {
        r->a = (uint16_t)(value2 + 1);
        r->x = value;
        r->z = (uint16_t)(value2 + 1) == 0;
        r->n = (uint16_t)(value2 + 1) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDC72, 0xD0DC74); GUARD_JSR(c, sp_call, 0xDC72); } /* publish_one_native_actor_target_marker_and_advance_list_cursor */
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret = r->v;
        m_flag2 = m_ret;
        x_flag2 = x_ret;
        a3 = (uint8_t)a_all2;
        a_hi3 = a_all2 >> 8;
        x2 = x_ret2;
        y2 = y_ret;
        carry2 = carry_ret;
        zero3 = zero_ret2;
        negative3 = negative_ret2;
        overflow2 = overflow_ret;
    } else {
        uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x181E);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if ((uint16_t)(value3 + 1) < 2) {
            a1 = (uint8_t)(value3 + 1);
            a_hi1 = (uint16_t)(value3 + 1) >> 8;
            zero1 = (uint16_t)(value3 + 1) == 2;
            negative1 = (uint16_t)((uint16_t)(value3 + 1) - 2) & 0x8000;
        } else {
            a1 = 0;
            a_hi1 = 0;
            zero1 = 1;
            negative1 = 0;
        }
        BUS16_SET(c, (db << 0x10) + 0x181E, (a_hi1 << 8) | a1);
        bool m_flag;
        bool x_flag;
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool zero2;
        bool negative2;
        bool overflow1;
        if (zero1) {
            m_flag = 0;
            x_flag = 0;
            a2 = a1;
            a_hi2 = a_hi1;
            x1 = value;
            y1 = y;
            carry1 = (uint16_t)(value3 + 1) >= 2;
            zero2 = zero1;
            negative2 = negative1;
            overflow1 = overflow;
        } else {
            r->a = (a_hi1 << 8) | a1;
            r->x = 0x1812;
            r->c = (uint16_t)(value3 + 1) >= 2;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xDC6C, 0xD0DC74); GUARD_JSR(c, sp_call, 0xDC6C); } /* publish_one_native_actor_target_marker_and_advance_list_cursor */
            { const uint16_t sp_call = r->sp; JSR(c, 0xDC6F, 0xD0DC74); GUARD_JSR(c, sp_call, 0xDC6F); } /* publish_one_native_actor_target_marker_and_advance_list_cursor */
            { const uint16_t sp_call = r->sp; JSR(c, 0xDC72, 0xD0DC74); GUARD_JSR(c, sp_call, 0xDC72); } /* publish_one_native_actor_target_marker_and_advance_list_cursor */
            bool m_ret4 = r->mf;
            bool x_ret7 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret8 = r->x;
            uint16_t y_ret4 = r->y;
            bool carry_ret4 = r->c;
            bool zero_ret5 = r->z;
            bool negative_ret5 = r->n;
            bool overflow_ret4 = r->v;
            m_flag = m_ret4;
            x_flag = x_ret7;
            a2 = (uint8_t)a_all5;
            a_hi2 = a_all5 >> 8;
            x1 = x_ret8;
            y1 = y_ret4;
            carry1 = carry_ret4;
            zero2 = zero_ret5;
            negative2 = negative_ret5;
            overflow1 = overflow_ret4;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a3 = a2;
        a_hi3 = a_hi2;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero3 = zero2;
        negative3 = negative2;
        overflow2 = overflow1;
    }
    r->a = (a_hi3 << 8) | a3;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

/* D0DC44 publish_native_single_or_blinking_multi_target_markers_v2   [class A, 48 bytes, 19 instructions]
 * Source: src/rom/select_native_menu_target_with_controller_edges_and_real_vblank.s
 * Subroutine of select_native_menu_target_with_controller_edges_and_real_vblank, translated in place.
 * Entry: M=16 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void publish_native_single_or_blinking_multi_target_markers_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 1)) return;
    const uint16_t dp = r->dp;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    BUS16_SET(c, (db << 0x10) + 0x1832, 0x082C);
    r->a = 0x082C;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC4D, 0xC0793D); GUARD_JSL(c, sp_call, 0xDC4D); } /* hide_shop_hero_markers_before_price_selection */
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1822);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + value));
    bool m_flag;
    bool x_flag;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero2;
    bool negative2;
    bool overflow1;
    if ((uint16_t)(value2 + 1) != 0) {
        r->a = (uint16_t)(value2 + 1);
        r->x = value;
        r->z = (uint16_t)(value2 + 1) == 0;
        r->n = (uint16_t)(value2 + 1) & 0x8000;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xDC72, 0xD0DC74); GUARD_JSR(c, sp_call, 0xDC72); } /* publish_one_native_actor_target_marker_and_advance_list_cursor */
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a2 = (uint8_t)a_all2;
        a_hi2 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero2 = zero_ret2;
        negative2 = negative_ret2;
        overflow1 = overflow_ret;
    } else {
        uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x181E);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if ((uint16_t)(value3 + 1) < 2) {
            a1 = (uint8_t)(value3 + 1);
            a_hi1 = (uint16_t)(value3 + 1) >> 8;
            zero1 = (uint16_t)(value3 + 1) == 2;
            negative1 = (uint16_t)((uint16_t)(value3 + 1) - 2) & 0x8000;
        } else {
            a1 = 0;
            a_hi1 = 0;
            zero1 = 1;
            negative1 = 0;
        }
        BUS16_SET(c, (db << 0x10) + 0x181E, (a_hi1 << 8) | a1);
        if (!zero1) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        }
        m_flag = 0;
        x_flag = 1;
        a2 = a1;
        a_hi2 = a_hi1;
        x1 = value;
        y1 = y;
        carry1 = (uint16_t)(value3 + 1) >= 2;
        zero2 = zero1;
        negative2 = negative1;
        overflow1 = overflow;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

/* D0DC44 publish_native_single_or_blinking_multi_target_markers_v3   [class A, 48 bytes, 19 instructions]
 * Source: src/rom/select_native_menu_target_with_controller_edges_and_real_vblank.s
 * Subroutine of select_native_menu_target_with_controller_edges_and_real_vblank, translated in place.
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void publish_native_single_or_blinking_multi_target_markers_v3(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}

/* D0DC44 publish_native_single_or_blinking_multi_target_markers_v4   [class A, 48 bytes, 19 instructions]
 * Source: src/rom/select_native_menu_target_with_controller_edges_and_real_vblank.s
 * Subroutine of select_native_menu_target_with_controller_edges_and_real_vblank, translated in place.
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void publish_native_single_or_blinking_multi_target_markers_v4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 1)) return;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}

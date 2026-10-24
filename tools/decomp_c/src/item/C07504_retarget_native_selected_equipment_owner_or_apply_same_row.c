#include "som_c.h"
#include "som_hand_d.h"

static void rebuild_native_equipment_stats_publish_rows_and_request_refresh(SomCtx *c);

/* C07504 retarget_native_selected_equipment_owner_or_apply_same_row   [class C, 278 bytes, 109 instructions]
 * Source: src/rom/retarget_native_selected_equipment_owner_or_apply_same_row.s
 * Entry: any M, X, DB and D.  Callers read: BXYCV.
 */
static void retarget_native_selected_equipment_owner_or_apply_same_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    i_sep(r, 0x20);
    LDA(c, ABS, 0x180A);
    CMP(c, ABS, 0x185C);
    if (!r->z) {
        STA(c, ABS, 0x185C);
        JSR(c, 0x7513, 0xC07908);
        JSR(c, 0x7516, 0xC0794A);
        i_sep(r, 0x20);
        STA(c, ABS, 0x185D);
        TAIL_CALL(c, 0xC07275, SOM_RTS); /* external */
    }
    i_rep(r, 0x30);
    LDX(c, ABS, 0x182C);
    LDA(c, ALX, 0x7ECC00);
    a_and(r, 0x003F);
    LDY(c, ABS, 0x1808);
    JSL(c, 0x7539, 0xC079C7); /* test_native_menu_item_eligibility_for_selected_hero */
    if (!r->z) {
        i_rep(r, 0x30);
        LDA(c, ABS, 0x1808);
        JSR(c, 0x7543, 0xC076CC); /* remove_native_inventory_owner_and_return_owner_bits */
        i_sep(r, 0x20);
        i_pha(c);
        LDX(c, ABS, 0x182C);
        LDA(c, ALX, 0x7ECC00);
        ORA(c, SR, 0x01);
        STA(c, ALX, 0x7ECC00);
        JSL(c, 0x7557, 0xD0D1FB);
        LDX(c, ABS, 0x182A);
        JSR(c, 0x755D, 0xC07A7D);
        i_pla(c);
        LDA(c, ABS, 0x19F0);
        if (!r->n) {
            LDA(c, ABS, 0x1808);
            STA(c, ABS, 0x19F2);
            JSR(c, 0x75AB, 0xC07699);
        }
        rebuild_native_equipment_stats_publish_rows_and_request_refresh(c); /* the code at C075E4 runs on to the RTS */
        return;
    }
    JSR(c, 0x759A, 0xC07908);
    JSR(c, 0x760C, 0xC0692D);
    i_sep(r, 0x20);
    a_lda(r, 0x40);
    TRB(c, ABS, 0x1803);
    a_lda(r, 0x02);
    TSB(c, ABS, 0x1803);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07504, SOM_RTS, "hand", retarget_native_selected_equipment_owner_or_apply_same_row, 0, L_B | L_X | L_Y | L_C | L_V, 6, -1, -1, 278, 109)

/* C075E4 rebuild_native_equipment_stats_publish_rows_and_request_refresh   [class A, 54 bytes, 25 instructions]
 * Source: src/rom/retarget_native_selected_equipment_owner_or_apply_same_row.s
 * Subroutine of retarget_native_selected_equipment_owner_or_apply_same_row, translated in place.
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCZNV.
 */
static void rebuild_native_equipment_stats_publish_rows_and_request_refresh(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x1808);
    r->a = (((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) & 0xFF00;
    r->x = (((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) & 0xFF00;
    r->c = value & 0x8000;
    r->z = ((((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) & 0xFF00) == 0;
    r->n = (((uint8_t)(value << 1) << 8) | ((uint16_t)(value << 1) >> 8)) & 0xFF00 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x75F1, 0xC07A28); GUARD_JSR(c, sp_call, 0x75F1); } /* rebuild_native_equipped_actor_stats_and_cap_persistent_mana */
    { const uint16_t sp_call = r->sp; JSR(c, 0x75F4, 0xC0761A); GUARD_JSR(c, sp_call, 0x75F4); } /* publish_native_menu_transaction_result_with_real_vblank_and_ring_phase */
    uint8_t db_ret2 = r->db;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint8_t value2 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x1808);
    uint8_t a1;
    if ((uint8_t)(value2 << 1) != 0) {
        a1 = (uint8_t)(value2 << 1);
    } else {
        a1 = (uint8_t)((uint8_t)(value2 << 1) + 1);
    }
    BUS8_SET(c, (db_ret2 << 0x10) + 0x19F2, a1);
    uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x19F0);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    if (value3 == 2) {
        m_flag = 1;
        x_flag = x_ret3;
        a_hi1 = a_all2 >> 8;
    } else {
        r->c = value3 >= 2;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x760C, 0xC0692D); GUARD_JSR(c, sp_call, 0x760C); } /* request_event_menu_loop_and_initialize_input_state */
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        m_flag = 0;
        x_flag = x_ret5;
        a_hi1 = a_all3 >> 8;
    }
    uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x1803);
    BUS8_SET(c, (db_ret2 << 0x10) + 0x1803, value4 & 0xBF);
    uint8_t value5 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x1803);
    BUS8_SET(c, (db_ret2 << 0x10) + 0x1803, value5 | 2);
    r->a = (a_hi1 << 8) | 2;
    r->c = value3 >= 2;
    r->z = (value5 & 2) == 0;
    r->n = 0;
    r->mf = 1;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

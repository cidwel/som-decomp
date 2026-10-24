#include "som_c.h"

static void play_native_purchase_sound_and_publish_numeric_window_twice_v2(SomCtx *c);

/* C07AD1 buy_native_selected_shop_item_after_confirmation_and_capacity_checks   [class C, 379 bytes, 151 instructions]
 * Source: src/rom/buy_native_selected_shop_item_after_confirmation_and_capacity_checks.s
 * Documented in docs/event-menu-shop-purchase.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void buy_native_selected_shop_item_after_confirmation_and_capacity_checks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp_in = r->sp;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7AD3, 0xC07E30); GUARD_JSR(c, sp_call, 0x7AD3); } /* confirm_native_shop_transaction_with_real_dialogue_and_controller */
    uint8_t db_ret = r->db;
    bool zero_ret = r->z;
    if (!zero_ret) {
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x180A);
    uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x183C);
    uint16_t value3 = BUS16(c, 0xD80000 + (uint16_t)((value & 0xFF) + value2));
    r->a = value3;
    r->x = (uint16_t)((value & 0xFF) + value2);
    r->v = (((value & 0xFF) ^ (uint16_t)((value & 0xFF) + value2)) & (value2 ^ (uint16_t)((value & 0xFF) + value2)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7AE9, 0xC07C7B); GUARD_JSR(c, sp_call, 0x7AE9); } /* resolve_native_shop_item_price_and_test_money_preserving_item */
    uint16_t x_ret3 = r->x;
    if (x_ret3 != 0) {
        r->x = 0xFE2D;
        r->c = x_ret3 >= 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7B80, 0xD0CF00); GUARD_JSL(c, sp_call, 0x7B80); } /* request_native_menu_audio_0d */
        TAIL_CALL(c, 0xC07E95, SOM_RTS); /* display_native_shop_message_wait_release_and_new_button_then_refresh */
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7AF1, 0xC07D83); GUARD_JSR(c, sp_call, 0x7AF1); } /* insert_native_purchased_shop_item_and_consume_inventory_result_flag */
    bool x_ret6 = r->xf;
    bool zero_ret4 = r->z;
    if (!zero_ret4) {
        if (x_ret6) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->x = 0xFE49;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x7B80, 0xD0CF00); GUARD_JSL(c, sp_call, 0x7B80); } /* request_native_menu_audio_0d */
            TAIL_CALL(c, 0xC07E95, SOM_RTS); /* display_native_shop_message_wait_release_and_new_button_then_refresh */
        }
    }
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7AF6, 0xC07D0D); GUARD_JSR(c, sp_call, 0x7AF6); } /* deduct_native_shop_price_from_persistent_money */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x7AF9, play_native_purchase_sound_and_publish_numeric_window_twice_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x7AF9); }
    r->x = 0xFE20;
    TAIL_CALL(c, 0xC07E95, SOM_RTS); /* display_native_shop_message_wait_release_and_new_button_then_refresh */
}
SOM_REGISTER(0xC07AD1, SOM_RTS, "gen", buy_native_selected_shop_item_after_confirmation_and_capacity_checks, 0, L_B | L_X | L_Y | L_C | L_V, 5, -1, 0, 379, 151)

/* C07B00 play_native_purchase_sound_and_publish_numeric_window_twice_v2   [class A, 13 bytes, 4 instructions]
 * Source: src/rom/buy_native_selected_shop_item_after_confirmation_and_capacity_checks.s
 * Subroutine of buy_native_selected_shop_item_after_confirmation_and_capacity_checks, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void play_native_purchase_sound_and_publish_numeric_window_twice_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7B03, 0xD0CF28); GUARD_JSL(c, sp_call, 0x7B03); } /* request_native_menu_audio_2c */
    { const uint16_t sp_call = r->sp; JSL(c, 0x7B07, 0xD0D599); GUARD_JSL(c, sp_call, 0x7B07); } /* select_native_numeric_menu_window_script */
    { const uint16_t sp_call = r->sp; JSL(c, 0x7B0B, 0xD0D599); GUARD_JSL(c, sp_call, 0x7B0B); } /* select_native_numeric_menu_window_script */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}

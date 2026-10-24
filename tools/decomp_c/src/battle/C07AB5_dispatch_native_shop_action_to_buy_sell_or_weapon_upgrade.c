#include "som_c.h"

/* C07AB5 dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade   [class C, 22 bytes, 10 instructions]
 * Source: src/rom/dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade.s
 * Entry: M=8 bit X=any DB=any D=any.  Callers read: BXYCV.
 */
static void dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, -1)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7AB8, 0xD0CF08); GUARD_JSL(c, sp_call, 0x7AB8); } /* request_native_menu_audio_0e */
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0x1804);
    BUS8_SET(c, (db_ret << 0x10) + 0x1804, value | 0x40);
    uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x1847);
    r->a = (a_all >> 8 << 8) | (uint8_t)((uint8_t)(value2 - 1) << 1);
    r->x = (uint8_t)((a_all >> 8 << 8) | (uint8_t)((uint8_t)(value2 - 1) << 1));
    r->y = (uint8_t)y_ret;
    r->c = (uint8_t)(value2 - 1) & 0x80;
    r->z = (uint8_t)((a_all >> 8 << 8) | (uint8_t)((uint8_t)(value2 - 1) << 1)) == 0;
    r->n = (uint8_t)((a_all >> 8 << 8) | (uint8_t)((uint8_t)(value2 - 1) << 1)) & 0x80;
    r->mf = 0;
    r->xf = 0;
    switch ((uint8_t)((a_all >> 8 << 8) | (uint8_t)((uint8_t)(value2 - 1) << 1))) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC07AD1, SOM_RTS); /* buy_native_selected_shop_item_after_confirmation_and_capacity_checks */
    case 0x0002: TAIL_CALL_DYN(c, 0xC07B17, SOM_RTS); /* sell_native_selected_inventory_item_and_publish_remaining_inventory */
    case 0x0004: TAIL_CALL_DYN(c, 0xC07B95, SOM_RTS); /* upgrade_native_selected_weapon_with_orbs_money_and_equipped_hero_rebuild */
    default: TAIL_CALL_DYN(c, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x7ACB + ((uint8_t)((a_all >> 8 << 8) | (uint8_t)((uint8_t)(value2 - 1) << 1))))), SOM_RTS);
    }
}
SOM_REGISTER(0xC07AB5, SOM_RTS, "gen", dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 22, 10)

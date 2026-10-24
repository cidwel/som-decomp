#include "som_c.h"

/* C0B0D3 dispatch_five_phase_map_actor_animation_combat_and_menu_frame   [class B, 47 bytes, 20 instructions]
 * Source: src/rom/dispatch_five_phase_map_actor_animation_combat_and_menu_frame.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void dispatch_five_phase_map_actor_animation_combat_and_menu_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0056);
    if (value == 0) {
        r->a = (a >> 8 << 8) | value;
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB0F2, 0xC0FC8C); GUARD_JSR(c, sp_call, 0xB0F2); } /* advance_first_enemy_group_or_first_selected_boss_actor */
        TAIL_CALL(c, 0xC0E8D7, SOM_RTS); /* order_map_sprite_actor_groups */
    }
    if ((uint8_t)(value - 1) == 0) {
        r->a = (a >> 8 << 8) | (uint8_t)(value - 1);
        r->z = (uint8_t)(value - 1) == 0;
        r->n = (uint8_t)(value - 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB0F8, 0xC0B102); GUARD_JSR(c, sp_call, 0xB0F8); } /* release_global_actor_freeze_when_visible_effects_finish */
        r->mf = 1;
        r->xf = 0;
        TAIL_CALL(c, 0xC0FCB5, SOM_RTS); /* advance_second_enemy_group_or_second_selected_boss_actor */
    }
    if ((uint8_t)(value - 2) == 0) {
        r->a = (a >> 8 << 8) | (uint8_t)(value - 2);
        r->z = (uint8_t)(value - 2) == 0;
        r->n = (uint8_t)(value - 2) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB0FE, 0xC0FCDE); GUARD_JSR(c, sp_call, 0xB0FE); } /* advance_third_enemy_group_or_third_selected_boss_actor */
        TAIL_CALL(c, 0xC0B136, SOM_RTS); /* consume_three_controller_menu_edges_and_dispatch_full_ring */
    }
    if ((uint8_t)(value - 3) == 0) {
        r->a = (a >> 8 << 8) | (uint8_t)(value - 3);
        r->z = (uint8_t)(value - 3) == 0;
        r->n = (uint8_t)(value - 3) & 0x80;
        r->mf = 1;
        TAIL_CALL(c, 0xC0F4AB, SOM_RTS); /* advance_three_hero_animations_and_primary_geometry */
    }
    uint8_t value2 = RAM8(0x002A);
    bool m_flag;
    uint8_t a_hi1;
    uint16_t x1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    if (value2 == 0) {
        m_flag = 1;
        a_hi1 = a >> 8;
        x1 = x;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = 0;
    } else {
        r->a = (a >> 8 << 8) | value2;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xB0E9, 0x02C820); GUARD_JSL(c, sp_call, 0xB0E9); } /* update_scene_palette_rgb_offset_and_transition_phase */
        uint8_t db_ret3 = r->db;
        bool m_ret3 = r->mf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret6 = r->x;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        m_flag = m_ret3;
        a_hi1 = a_all4 >> 8;
        x1 = x_ret6;
        carry1 = carry_ret4;
        overflow1 = overflow_ret4;
        data_bank = db_ret3;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = 0;
    r->db = data_bank;
    TAIL_CALL(c, 0xC0F1AE, SOM_RTS); /* publish_secondary_hero_frame_geometry_with_saved_data_bank */
}
SOM_REGISTER(0xC0B0D3, SOM_RTS, "gen", dispatch_five_phase_map_actor_animation_combat_and_menu_frame, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 47, 20)

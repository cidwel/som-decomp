#include "som_c.h"
/* SOM_POLL_HOOK */

/* C1CB38 enter_complete_general_ring_between_scene_palette_and_nmi_phases   [class B, 74 bytes, 35 instructions]
 * Source: src/rom/enter_complete_general_ring_between_scene_palette_and_nmi_phases.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void enter_complete_general_ring_between_scene_palette_and_nmi_phases(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint64_t loop_guard = 0;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0010, x);
    RAM16_SET(0x0012, y);
    RAM8(0x0000 + sp0) = 0;
    r->mf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB41, 0xC1CB82); GUARD_JSR(c, sp_call, 0xCB41); } /* select_scene_bank_and_update_ring_sprite_shadow_priority */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM8(0x00EC) = 1;
    bool overflow1 = overflow_ret;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value = RAM8(0x00EC);
        overflow1 = value & 0x40;
        if (!((value & 1) != 0)) break;
    }
    uint8_t value2 = RAM8(0x002A);
    RAM8(0x0000 + sp0 - 1) = value2;
    r->a = (a_all >> 8 << 8) | value2;
    r->x = x;
    r->y = y_ret;
    r->c = carry_ret;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCB52, 0x02C7DD); GUARD_JSL(c, sp_call, 0xCB52); } /* exchange_native_scene_and_event_transition_palettes_when_active */
    r->sp += 2;
    RAM8(0x002A) = 0;
    uint16_t value3 = RAM16(0x0010);
    uint16_t value4 = RAM16(0x0012);
    uint8_t value5 = RAM8(0x0099);
    r->a = value5;
    r->x = value3;
    r->y = value4;
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCB63, 0xC00015); GUARD_JSL(c, sp_call, 0xCB63); } /* public_general_ring_menu_alias */
    r->sp += 2;
    uint16_t dp_ret = r->dp;
    uint16_t a_all3 = r->a;
    BUS8_SET(c, (uint16_t)(dp_ret + 0xEC), 0);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    BUS8_SET(c, (uint16_t)(dp_ret + 0x2A), value6);
    r->a = (a_all3 >> 8 << 8) | value6;
    r->z = value6 == 0;
    r->n = value6 & 0x80;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCB6E, 0x02C7DD); GUARD_JSL(c, sp_call, 0xCB6E); } /* exchange_native_scene_and_event_transition_palettes_when_active */
    r->sp += 1;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCB72, 0x02AB30); GUARD_JSL(c, sp_call, 0xCB72); } /* restore_event_sprite_palette_from_shadow */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCB75, 0xC1DB6B); GUARD_JSR(c, sp_call, 0xCB75); } /* dispatch_queued_actor_weapon_cast_or_motion_request */
    r->sp += 1;
    uint16_t dp_ret2 = r->dp;
    uint16_t a_all6 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret6 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint8_t value7 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (uint16_t)(dp_ret2 + 0xEC), 6);
    bool overflow2 = overflow_ret3;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0xEC));
        overflow2 = value8 & 0x40;
        if (!((value8 & 6) != 0)) break;
    }
    r->a = (a_all6 >> 8 << 8) | 6;
    r->x = x_ret5;
    r->y = y_ret6;
    r->c = carry_ret3;
    r->v = overflow2;
    r->mf = 1;
    r->db = value7;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1CB38, SOM_RTL, "gen", enter_complete_general_ring_between_scene_palette_and_nmi_phases, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 74, 35)

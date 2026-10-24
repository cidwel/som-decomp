#include "som_c.h"

/* C1EAC1 open_event_sale_ring_and_restore_native_sprite_context   [class C, 80 bytes, 31 instructions]
 * Source: src/rom/open_event_sale_ring_and_restore_native_sprite_context.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void open_event_sale_ring_and_restore_native_sprite_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0xD1));
    BUS16_RMW_SET(c, (uint16_t)(dp + 0xD1), (uint16_t)(value + 1));
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x3A));
    r->x = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEAC9, 0xC1F3F3); GUARD_JSR(c, sp_call, 0xEAC9); } /* stage_event_menu_sprites_and_preserve_actor_context */
    uint16_t dp_ret = r->dp;
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
    r->a = value3 & 0xFF;
    r->z = (value3 & 0xFF) == 0;
    r->n = value3 & 0xFF & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEAD2, 0xC0004B); GUARD_JSL(c, sp_call, 0xEAD2); } /* public_sale_ring_menu_alias */
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3ED, 0x00E351); GUARD_JSL(c, sp_call, 0xF3ED); } /* initialize_sprite_workspace_long */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF3F1, 0x02AB30); GUARD_JSL(c, sp_call, 0xF3F1); } /* restore_event_sprite_palette_from_shadow */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EAC1, SOM_RTS, "gen", open_event_sale_ring_and_restore_native_sprite_context, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 2354, 31)

#include "som_c.h"

/* C0FCB5 advance_second_enemy_group_or_second_selected_boss_actor   [class B, 41 bytes, 20 instructions]
 * Source: src/rom/advance_second_enemy_group_or_second_selected_boss_actor.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_second_enemy_group_or_second_selected_boss_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    uint8_t value = RAM8(0x00ED);
    if (!(value & 0x80)) {
        r->a = (a_hi << 8) | 0x7E;
        r->x = 0x0C00;
        r->z = 0;
        r->n = 0;
        r->v = value & 0x40;
        r->db = 0x7E;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFCCF, 0xC0FD1F); GUARD_JSR(c, sp_call, 0xFCCF); } /* tail_dispatch_ordinary_enemy_animation_step */
        r->sp += 1;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 0x0E00;
        r->z = 0;
        r->n = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFCD5, 0xC0FD1F); GUARD_JSR(c, sp_call, 0xFCD5); } /* tail_dispatch_ordinary_enemy_animation_step */
        r->sp += 1;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 0x1000;
        r->z = 0;
        r->n = 0;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFCDB, 0xC0FD1F); GUARD_JSR(c, sp_call, 0xFCDB); } /* tail_dispatch_ordinary_enemy_animation_step */
        r->sp += 1;
        r->db = RAM8(0x0000 + sp0);
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = (a_hi << 8) | 0x7E;
    r->x = 0x0800;
    r->z = 0;
    r->n = 0;
    r->v = value & 0x40;
    r->db = 0x7E;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFCC7, 0xC0FD07); GUARD_JSR(c, sp_call, 0xFCC7); } /* advance_selected_actor_frame_or_public_boss_pool */
    r->sp += 1;
    r->db = RAM8(0x0000 + sp0);
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0FCB5, SOM_RTS, "gen", advance_second_enemy_group_or_second_selected_boss_actor, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 41, 20)

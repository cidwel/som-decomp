#include "som_c.h"
#include "som_hand_b.h"

/* C12E94 project_packed_spell_entity_sprite_record_long   [class A, 29 bytes, 22 instructions]
 * Source: src/rom/project_packed_spell_entity_sprite_record_long.s
 * Documented in docs/actor-cast-entity-projection.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01D7.  Callers read: ABXYCV.
 */
static void project_packed_spell_entity_sprite_record_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$30, PHA: the caller's D, flags and A are kept on the stack. */
    RAM8(sp0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = hand_p_byte(r);
    r->mf = 0; r->xf = 0;                        /* REP #$30 */
    RAM8(sp0 - 3) = r->a >> 8;
    RAM8(sp0 - 4) = (uint8_t)r->a;

    /* TSC, INC, TCD: D points at the saved A.  PHB, then the two parameter words $0A and $08 above the return
     * address are pushed for the callee. */
    const uint16_t frame = (uint16_t)(sp0 - 4);
    RAM8(sp0 - 3) = r->db;
    uint16_t param1 = RAM16((uint16_t)(frame + 0x0A));
    RAM16_SET(sp0 - 5, param1);
    uint16_t param0 = RAM16((uint16_t)(frame + 0x08));
    RAM16_SET(sp0 - 7, param0);
    hand_nz16(r, param0);
    r->a = param0;
    r->dp = frame;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2EA6, 0xC1386F); GUARD_JSR(c, sp_call, 0x2EA6); }                /* project_packed_spell_entity_sprite_record */
    r->sp += 8;

    /* PLA, PLA leave the first parameter word in A (the callee may have rewritten it); SEP #$20, STA $01,S, PLA
     * pass its low byte through the saved bank byte; PLP and PLD restore the flags and D from the stack bytes,
     * which the callee (it ran with D inside this frame) may have changed. */
    r->a = RAM16(sp0 - 5);
    RAM8(sp0 - 3) = (uint8_t)r->a;
    r->mf = 1;
    som_pull_p(c, sp0 - 2);
    r->dp = (RAM8(sp0) << 8) | RAM8(sp0 - 1);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC12E94, SOM_RTL, "hand", project_packed_spell_entity_sprite_record_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 8, 0, 0, 29, 22)

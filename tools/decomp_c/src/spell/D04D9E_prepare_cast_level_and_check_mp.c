#include "som_c.h"
#include "som_hand_b.h"

/* D04D9E prepare_cast_level_and_check_mp   [class B, 47 bytes, hand written]
 * Source: src/rom/prepare_cast_level_and_check_mp.s
 *
 * PHD, PHB, PHP, prepare the cast actor context (it returns with its own D and the 8-bit accumulator), mark the
 * actor's three cast level bytes ($E172..$E174 + $83 index) as $FF, derive the element spell level and the cast level,
 * start the hardware multiply ($4202 = $E170 + index, $4203 = $40) and tail-jump to the MP check, which pops the
 * saved P, DB and D.  Every direct-page read uses the D the previous callee left.
 */
static void prepare_cast_level_and_check_mp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    i_phd(c);                                    /* PHD, PHB, PHP */
    i_phb(c);
    push8(c, hand_p_byte(r));
    { const uint16_t sp_call = r->sp; JSL(c, 0x4DA4, 0xC0395E); GUARD_JSL(c, sp_call, 0x4DA4); }   /* prepare_cast_actor_context_long */
    if (!r->mf || r->xf) { c->fail = 3; return; }           /* the 8-bit immediates below need the callee's widths */
    a_ldx(r, dp_rd16(c, 0x83));                  /* LDX $83 */
    const uint32_t bank = (uint32_t)r->db << 16;
    a_lda(r, 0xFF);                              /* LDA #$FF */
    BUS8_SET(c, bank + 0xE172 + r->x, 0xFF);     /* STA $E172,X ; $E173,X ; $E174,X */
    BUS8_SET(c, bank + 0xE173 + r->x, 0xFF);
    BUS8_SET(c, bank + 0xE174 + r->x, 0xFF);
    { const uint16_t sp_call = r->sp; JSR(c, 0x4DB4, 0xD04E6E); GUARD_JSR(c, sp_call, 0x4DB4); }   /* read_actor_element_spell_level */
    if (r->xf) { c->fail = 3; return; }
    a_ldx(r, dp_rd16(c, 0x83));                  /* LDX $83 */
    { const uint16_t sp_call = r->sp; JSR(c, 0x4DB9, 0xD04EAC); GUARD_JSR(c, sp_call, 0x4DB9); }   /* select_cast_level_with_grade_eight_progress */
    if (!r->mf || r->xf) { c->fail = 3; return; }
    a_ldx(r, dp_rd16(c, 0x83));                  /* LDX $83 */
    a_lda(r, BUS8(c, ((uint32_t)r->db << 16) + 0xE170 + r->x));   /* LDA $E170,X */
    BUS8_SET(c, 0x004202, r->a & 0xFF);          /* STA $004202 */
    a_lda(r, 0x40);                              /* LDA #$40 */
    BUS8_SET(c, 0x004203, 0x40);                 /* STA $004203 */
    r->sp += 4;                                  /* JML: the pushes stay for the callee to pop */
    TAIL_CALL_FRAME(c, 0xC03F69, SOM_RTL, 4);    /* check_cast_mp_and_queue_level_message */
}
SOM_REGISTER(0xD04D9E, SOM_RTL, "hand", prepare_cast_level_and_check_mp, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, -1, -1, 47, 18)

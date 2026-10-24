#include "som_c.h"
#include "som_hand_b.h"

/* C13D48 allocate_and_fill_spell_entity_heap_bytes   [class B, 53 bytes, hand written]
 * Source: src/rom/allocate_and_fill_spell_entity_heap_bytes.s
 * Documented in docs/actor-cast-entity-memory.md
 *
 * A.low = fill byte, X = byte count.  Builds a stack frame (D = S - 3, so $01..$05 are its locals and $04/$05 overlay
 * the saved accumulator), allocates the heap bytes with DB = $7E and fills them with the saved byte; returns the
 * allocated offset in X.  The frame is on the real stack because both callees run with D inside it.
 * Entry: any widths and any data bank (DB is saved and restored).
 */
static void allocate_and_fill_spell_entity_heap_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    (void)ram;
    i_phd(c);                                    /* PHD */
    push8(c, hand_p_byte(r));                    /* PHP */
    r->mf = 0; r->xf = 0;                        /* REP #$30 */
    push16(c, r->a);                             /* PHA */
    r->a = r->sp; zn(r, r->a, 0);                /* TSC */
    r->c = 1;                                    /* SEC, SBC #$0003 */
    r->a = hand_sbc16(r, r->a, 0x0003);
    r->dp = r->a; zn(r, r->dp, 0);               /* TCD */
    r->sp = r->a;                                /* TCS */
    a_lda(r, bus16_dp(c, (uint16_t)(r->sp + 4)));            /* LDA $04,S */
    r->mf = 1;                                   /* SEP #$20 */
    push8(c, r->db);                             /* PHB */
    push8(c, r->a);                              /* PHA */
    a_lda(r, 0x7E);                              /* LDA #$7E */
    push8(c, 0x7E);                              /* PHA, PLB */
    r->db = pull8(c); zn(r, r->db, 1);
    a_lda(r, pull8(c));                          /* PLA */
    dp_wr8(c, 0x01, r->a);                       /* STA $01 */
    dp_wr16(c, 0x04, r->x);                      /* STX $04 */
    { const uint16_t sp_call = r->sp; JSR(c, 0x3D65, 0xC13D29); GUARD_JSR(c, sp_call, 0x3D65); }   /* allocate_spell_entity_heap_bytes */
    if (r->xf) { c->fail = 3; return; }          /* STX/LDY below move 16 bits */
    dp_wr16(c, 0x02, r->x);                      /* STX $02 */
    a_lda(r, dp_rd8(c, 0x01));                   /* LDA $01 */
    a_ldy(r, dp_rd16(c, 0x04));                  /* LDY $04 */
    { const uint16_t sp_call = r->sp; JSR(c, 0x3D6E, 0xC14738); GUARD_JSR(c, sp_call, 0x3D6E); }   /* fill_native_entity_memory_bytes */
    if (r->xf) { c->fail = 3; return; }
    a_ldx(r, dp_rd16(c, 0x02));                  /* LDX $02 */
    r->db = pull8(c); zn(r, r->db, 1);           /* PLB */
    r->mf = 0;                                   /* REP #$20 */
    r->a = r->sp; zn(r, r->a, 0);                /* TSC */
    r->c = 0;                                    /* CLC, ADC #$0005 */
    r->a = hand_adc16(r, r->a, 0x0005);
    r->sp = r->a;                                /* TCS */
    som_pull_p(c, (uint16_t)(r->sp + 1)); r->sp++;           /* PLP */
    r->dp = pull16(c); zn(r, r->dp, 0);          /* PLD */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13D48, SOM_RTS, "hand", allocate_and_fill_spell_entity_heap_bytes, 0, L_ALL, 11, -1, -1, 53, 34)

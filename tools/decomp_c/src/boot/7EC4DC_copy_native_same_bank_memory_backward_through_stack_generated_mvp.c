#include "som_c.h"
#include "som_hand_b.h"

/* 7EC4DC copy_native_same_bank_memory_backward_through_stack_generated_mvp   [class C, 167 bytes, 101 instructions]
 * Source: src/boot/copy_native_same_bank_memory_backward_through_stack_generated_mvp.s
 * Documented in docs/boot-native-backward-memory-copy.md
 * Entry: any M/X/DB/D (REP #$30 comes first).  Callers read: nothing.
 *
 * Literal translation.  The count is the A passed in; X and Y are the end-relative pointers (source and destination
 * ends are X + count and Y + count).  Counts up to 20 bytes are copied backwards with absolute loads and stores in
 * the current data bank.  Larger counts write a four-byte MVP stub into the frame ($01..$04), then jump to it with RTS
 * once per 256-byte block; the stub's own RTS returns to the instruction after the jump.  The stub is executed by the
 * interpreter (it is code the routine writes).
 */

#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)
static inline void swap_a(Cpu *r) { r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); hand_nz8(r, r->a & 0xFF); }   /* XBA */

/* The routine itself lives in WRAM ($7E:C4DC..C582).  A copy whose destination overlaps those bytes rewrites the code that is
 * executing (the original then runs whatever the data decodes to), which this transliteration cannot follow: such a call is
 * outside the contract (fail = 3).  Block copies (MVP, count > 20) wrap inside the destination bank, byte copies do not. */
#define SELF_LO 0xC4DCu
#define SELF_HI 0xC583u
static inline int dest_hits_code_block(const Cpu *r, uint16_t y0, uint16_t count)
{
    if (r->db != 0x7E) return 0;
    return (uint16_t)(y0 - SELF_LO) < (SELF_HI - SELF_LO) || (uint16_t)(SELF_LO - y0) < count;
}
static inline int dest_hits_code_bytes(const Cpu *r, uint16_t y0, uint16_t count)
{
    const uint32_t lin = ((uint32_t)r->db << 16) + y0;
    return lin < (0x7E0000u + SELF_HI) && lin + count > (0x7E0000u + SELF_LO);
}

static void copy_native_same_bank_memory_backward_through_stack_generated_mvp(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$30, PHA, TSC, SEC, SBC #$0004, TCD, TCS */
    push16(c, r->dp);
    push8(c, hand_p_byte(r));
    r->mf = 0; r->xf = 0;
    push16(c, r->a);
    const uint16_t f = (uint16_t)(sp0 - 9);
    r->c = 1;
    r->a = hand_sbc16(r, (uint16_t)(sp0 - 5), 4);
    r->dp = f;
    r->sp = f;

    a_lda(r, RAM16((uint16_t)(f + 5)));  /* LDA $05,S: the A the routine was called with */
    hand_cmp16(r, r->a, 0x0000);         /* CMP #$0000 */
    if (!r->z) {
        hand_cmp16(r, r->a, 0x0015);     /* CMP #$0015 */
        if (r->c) {                      /* more than 20 bytes */
            if (dest_hits_code_block(r, r->y, r->a)) { c->fail = 3; return; }
            push8(c, r->db);             /* PHB */
            r->a = (uint16_t)(r->a - 1); hand_nz16(r, r->a);   /* DEC */
            dp_wr16(c, 0x05, r->a);      /* STA $05 */
            r->mf = 1;                   /* SEP #$20 */
            a_lda(r, 0x44); dp_wr8(c, 0x01, 0x44);
            { uint8_t b = RAM8((uint16_t)(f)); a_lda(r, b); dp_wr8(c, 0x02, b); }   /* LDA $01,S: the pushed DB */
            { uint8_t b = RAM8((uint16_t)(f)); a_lda(r, b); dp_wr8(c, 0x03, b); }
            a_lda(r, 0x60); dp_wr8(c, 0x04, 0x60);
            r->c = 0;
            r->mf = 0;
            r->a = r->x; hand_nz16(r, r->a);                    /* TXA */
            r->a = hand_adc16(r, r->a, dp_rd16(c, 0x05));      /* ADC $05 */
            r->x = r->a;                                        /* TAX */
            r->mf = 1; r->c = 0; r->mf = 0;
            r->a = r->y; hand_nz16(r, r->a);                    /* TYA */
            r->a = hand_adc16(r, r->a, dp_rd16(c, 0x05));
            r->y = r->a;                                        /* TAY */
            r->mf = 1;
            { uint8_t v = (uint8_t)(dp_rd8(c, 0x06) + 1); dp_wr8(c, 0x06, v); hand_nz8(r, v); }   /* INC $06 */
            do {
                push8(c, hand_p_byte(r));              /* PHP */
                r->mf = 0;
                a_lda(r, 0xC536); push16(c, 0xC536);   /* LDA #$C536 ; PHA */
                r->a = r->dp; hand_nz16(r, r->a);      /* TDC */
                r->c = 0;
                r->a = hand_adc16(r, r->a, 0);         /* CLC ; ADC #$0000 */
                push16(c, r->a);                       /* PHA */
                r->mf = 1;
                a_lda(r, 0x00);
                swap_a(r);                             /* XBA */
                a_lda(r, dp_rd8(c, 0x05));             /* LDA $05 */
                r->i = 1;                              /* SEI */
                i_rts(c);                              /* RTS into the stub at D+1 */
                som_interp_run(c, SOM_RTS, r->sp);     /* MVP ; RTS back to c537 */
                if (c->fail) return;
                swap_a(r);                             /* XBA */
                hand_plp(c);                           /* PLP */
                swap_a(r);                             /* XBA */
                dp_wr8(c, 0x05, r->a & 0xFF);          /* STA $05 */
                { uint8_t v = (uint8_t)(dp_rd8(c, 0x06) - 1); dp_wr8(c, 0x06, v); hand_nz8(r, v); }   /* DEC $06 */
            } while (!r->z);
            hand_plb(c); hand_nz8(r, r->db);           /* PLB */
            r->mf = 0;                                 /* REP #$20 */
        } else {
            /* c545: 1 to 20 bytes */
            if (dest_hits_code_bytes(r, r->y, r->a)) { c->fail = 3; return; }
            dp_wr16(c, 0x05, r->a);
            r->c = 0;
            r->a = r->x; hand_nz16(r, r->a);
            r->a = hand_adc16(r, r->a, dp_rd16(c, 0x05)); r->x = r->a;
            r->c = 0;
            r->a = r->y; hand_nz16(r, r->a);
            r->a = hand_adc16(r, r->a, dp_rd16(c, 0x05)); r->y = r->a;
            a_lda(r, dp_rd16(c, 0x05));
            r->z = (r->a & 1) == 0;                            /* BIT #$0001 */
            bool done = false;
            if (!r->z) {
                r->x = (uint16_t)(r->x - 1);
                r->y = (uint16_t)(r->y - 1);
                uint8_t b;
                BUS8_OK(c, ABS_ADDR(0x0000, r->x), b);
                BUS8_SET(c, ABS_ADDR(0x0000, r->y), b);
                a_lda(r, dp_rd16(c, 0x05));
                r->a = (uint16_t)(r->a - 1); hand_nz16(r, r->a);
                if (r->z) done = true;
            }
            if (!done) {
                r->a >>= 1;                                    /* LSR */
                dp_wr16(c, 0x05, r->a);
                do {
                    uint16_t w;
                    r->x = (uint16_t)(r->x - 2);
                    r->y = (uint16_t)(r->y - 2);
                    BUS16_OK(c, ABS_ADDR(0x0000, r->x), w);
                    bus16_set_once(c, ABS_ADDR(0x0000, r->y), w);
                    a_lda(r, w);
                    {
                        uint16_t v = (uint16_t)(dp_rd16(c, 0x05) - 1);
                        dp_wr16(c, 0x05, v);                   /* DEC $05 */
                        hand_nz16(r, v);
                    }
                } while (!r->z);
            }
        }
    }
    /* c57a: TSC, CLC, ADC #$0006, TCS, PLP, PLD, RTS */
    r->a = (uint16_t)(r->sp + 6);
    r->sp = (uint16_t)(sp0 - 3);
    som_pull_p(c, (uint16_t)(sp0 - 2));
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    RETURN_RTS(c);
}
#undef ABS_ADDR
SOM_REGISTER(0x7EC4DC, SOM_RTS, "hand", copy_native_same_bank_memory_backward_through_stack_generated_mvp, 0, 0, 15, -1, -1, 167, 101)

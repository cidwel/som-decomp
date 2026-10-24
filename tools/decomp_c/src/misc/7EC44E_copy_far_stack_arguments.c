#include "som_c.h"
#include "som_hand_b.h"

/* 7EC44E copy_far_stack_arguments   [class C, 142 bytes, 87 instructions]
 * Source: src/boot/copy_far_stack_arguments.s
 * Documented in docs/boot.md
 * Entry: any M/X/DB/D (REP #$30 comes first).  Callers read: XY.
 *
 * Literal translation.  The arguments sit above the saved D and P in the caller's stack: destination pointer at $0A,
 * source pointer at $0D, count word at $10, one byte of block counter at $11.  Counts up to 16 bytes are copied
 * with long indirect loads and stores.  Larger copies write a four-byte MVN stub into the frame ($01..$04), push the
 * return frame for it and jump to it with RTL, once per 256-byte block; the stub's own RTL comes back to the
 * instruction after the jump.  The stub is executed by the interpreter (it is code the routine writes).
 */

static void copy_far_stack_arguments(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$30, TSC, SEC, SBC #$0004, TCD, TCS */
    push16(c, r->dp);
    push8(c, hand_p_byte(r));
    r->mf = 0; r->xf = 0;
    const uint16_t f = (uint16_t)(sp0 - 7);
    r->c = 1;
    r->a = hand_sbc16(r, (uint16_t)(sp0 - 3), 4);
    r->dp = f;
    r->sp = f;

    /* SEP #$20, PHB, LDA #$00, PHA, PLB, REP #$20 */
    r->mf = 1;
    push8(c, r->db);
    a_lda(r, 0);
    push8(c, 0);
    r->db = pull8(c); hand_nz8(r, r->db);
    r->mf = 0;

    a_lda(r, dp_rd16(c, 0x10));          /* LDA $10 */
    if (!r->z) {                         /* BEQ c4d2 */
        hand_cmp16(r, r->a, 0x0011);     /* CMP #$0011 */
        if (r->c) {                      /* BCC c4b3 not taken: more than 16 bytes */
            r->a = (uint16_t)(r->a - 1); hand_nz16(r, r->a);   /* DEC */
            dp_wr16(c, 0x10, r->a);
            r->mf = 1;                   /* SEP #$20 */
            a_lda(r, 0x54); dp_wr8(c, 0x01, 0x54);
            { uint8_t b = dp_rd8(c, 0x0C); a_lda(r, b); dp_wr8(c, 0x02, b); }
            { uint8_t b = dp_rd8(c, 0x0F); a_lda(r, b); dp_wr8(c, 0x03, b); }
            a_lda(r, 0x6B); dp_wr8(c, 0x04, 0x6B);
            a_ldy(r, dp_rd16(c, 0x0A));  /* LDY $0A */
            a_ldx(r, dp_rd16(c, 0x0D));  /* LDX $0D */
            { uint8_t v = (uint8_t)(dp_rd8(c, 0x11) + 1); dp_wr8(c, 0x11, v); hand_nz8(r, v); }   /* INC $11 */
            do {
                push8(c, hand_p_byte(r));              /* PHP */
                a_lda(r, 0x7E); push8(c, 0x7E);        /* LDA #$7E ; PHA */
                r->mf = 0;
                a_lda(r, 0xC4A5); push16(c, 0xC4A5);   /* LDA #$C4A5 ; PHA */
                r->mf = 1;
                a_lda(r, 0x00); push8(c, 0x00);        /* LDA #$00 ; PHA */
                r->mf = 0;
                r->a = r->dp; hand_nz16(r, r->a);      /* TDC */
                r->c = 0;
                r->a = hand_adc16(r, r->a, 0);         /* CLC ; ADC #$0000 */
                push16(c, r->a);                       /* PHA */
                r->mf = 1;
                a_lda(r, 0x00);
                r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); hand_nz8(r, r->a & 0xFF);   /* XBA */
                a_lda(r, dp_rd8(c, 0x10));             /* LDA $10 */
                r->i = 1;                              /* SEI */
                i_rtl(c);                              /* RTL into the stub at D+1 */
                som_interp_run(c, SOM_RTL, r->sp);     /* MVN ; RTL back to c4a6 */
                if (c->fail) return;
                r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); hand_nz8(r, r->a & 0xFF);   /* XBA */
                hand_plp(c);                           /* PLP */
                r->a = (uint16_t)((r->a << 8) | (r->a >> 8)); hand_nz8(r, r->a & 0xFF);   /* XBA */
                dp_wr8(c, 0x10, r->a & 0xFF);          /* STA $10 */
                { uint8_t v = (uint8_t)(dp_rd8(c, 0x11) - 1); dp_wr8(c, 0x11, v); hand_nz8(r, v); }   /* DEC $11 */
            } while (!r->z);
            r->mf = 0;                   /* REP #$20 */
        } else {
            /* c4b3: 1 to 16 bytes */
            r->y = 0; r->z = 1; r->n = 0;                      /* LDY #$0000 */
            r->z = (r->a & 1) == 0;                            /* BIT #$0001 */
            /* the long pointers are read again at every access: the copy may overwrite them */
#define SRC_ADDR() ((dp_rd16(c, 0x0D) | ((uint32_t)dp_rd8(c, 0x0F) << 16)) + r->y)
#define DST_ADDR() ((dp_rd16(c, 0x0A) | ((uint32_t)dp_rd8(c, 0x0C) << 16)) + r->y)
            bool done = false;
            if (!r->z) {
                uint8_t b;
                r->mf = 1;               /* SEP #$20 */
                BUS8_OK(c, SRC_ADDR() & 0xFFFFFF, b);
                a_lda(r, b);             /* LDA [$0D],Y: the byte replaces the low half of the count */
                BUS8_SET(c, DST_ADDR() & 0xFFFFFF, b);
                r->mf = 0;               /* REP #$20 */
                r->y = (uint16_t)(r->y + 1);
                r->a = (uint16_t)(r->a - 1); hand_nz16(r, r->a);   /* DEC works on the loaded byte, as in the original */
                if (r->z) done = true;
            }
            if (!done) {
                r->x = r->a >> 1;        /* LSR ; TAX */
                hand_nz16(r, r->x);
                do {
                    uint16_t w;
                    BUS16_OK(c, SRC_ADDR() & 0xFFFFFF, w);
                    bus16_set_once(c, DST_ADDR() & 0xFFFFFF, w);
                    r->y = (uint16_t)(r->y + 2);
                    r->x = (uint16_t)(r->x - 1); hand_nz16(r, r->x);
                } while (!r->z);
            }
#undef SRC_ADDR
#undef DST_ADDR
        }
    }
    /* c4d2: PLB, SEP #$20, four PLA, PLP, PLD, RTS */
    r->db = pull8(c); hand_nz8(r, r->db);
    r->mf = 1;
    r->sp = (uint16_t)(f + 4);
    a_lda(r, RAM8((uint16_t)(f + 4)));
    r->sp = (uint16_t)(sp0 - 3);
    som_pull_p(c, (uint16_t)(sp0 - 2));
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC44E, SOM_RTS, "hand", copy_far_stack_arguments, 0, L_X | L_Y, 15, -1, -1, 142, 87)

#include "som_c.h"
#include "som_hand_b.h"

/* C1479D copy_stack_argument_long_pointer_bytes   [class B, 79 bytes, hand written]
 * Source: src/rom/copy_stack_argument_long_pointer_bytes.s
 *
 * Copies a byte count from one 24-bit address to another; the arguments are on the caller's stack, above the return
 * address: destination pointer (3 bytes) at +$0C, source pointer (3 bytes) at +$0F, count at +$12, all relative to the
 * frame D (= S - 6 after the saves).  The routine copies a leading odd byte, then words.  It runs with DB = 0.
 *
 * The frame is built on the real stack:   sp0 D high, D low, P, ... (PHD, PHP, then PHB, PHA of the bank zero)
 * Exit: A = frame D + 6, X/Y = the copy counters, C/V/D/I and the widths = the entry flags (PLP), N/Z from the
 * pulled D (PLD).
 */
static inline int rd_long_ok(SomCtx *c, uint32_t a, uint8_t *out)
{
    if (!hand_rd_ok(a & 0xFFFFFF)) { c->fail = 3; return 0; }
    *out = BUS8(c, a & 0xFFFFFF);
    return 1;
}

static void copy_stack_argument_long_pointer_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;

    i_phd(c);                                    /* PHD */
    push8(c, hand_p_byte(r));                    /* PHP */
    r->mf = 0;                                   /* REP #$20 */
    r->a = r->sp; zn(r, r->a, 0);                /* TSC */
    r->c = 1;                                    /* SEC, SBC #$0006 */
    r->a = hand_sbc16(r, r->a, 0x0006);
    r->dp = r->a; zn(r, r->dp, 0);               /* TCD */
    r->sp = r->a;                                /* TCS */
    r->mf = 1;                                   /* SEP #$20 */
    push8(c, r->db);                             /* PHB */
    r->a &= 0xFF00; zn(r, 0, 1);                 /* LDA #$00 */
    push8(c, 0);                                 /* PHA, PLB */
    r->db = pull8(c); zn(r, r->db, 1);
    r->mf = 0;                                   /* REP #$20 */
    r->x = dp_rd16(c, 0x12); zn(r, r->x, 0);     /* LDX $12: the count */
    if (r->x != 0) {                             /* BEQ */
        r->a = dp_rd16(c, 0x0C); zn(r, r->a, 0); dp_wr16(c, 0x01, r->a);   /* the 6 pointer bytes move to $01..$06 */
        r->a = dp_rd16(c, 0x0E); zn(r, r->a, 0); dp_wr16(c, 0x03, r->a);
        r->a = dp_rd16(c, 0x10); zn(r, r->a, 0); dp_wr16(c, 0x05, r->a);
        r->y = 0;                                /* LDY #$0000 */
        zn(r, r->y, 0);
        r->a = r->x; zn(r, r->a, 0);             /* TXA */
        a_biti(r, 0x0001);                       /* BIT #$0001 */
        int done = 0;
        if (!r->z) {                             /* odd count: copy one byte first */
            uint32_t src = (dp_rd16(c, 0x04) | ((uint32_t)dp_rd8(c, 0x06) << 16)) + r->y;
            uint32_t dst = (dp_rd16(c, 0x01) | ((uint32_t)dp_rd8(c, 0x03) << 16)) + r->y;
            uint8_t v;
            if (!rd_long_ok(c, src, &v)) return;
            r->mf = 1; r->a = (r->a & 0xFF00) | v; zn(r, v, 1);      /* SEP #$20, LDA [$04],Y */
            BUS8_SET(c, dst & 0xFFFFFF, v);      /* STA [$01],Y */
            r->mf = 0;                           /* REP #$20 */
            r->y = (uint16_t)(r->y + 1); zn(r, r->y, 0);               /* INY */
            r->a = r->x; zn(r, r->a, 0);         /* TXA */
            r->a = (uint16_t)(r->a - 1); zn(r, r->a, 0);               /* DEC */
            if (r->z) done = 1;                  /* BEQ: a single byte */
        }
        if (!done) {
            r->c = r->a & 1; r->a >>= 1; zn(r, r->a, 0);               /* LSR */
            r->x = r->a; zn(r, r->x, 0);         /* TAX */
            do {
                uint32_t src = (dp_rd16(c, 0x04) | ((uint32_t)dp_rd8(c, 0x06) << 16)) + r->y;
                uint32_t dst = (dp_rd16(c, 0x01) | ((uint32_t)dp_rd8(c, 0x03) << 16)) + r->y;
                uint8_t lo, hi;
                if (!rd_long_ok(c, src, &lo) || !rd_long_ok(c, src + 1, &hi)) return;
                r->a = lo | (hi << 8); zn(r, r->a, 0);                 /* LDA [$04],Y */
                BUS8_SET(c, dst & 0xFFFFFF, lo);                       /* STA [$01],Y */
                BUS8_SET(c, (dst + 1) & 0xFFFFFF, hi);
                r->y = (uint16_t)(r->y + 2); zn(r, r->y, 0);           /* INY, INY */
                r->x = (uint16_t)(r->x - 1); zn(r, r->x, 0);           /* DEX */
            } while (!r->z);                     /* BNE */
        }
    }
    r->db = pull8(c); zn(r, r->db, 1);           /* PLB */
    r->a = r->sp; zn(r, r->a, 0);                /* TSC */
    r->c = 0;                                    /* CLC, ADC #$0006 */
    r->a = hand_adc16(r, r->a, 0x0006);
    r->sp = r->a;                                /* TCS */
    som_pull_p(c, (uint16_t)(r->sp + 1)); r->sp++;   /* PLP */
    r->dp = pull16(c); zn(r, r->dp, 0);          /* PLD */
    (void)sp0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1479D, SOM_RTS, "hand", copy_stack_argument_long_pointer_bytes, 0, L_ALL, 11, -1, 0, 79, 50)

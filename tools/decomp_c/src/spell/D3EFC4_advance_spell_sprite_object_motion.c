#include "som_c.h"
#include "som_hand_b.h"

/* D3EFC4 advance_spell_sprite_object_motion   [class B, 237 bytes, 115 instructions]
 * Source: src/rom/advance_spell_sprite_object_motion.s
 * Documented in docs/actor-cast-entity-sprite-motion.md
 * Entry: any M/X/DB/D (REP #$30 comes first).  Callers read: B.
 *
 * Literal translation: a 10-byte direct-page frame under the saved A, D points at it, every D-relative access goes
 * through the live D and every absolute access through the live DB.
 */

/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSR
#undef I_JSL
#define I_JSR(c, retpc, target) HAND_JSR_RESUME(c, retpc, target, sp0)
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)
/* The code after every call is assembled for 16-bit A and index registers where it matters. */
#define NEED_WIDE() do { if (r->mf || r->xf) { c->fail = 3; return; } } while (0)

static void advance_spell_sprite_object_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$30, PHA, TSC, SEC, SBC #$000A, TCD, TCS */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    r->mf = 0; r->xf = 0;
    RAM8((uint16_t)(sp0 - 3)) = r->a >> 8;
    RAM8((uint16_t)(sp0 - 4)) = (uint8_t)r->a;
    const uint16_t f = (uint16_t)(sp0 - 15);
    r->c = 1;
    hand_sbc16(r, (uint16_t)(sp0 - 5), 0x000A);
    r->dp = f;
    r->sp = f;

    /* LDA $0B,S; SEP #$20; STX $03; XBA; LDA a:$023A,X; REP #$20; PHA */
    uint16_t saved = RAM16((uint16_t)(sp0 - 4));
    r->mf = 1;
    dp_wr16(c, 3, r->x);
    r->a = (uint16_t)((saved << 8) | (saved >> 8));
    hand_nz8(r, r->a & 0xFF);
    {
        uint8_t b;
        BUS8_OK(c, ABS_ADDR(0x023A, r->x), b);
        a_lda(r, b);
    }
    r->mf = 0;
    RAM8(f) = r->a >> 8;
    RAM8((uint16_t)(f - 1)) = (uint8_t)r->a;
    r->sp = (uint16_t)(f - 2);
    JSL(c, 0xEFE0, 0xC12EC5);            /* scale_native_spell_sprite_angle_coefficient_long */
    NEED_WIDE();
    dp_wr16(c, 7, r->a);                 /* STA $07 */
    r->sp = f;                           /* PLA */
    r->a = (uint16_t)(RAM8((uint16_t)(f - 1)) | (RAM8(f) << 8));
    hand_nz16(r, r->a);
    JSL(c, 0xEFE7, 0xC12EC1);            /* scale_native_spell_sprite_quarter_turn_coefficient_long */
    NEED_WIDE();
    dp_wr16(c, 9, r->a);                 /* STA $09 */
    a_ldx(r, dp_rd16(c, 3));             /* LDX $03 */
    r->c = 0;                            /* CLC */
    {
        uint16_t m;
        BUS16_OK(c, ABS_ADDR(0x0237, r->x), m);
        r->a = hand_adc16(r, r->a, m);
        bus16_set_once(c, ABS_ADDR(0x0237, r->x), r->a);
    }
    r->mf = 1;
    a_lda(r, dp_rd8(c, 0x0A));           /* LDA $0A */
    a_and(r, 0x80);
    if (!r->z) { a_lda(r, 0xFF); }
    {
        uint8_t m;
        BUS8_OK(c, ABS_ADDR(0x0239, r->x), m);
        r->a = (r->a & 0xFF00) | hand_adc8(r, r->a & 0xFF, m);
        BUS8_SET(c, ABS_ADDR(0x0239, r->x), r->a & 0xFF);
    }
    r->mf = 0;
    a_lda(r, dp_rd16(c, 7));             /* LDA $07 */
    r->c = 0;
    {
        uint16_t m;
        BUS16_OK(c, ABS_ADDR(0x0234, r->x), m);
        r->a = hand_adc16(r, r->a, m);
        bus16_set_once(c, ABS_ADDR(0x0234, r->x), r->a);
    }
    r->mf = 1;
    a_lda(r, dp_rd8(c, 8));              /* LDA $08 */
    a_and(r, 0x80);
    if (!r->z) { a_lda(r, 0xFF); }
    {
        uint8_t m;
        BUS8_OK(c, ABS_ADDR(0x0236, r->x), m);
        r->a = (r->a & 0xFF00) | hand_adc8(r, r->a & 0xFF, m);
        BUS8_SET(c, ABS_ADDR(0x0236, r->x), r->a & 0xFF);
    }
    {
        uint8_t m;
        BUS8_OK(c, ABS_ADDR(0x023A, r->x), m);
        a_lda(r, m);
        r->c = 0;
        r->a = (r->a & 0xFF00) | hand_adc8(r, r->a & 0xFF, 0x10);
        for (int i = 0; i < 5; i++) i_lsra(r);
        dp_wr8(c, 0x0B, r->a & 0xFF);    /* STA $0B */
        BUS8_OK(c, ABS_ADDR(0x023B, r->x), m);
        a_lda(r, (uint8_t)(m + 1));      /* LDA a:$023B,X ; INC */
        a_cmp(r, 0x78);
        if (r->c) a_lda(r, 0);           /* BCC keeps the incremented value */
        BUS8_SET(c, ABS_ADDR(0x023B, r->x), r->a & 0xFF);
    }
    JSR(c, 0xF03A, 0xD3EFAE);            /* get_spell_sprite_object_history_entry */
    if (r->xf) { c->fail = 3; return; }
    r->mf = 0;
    {
        uint16_t m;
        BUS16_OK(c, ABS_ADDR(0x0238, r->x), m);
        a_lda(r, m);
        BUS16_SET(c, ABS_ADDR(0x0002, r->y), r->a);
        BUS16_OK(c, ABS_ADDR(0x0235, r->x), m);
        a_lda(r, m);
        BUS16_SET(c, ABS_ADDR(0x0000, r->y), r->a);
    }
    r->a = 0x000A; r->z = 0; r->n = 0;   /* LDA #$000A */
    dp_wr16(c, 1, r->a);
    a_ldx(r, dp_rd16(c, 3));
    r->c = 0;
    r->a = r->x; hand_nz16(r, r->a);     /* TXA */
    r->a = hand_adc16(r, r->a, 0);       /* ADC #$0000 */
    r->x = r->a;                         /* TAX */
    do {
        dp_wr16(c, 5, r->x);             /* STX $05 */
        {
            uint16_t m;
            BUS16_OK(c, ABS_ADDR(0x0007, r->x), m);
            a_lda(r, m);
        }
        a_and(r, 0x00FF);
        r->z = (r->a & 0x0080) == 0;     /* BIT #$0080 (immediate: Z only) */
        if (r->z) {
            a_ldx(r, dp_rd16(c, 3));
            JSR(c, 0xF067, 0xD3EFAE);    /* get_spell_sprite_object_history_entry */
            NEED_WIDE();
            a_ldx(r, dp_rd16(c, 5));
            {
                uint16_t m;
                BUS16_OK(c, ABS_ADDR(0x0002, r->y), m);
                a_lda(r, m);
                BUS16_SET(c, ABS_ADDR(0x0004, r->x), r->a);
                BUS16_OK(c, ABS_ADDR(0x0000, r->y), m);
                a_lda(r, m);
                BUS16_SET(c, ABS_ADDR(0x0002, r->x), r->a);
            }
            a_lda(r, dp_rd16(c, 1));
            a_cmp(r, 0x0004);
            if (r->c) a_lda(r, 0x0008);
            else a_lda(r, dp_rd16(c, 0x0B));
            JSR(c, 0xF086, 0xD3EF74);    /* project_spell_sprite_object_child */
            if (r->xf) { c->fail = 3; return; }
        }
        a_ldx(r, dp_rd16(c, 5));
        r->mf = 1;
        {
            uint8_t m;
            BUS8_OK(c, ABS_ADDR(0x0007, r->x), m);
            a_lda(r, (uint8_t)(m + 1));  /* LDA a:$0007,X ; INC */
            a_cmp(r, 0x78);
            if (r->c) {
                r->z = (r->a & 0x80) == 0;   /* BIT #$80 */
                if (r->z) a_lda(r, 0);
            }
            BUS8_SET(c, ABS_ADDR(0x0007, r->x), r->a & 0xFF);
        }
        r->mf = 0;
        r->c = 0;
        r->a = r->x; hand_nz16(r, r->a);
        r->a = hand_adc16(r, r->a, 8);
        r->x = r->a;
        {
            uint16_t cnt = (uint16_t)(dp_rd16(c, 1) - 1);
            dp_wr16(c, 1, cnt);
            hand_nz16(r, cnt);
        }
    } while (!r->z);

    /* TSC, CLC, ADC #$000C, TCS, PLP, PLD, RTS */
    r->a = (uint16_t)(r->sp + 0x0C);
    r->sp = (uint16_t)(sp0 - 3);
    som_pull_p(c, (uint16_t)(sp0 - 2));
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    RETURN_RTS(c);
}
#undef ABS_ADDR
SOM_REGISTER(0xD3EFC4, SOM_RTS, "hand", advance_spell_sprite_object_motion, 0, L_B, 17, -1, -1, 237, 115)

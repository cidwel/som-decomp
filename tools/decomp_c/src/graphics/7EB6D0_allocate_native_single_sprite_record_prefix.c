#include "som_c.h"
#include "som_hand_b.h"

/* 7EB6D0 allocate_native_single_sprite_record_prefix   [class C, 97 bytes, 53 instructions]
 * Source: src/boot/allocate_native_single_sprite_record_prefix.s
 * Documented in docs/boot-native-single-sprite-allocate.md
 * Entry: any M/X/DB/D (REP #$30 comes first).  Callers read: BXYCV.
 *
 * Native twin of C1402F working in bank 7F (the data bank is switched to $7F for the body).  Literal translation with a real stack.  The saved X word doubles as scratch ($01 is the counter, $02 the sprite
 * flag byte, both inside the pushed X), and the quad path ends with an extra PLX that leaves the stack one word short:
 * the final PLP, PLD and RTS then consume the caller's return address, i.e. the routine unwinds (SOM_UNWINDS).
 */

/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSR
#define I_JSR(c, retpc, target) HAND_JSR_RESUME(c, retpc, target, sp0)

#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)

static void allocate_native_single_sprite_record_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    bool quad = false;

    push16(c, r->dp);                    /* PHD */
    push8(c, hand_p_byte(r));            /* PHP */
    r->mf = 0; r->xf = 0;                /* REP #$30 */
    i_pha(c);                            /* PHA */
    r->a = r->sp; hand_nz16(r, r->a);    /* TSC */
    r->dp = r->a;                        /* TCD */
    i_pla(c);                            /* PLA */
    i_phx(c);                            /* PHX */
    r->mf = 1;                           /* SEP #$20 */
    push8(c, r->db);                     /* PHB */
    i_pha(c);                            /* PHA */
    a_lda(r, 0x7F);
    i_pha(c);                            /* LDA #$7F ; PHA */
    r->db = pull8(c); hand_nz8(r, r->db);/* PLB */
    i_pla(c);                            /* PLA */
    dp_wr8(c, 2, r->a & 0xFF);           /* STA $02 */
    {
        uint8_t v;
        BUS8_OK(c, ABS_ADDR(0x02CE, 0), v);
        a_lda(r, v);                     /* LDA a:$02CE */
    }
    quad = r->z;                         /* BEQ c1405e */
    a_lda(r, dp_rd8(c, 2));              /* LDA $02 */
    if (!quad) JSR(c, 0xB6ED, 0x7EB612); /* find_native_free_sprite_record_preferring_owner */
    else       JSR(c, 0xB703, 0x7EB671); /* find_native_free_sprite_group_preferring_owner */
    if (r->xf) { c->fail = 3; return; }  /* CPX #$0000 is assembled for 16-bit index registers */
    hand_cmp16(r, r->x, 0x0000);
    if (!r->z) {
        if (!r->mf) { c->fail = 3; return; }         /* LDA #$01 is assembled for 8-bit A */
        a_lda(r, 0x01);
        BUS8_SET(c, ABS_ADDR(0x0008, r->x), 0x01);
        a_lda(r, dp_rd8(c, 2));
        BUS8_SET(c, ABS_ADDR(0x000B, r->x), r->a & 0xFF);
        if (quad) {
            a_lda(r, 0x04);
            dp_wr8(c, 1, 0x04);          /* STA $01 */
            do {
                uint16_t yv;
                BUS16_OK(c, ABS_ADDR(0x0000, r->x), yv);
                a_ldy(r, yv);            /* LDY a:$0000,X */
                a_lda(r, 0x01);
                BUS8_SET(c, ABS_ADDR(0x0008, r->y), 0x01);
                a_lda(r, dp_rd8(c, 2));
                BUS8_SET(c, ABS_ADDR(0x000B, r->y), r->a & 0xFF);
                r->x = (uint16_t)(r->x + 1); hand_nz16(r, r->x);   /* INX */
                r->x = (uint16_t)(r->x + 1); hand_nz16(r, r->x);   /* INX */
                {
                    uint8_t v = (uint8_t)(dp_rd8(c, 1) - 1);
                    dp_wr8(c, 1, v);     /* DEC $01 */
                    hand_nz8(r, v);
                }
            } while (!r->z);
            i_plx(c);                    /* PLX */
        }
    }
    /* c1408a: PLB, PLA, PLA, PLP, PLD, RTS */
    r->db = pull8(c); hand_nz8(r, r->db);
    i_pla(c);
    i_pla(c);
    hand_plp(c);
    hand_pld(c);
    RETURN_RTS(c);
}
#undef ABS_ADDR
SOM_REGISTER(0x7EB6D0, SOM_RTS, "hand", allocate_native_single_sprite_record_prefix, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 10, -1, -1, 97, 53)

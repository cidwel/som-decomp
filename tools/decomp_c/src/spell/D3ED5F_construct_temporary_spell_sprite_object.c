#include "som_c.h"
#include "som_hand_b.h"

/* D3ED5F construct_temporary_spell_sprite_object   [class B, 181 bytes, 88 instructions]
 * Source: src/rom/construct_temporary_spell_sprite_object.s
 * Documented in docs/actor-cast-entity-sprite-objects.md
 * Entry: any M/X/DB/D (REP #$30 comes first).  Callers read: X.
 */
/* A callee that replaces its own return address makes the original resume at the new address and run on until this
 * routine's own RTS (the stack slides up to its entry); the interpreter does exactly that from the popped address. */
#undef I_JSL
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

static void construct_temporary_spell_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)

    /* PHD, PHP, REP #$30, PHA: the caller's D, flags and A are kept on the stack. */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    r->mf = 0; r->xf = 0;
    RAM8((uint16_t)(sp0 - 3)) = r->a >> 8;
    RAM8((uint16_t)(sp0 - 4)) = (uint8_t)r->a;

    /* TSC, SEC, SBC #7, TCD, TCS: a 9-byte frame below the saved A, D points at it. */
    const uint16_t f = (uint16_t)(sp0 - 12);
    r->c = 1;
    hand_sbc16(r, (uint16_t)(sp0 - 5), 7);        /* C and V of the SBC are still live at the first call */
    r->dp = f;
    r->sp = f;

    /* LDA $08,S (16-bit); SEP #$20; STA $01; XBA; STA $08; STX $02; LDA a:$0018,Y; STA $09 */
    uint16_t saved_a = RAM16((uint16_t)(sp0 - 4));
    r->mf = 1;
    dp_wr8(c, 1, (uint8_t)saved_a);
    dp_wr8(c, 8, saved_a >> 8);
    dp_wr16(c, 2, r->x);
    uint8_t b18;
    BUS8_OK(c, ABS_ADDR(0x0018, r->y), b18);
    dp_wr8(c, 9, b18);
    r->a = ((saved_a & 0xFF) << 8) | 0xF0;
    r->x = 0x0240;
    r->z = 0; r->n = 1;
    { JSL(c, 0xED83, 0xC12E78); }   /* allocate_and_fill_spell_entity_bytes_long */
    if (r->mf != 1 || r->xf) { c->fail = 3; return; }

    uint16_t x_ret = r->x;
    uint16_t a_all = r->a;
    dp_wr16(c, 4, x_ret);
    BUS8_SET(c, ABS_ADDR(0x023A, x_ret), dp_rd8(c, 1));
    BUS8_SET(c, ABS_ADDR(0x023B, x_ret), 0);
    BUS8_SET(c, ABS_ADDR(0x023C, x_ret), 0);
    BUS8_SET(c, ABS_ADDR(0x0237, x_ret), 0);
    BUS8_SET(c, ABS_ADDR(0x0234, x_ret), 0);
    (void)a_all;
    r->mf = 0;
    uint16_t v2 = dp_rd8(c, 2);
    BUS16_SET(c, ABS_ADDR(0x0052, x_ret), v2);
    BUS16_SET(c, ABS_ADDR(0x0238, x_ret), v2);
    uint16_t v3 = dp_rd16(c, 3) & 0xFF;
    BUS16_SET(c, ABS_ADDR(0x0050, x_ret), v3);
    BUS16_SET(c, ABS_ADDR(0x0235, x_ret), v3);
    r->c = 0;
    r->a = x_ret;
    r->a = hand_adc16(r, r->a, 0x0230);
    r->x = r->a;
    hand_lda_dp(c, 8);                             /* M is 16-bit here */
    { JSL(c, 0xEDBA, 0xC12EB1); }   /* position_spell_entity_from_actor_long */
    if (r->mf || r->xf) { c->fail = 3; return; }   /* the next LDA #$000A is assembled for 16-bit A */

    dp_wr16(c, 6, 0x000A);
    r->mf = 1;
    uint8_t v9 = dp_rd8(c, 9);
    r->a = v9 >> 4;                                /* LDA #$000A cleared the high byte */
    r->c = (v9 >> 3) & 1;
    dp_wr8(c, 9, (v9 >> 4) & 7);
    r->y = dp_rd16(c, 4);

    do {
        /* PHY, LDA #$03, JSL C12E80 */
        RAM8(f) = r->y >> 8;
        RAM8((uint16_t)(f - 1)) = (uint8_t)r->y;
        r->sp = (uint16_t)(f - 2);
        r->a = (r->a & 0xFF00) | 3;
        r->z = 0; r->n = 0;
        { JSL(c, 0xEDD4, 0xC12E80); }   /* activate_native_entity_sprite_long */
        if (r->mf != 1 || r->xf) { c->fail = 3; return; }
        uint16_t x3 = r->x;
        BUS8_SET(c, ABS_ADDR(0x0001, x3), dp_rd8(c, 9));
        BUS8_SET(c, ABS_ADDR(0x0002, x3), 0xF0);
        r->mf = 0;
        r->a = x3;
        /* PLY */
        r->sp = f;
        uint16_t y2 = (uint16_t)(RAM8((uint16_t)(f - 1)) | (RAM8(f) << 8));
        r->y = y2;
        BUS16_SET(c, ABS_ADDR(0x0000, y2), x3);
        r->x = dp_rd16(c, 6);
        r->x = (uint16_t)(r->x - 1);
        r->mf = 1;
        uint8_t t1, t2;
        BUS8_OK(c, 0xDCF88F + r->x, t1);
        BUS8_SET(c, ABS_ADDR(0x0006, y2), t1);
        BUS8_OK(c, 0xDCF899 + r->x, t2);
        BUS8_SET(c, ABS_ADDR(0x0007, y2), t2);
        r->c = 0;
        r->mf = 0;
        r->a = y2;
        r->a = hand_adc16(r, r->a, 8);
        r->y = r->a;
        r->mf = 1;
        uint8_t cnt = (uint8_t)(dp_rd8(c, 6) - 1);
        dp_wr8(c, 6, cnt);
        hand_nz8(r, cnt);
    } while (!r->z);

    /* LDX $04; REP #$20; TSC; CLC; ADC #$0009; TCS; PLP; PLD; RTS */
    r->x = dp_rd16(c, 4);
    r->mf = 0;
    r->a = (uint16_t)(r->sp + 9);
    r->sp = (uint16_t)(sp0 - 3);
    som_pull_p(c, (uint16_t)(sp0 - 2));
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    RETURN_RTS(c);
#undef ABS_ADDR
}
SOM_REGISTER(0xD3ED5F, SOM_RTS, "hand", construct_temporary_spell_sprite_object, 0, L_X, 14, -1, -1, 181, 88)

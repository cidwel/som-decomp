#include "som_c.h"
#include "som_hand.h"

/* 7EB23A release_record_chain   [class A, 30 bytes, 21 instructions]
 * Source: src/boot/release_record_chain.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: CV.
 */
static void release_record_chain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$30, SEP #$20, PHB, LDA #$7F, PHA, PLB, REP #$20, PHP, SEI */
    RAM8(sp0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = hand_p_byte(r);
    RAM8(sp0 - 3) = r->db;
    r->db = 0x7F;
    r->mf = 0;
    r->xf = 0;
    RAM8(sp0 - 4) = hand_p_byte(r);
    r->i = 1;
    r->sp = sp0 - 5;

    uint16_t link;
    do {
        r->sp = sp0 - 5;
        JSR(c, 0xB24B, 0x7EB20B); /* take_record_link */
        if (r->mf || r->xf) { c->fail = 3; return; }
        RAM8(sp0 - 5) = r->a >> 8;
        RAM8(sp0 - 6) = (uint8_t)r->a;
        r->sp = sp0 - 7;
        JSR(c, 0xB24F, 0x7EB1DD); /* release_eight_byte_record */
        if (r->mf || r->xf) { c->fail = 3; return; }
        link = RAM16(sp0 - 6);
        r->x = link;
        r->z = link == 0;
        r->n = link & 0x8000;
    } while (link != 0);

    r->sp = sp0 - 5;
    hand_plp(c);
    hand_plb(c);
    hand_plp(c);
    hand_pld(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB23A, SOM_RTS, "hand", release_record_chain, 0, L_C | L_V, 7, 0, 0, 30, 21)

#include "som_c.h"
#include "som_hand_b.h"

/* D3F983 release_spell_entity_trail_sprite_object   [class B, 53 bytes, 32 instructions]
 * Source: src/rom/release_spell_entity_trail_sprite_object.s
 * Documented in docs/actor-cast-entity-trail-objects.md
 * Entry: any M, X=16 bit, any DB and D.  Callers read: nothing.
 *
 * Literal translation: a 4-byte direct-page frame under the saved D and P, D points at it; the 20 trail objects of 16
 * bytes each are released one by one, then the heap bank.  The final four PLA instructions read the frame bytes back.
 */

/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSL
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)

static void release_spell_entity_trail_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$20, TSC, SEC, SBC #$0004, TCD, TCS */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    r->mf = 0;
    const uint16_t f = (uint16_t)(sp0 - 7);
    r->c = 1;
    r->a = hand_sbc16(r, (uint16_t)(sp0 - 3), 4);
    r->dp = f;
    r->sp = f;

    dp_wr16(c, 3, r->x);                 /* STX $03 */
    r->y = r->x; hand_nz16(r, r->y);     /* TXY */
    r->a = 0x0014; r->z = 0; r->n = 0;   /* LDA #$0014 */
    dp_wr16(c, 1, r->a);                 /* STA $01 */
    do {
        {
            uint16_t m;
            BUS16_OK(c, ABS_ADDR(0x0000, r->y), m);
            a_ldx(r, m);                 /* LDX a:$0000,Y */
        }
        RAM8(f) = r->y >> 8;             /* PHY */
        RAM8((uint16_t)(f - 1)) = (uint8_t)r->y;
        r->sp = (uint16_t)(f - 2);
        JSL(c, 0xF99D, 0xC12E88);        /* release_spell_sprite_instance_long */
        if (r->mf || r->xf) { c->fail = 3; return; }   /* the 16-bit immediate below needs 16-bit A and index registers */
        r->sp = f;                       /* PLY */
        r->y = (uint16_t)(RAM8((uint16_t)(f - 1)) | (RAM8(f) << 8));
        hand_nz16(r, r->y);
        r->c = 0;
        r->a = r->y; hand_nz16(r, r->a); /* TYA */
        r->a = hand_adc16(r, r->a, 0x0010);
        r->y = r->a;                     /* TAY */
        {
            uint16_t cnt = (uint16_t)(dp_rd16(c, 1) - 1);
            dp_wr16(c, 1, cnt);          /* DEC $01 */
            hand_nz16(r, cnt);
        }
    } while (!r->z);
    a_ldx(r, dp_rd16(c, 3));             /* LDX $03 */
    JSL(c, 0xF9AE, 0xC12E7C);            /* release_spell_entity_heap_bank_long */

    /* SEP #$20, four PLA, PLP, PLD, RTS: the pulls read the frame bytes back */
    r->mf = 1;
    r->sp = (uint16_t)(f + 4);
    a_lda(r, RAM8((uint16_t)(f + 4)));
    r->sp = (uint16_t)(sp0 - 3);
    som_pull_p(c, (uint16_t)(sp0 - 2));
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    RETURN_RTS(c);
}
#undef ABS_ADDR
SOM_REGISTER(0xD3F983, SOM_RTS, "hand", release_spell_entity_trail_sprite_object, 0, 0, 9, -1, -1, 53, 32)

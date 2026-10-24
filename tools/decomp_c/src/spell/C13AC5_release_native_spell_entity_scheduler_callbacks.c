#include "som_c.h"
#include "som_hand_b.h"

/* C13AC5 release_native_spell_entity_scheduler_callbacks   [class C, 105 bytes, 54 instructions]
 * Source: src/rom/release_native_spell_entity_scheduler_callbacks.s
 * Documented in docs/actor-cast-entity-engine.md
 * Entry: any M, X=16 bit, any DB and D.  Callers read: XYV.
 *
 * Literal translation.  Each live scheduler slot (8 bytes at X+0..) with a callback word at +6 is called through
 * PEA / PHA / RTS: the pushed address is the callback minus one, so the dispatch is a call whose return lands on the
 * instruction after the RTS.  X, Y and A are set up for the callback as the original leaves them.
 */

/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSR
#define I_JSR(c, retpc, target) HAND_JSR_RESUME(c, retpc, target, sp0)

#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)

static void release_native_spell_entity_scheduler_callbacks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;

    /* PHD, PHP, REP #$20, TSC, SEC, SBC #$0006, TCD, TCS */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    r->mf = 0;
    const uint16_t f = (uint16_t)(sp0 - 9);
    r->c = 1;
    r->a = hand_sbc16(r, (uint16_t)(sp0 - 3), 6);
    r->dp = f;
    r->sp = f;

    hand_cmp16(r, r->x, 0x0000);         /* CPX #$0000 */
    if (r->z) goto cleanup;              /* BEQ c13b19 */

    dp_wr16(c, 3, r->x);                 /* STX $03 */
    r->a = 4; r->z = 0; r->n = 0;
    dp_wr16(c, 1, 4);                    /* STA $01 */
    r->c = 0;
    r->a = r->x; hand_nz16(r, r->a);     /* TXA */
    r->a = hand_adc16(r, r->a, 0);
    r->x = r->a;                         /* TAX */
    do {
        dp_wr16(c, 5, r->x);             /* STX $05 */
        {
            uint16_t cb;
            BUS16_OK(c, ABS_ADDR(0x0006, r->x), cb);
            a_lda(r, cb);                /* LDA a:$0006,X */
        }
        if (!r->z) {
            /* PEA $3AF4; TXY; LDX a:$0002,Y; LDY $03; DEC; PHA; RTS */
            RAM8(f) = 0x3A;
            RAM8((uint16_t)(f - 1)) = 0xF4;
            r->y = r->x; hand_nz16(r, r->y);
            {
                uint16_t w;
                BUS16_OK(c, ABS_ADDR(0x0002, r->y), w);
                a_ldx(r, w);
            }
            a_ldx(r, r->x);              /* keeps the flags of LDX a:$0002,Y */
            r->y = dp_rd16(c, 3); hand_nz16(r, r->y);   /* LDY $03 */
            const uint16_t target = r->a;                /* the pushed address is A - 1; RTS adds one */
            r->a = (uint16_t)(r->a - 1); hand_nz16(r, r->a);   /* DEC */
            RAM8((uint16_t)(f - 2)) = r->a >> 8;         /* PHA leaves its bytes under the callee's stack */
            RAM8((uint16_t)(f - 3)) = (uint8_t)r->a;
            r->sp = f;
            const uint16_t ret_cb = 0x3AF4;                /* the address PEA pushed */
            const uint32_t callback = 0xC10000u | target;  /* K stays C1 */
            JSR(c, ret_cb, callback);                    /* the callback of the slot */
            if (r->mf || r->xf) { c->fail = 3; return; } /* the code that follows is assembled for 16-bit A and X */
        }
        a_ldx(r, dp_rd16(c, 5));         /* LDX $05 */
        BUS16_SET(c, ABS_ADDR(0x0004, r->x), 0);
        BUS16_SET(c, ABS_ADDR(0x0002, r->x), 0);
        BUS16_SET(c, ABS_ADDR(0x0006, r->x), 0);
        r->c = 0;
        r->a = r->x; hand_nz16(r, r->a);
        r->a = hand_adc16(r, r->a, 8);
        r->x = r->a;
        {
            uint16_t v = (uint16_t)(dp_rd16(c, 1) - 1);
            dp_wr16(c, 1, v);            /* DEC $01 */
            hand_nz16(r, v);
        }
    } while (!r->z);

    a_ldx(r, dp_rd16(c, 3));             /* LDX $03 */
    {
        uint16_t w;
        BUS16_OK(c, ABS_ADDR(0x002C, r->x), w);
        a_lda(r, w);                     /* LDA a:$002C,X */
        if (!r->z) goto done;            /* BNE c13b25 */
    }
    a_ldx(r, dp_rd16(c, 3));             /* LDX $03 */
    JSR(c, 0x3B15, 0xC13D7D);            /* release_spell_entity_heap_with_saved_bank */
    JSR(c, 0x3B18, 0xC12FE4);            /* wait_for_spell_entity_irq_completion */
cleanup:
    JSR(c, 0x3B1B, 0xC139BA);            /* queue_spell_entity_script_cleanup */
    JSR(c, 0x3B1E, 0xC12FE4);            /* wait_for_spell_entity_irq_completion */
    JSR(c, 0x3B21, 0xC12F33);            /* restore_spell_entity_irq_handler */
    if (r->xf) { c->fail = 3; return; }  /* LDX #$0000 is assembled for 16-bit index registers */
    r->x = 0; r->z = 1; r->n = 0;
done:
    /* TSC, CLC, ADC #$0006, TCS, PLP, PLD, RTS */
    r->a = (uint16_t)(r->sp + 6);
    r->sp = (uint16_t)(sp0 - 3);
    som_pull_p(c, (uint16_t)(sp0 - 2));
    r->dp = (uint16_t)(RAM8((uint16_t)(sp0 - 1)) | (RAM8(sp0) << 8));
    r->sp = sp0;
    RETURN_RTS(c);
}
#undef ABS_ADDR
SOM_REGISTER(0xC13AC5, SOM_RTS, "hand", release_native_spell_entity_scheduler_callbacks, 0, L_X | L_Y | L_V, 9, -1, 0, 105, 54)

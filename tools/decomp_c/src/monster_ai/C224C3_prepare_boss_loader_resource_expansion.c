#include "som_c.h"
#include "som_hand_b.h"

/* C224C3 prepare_boss_loader_resource_expansion   [class B, 46 bytes, 20 instructions]
 * Source: src/rom/prepare_boss_loader_resource_expansion.s
 * Documented in docs/maps.md
 * Entry: any A width, X=16 bit, any DB and D.  Callers read: BXYCV.
 *
 * Literal translation: the record index in A is shifted left three times (in the accumulator width at entry), moved
 * to X and used as the offset into the boss loader table in ROM bank D0; the six fields go to the direct page of the
 * caller, then the resource is expanded.
 */

/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSR
#define I_JSR(c, retpc, target) HAND_JSR_RESUME(c, retpc, target, sp0)

static void prepare_boss_loader_resource_expansion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;

    for (int i = 0; i < 3; i++) {                        /* ASL A */
        if (r->mf) { r->c = (r->a >> 7) & 1; r->a = (r->a & 0xFF00) | ((r->a << 1) & 0xFF); hand_nz8(r, r->a & 0xFF); }
        else       { r->c = (r->a >> 15) & 1; r->a = (uint16_t)(r->a << 1); hand_nz16(r, r->a); }
    }
    r->x = r->a; hand_nz16(r, r->x);                     /* TAX */
    r->mf = 1;                                           /* SEP #$20 */
    {
        uint8_t b;
        BUS8_OK(c, 0xD0BC52 + r->x, b); a_lda(r, b); dp_wr8(c, 0x7B, b);
        BUS8_OK(c, 0xD0BC53 + r->x, b); a_lda(r, b); dp_wr8(c, 0x7E, b);
    }
    r->mf = 0;                                           /* REP #$20 */
    {
        uint16_t w;
        BUS16_OK(c, 0xD0BC54 + r->x, w); a_lda(r, w); dp_wr16(c, 0x79, w);
        BUS16_OK(c, 0xD0BC56 + r->x, w); a_lda(r, w); dp_wr16(c, 0x7C, w);
        BUS16_OK(c, 0xD0BC58 + r->x, w); a_lda(r, w); dp_wr16(c, 0x68, w);
    }
    dp_wr16(c, 0x6A, 0);                                 /* STZ $6A */
    dp_wr16(c, 0x6C, 0);                                 /* STZ $6C */
    JSR(c, 0x24EF, 0xC224F1);                            /* expand_boss_loader_resource_to_bus */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC224C3, SOM_RTS, "hand", prepare_boss_loader_resource_expansion, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 46, 20)

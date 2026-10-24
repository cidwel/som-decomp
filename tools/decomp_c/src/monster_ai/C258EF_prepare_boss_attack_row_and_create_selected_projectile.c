#include "som_c.h"
#include "som_hand_b.h"

/* C258EF prepare_boss_attack_row_and_create_selected_projectile   [class A, 23 bytes, hand written]
 * Source: src/rom/prepare_boss_attack_row_and_create_selected_projectile.s
 *
 * Stores A at D+$00, reloads the boss pointer X from $87, runs the boss attack row selection (C0:006C), fetches the
 * projectile word $A9,X into Y, clears $95/$97 and creates the projectile with the saved A.  Every direct-page access
 * uses the D the caller (and then the row selection) leaves, and every load/store follows the accumulator and index
 * widths at run time.
 */
/* A callee that replaces its own return address: the interpreter continues from the popped address (see som_hand_b.h). */
#undef I_JSR
#undef I_JSL
#define I_JSR(c, retpc, target) HAND_JSR_RESUME(c, retpc, target, sp0)
#define I_JSL(c, retpc, target) HAND_JSL_RESUME(c, retpc, target, sp0)

static void prepare_boss_attack_row_and_create_selected_projectile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const uint16_t sp0 = r->sp;
    hand_sta_dp(c, 0x00);                        /* STA $00 */
    hand_ldx_dp(c, 0x87);                        /* LDX $87 */
    JSL(c, 0x58F6, 0xC0006C);   /* boss_attack_row_public_jump */
    hand_ldx_dp(c, 0x87);                        /* LDX $87 */
    {   /* LDY $00A9,X */
        const uint32_t a = ((uint32_t)r->db << 16) + 0x00A9 + r->x;
        const int n = r->xf ? 1 : 2;
        for (int i = 0; i < n; i++) if (!hand_rd_ok((a + i) & 0xFFFFFF)) { c->fail = 3; return; }
        a_ldy(r, r->xf ? BUS8(c, a & 0xFFFFFF) : BUS16(c, a & 0xFFFFFF));
    }
    if (r->mf) { dp_wr8(c, 0x95, 0); dp_wr8(c, 0x97, 0); }      /* STZ $95 ; STZ $97 */
    else { dp_wr16(c, 0x95, 0); dp_wr16(c, 0x97, 0); }
    hand_lda_dp(c, 0x00);                        /* LDA $00 */
    JSR(c, 0x5904, 0xC233BE);   /* create_boss_projectile_with_graphics_and_palette */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC258EF, SOM_RTS, "hand", prepare_boss_attack_row_and_create_selected_projectile, 0, L_ALL, 1, -1, -1, 23, 10)

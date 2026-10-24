#include "som_c.h"

/* C2362D resolve_boss_hurt_death_timer_and_animation_completion   [class B, 134 bytes, hand written]
 * docs/graphics.md.  Per-frame boss life-cycle decision for the descriptor in X.  Returns carry set when the descriptor
 * changed state this frame (callers then publish a notification), carry clear when nothing happened.
 *
 * Fields ($nn,X, accumulator width as left by the callees; the source assembles word immediates, so M = 16 in practice):
 *   $4A hurt callback    $82 hurt state (0 idle, 1 hurt, 2 dying)   $2D timer     $14 hit points    $96 damage taken
 *   $7C status flags     $AD armour counter   $9E invulnerable      $B0/$B2 death animation words  $BA/$BE death timer sources
 *   $94 descriptor phase
 */
static inline uint16_t ldm(SomCtx *c, uint32_t off) { return rdm(c, 0x7E0000 | (off & 0x1FFFF), 0x7E0000 | ((off + 1) & 0x1FFFF)); }
static inline void stm(SomCtx *c, uint32_t off, uint16_t v) { wrm(c, 0x7E0000 | (off & 0x1FFFF), 0x7E0000 | ((off + 1) & 0x1FFFF), v); }

static void resolve_boss_hurt_death_timer_and_animation_completion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    a_lda(r, ldm(c, 0x4A + r->x));
    if (!r->z) {
        JSR(c, 0x3634, 0xC236B3); /* invoke_state_callback */
        if (r->c) RETURN_RTS(c);  /* the callback finished the descriptor */
    }
    a_lda(r, ldm(c, 0x82 + r->x));
    a_cmp(r, 2);
    if (r->z) { /* already dying */
        JSR(c, 0x3671, 0xC234B0); /* test_boss_negative_status_word */
        if (r->c) {
            a_lda(r, 4);
            stm(c, 0x94 + r->x, r->a); /* phase 4: custom terminal state */
            r->c = 0;
            RETURN_RTS(c);
        }
        goto not_ready;
    }
    JSR(c, 0x3642, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
    if (!r->c) goto not_ready;
    a_lda(r, ldm(c, 0x82 + r->x));
    if (r->z) {
        JSR(c, 0x364C, 0xC234B0); /* test_boss_negative_status_word */
        if (!r->c) goto not_ready;
    }
    a_lda(r, 2); /* start dying */
    stm(c, 0x82 + r->x, r->a);
    stm(c, 0x2D + r->x, 0); /* STZ */
    a_lda(r, ldm(c, 0xBA + r->x));
    if (!r->z) {
        JSR(c, 0x365F, 0xC236B3); /* invoke_state_callback */
        a_ldx(r, rdx(c, 0x0287, 0x0288));
    } else {
        a_lda(r, ldm(c, 0xBE + r->x));
    }
    stm(c, 0xB0 + r->x, r->a);
    stm(c, 0xB2 + r->x, 0);
    r->c = 1;
    RETURN_RTS(c);

not_ready:
    a_lda(r, ldm(c, 0x14 + r->x));
    if (!r->z) {
        a_lda(r, ldm(c, 0x96 + r->x));
        a_cmp(r, ldm(c, 0x14 + r->x));
        if (r->c) RETURN_RTS(c); /* damage taken >= hit points: carry stays set */
    }
    a_lda(r, ldm(c, 0x4A + r->x));
    if (!r->z) { r->c = 0; RETURN_RTS(c); }
    a_lda(r, ldm(c, 0x82 + r->x));
    if (!r->z) {
        a_lda(r, ldm(c, 0x7C + r->x));
        a_biti(r, 1);
        if (r->z) {
            a_lda(r, ldm(c, 0xAD + r->x));
            a_cmp(r, ldm(c, 0x2D + r->x));
            if (r->c) RETURN_RTS(c);
        }
    }
    a_lda(r, ldm(c, 0x14 + r->x));
    if (!r->z) { r->c = 0; RETURN_RTS(c); }
    a_lda(r, ldm(c, 0x9E + r->x));
    if (!r->z) { r->c = 0; RETURN_RTS(c); }
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2362D, SOM_RTS, "hand", resolve_boss_hurt_death_timer_and_animation_completion, 0, L_ALL, 16, -1, -1, 134, 58)

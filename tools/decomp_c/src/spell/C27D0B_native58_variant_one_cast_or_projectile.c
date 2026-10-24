#include "som_c.h"
#include "som_hand_b.h"

/* C27D0B native58_variant_one_cast_or_projectile   [class B, 80 bytes, 32 instructions]
 * Source: src/rom/native58_variant_one_cast_or_projectile.s
 * Documented in docs/boss-native58-parent-actions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void native58_variant_one_cast_or_projectile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t x = RAM16(0x0287);
    r->x = x;
    uint16_t flags_a = RAM16(0xE990);
    uint16_t flags_b = RAM16(0xEB90);
    hand_nz16(r, flags_a & flags_b);
    if (r->n) {
        x = RAM16(0x0287);
        r->x = x;
        hand_nz16(r, x);
        uint16_t target = RAM16(0x02C7);
        r->a = target;
        RAM16_SET(0x00B6 + x, target);
        r->a = 0x012F;
        JSR_CHK(c, 0x7D56, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        JSR_CHK(c, 0x7D59, 0xC27D5B); /* choose_native58_farthest_close_or_nearest_projectile_attack */
        RETURN_RTS(c);
    }
    hand_nz16(r, flags_a);
    if (r->n) {
        r->a = 2;
        JSR_CHK(c, 0x7D1F, 0xC2300B); /* draw_boss_frame_random_number */
        if (r->z) {
            r->a = 5;
            RAM16_SET(0x0295, 5);
            JSR_CHK(c, 0x7D29, 0xC27DB5); /* prepare_native58_revive_cast_and_execute_success */
        }
    } else {
        r->a = flags_b;
        hand_nz16(r, flags_b);
        if (r->n) {
            r->a = 2;
            JSR_CHK(c, 0x7D36, 0xC2300B);
            if (r->z) {
                r->a = 6;
                RAM16_SET(0x0295, 6);
                JSR_CHK(c, 0x7D40, 0xC27DB5);
            }
        }
    }
    x = RAM16(0x0287);
    r->x = x;
    hand_nz16(r, x);
    r->a = 0x012F;
    JSR_CHK(c, 0x7D48, 0xC21394);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27D0B, SOM_RTS, "hand", native58_variant_one_cast_or_projectile, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 80, 32)

#include "som_c.h"
#include "som_hand_b.h"

/* C27CAB native58_variant_zero_cast_or_charge   [class B, 96 bytes, 38 instructions]
 * Source: src/rom/native58_variant_zero_cast_or_charge.s
 * Documented in docs/boss-native58-parent-actions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void native58_variant_zero_cast_or_charge(SomCtx *c)
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
        /* Both slots flagged: advance the charge counter at $00B2,X. */
        uint16_t counter = RAM16(0x00B2 + x);
        hand_nz16(r, counter);
        r->a = counter;
        if (counter == 0) {
            RAM16_SET(0x00B2 + x, (uint16_t)(counter + 1));
            hand_nz16(r, (uint16_t)(counter + 1));
            RETURN_RTS(c);
        }
        counter = (uint16_t)(counter + 1);
        RAM16_SET(0x00B2 + x, counter);
        hand_nz16(r, counter);
        r->a = counter;
        hand_cmp16(r, counter, 3);
        if (counter == 3) {
            r->a = 0x0120;
            JSR_CHK(c, 0x7D03, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
            r->a = 0x8000;
            r->n = 1;
            r->z = 0;
            RAM16_SET(0x003E + r->x, 0x8000);
        }
        RETURN_RTS(c);
    }
    hand_nz16(r, flags_a);
    if (r->n) {
        r->a = 2;
        JSR_CHK(c, 0x7CBF, 0xC2300B); /* draw_boss_frame_random_number */
        if (r->z) {
            r->a = 5;
            RAM16_SET(0x0295, 5);
            JSR_CHK(c, 0x7CC9, 0xC27DB5); /* prepare_native58_revive_cast_and_execute_success */
        }
    } else {
        r->a = flags_b;
        hand_nz16(r, flags_b);
        if (r->n) {
            r->a = 2;
            JSR_CHK(c, 0x7CD6, 0xC2300B);
            if (r->z) {
                r->a = 6;
                RAM16_SET(0x0295, 6);
                JSR_CHK(c, 0x7CE0, 0xC27DB5);
            }
        }
    }
    x = RAM16(0x0287);
    r->x = x;
    hand_nz16(r, x);
    r->a = 0x012F;
    JSR_CHK(c, 0x7CE8, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27CAB, SOM_RTS, "hand", native58_variant_zero_cast_or_charge, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 96, 38)

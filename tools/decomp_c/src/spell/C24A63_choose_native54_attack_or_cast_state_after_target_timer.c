#include "som_c.h"
#include "som_hand_b.h"

/* C24A63 choose_native54_attack_or_cast_state_after_target_timer   [class B, 115 bytes, 47 instructions]
 * Source: src/rom/choose_native54_attack_or_cast_state_after_target_timer.s
 * Documented in docs/boss-native54-motion.md
 * Entry: any M, X=16 bit, any DB and D.  Callers read: ABXYCZNV.
 */
/* A callee that replaces its own return address makes the original resume at the new address and run on until this
 * routine's own RTS; the interpreter does exactly that from the popped address. */
#undef I_JSR
#define I_JSR(c, retpc, target) HAND_JSR_RESUME(c, retpc, target, sp0)

#define ABS_ADDR(off, idx) ((((uint32_t)r->db << 16) + (off) + (idx)) & 0xFFFFFF)
/* STZ abs,X in the current accumulator width */
#define STZ_ABS(off, idx) do { if (r->mf) BUS8_SET(c, ABS_ADDR(off, idx), 0); else BUS16_SET(c, ABS_ADDR(off, idx), 0); } while (0)
#define STA_ABS(off, idx) do { if (r->mf) BUS8_SET(c, ABS_ADDR(off, idx), r->a & 0xFF); else BUS16_SET(c, ABS_ADDR(off, idx), r->a); } while (0)
/* The 16-bit immediates below are assembled for M=0: running them with M=1 executes the operand as code. */
#define NEED_WIDE_A() do { if (r->mf) { c->fail = 3; return; } } while (0)

static void choose_native54_attack_or_cast_state_after_target_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp0 = r->sp;
    bool to_c24ac6 = false;

    hand_ldx_dp(c, 0x87);
    JSR(c, 0x4A67, 0xC2496C);            /* consume_native54_action_damage_and_initialize_auxiliary_recoil */
    if (r->c) { r->c = 0; RETURN_RTS(c); }

    if (!hand_lda_abs(c, ABS_ADDR(0x00AD, r->x))) return;
    uint16_t cmp_op;
    {
        uint32_t ca = ABS_ADDR(0x002D, r->x);
        if (!hand_rd_ok(ca) || (!r->mf && !hand_rd_ok((ca + 1) & 0xFFFFFF))) { c->fail = 3; return; }
        cmp_op = r->mf ? BUS8(c, ca) : BUS16(c, ca);
    }
    if (r->mf) hand_cmp8(r, r->a & 0xFF, (uint8_t)cmp_op); else hand_cmp16(r, r->a, cmp_op);
    if (!r->c) { r->c = 0; RETURN_RTS(c); }

    JSR(c, 0x4A74, 0xC23372);            /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
    STZ_ABS(0x00AD, r->x);
    STZ_ABS(0x0096, r->x);
    JSR(c, 0x4A7D, 0xC23224);            /* select_nearest_active_living_party_actor */
    hand_ldx_dp(c, 0x87);
    STA_ABS(0x00A9, r->x);
    if (!hand_lda_abs(c, ABS_ADDR(0x0042, r->x))) return;
    if (r->z) {
        to_c24ac6 = true;
    } else {
        if (!hand_lda_abs(c, ABS_ADDR(0x00A9, r->x))) return;
        JSR(c, 0x4A8D, 0xC208D9);        /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        hand_ldx_dp(c, 0x87);
        NEED_WIDE_A();
        hand_cmp16(r, r->a, 0x0006);
        if (!r->c) {
            to_c24ac6 = true;
        } else {
            r->a = 0x0002; r->z = 0; r->n = 0;
            JSR(c, 0x4A9A, 0xC2300B);    /* draw_boss_frame_random_number */
            if (!r->z) {
                to_c24ac6 = true;
            } else {
                hand_ldx_dp(c, 0x87);
                NEED_WIDE_A();
                BUS16_SET(c, ABS_ADDR(0x0094, r->x), 0x0009);
                BUS16_SET(c, ABS_ADDR(0x00B4, r->x), 0);
                r->c = 1;
                r->a = hand_sbc16(r, dp_rd16(c, 0x89), 0xF800);
                r->y = r->xf ? (r->a & 0xFF) : r->a;
                hand_nz16(r, r->xf ? (r->a & 0xFF) : r->a);
                r->mf = 1;
                uint8_t t1, t2;
                BUS8_OK(c, ABS_ADDR(0xF811, r->y), t1);
                BUS8_SET(c, ABS_ADDR(0x007A, r->x), t1);
                BUS8_OK(c, ABS_ADDR(0xF80D, r->y), t2);
                BUS8_SET(c, ABS_ADDR(0x007B, r->x), t2);
                r->a = (r->a & 0xFF00) | 0x44;
                r->z = 0; r->n = 0;
                BUS8_SET(c, ABS_ADDR(0xF813, r->y), 0x44);
                r->mf = 0;
                r->c = 0;
                RETURN_RTS(c);
            }
        }
    }
    if (to_c24ac6) {
        hand_ldx_dp(c, 0x87);
        NEED_WIDE_A();
        r->a = 0x0006; r->z = 0; r->n = 0;
        STA_ABS(0x0094, r->x);
        r->a = 0x0076;
        JSR(c, 0x4AD3, 0xC21394);        /* select_boss_animation_and_reset_frame_cursor */
    }
    r->c = 0;
    RETURN_RTS(c);
}
#undef ABS_ADDR
SOM_REGISTER(0xC24A63, SOM_RTS, "hand", choose_native54_attack_or_cast_state_after_target_timer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, -1, 115, 47)

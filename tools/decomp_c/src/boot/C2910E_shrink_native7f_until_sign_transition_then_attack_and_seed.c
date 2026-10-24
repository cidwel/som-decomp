#include "som_c.h"

/* C2910E shrink_native7f_until_sign_transition_then_attack_and_seed   [class B, 74 bytes, 28 instructions]
 * Source: src/rom/shrink_native7f_until_sign_transition_then_attack_and_seed.s
 * Documented in docs/boss-native7f-motion-collapse.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void shrink_native7f_until_sign_transition_then_attack_and_seed(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint8_t a_9153 = 0;
    uint8_t a_hi_9153 = 0;
    uint16_t x_9153 = 0;
    uint16_t y_9153 = 0;
    bool carry_9153 = 0;
    bool zero_9153 = 0;
    bool negative_9153 = 0;
    bool overflow_9153 = 0;
    uint8_t a_91532 = 0;
    uint8_t a_hi_91532 = 0;
    uint8_t x_91532 = 0;
    uint8_t y_91532 = 0;
    bool carry_91532 = 0;
    bool zero_91532 = 0;
    bool negative_91532 = 0;
    bool overflow_91532 = 0;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x00B0 + battle_defence_work);
    RAM16_SET(0x00B0 + battle_defence_work, (uint16_t)(value - 0x40));
    if (!((uint16_t)(value - 0x40) & 0x8000)) {
        a_9153 = (uint8_t)(value - 0x40);
        a_hi_9153 = (uint16_t)(value - 0x40) >> 8;
        x_9153 = battle_defence_work;
        y_9153 = y;
        carry_9153 = value >= 0x40;
        zero_9153 = (uint16_t)(value - 0x40) == 0;
        negative_9153 = (uint16_t)(value - 0x40) & 0x8000;
        overflow_9153 = ((value ^ 0x40) & (value ^ (uint16_t)(value - 0x40)) & 0x8000) != 0;
        goto shared_9153;
    }
    RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
    r->a = 0x0117;
    r->x = battle_defence_work;
    r->c = value >= 0x40;
    r->v = ((value ^ 0x40) & (value ^ (uint16_t)(value - 0x40)) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9124, 0xC21394); GUARD_JSR(c, sp_call, 0x9124); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B0 + battle_defence_work, 0x80);
    RAM16_SET(0x0090 + battle_defence_work, 0);
    RAM16_SET(0x002B + battle_defence_work, 0);
    RAM16_SET(OBJECT_PHASE + battle_defence_work, 0x0E);
    r->a = 0x1F;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x913C, 0xC224C3); GUARD_JSR(c, sp_call, 0x913C); } /* prepare_boss_loader_resource_expansion */
    uint16_t x_ret = r->x;
    RAM16_SET(0x00B6 + x_ret, 1);
    uint16_t battle_defence_work2 = RAM16(BATTLE_DEFENCE_WORK);
    r->a = 0x71;
    r->x = battle_defence_work2;
    r->z = battle_defence_work2 == 0;
    r->n = battle_defence_work2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x914B, 0xC0006C); GUARD_JSL(c, sp_call, 0x914B); } /* boss_attack_row_public_jump */
    bool x_ret2 = r->xf;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (x_ret2) {
        r->y = (uint8_t)y_ret2;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9150, 0xC290E4); GUARD_JSR(c, sp_call, 0x9150); } /* publish_native7f_actor_mask_to_party_and_collision_byte */
        uint16_t a_all4 = r->a;
        uint8_t battle_defence_work4 = RAM8(BATTLE_DEFENCE_WORK);
        a_91532 = (uint8_t)a_all4;
        a_hi_91532 = a_all4 >> 8;
        x_91532 = battle_defence_work4;
        y_91532 = (uint8_t)y_ret2;
        carry_91532 = carry_ret2;
        zero_91532 = battle_defence_work4 == 0;
        negative_91532 = battle_defence_work4 & 0x80;
        overflow_91532 = overflow_ret2;
        goto shared_9153_1;
    } else {
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9150, 0xC290E4); GUARD_JSR(c, sp_call, 0x9150); } /* publish_native7f_actor_mask_to_party_and_collision_byte */
        uint16_t a_all5 = r->a;
        uint16_t battle_defence_work6 = RAM16(BATTLE_DEFENCE_WORK);
        a_9153 = (uint8_t)a_all5;
        a_hi_9153 = a_all5 >> 8;
        x_9153 = battle_defence_work6;
        y_9153 = y_ret2;
        carry_9153 = carry_ret2;
        zero_9153 = battle_defence_work6 == 0;
        negative_9153 = battle_defence_work6 & 0x8000;
        overflow_9153 = overflow_ret2;
        goto shared_9153;
    }
    shared_9153:;
    r->a = (a_hi_9153 << 8) | a_9153;
    r->y = y_9153;
    r->c = carry_9153;
    r->v = overflow_9153;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9155, 0xC2979F); GUARD_JSR(c, sp_call, 0x9155); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_9153_1:;
    r->a = (a_hi_91532 << 8) | a_91532;
    r->y = y_91532;
    r->c = carry_91532;
    r->v = overflow_91532;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9155, 0xC2979F); GUARD_JSR(c, sp_call, 0x9155); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2910E, SOM_RTS, "gen", shrink_native7f_until_sign_transition_then_attack_and_seed, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 74, 28)

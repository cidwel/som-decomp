#include "som_c.h"

/* C291A4 release_native7f_party_mask_once_and_wait_for_left_boundary   [class B, 79 bytes, 31 instructions]
 * Source: src/rom/release_native7f_party_mask_once_and_wait_for_left_boundary.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void release_native7f_party_mask_once_and_wait_for_left_boundary(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi_91d4 = 0;
    uint16_t x_91d4 = 0;
    uint16_t y_91d4 = 0;
    bool overflow_91d4 = 0;
    uint8_t a_hi_91d42 = 0;
    uint8_t x_91d42 = 0;
    uint8_t y_91d42 = 0;
    bool overflow_91d42 = 0;
    uint8_t a_91ee = 0;
    uint8_t a_hi_91ee = 0;
    uint16_t x_91ee = 0;
    uint16_t y_91ee = 0;
    bool carry_91ee = 0;
    bool zero_91ee = 0;
    bool negative_91ee = 0;
    bool overflow_91ee = 0;
    uint8_t a_91ee2 = 0;
    uint8_t a_hi_91ee2 = 0;
    uint8_t x_91ee2 = 0;
    uint8_t y_91ee2 = 0;
    bool carry_91ee2 = 0;
    bool zero_91ee2 = 0;
    bool negative_91ee2 = 0;
    bool overflow_91ee2 = 0;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x00B4 + battle_defence_work);
    if (value != 0) {
        a_hi_91d4 = value >> 8;
        x_91d4 = battle_defence_work;
        y_91d4 = y;
        overflow_91d4 = overflow;
        goto shared_91D4;
    }
    uint16_t value2 = RAM16(0x002B + battle_defence_work);
    if (value2 >= 0x0128) {
        a_hi_91d4 = value2 >> 8;
        x_91d4 = battle_defence_work;
        y_91d4 = y;
        overflow_91d4 = overflow;
        goto shared_91D4;
    }
    RAM16_SET(0x00B4 + battle_defence_work, RAM16(0x03C7));
    RAM8(HERO_HIT_MASK) = 1;
    RAM8(0xE259) = 1;
    RAM8(0xE459) = 1;
    r->a = 0x6F;
    r->x = battle_defence_work;
    r->c = value2 >= 0x0128;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x91D1, 0xC0006C); GUARD_JSL(c, sp_call, 0x91D1); } /* boss_attack_row_public_jump */
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    if (x_ret) {
        uint8_t battle_defence_work2 = RAM8(BATTLE_DEFENCE_WORK);
        a_hi_91d42 = a_all >> 8;
        x_91d42 = battle_defence_work2;
        y_91d42 = (uint8_t)y_ret;
        overflow_91d42 = overflow_ret;
        goto shared_91D4_1;
    } else {
        uint16_t battle_defence_work3 = RAM16(BATTLE_DEFENCE_WORK);
        a_hi_91d4 = a_all >> 8;
        x_91d4 = battle_defence_work3;
        y_91d4 = y_ret;
        overflow_91d4 = overflow_ret;
        goto shared_91D4;
    }
    shared_91D4:;
    uint16_t value4 = RAM16(0x002B + x_91d4);
    if (value4 > 0x28) {
        a_91ee = 0x28;
        a_hi_91ee = 0;
        x_91ee = x_91d4;
        y_91ee = y_91d4;
        carry_91ee = value4 <= 0x28;
        zero_91ee = value4 == 0x28;
        negative_91ee = (uint16_t)(0x28 - value4) & 0x8000;
        overflow_91ee = overflow_91d4;
        goto shared_91EE;
    }
    RAM16_SET(OBJECT_AGE + x_91d4, 0);
    RAM16_SET(OBJECT_PHASE + x_91d4, 0x11);
    RAM16_SET(0x0090 + x_91d4, 0);
    RAM16_SET(0x00B0 + x_91d4, 0x80);
    a_91ee = 0x80;
    a_hi_91ee = 0;
    x_91ee = x_91d4;
    y_91ee = y_91d4;
    carry_91ee = value4 <= 0x28;
    zero_91ee = 0;
    negative_91ee = 0;
    overflow_91ee = overflow_91d4;
    goto shared_91EE;
    shared_91D4_1:;
    uint16_t value5 = RAM16(0x002B + x_91d42);
    if (value5 > 0x28) {
        a_91ee2 = 0x28;
        a_hi_91ee2 = 0;
        x_91ee2 = x_91d42;
        y_91ee2 = y_91d42;
        carry_91ee2 = value5 <= 0x28;
        zero_91ee2 = value5 == 0x28;
        negative_91ee2 = (uint16_t)(0x28 - value5) & 0x8000;
        overflow_91ee2 = overflow_91d42;
        goto shared_91EE_1;
    }
    RAM16_SET(OBJECT_AGE + x_91d42, 0);
    RAM16_SET(OBJECT_PHASE + x_91d42, 0x11);
    RAM16_SET(0x0090 + x_91d42, 0);
    RAM16_SET(0x00B0 + x_91d42, 0x80);
    a_91ee2 = 0x80;
    a_hi_91ee2 = 0;
    x_91ee2 = x_91d42;
    y_91ee2 = y_91d42;
    carry_91ee2 = value5 <= 0x28;
    zero_91ee2 = 0;
    negative_91ee2 = 0;
    overflow_91ee2 = overflow_91d42;
    goto shared_91EE_1;
    shared_91EE:;
    r->a = (a_hi_91ee << 8) | a_91ee;
    r->x = x_91ee;
    r->y = y_91ee;
    r->c = carry_91ee;
    r->z = zero_91ee;
    r->n = negative_91ee;
    r->v = overflow_91ee;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0x91F0, 0xC2979F); GUARD_JSR(c, sp_call, 0x91F0); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_91EE_1:;
    r->a = (a_hi_91ee2 << 8) | a_91ee2;
    r->x = x_91ee2;
    r->y = y_91ee2;
    r->c = carry_91ee2;
    r->z = zero_91ee2;
    r->n = negative_91ee2;
    r->v = overflow_91ee2;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0x91F0, 0xC2979F); GUARD_JSR(c, sp_call, 0x91F0); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC291A4, SOM_RTS, "gen", release_native7f_party_mask_once_and_wait_for_left_boundary, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 79, 31)

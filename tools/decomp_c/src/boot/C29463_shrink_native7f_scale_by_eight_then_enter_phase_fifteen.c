#include "som_c.h"

/* C29463 shrink_native7f_scale_by_eight_then_enter_phase_fifteen   [class B, 54 bytes, 21 instructions]
 * Source: src/rom/shrink_native7f_scale_by_eight_then_enter_phase_fifteen.s
 * Documented in docs/boss-native7f-frame-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void shrink_native7f_scale_by_eight_then_enter_phase_fifteen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x00B0 + battle_defence_work);
    RAM16_SET(0x00B0 + battle_defence_work, (uint16_t)(value - 8));
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (!((uint16_t)(value - 8) & 0x8000)) {
        a1 = (uint8_t)(value - 8);
        a_hi1 = (uint16_t)(value - 8) >> 8;
        x1 = battle_defence_work;
        y1 = y;
        carry1 = value >= 8;
        zero1 = (uint16_t)(value - 8) == 0;
        negative1 = (uint16_t)(value - 8) & 0x8000;
        overflow1 = ((value ^ 8) & (value ^ (uint16_t)(value - 8)) & 0x8000) != 0;
    } else {
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        RAM16_SET(0x00B0 + battle_defence_work, 0x80);
        RAM16_SET(0x002B + battle_defence_work, 0);
        r->a = 0x0117;
        r->x = battle_defence_work;
        r->c = value >= 8;
        r->v = ((value ^ 8) & (value ^ (uint16_t)(value - 8)) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9482, 0xC21394); GUARD_JSR(c, sp_call, 0x9482); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(OBJECT_PHASE + battle_defence_work, 0x0F);
        r->a = 0x20;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x948E, 0xC224C3); GUARD_JSR(c, sp_call, 0x948E); } /* prepare_boss_loader_resource_expansion */
        uint16_t a_all2 = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        RAM16_SET(0x00B6 + x_ret, 0);
        uint16_t battle_defence_work2 = RAM16(BATTLE_DEFENCE_WORK);
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = battle_defence_work2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = battle_defence_work2 == 0;
        negative1 = battle_defence_work2 & 0x8000;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9496, 0xC2979F); GUARD_JSR(c, sp_call, 0x9496); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29463, SOM_RTS, "gen", shrink_native7f_scale_by_eight_then_enter_phase_fifteen, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 54, 21)

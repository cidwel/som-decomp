#include "som_c.h"

/* C29499 move_native7f_up_two_pixels_until_unsigned_y_at_most0160   [class A, 37 bytes, 15 instructions]
 * Source: src/rom/move_native7f_up_two_pixels_until_unsigned_y_at_most0160.s
 * Documented in docs/boss-native7f-frame-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void move_native7f_up_two_pixels_until_unsigned_y_at_most0160(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x0032 + battle_defence_work);
    RAM16_SET(0x0032 + battle_defence_work, (uint16_t)(value - 2));
    uint16_t value2 = RAM16(0x0032 + battle_defence_work);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value2 > 0x0160) {
        a1 = 0x60;
        a_hi1 = 1;
        zero1 = value2 == 0x0160;
        negative1 = (uint16_t)(0x0160 - value2) & 0x8000;
    } else {
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        RAM16_SET(OBJECT_PHASE + battle_defence_work, 0x0B);
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        a1 = 0x0B;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = value2 <= 0x0160;
    r->v = ((value ^ 2) & (value ^ (uint16_t)(value - 2)) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x94BB, 0xC2979F); GUARD_JSR(c, sp_call, 0x94BB); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29499, SOM_RTS, "gen", move_native7f_up_two_pixels_until_unsigned_y_at_most0160, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 37, 15)

#include "som_c.h"

/* C290AC shrink_native7f_while_rotating_then_attack_and_mask_party   [class B, 56 bytes, 22 instructions]
 * Source: src/rom/shrink_native7f_while_rotating_then_attack_and_mask_party.s
 * Documented in docs/boss-native7f-motion-collapse.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void shrink_native7f_while_rotating_then_attack_and_mask_party(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    uint16_t current_object_dp0 = RAM16(CURRENT_OBJECT_DP0 + dp);
    RAM16_SET(0x00B2 + current_object_dp0, (uint16_t)(RAM16(0x00B2 + current_object_dp0) + 0x80));
    uint16_t value2 = RAM16(0x00B0 + current_object_dp0);
    RAM16_SET(0x00B0 + current_object_dp0, (uint16_t)(value2 - 0x18));
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if ((uint16_t)(value2 - 0x18) >= 0x10) {
        a1 = (uint8_t)(value2 - 0x18);
        a_hi1 = (uint16_t)(value2 - 0x18) >> 8;
        x1 = current_object_dp0;
        y1 = y;
        carry1 = (uint16_t)(value2 - 0x18) >= 0x10;
        zero1 = (uint16_t)(value2 - 0x18) == 0x10;
        negative1 = (uint16_t)(value2 - 0x28) & 0x8000;
        overflow1 = ((value2 ^ 0x18) & (value2 ^ (uint16_t)(value2 - 0x18)) & 0x8000) != 0;
    } else {
        RAM16_SET(OBJECT_PHASE + current_object_dp0, 9);
        RAM16_SET(OBJECT_AGE + current_object_dp0, 0);
        RAM16_SET(0x00B0 + current_object_dp0, 0);
        r->a = 0x72;
        r->x = current_object_dp0;
        r->c = (uint16_t)(value2 - 0x18) >= 0x10;
        r->z = false;
        r->n = false;
        r->v = ((value2 ^ 0x18) & (value2 ^ (uint16_t)(value2 - 0x18)) & 0x8000) != 0;
        JSL(c, 0x90D9, 0xC0006C); /* boss_attack_row_public_jump */
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x90DE, 0xC290E4); /* publish_native7f_actor_mask_to_party_and_collision_byte */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = false;
    r->xf = false;
    JSR(c, 0x90E1, 0xC2979F); /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = false;
    r->mf = false;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC290AC, SOM_RTS, "hand", shrink_native7f_while_rotating_then_attack_and_mask_party, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 56, 22)

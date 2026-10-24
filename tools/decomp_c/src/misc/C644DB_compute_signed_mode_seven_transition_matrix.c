#include "som_c.h"

/* C644DB compute_signed_mode_seven_transition_matrix   [class D, 123 bytes, 55 instructions]
 * Source: src/rom/compute_signed_mode_seven_transition_matrix.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void compute_signed_mode_seven_transition_matrix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0xC6;
    uint16_t value = RAM16(0x0044);
    uint8_t a1;
    uint8_t a_hi1;
    if ((value & 0xFF) + 0x12 < 0x48) {
        a1 = (uint8_t)((value & 0xFF) + 0x12);
        a_hi1 = (value & 0xFF) + 0x12 >> 8;
    } else {
        a1 = (uint8_t)((value & 0xFF) - 0x36 - ((value & 0xFF) + 0x12 >= 0x48 ^ 1));
        a_hi1 = (uint16_t)((value & 0xFF) - 0x36 - ((value & 0xFF) + 0x12 >= 0x48 ^ 1)) >> 8;
    }
    uint16_t value2 = BUS16(c, 0xC646EA + (uint16_t)(((a_hi1 << 8) | a1) << 1));
    RAM16_SET(0x0030, value2);
    uint16_t value3 = RAM16(0x0040);
    r->a = value3;
    r->x = (uint16_t)(((a_hi1 << 8) | a1) << 1);
    r->c = ((a_hi1 << 8) | a1) & 0x8000;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->db = 0xC6;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x44FE, 0xC64556); GUARD_JSR(c, sp_call, 0x44FE); } /* divide_signed_scene_ratio_with_native_saturation */
    r->sp += 1;
    uint16_t a_all = r->a;
    BUS8_SET(c, 0x00211B, (uint8_t)a_all);
    BUS8_SET(c, 0x00211B, a_all >> 8);
    uint16_t value4 = RAM16(0x0042);
    r->a = value4;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4510, 0xC64556); GUARD_JSR(c, sp_call, 0x4510); } /* divide_signed_scene_ratio_with_native_saturation */
    r->sp += 1;
    uint16_t a_all2 = r->a;
    BUS8_SET(c, 0x00211E, (uint8_t)a_all2);
    BUS8_SET(c, 0x00211E, a_all2 >> 8);
    uint16_t value5 = RAM16(0x0044);
    uint16_t value6 = BUS16(c, 0xC646EA + ((value5 & 0xFF) << 1));
    RAM16_SET(0x0030, value6);
    uint16_t value7 = RAM16(0x0040);
    r->a = value7;
    r->x = (value5 & 0xFF) << 1;
    r->c = value5 & 0xFF & 0x8000;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x452E, 0xC64556); GUARD_JSR(c, sp_call, 0x452E); } /* divide_signed_scene_ratio_with_native_saturation */
    r->sp += 1;
    uint16_t a_all3 = r->a;
    BUS8_SET(c, 0x00211C, (uint8_t)a_all3);
    BUS8_SET(c, 0x00211C, a_all3 >> 8);
    RAM16_SET(0x0030, (uint16_t)((RAM16(0x0030) ^ 0xFFFF) + 1));
    uint16_t value9 = RAM16(0x0042);
    r->a = value9;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4548, 0xC64556); GUARD_JSR(c, sp_call, 0x4548); } /* divide_signed_scene_ratio_with_native_saturation */
    r->sp += 1;
    uint16_t a_all4 = r->a;
    BUS8_SET(c, 0x00211D, (uint8_t)a_all4);
    BUS8_SET(c, 0x00211D, a_all4 >> 8);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->mf = 1;
    r->xf = 0;
    r->db = value10;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC644DB, SOM_RTS, "gen", compute_signed_mode_seven_transition_matrix, 0, L_Y, 2, 1, 0, 123, 55)

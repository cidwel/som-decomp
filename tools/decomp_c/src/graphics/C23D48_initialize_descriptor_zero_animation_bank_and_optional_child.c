#include "som_c.h"

/* C23D48 initialize_descriptor_zero_animation_bank_and_optional_child   [class A, 18 bytes, 7 instructions]
 * Source: src/rom/initialize_descriptor_zero_animation_bank_and_optional_child.s
 * Documented in docs/boss-descriptor-zero.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_zero_animation_bank_and_optional_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    JSR(c, 0x3D4A, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    uint16_t value = RAM16(0x0042 + x);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value != 0) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        x1 = x;
        y1 = y;
        carry1 = carry;
        zero1 = value == 0;
        negative1 = value & 0x8000;
        overflow1 = overflow;
    } else {
        r->a = value;
        r->x = 0x3E27;
        r->y = 0x2901;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3D58, 0xC20D53); /* allocate_boss_object_pool_slot */
        uint16_t a_all2 = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all2;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret;
        y1 = 0x2901;
        carry1 = carry_ret;
        zero1 = zero_ret2;
        negative1 = negative_ret2;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23D48, SOM_RTS, "gen", initialize_descriptor_zero_animation_bank_and_optional_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 7)

#include "som_c.h"

/* C23E7F launch_mantis_ant_homing_projectile   [class B, 87 bytes, 37 instructions]
 * Source: src/rom/launch_mantis_ant_homing_projectile.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void launch_mantis_ant_homing_projectile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0295, RAM16(0x002B + x));
    RAM16_SET(0x0297, RAM16(0x0032 + x));
    RAM16_SET(0x029D, RAM16(0x00A9 + x));
    RAM16_SET(0x029F, x);
    uint16_t value4 = RAM16(0x00AB + x);
    uint16_t value5 = BUS16(c, 0xDCE028 + (uint16_t)(value4 << 2));
    RAM16_SET(0x0299, value5);
    uint16_t value6 = BUS16(c, 0xDCE02A + (uint16_t)(value4 << 2));
    RAM16_SET(0x029B, value6);
    r->a = value6;
    r->x = 0x3ED6;
    r->y = 0x2801;
    JSR(c, 0x3EAA, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (carry_ret) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    } else {
        RAM16_SET(0x002B + x_ret, (uint16_t)(RAM16(0x0295) - 0x0C));
        uint16_t value8 = RAM16(0x0297);
        RAM16_SET(0x0032 + x_ret, (uint16_t)(value8 + 4));
        RAM16_SET(0x003C + x_ret, RAM16(0x0299));
        RAM16_SET(0x0040 + x_ret, RAM16(0x029B));
        RAM16_SET(0x00A9 + x_ret, RAM16(0x029D));
        uint16_t value12 = RAM16(0x029F);
        RAM16_SET(0x00B0 + x_ret, value12);
        a1 = (uint8_t)value12;
        a_hi1 = value12 >> 8;
        carry1 = value8 + 4 > 0xFFFF;
        overflow1 = ((value8 ^ (uint16_t)(value8 + 4)) & ((uint16_t)(value8 + 4) ^ 4) & 0x8000) != 0;
    }
    uint16_t value13 = RAM16(0x0287);
    r->a = (a_hi1 << 8) | a1;
    r->x = value13;
    r->c = carry1;
    r->z = value13 == 0;
    r->n = value13 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23E7F, SOM_RTS, "gen", launch_mantis_ant_homing_projectile, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 87, 37)

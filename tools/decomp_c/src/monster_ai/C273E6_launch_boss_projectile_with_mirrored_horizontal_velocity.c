#include "som_c.h"

/* C273E6 launch_boss_projectile_with_mirrored_horizontal_velocity   [class B, 112 bytes, 49 instructions]
 * Source: src/rom/launch_boss_projectile_with_mirrored_horizontal_velocity.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void launch_boss_projectile_with_mirrored_horizontal_velocity(SomCtx *c)
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
    RAM16_SET(0x0299, 0x1E);
    RAM16_SET(0x02A1, 4);
    RAM16_SET(0x02A3, 0xFFFC);
    uint16_t value4 = RAM16(0x0098 + x);
    uint8_t a_hi1;
    if ((value4 & 0x40) == 0) {
        a_hi1 = value4 >> 8;
    } else {
        uint16_t value5 = RAM16(0x0299);
        uint16_t value6 = RAM16(0x02C7);
        RAM16_SET(0x0299, (uint16_t)((value5 ^ value6) + 1));
        uint16_t value7 = RAM16(0x02A1);
        RAM16_SET(0x02A1, (uint16_t)((value7 ^ value6) + 1));
        a_hi1 = (uint16_t)((value7 ^ value6) + 1) >> 8;
    }
    RAM16_SET(0x029B, 0xFFD8);
    r->a = 0xFFD8;
    r->x = 0x7456;
    r->y = 0xB801;
    JSR(c, 0x7429, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if (carry_ret) {
        a1 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        y1 = 0xB801;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    } else {
        RAM16_SET(0x002B + x_ret, (uint16_t)(RAM16(0x0295) + RAM16(0x0299)));
        RAM16_SET(0x0032 + x_ret, (uint16_t)(RAM16(0x0297) + RAM16(0x029B)));
        RAM16_SET(0x00A9 + x_ret, RAM16(0x029D));
        RAM16_SET(0x003C + x_ret, RAM16(0x02A1));
        RAM16_SET(0x0040 + x_ret, RAM16(0x02A3));
        RAM16_SET(0x00B0 + x_ret, RAM16(0x029F));
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x7452, 0xC27273); /* load_leaping_boss_projectile_palette_58 */
        uint16_t a_all2 = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a1 = (uint8_t)a_all2;
        a_hi2 = a_all2 >> 8;
        y1 = y_ret;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    }
    uint16_t value16 = RAM16(0x0287);
    r->a = (a_hi2 << 8) | a1;
    r->x = value16;
    r->y = y1;
    r->c = carry1;
    r->z = value16 == 0;
    r->n = value16 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC273E6, SOM_RTS, "gen", launch_boss_projectile_with_mirrored_horizontal_velocity, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 112, 49)

#include "som_c.h"

/* C2507D advance_projectile_height_bounce_sound_and_simple_terrain_motion   [class B, 61 bytes, 24 instructions]
 * Source: src/rom/advance_projectile_height_bounce_sound_and_simple_terrain_motion.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_projectile_height_bounce_sound_and_simple_terrain_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_50a7 = 0;
    uint8_t a_hi_50a7 = 0;
    uint16_t x_50a7 = 0;
    uint16_t y_50a7 = 0;
    uint8_t a_50a72 = 0;
    uint8_t a_hi_50a72 = 0;
    uint8_t x_50a72 = 0;
    uint8_t y_50a72 = 0;
    uint16_t value = RAM16(0x0064 + x);
    uint16_t value2 = RAM16(0x00C4 + x);
    RAM16_SET(0x0064 + x, (uint16_t)(value + value2));
    uint16_t value3 = RAM16(0x0066 + x);
    uint16_t value4 = RAM16(0x00C6 + x);
    if (!((uint16_t)(value3 + value4 + (value + value2 > 0xFFFF)) & 0x8000)) {
        a_50a7 = (uint8_t)(value3 + value4 + (value + value2 > 0xFFFF));
        a_hi_50a7 = (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF)) >> 8;
        x_50a7 = x;
        y_50a7 = y;
        goto shared_50A7;
    }
    r->a = 0x1C;
    r->x = 0x0F;
    r->c = value3 + value4 + (value + value2 > 0xFFFF) > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((value3 ^ (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF))) & (value4 ^ (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF))) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5097, 0xC230E3); GUARD_JSR(c, sp_call, 0x5097); } /* request_boss_sound_with_parameter_word */
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value5 = RAM8(0x0287);
        RAM16_SET(0x00C6 + value5, (uint16_t)((RAM16(0x00C6 + value5) ^ 0xFFFF) + 1));
        a_50a72 = 0;
        a_hi_50a72 = 0;
        x_50a72 = value5;
        y_50a72 = (uint8_t)y_ret;
        goto shared_50A7_1;
    } else {
        uint16_t value7 = RAM16(0x0287);
        RAM16_SET(0x00C6 + value7, (uint16_t)((RAM16(0x00C6 + value7) ^ 0xFFFF) + 1));
        a_50a7 = 0;
        a_hi_50a7 = 0;
        x_50a7 = value7;
        y_50a7 = y_ret;
        goto shared_50A7;
    }
    shared_50A7:;
    RAM16_SET(0x0066 + x_50a7, (a_hi_50a7 << 8) | a_50a7);
    uint16_t value9 = RAM16(0x02C5);
    r->a = value9;
    r->x = x_50a7;
    r->y = y_50a7;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    { const uint16_t sp_call = r->sp; JSR(c, 0x50AE, 0xC20A47); GUARD_JSR(c, sp_call, 0x50AE); } /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
    uint16_t x_ret3 = r->x;
    uint16_t value10 = RAM16(0x00C6 + x_ret3);
    RAM16_SET(0x00C6 + x_ret3, (uint16_t)(value10 - 1));
    r->a = (uint16_t)(value10 - 1);
    r->c = value10 >= 1;
    r->z = (uint16_t)(value10 - 1) == 0;
    r->n = (uint16_t)(value10 - 1) & 0x8000;
    r->v = ((value10 ^ 1) & (value10 ^ (uint16_t)(value10 - 1)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
    shared_50A7_1:;
    RAM16_SET(0x0066 + x_50a72, (a_hi_50a72 << 8) | a_50a72);
    uint16_t value11 = RAM16(0x02C5);
    r->a = value11;
    r->x = x_50a72;
    r->y = y_50a72;
    r->z = value11 == 0;
    r->n = value11 & 0x8000;
    r->mf = 0;
    r->xf = 1;
    r->db = 0x7E;
    r->dp = 0x0200;
    { const uint16_t sp_call = r->sp; JSR(c, 0x50AE, 0xC20A47); GUARD_JSR(c, sp_call, 0x50AE); } /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
    uint8_t x_ret4 = r->x;
    uint16_t value12 = RAM16(0x00C6 + x_ret4);
    RAM16_SET(0x00C6 + x_ret4, (uint16_t)(value12 - 1));
    r->a = (uint16_t)(value12 - 1);
    r->c = value12 >= 1;
    r->z = (uint16_t)(value12 - 1) == 0;
    r->n = (uint16_t)(value12 - 1) & 0x8000;
    r->v = ((value12 ^ 1) & (value12 ^ (uint16_t)(value12 - 1)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2507D, SOM_RTS, "gen", advance_projectile_height_bounce_sound_and_simple_terrain_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 61, 24)

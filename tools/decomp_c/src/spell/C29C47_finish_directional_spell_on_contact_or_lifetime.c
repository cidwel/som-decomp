#include "som_c.h"

/* C29C47 finish_directional_spell_on_contact_or_lifetime   [class A, 14 bytes, 6 instructions]
 * Source: src/rom/finish_directional_spell_on_contact_or_lifetime.s
 * Documented in docs/boss-native-spell-projectile-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void finish_directional_spell_on_contact_or_lifetime(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->x = RAM16(0x0287);
    JSR(c, 0x9C4B, 0xC23CE8); /* scan_projectile_collision_and_mark_parent_target_contacts */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    bool zero1;
    bool negative1;
    if (carry_ret) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
    } else {
        uint16_t value2 = RAM16(OBJECT_AGE + x_ret);
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        carry1 = value2 >= 0x24;
        zero1 = value2 == 0x24;
        negative1 = (uint16_t)(value2 - 0x24) & 0x8000;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29C47, SOM_RTS, "gen", finish_directional_spell_on_contact_or_lifetime, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 6)

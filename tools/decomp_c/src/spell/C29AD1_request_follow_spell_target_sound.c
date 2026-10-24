#include "som_c.h"

/* C29AD1 request_follow_spell_target_sound   [class A, 20 bytes, 9 instructions]
 * Source: src/rom/request_follow_spell_target_sound.s
 * Documented in docs/boss-native-spell-follow-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void request_follow_spell_target_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x00B4 + x);
    uint16_t value2 = BUS16(c, 0xDCE7B9 + (uint16_t)(value << 1));
    uint8_t a_hi1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if (value2 == 0) {
        a_hi1 = value2 >> 8;
        y1 = y;
        carry1 = value & 0x8000;
        overflow1 = overflow;
    } else {
        r->a = value2;
        r->x = 0x0F;
        r->c = value & 0x8000;
        JSR(c, 0x9AE1, 0xC230E3); /* request_boss_sound_with_parameter_word */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    }
    uint16_t value3 = RAM16(0x0287);
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = value3;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29AD1, SOM_RTS, "gen", request_follow_spell_target_sound, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 20, 9)

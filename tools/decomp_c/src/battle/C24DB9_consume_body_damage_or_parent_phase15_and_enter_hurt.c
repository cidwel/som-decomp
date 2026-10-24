#include "som_c.h"

/* C24DB9 consume_body_damage_or_parent_phase15_and_enter_hurt   [class B, 37 bytes, 17 instructions]
 * Source: src/rom/consume_body_damage_or_parent_phase15_and_enter_hurt.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void consume_body_damage_or_parent_phase15_and_enter_hurt(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x4DBB, 0xC2051C); /* consume_boss_byte35_request */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4DBE, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
    bool carry_ret2 = r->c;
    if (carry_ret2) {
        uint16_t value = RAM16(0x0287);
        RAM16_SET(OBJECT_PHASE + value, 7);
        RAM16_SET(OBJECT_AGE + value, 0);
        r->a = 7;
        r->x = value;
        r->c = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(OBJECT_PHASE + RAM16(0x00B0 + x));
    if (value3 != 0x0F) {
        uint16_t value4 = RAM16(0x0287);
        r->a = value3;
        r->x = value4;
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value5, 7);
    RAM16_SET(OBJECT_AGE + value5, 0);
    r->a = 7;
    r->x = value5;
    r->c = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24DB9, SOM_RTS, "gen", consume_body_damage_or_parent_phase15_and_enter_hurt, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 37, 17)

#include "som_c.h"

/* C27BC0 aim_native58_and_advance_or_enter_death_phase   [class B, 76 bytes, 31 instructions]
 * Source: src/rom/aim_native58_and_advance_or_enter_death_phase.s
 * Documented in docs/boss-native58-action-helpers.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void aim_native58_and_advance_or_enter_death_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM8(0x0380) &= 0x7F;
    uint16_t value2 = RAM16(0x0287);
    if (RAM16(0x0190 + value2) & 0x8000) {
        RAM16_SET(OBJECT_PHASE + value2, 4);
        RAM16_SET(0x003E + value2, 0);
        RAM16_SET(0x0040 + value2, 0);
        r->a = 4;
        r->x = value2;
        r->c = 0;
        r->z = 0;
        r->n = 0;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x00A9 + value2);
    { const uint16_t sp_call = r->sp; JSR(c, 0x7BD8, 0xC20965); GUARD_JSR(c, sp_call, 0x7BD8); } /* derive_fine_direction_to_low_byte_target */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool overflow_ret = r->v;
    uint16_t value5 = RAM16(0x0287);
    RAM16_SET(0x00AB + value5, a_all);
    uint16_t value6 = RAM16(0x00AD + value5);
    uint16_t value7 = RAM16(0x002D + value5);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value6 < value7) {
        a1 = (uint8_t)value6;
        a_hi1 = value6 >> 8;
        x1 = value5;
        y1 = y_ret;
        zero1 = value6 == value7;
        negative1 = (uint16_t)(value6 - value7) & 0x8000;
        overflow1 = overflow_ret;
    } else {
        RAM16_SET(OBJECT_PHASE + value5, (uint16_t)(RAM16(OBJECT_PHASE + value5) + 1));
        RAM16_SET(0x00AD + value5, 0);
        r->a = value6;
        r->x = value5;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7BEE, 0xC23372); GUARD_JSR(c, sp_call, 0x7BEE); } /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7BF6, 0xC23224); GUARD_JSR(c, sp_call, 0x7BF6); } /* select_nearest_active_living_party_actor */
        uint16_t a_all3 = r->a;
        uint16_t y_ret2 = r->y;
        bool overflow_ret3 = r->v;
        uint16_t value10 = RAM16(0x0287);
        RAM16_SET(0x00A9 + value10, a_all3);
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = value10;
        y1 = y_ret2;
        zero1 = value10 == 0;
        negative1 = value10 & 0x8000;
        overflow1 = overflow_ret3;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27BC0, SOM_RTS, "gen", aim_native58_and_advance_or_enter_death_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 76, 31)

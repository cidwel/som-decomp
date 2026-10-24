#include "som_c.h"

/* C1E06F prepare_and_place_party_actor   [class B, 104 bytes, 49 instructions]
 * Source: src/rom/prepare_and_place_party_actor.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void prepare_and_place_party_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xE071, 0xC1E022); GUARD_JSR(c, sp_call, 0xE071); } /* load_actor_map_palette */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE074, 0xC1DFD3); GUARD_JSR(c, sp_call, 0xE074); } /* load_actor_map_graphics */
    uint16_t x_ret2 = r->x;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE078, 0x02A2E8); GUARD_JSL(c, sp_call, 0xE078); } /* clear_actor_map_motion_state */
    RAM8(0xE02F + x_ret2) = 0;
    RAM8(ACTOR_CHARGE_STAGE + x_ret2) = 0;
    uint8_t value = RAM8(0x00E0);
    if (value & 0x80) {
        uint8_t a1;
        if (((uint8_t)(((uint8_t)(((uint8_t)(value << 2) << 1) | ((uint8_t)(value << 1) >> 7)) << 1) | ((uint8_t)(value << 2) >> 7)) & 3) != 3) {
            a1 = (uint8_t)(((uint8_t)(((uint8_t)(value << 2) << 1) | ((uint8_t)(value << 1) >> 7)) << 1) | ((uint8_t)(value << 2) >> 7)) & 3;
        } else {
            a1 = 0x82;
        }
        RAM8(0xE010 + x_ret2) = a1;
    }
    RAM8(0xE083 + x_ret2) = 1;
    RAM8(0xE033 + x_ret2) = 0xD2;
    uint8_t value2 = RAM8(0x00BF);
    uint8_t value3 = RAM8(0x00E8);
    uint8_t a2;
    if (!(value3 & 0x80)) {
        a2 = value2;
    } else {
        a2 = RAM8(0xCD0A);
    }
    RAM8(0xE00B + x_ret2) = a2 & 0x80;
    uint16_t value5 = RAM16(0x00A8);
    uint16_t value6 = RAM16(0x00AA);
    uint8_t a3;
    uint8_t a_hi1;
    uint16_t y1;
    if (!(a2 & 0x80 & 0x80)) {
        a3 = (uint8_t)value5;
        a_hi1 = value5 >> 8;
        y1 = value6;
    } else {
        uint16_t value7 = RAM16(0x00AC);
        uint16_t value8 = RAM16(0x00AE);
        a3 = (uint8_t)value7;
        a_hi1 = value7 >> 8;
        y1 = value8;
    }
    uint16_t value9 = RAM16(0x00C0);
    uint8_t a4;
    uint8_t a_hi2;
    if ((uint16_t)(((a_hi1 << 8) | a3) + 0x80) < value9) {
        a4 = (uint8_t)(((a_hi1 << 8) | a3) + 0x80);
        a_hi2 = (uint16_t)(((a_hi1 << 8) | a3) + 0x80) >> 8;
    } else {
        a4 = (uint8_t)((uint16_t)(((a_hi1 << 8) | a3) + 0x80) - value9 - ((uint16_t)(((a_hi1 << 8) | a3) + 0x80) >= value9 ^ 1));
        a_hi2 = (uint16_t)((uint16_t)(((a_hi1 << 8) | a3) + 0x80) - value9 - ((uint16_t)(((a_hi1 << 8) | a3) + 0x80) >= value9 ^ 1)) >> 8;
    }
    RAM16_SET(0xE002 + x_ret2, (a_hi2 << 8) | a4);
    uint16_t value10 = RAM16(0x00C2);
    uint8_t a5;
    uint8_t a_hi3;
    bool carry1;
    bool overflow1;
    if ((uint16_t)(y1 + 0x72) < value10) {
        a5 = (uint8_t)(y1 + 0x72);
        a_hi3 = (uint16_t)(y1 + 0x72) >> 8;
        carry1 = (uint16_t)(y1 + 0x72) >= value10;
        overflow1 = ((y1 ^ (uint16_t)(y1 + 0x72)) & ((uint16_t)(y1 + 0x72) ^ 0x72) & 0x8000) != 0;
    } else {
        a5 = (uint8_t)((uint16_t)(y1 + 0x72) - value10 - ((uint16_t)(y1 + 0x72) >= value10 ^ 1));
        a_hi3 = (uint16_t)((uint16_t)(y1 + 0x72) - value10 - ((uint16_t)(y1 + 0x72) >= value10 ^ 1)) >> 8;
        carry1 = (uint16_t)(y1 + 0x72) - value10 >= ((uint16_t)(y1 + 0x72) >= value10 ^ 1);
        overflow1 = (((uint16_t)(y1 + 0x72) ^ value10) & ((uint16_t)(y1 + 0x72) ^ (uint16_t)((uint16_t)(y1 + 0x72) - value10 - ((uint16_t)(y1 + 0x72) >= value10 ^ 1))) & 0x8000) != 0;
    }
    RAM16_SET(0xE004 + x_ret2, (a_hi3 << 8) | a5);
    r->a = (a_hi3 << 8) | a5;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E06F, SOM_RTS, "gen", prepare_and_place_party_actor, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 104, 49)

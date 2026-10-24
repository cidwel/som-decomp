#include "som_c.h"

/* C04AFF apply_packed_appearance_attribute_adjustments   [class B, 122 bytes, 66 instructions]
 * Source: src/rom/apply_packed_appearance_attribute_adjustments.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void apply_packed_appearance_attribute_adjustments(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1002, value);
    uint8_t value2;
    BUS8_OK(c, 0xC04B79 + (value & 3), value2);
    RAM8(ACTOR_STRENGTH + x) = (uint8_t)(value2 + RAM8(ACTOR_STRENGTH + x));
    uint8_t value4;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1001, value4);
    uint8_t value5;
    BUS8_OK(c, 0xC04B79 + (value4 >> 6), value5);
    RAM8(ACTOR_AGILITY + x) = (uint8_t)(value5 + RAM8(ACTOR_AGILITY + x));
    uint8_t value7;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1001, value7);
    uint8_t value8;
    BUS8_OK(c, 0xC04B79 + ((value7 >> 4) & 3), value8);
    RAM8(ACTOR_CONSTITUTION + x) = (uint8_t)(value8 + RAM8(ACTOR_CONSTITUTION + x));
    uint8_t value10;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1001, value10);
    uint8_t value11;
    BUS8_OK(c, 0xC04B79 + ((value10 >> 2) & 3), value11);
    RAM8(ACTOR_INTELLIGENCE + x) = (uint8_t)(value11 + RAM8(ACTOR_INTELLIGENCE + x));
    uint8_t value13;
    BUS8_OK(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1001, value13);
    uint8_t value14;
    BUS8_OK(c, 0xC04B79 + (value13 & 3), value14);
    RAM8(ACTOR_WISDOM + x) = (uint8_t)(value14 + RAM8(ACTOR_WISDOM + x));
    uint16_t value16 = RAM16(0x03BD);
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->x = value16;
    r->y = x;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04AFF, SOM_RTS, "hand", apply_packed_appearance_attribute_adjustments, 0, L_B | L_X | L_Y, 2, 1, 0, 122, 66)

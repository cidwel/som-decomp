#include "som_c.h"

/* C0474F load_actor_base_attributes_for_appearance   [class B, 142 bytes, 50 instructions]
 * Source: src/rom/load_actor_base_attributes_for_appearance.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void load_actor_base_attributes_for_appearance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(ACTOR_GUARD_FLAGS + x) &= 0xFD;
    uint8_t value2 = RAM8(ACTOR_STATUS_HIGH + x);
    uint8_t a2;
    if ((value2 & 8) == 0) {
        a2 = RAM8(0xE1E7 + x);
    } else {
        uint8_t value4 = RAM8(0xE180 + x);
        uint8_t a1;
        if (value4 & 0x80) {
            a1 = RAM8(0xE1E7 + x);
        } else {
            a1 = value4;
        }
        a2 = a1;
    }
    BUS8_SET(c, 0x004202, a2);
    BUS8_SET(c, 0x004203, 0x1D);
    uint16_t value6 = BUS16(c, 0x004216);
    uint16_t value7 = RAM16(0x03BD);
    uint16_t value8 = BUS16(c, 0xD01C04 + value6);
    RAM16_SET(ACTOR_STRENGTH + value7, value8);
    uint16_t value9 = BUS16(c, 0xD01C06 + value6);
    RAM16_SET(ACTOR_INTELLIGENCE + value7, value9);
    uint16_t value10 = BUS16(c, 0xD01C08 + value6);
    RAM16_SET(ACTOR_EVADE + value7, value10);
    uint16_t value11 = BUS16(c, 0xD01C0A + value6);
    RAM16_SET(0xE1A6 + value7, value11);
    uint16_t value12 = BUS16(c, 0xD01C0C + value6);
    RAM16_SET(ACTOR_MAGIC_DEFENSE + value7, value12);
    uint16_t value13 = BUS16(c, 0xD01C0E + value6);
    RAM16_SET(ACTOR_MONSTER_TYPE + value7, value13);
    uint16_t value14 = BUS16(c, 0xD01C09 + value6);
    RAM16_SET(ACTOR_DEFENSE + value7, value14);
    uint16_t value15 = BUS16(c, 0xD01C0C + value6);
    RAM16_SET(ACTOR_MAGIC_DEFENSE + value7, value15);
    uint16_t value16 = BUS16(c, 0xD01C12 + value6);
    RAM16_SET(0xE1FD + value7, value16);
    uint16_t value17 = BUS16(c, 0xD01C14 + value6);
    RAM16_SET(ACTOR_STATUS_IMMUNITY + value7, value17);
    uint16_t value18 = BUS16(c, 0xD01C19 + value6);
    RAM16_SET(ACTOR_GUARD_FLAGS + value7, ((value18 & 1) << 1) | RAM16(ACTOR_GUARD_FLAGS + value7));
    uint16_t value20 = BUS16(c, 0xD01C17 + value6);
    RAM16_SET(0xE1E8 + value7, value20);
    r->a = (r->a & 0x00FF) | ((value20 >> 8) << 8);
    r->x = value7;
    r->y = value7;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0474F, SOM_RTS, "gen", load_actor_base_attributes_for_appearance, 0, L_B | L_X | L_Y, 1, 1, 0, 142, 50)

#include "som_c.h"

/* C04860 prepare_actor_appearance_table_pointers   [class B, 134 bytes, 61 instructions]
 * Source: src/rom/prepare_actor_appearance_table_pointers.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void prepare_actor_appearance_table_pointers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM8(0x03CB) = 0xD0;
    RAM8(0x03C8) = 0xD0;
    RAM8(0x03C5) = 0xD0;
    RAM8(0x03C2) = 0xD0;
    BUS8_SET(c, 0x004202, 0x0A);
    BUS8_SET(c, 0x004203, RAM8(0xE1E0 + x));
    uint16_t value2 = BUS16(c, 0x004216);
    RAM16_SET(0x03C9, value2);
    BUS8_SET(c, 0x004203, RAM8(0xE1E1 + x));
    uint16_t value4 = BUS16(c, 0x004216);
    RAM16_SET(0x03C6, value4);
    BUS8_SET(c, 0x004203, RAM8(0xE1E2 + x));
    uint16_t value6 = BUS16(c, 0x004216);
    RAM16_SET(0x03C3, value6);
    if ((RAM8(ACTOR_KIND_FLAGS + x) & 0x40) == 0) {
        uint16_t value8 = RAM16(0x03BD);
        uint8_t value9 = RAM8(0xE1E4 + x);
        uint16_t y1;
        if (!(value9 & 0x80)) {
            y1 = value8;
        } else {
            y1 = (uint16_t)(value8 + 1);
        }
        BUS8_SET(c, 0x004202, RAM8(0xE1E8 + y1));
        BUS8_SET(c, 0x004203, 0x0C);
        uint16_t value11 = BUS16(c, 0x004216);
        RAM16_SET(0x03C0, value11);
        if (RAM8(ACTOR_KIND_FLAGS + x) & 0x80) {
            uint8_t value13 = BUS8(c, (RAM8(0x03C2) << 0x10) + RAM16(0x03C0) + 0x1000);
            RAM8(0xE1E4 + x) = value13;
        }
        r->a = (r->a & 0x00FF) | ((value11 >> 8) << 8);
        r->y = y1;
        RETURN_RTS(c);
    }
    r->a = (r->a & 0x00FF) | ((value6 >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04860, SOM_RTS, "gen", prepare_actor_appearance_table_pointers, 0, L_B | L_X | L_Y, 2, 1, 0, 134, 61)

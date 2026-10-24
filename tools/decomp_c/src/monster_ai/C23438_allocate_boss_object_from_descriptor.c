#include "som_c.h"

/* C23438 allocate_boss_object_from_descriptor   [class B, 120 bytes, 67 instructions]
 * Source: src/rom/allocate_boss_object_from_descriptor.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXV.
 */
static void allocate_boss_object_from_descriptor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x020D, 0xC200);
    uint16_t value = BUS16(c, 0xD0BC34 + (uint16_t)(a << 1));
    RAM16_SET(0x020C, value);
    uint16_t value2 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C));
    r->a = value2;
    r->x = 0x34D8;
    r->y = value2;
    r->sp -= 2;
    JSR(c, 0x3453, 0xC20D53); /* allocate_boss_object_pool_slot */
    r->sp += 2;
    uint16_t x_ret = r->x;
    uint16_t value3 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 2);
    RAM16_SET(0x0070 + x_ret, value3);
    uint16_t value4 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 4);
    RAM16_SET(0x00B4 + x_ret, value4);
    uint16_t value5 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 6);
    RAM16_SET(0x00B6 + x_ret, value5);
    uint16_t value6 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 8);
    RAM16_SET(0x00B8 + x_ret, value6);
    uint16_t value7 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x0A);
    RAM16_SET(0x00BA + x_ret, value7);
    uint16_t value8 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x0C);
    RAM16_SET(0x00BC + x_ret, value8);
    uint16_t value9 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x0E);
    RAM16_SET(0x00BE + x_ret, value9);
    uint16_t value10 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x10);
    RAM16_SET(0x0076 + x_ret, value10);
    uint16_t value11 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x12);
    RAM16_SET(0x00A7 + x_ret, value11);
    uint16_t value12 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x14);
    RAM16_SET(0x0078 + x_ret, value12);
    uint16_t value13 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x16);
    RAM16_SET(0x0062 + x_ret, value13);
    RAM16_SET(0x0045 + x_ret, (uint16_t)((value13 ^ RAM16(0x02C7)) + 1));
    uint16_t value15 = BUS16(c, (RAM8(0x020E) << 0x10) + RAM16(0x020C) + 0x18);
    RAM16_SET(0x004C + x_ret, value15);
    r->a = value15;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23438, SOM_RTS, "gen", allocate_boss_object_from_descriptor, 0, L_B | L_X | L_V, 2, 0, 0, 120, 67)

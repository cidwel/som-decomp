#include "som_c.h"

/* C22660 decompress_boss_resource_to_vram_high   [class D, 76 bytes, 32 instructions]
 * Source: src/rom/decompress_boss_resource_to_vram_high.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void decompress_boss_resource_to_vram_high(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = BUS16(c, 0xD0BC52 + (uint16_t)(a << 3));
    RAM16_SET(0x0295, value);
    RAM16_SET(0x029D, value);
    uint16_t value2 = BUS16(c, 0xD0BC54 + (uint16_t)(a << 3));
    RAM16_SET(0x0297, value2);
    uint16_t value3 = BUS16(c, 0xD0BC56 + (uint16_t)(a << 3));
    RAM16_SET(0x0299, value3);
    uint16_t value4 = BUS16(c, 0xD0BC58 + (uint16_t)(a << 3));
    RAM16_SET(0x029B, value4);
    uint16_t value5 = RAM16(0x0297);
    RAM16_SET(0x029E, 0x7F);
    uint16_t value6 = RAM16(0x029D);
    r->a = value6;
    r->x = value5;
    r->y = 0x6000;
    r->c = (uint16_t)(a << 2) & 0x8000;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x268D, 0xC10014); GUARD_JSL(c, sp_call, 0x268D); } /* decompress_block_long_call_wrapper */
    uint16_t dp_ret = r->dp;
    BUS8_SET(c, (uint16_t)(dp_ret + 0x7B), 0x7F);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x79), 0x6000);
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
    BUS16_SET(c, 0x002116, value7);
    uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
    BUS16_SET(c, (uint16_t)(dp_ret + 0x68), value8);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x6A), 0);
    BUS16_SET(c, (uint16_t)(dp_ret + 0x6C), 0);
    r->a = value8;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL(c, 0xC225D7, SOM_RTS); /* expand_boss_resource_to_vram_high */
}
SOM_REGISTER(0xC22660, SOM_RTS, "gen", decompress_boss_resource_to_vram_high, 0, 0, 1, 0, 0, 76, 32)

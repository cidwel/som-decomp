#include "som_c.h"

/* C1263C restart_actor_program   [class B, 92 bytes, 50 instructions]
 * Source: src/rom/restart_actor_program.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01EA.  Callers read: ABXYCV.
 */
static void restart_actor_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01EA) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xEA;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (a_hi << 8) | a);
    RAM16_SET(0x01AC + ((x & 0x1FFF) | 0xE000), 0xFFFF);
    uint16_t value = RAM16(0x0001 + (uint16_t)(sp0 - 5));
    BUS16_SET(c, 0x004202, ((uint8_t)value << 8) | 0x10);
    RAM8(0x0000 + sp0 - 6) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)(((uint8_t)value << 8) | 0x10);
    uint16_t value2 = BUS16(c, 0x004216);
    uint16_t value3 = BUS16(c, 0xD00009 + value2);
    RAM16_SET(0x0144 + ((x & 0x1FFF) | 0xE000), (uint16_t)(value3 + 3));
    RAM16_SET(0x0146 + ((x & 0x1FFF) | 0xE000), 0);
    RAM16_SET(0x014C + ((x & 0x1FFF) | 0xE000), 0);
    RAM8(0x014E + ((x & 0x1FFF) | 0xE000)) = 0;
    RAM8(0x014F + ((x & 0x1FFF) | 0xE000)) = 0;
    RAM8(0x0000 + sp0 - 3) = 0;
    r->a = RAM8(0x0000 + sp0 - 3);
    r->x = value2;
    r->y = (x & 0x1FFF) | 0xE000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1263C, SOM_RTS, "gen", restart_actor_program, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 8, 1, 0, 92, 50)

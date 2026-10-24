#include "som_c.h"

/* C12698 call_actor_status_program   [class B, 99 bytes, 56 instructions]
 * Source: src/rom/call_actor_status_program.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void call_actor_status_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
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
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 7) = 0x7E;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), value);
    uint16_t value2 = RAM16(0x014F + ((x & 0x1FFF) | 0xE000));
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), ((uint16_t)(value2 << 1) & 0xFF) + 0x0150);
    BUS16_SET(c, RAM16(0x0003 + (uint16_t)(sp0 - 7)) + 0x7E0000 + ((x & 0x1FFF) | 0xE000), RAM16(0x0144 + ((x & 0x1FFF) | 0xE000)));
    uint16_t value4 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    uint16_t value5 = BUS16(c, 0xD04ED3 + ((uint16_t)(value4 << 1) & 0xFF));
    RAM16_SET(0x0144 + ((x & 0x1FFF) | 0xE000), value5);
    uint8_t value6 = RAM8(0x014F + ((x & 0x1FFF) | 0xE000));
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if ((uint8_t)(value6 + 1) >= 0x10) {
        r->a = (value5 >> 8 << 8) | RAM8(0x0180 + ((x & 0x1FFF) | 0xE000));
        r->x = (x & 0x1FFF) | 0xE000;
        r->c = (uint8_t)(value6 + 1) >= 0x10;
        r->z = ((x & 0x1FFF) | 0xE000) == 0;
        r->n = ((x & 0x1FFF) | 0xE000) & 0x8000;
        r->v = ((((uint16_t)(value2 << 1) & 0xFF) ^ ((uint16_t)(value2 << 1) & 0xFF) + 0x0150) & (((uint16_t)(value2 << 1) & 0xFF) + 0x0150 ^ 0x0150) & 0x8000) != 0;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 8;
        JSR(c, 0x26F0, 0xC1263C); /* restart_actor_program */
        r->sp += 8;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
    } else {
        RAM8(0x014F + ((x & 0x1FFF) | 0xE000)) = (uint8_t)(value6 + 1);
        a1 = (uint8_t)(value6 + 1);
        a_hi1 = value5 >> 8;
        x1 = (uint16_t)(value4 << 1) & 0xFF;
        y1 = (x & 0x1FFF) | 0xE000;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value11 = RAM8(0x0000 + sp0 - 3);
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value11;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->dp = (value13 << 8) | value12;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12698, SOM_RTS, "gen", call_actor_status_program, 0, L_B | L_X | L_Y | L_C | L_V, 10, 1, 0, 99, 56)

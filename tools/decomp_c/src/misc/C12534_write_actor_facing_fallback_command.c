#include "som_c.h"

/* C12534 write_actor_facing_fallback_command   [class A, 30 bytes, 15 instructions]
 * Source: src/rom/write_actor_facing_fallback_command.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01E1.  Callers read: BY.
 */
static void write_actor_facing_fallback_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01E1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xE1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0140 + y) = 0xC1;
    r->a = (a_hi << 8) | 0xC1;
    r->z = 0;
    r->n = 1;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2541, 0xC10502); GUARD_JSR(c, sp_call, 0x2541); } /* read_actor_facing_direction_code */
    r->sp += 3;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    RAM8(0x0141 + y) = (uint8_t)a_all;
    RAM8(0x0142 + y) = 0;
    RAM8(0x0143 + y) = 5;
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12534, SOM_RTS, "gen", write_actor_facing_fallback_command, 0, L_B | L_Y, 3, 1, 0, 30, 15)

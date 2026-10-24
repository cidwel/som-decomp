#include "som_c.h"

/* C102F8 actor_script_return   [class B, 54 bytes, 30 instructions]
 * Source: src/rom/actor_script_return.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_return(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint8_t value = RAM8(0x014F + y);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if ((uint8_t)(value - 1) >= 0x10) {
        r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | (uint8_t)(value - 1);
        r->c = (uint8_t)(value - 1) >= 0x10;
        r->dp = (uint16_t)(sp0 - 5);
        r->sp -= 5;
        JSR(c, 0x0324, 0xC10100); /* restart_actor_program_on_script_error */
        r->sp += 5;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
    } else {
        RAM8(0x014F + y) = (uint8_t)(value - 1);
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), ((((uint16_t)(sp0 - 5) >> 8 << 8) | (uint8_t)((uint8_t)(value - 1) << 1)) & 0xFF) + 0x0150);
        uint16_t value2 = BUS16(c, RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 0x7E0000 + y);
        RAM16_SET(0x0144 + y, value2);
        a1 = 0xFF;
        a_hi1 = 0xFF;
        x1 = x;
        y1 = y;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 1);
    uint8_t value6 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value4;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->z = ((value6 << 8) | value5) == 0;
    r->n = ((value6 << 8) | value5) & 0x8000;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->dp = (value6 << 8) | value5;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC102F8, SOM_RTS, "gen", actor_script_return, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 54, 30)

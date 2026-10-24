#include "som_c.h"

/* C10502 read_actor_facing_direction_code   [class B, 36 bytes, 20 instructions]
 * Source: src/rom/read_actor_facing_direction_code.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABY.
 */
static void read_actor_facing_direction_code(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x0010 + y);
    uint8_t a3;
    if (value == 0) {
        a3 = 8;
    } else {
        uint8_t a2;
        if (value == 1) {
            a2 = 4;
        } else {
            uint8_t a1;
            if (value == 2) {
                a1 = 1;
            } else {
                a1 = 2;
            }
            a2 = a1;
        }
        a3 = a2;
    }
    SET_A8(r, a3);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10502, SOM_RTS, "gen", read_actor_facing_direction_code, 0, L_A | L_B | L_Y, 3, 1, 0, 36, 20)

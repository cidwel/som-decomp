#include "som_c.h"
#include "som_hand.h"

/* C1032E read_actor_y_minus_height_y   [class A, 21 bytes, 12 instructions]
 * Source: src/rom/read_actor_y_minus_height_y.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void read_actor_y_minus_height_y(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;

    /* PHD, PHP: the indexed reads below may land on these two stack bytes + P */
    RAM8(sp0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = hand_p_byte(r);
    r->sp = sp0 - 3;
    uint16_t height, pos;
    BUS16_OK(c, ((uint32_t)r->db << 16) + 0x0045u + y, height);
    BUS16_OK(c, ((uint32_t)r->db << 16) + 0x0022u + y, pos);
    r->a = (uint16_t)((uint16_t)(((height & 0xFF) ^ 0xFFFF) + 1) + pos);
    hand_plp(c);
    hand_pld(c);
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1032E, SOM_RTS, "hand", read_actor_y_minus_height_y, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 21, 12)

#include "som_c.h"

/* C9FDDC latent_clear_scrolling_dialogue_rows_and_initialize_registers   [class B, 59 bytes, 29 instructions]
 * Source: src/rom/latent_clear_scrolling_dialogue_rows_and_initialize_registers.s
 * Documented in docs/source-recovery-parallel-latent-scroll-flow.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void latent_clear_scrolling_dialogue_rows_and_initialize_registers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0x0800;
    for (;;) {
        RAM8(0x93FF + x1) = 0;
        x1 = (uint16_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x1D04) |= 0x44;
    RAM16_SET(0x003E, 0);
    RAM16_SET(0x0040, 0x1C);
    uint8_t a1 = 6;
    uint8_t a_hi1 = 0;
    uint16_t x2 = 0;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value2 = BUS8(c, 0xC9FFDB + x2);
        BUS8_SET(c, 0x000602 + y1, value2);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value2;
        x2 = (uint16_t)(x2 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    uint8_t value3 = RAM8(0x0000 + sp0);
    uint8_t value4 = BUS8_RDP(c, (value3 << 0x10) + 0xA161);
    BUS8_SET(c, (value3 << 0x10) + 0xA161, (uint8_t)(value4 + 1));
    r->a = (a_hi1 << 8) | a1;
    r->x = x2;
    r->y = y1;
    r->c = carry;
    r->z = (uint8_t)(value4 + 1) == 0;
    r->n = (uint8_t)(value4 + 1) & 0x80;
    r->v = overflow;
    r->db = value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC9FDDC, SOM_RTS, "gen", latent_clear_scrolling_dialogue_rows_and_initialize_registers, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 59, 29)

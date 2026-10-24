#include "som_c.h"

/* C14D0F initialize_hardware_and_load_boot_program   [class D, 53 bytes, 23 instructions]
 * Source: src/rom/initialize_hardware_and_load_boot_program.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_hardware_and_load_boot_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x004200, 0);
    BUS8_SET(c, 0x002100, 0x80);
    RAM8(0x0104) = 0x40;
    RAM8(0x0100) = 0x40;
    uint16_t x1 = 0x4200;
    uint16_t y1 = 0x0E;
    for (;;) {
        BUS8_SET(c, 0x0000 + x1, 0);
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    BUS8_SET(c, 0x004201, 0xFF);
    r->a = 0x7EC7;
    r->x = 0x7C00;
    r->y = 0x8000;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    JSR(c, 0x4D42, 0xC14C30); /* decompress_block */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14D0F, SOM_RTS, "hand", initialize_hardware_and_load_boot_program, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 53, 23)

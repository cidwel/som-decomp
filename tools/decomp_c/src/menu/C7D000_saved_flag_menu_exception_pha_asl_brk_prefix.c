#include "som_c.h"

/* C7D000 saved_flag_menu_exception_pha_asl_brk_prefix   [class A, 4 bytes, 3 instructions]
 * Source: src/rom/saved_flag_menu_exception_pha_asl_brk_prefix.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  PHA / ASL A / BRK $E0.
 * BRK pushes P and PC, so A, S and every flag written before it are live at the exit window.
 */
static void saved_flag_menu_exception_pha_asl_brk_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    if (som_exit_arrive(c, 0xC7D002)) {
        r->a = (a_hi << 8) | (uint8_t)(a << 1);
        r->c = a & 0x80;
        r->z = (uint8_t)(a << 1) == 0;
        r->n = (uint8_t)(a << 1) & 0x80;
        r->sp -= 1;
        c->cpu.k = 0xC7; c->cpu.pc = 0xD002; c->exited = 1;
        return;
    }
    c->fail = 1; /* BRK: software interrupt, outside the contract (the oracle stops here as well) */
    return;
}
SOM_REGISTER(0xC7D000, SOM_RTS, "hand", saved_flag_menu_exception_pha_asl_brk_prefix, 0, L_ALL, 1, 1, 0, 4, 3)

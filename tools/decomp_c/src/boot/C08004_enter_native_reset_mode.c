#include "som_c.h"
#include "somlift.h"

/* C08004 enter_native_reset_mode   [class A, 8 bytes, 4 instructions]
 * Source: src/rom/enter_native_reset_mode.s
 * Documented in docs/boot.md
 * Hand-written: the generator does not model XCE (mode switch).  CLC; XCE leaves
 * emulation mode and clears carry, SEP #$30 forces 8-bit M/X, then JML to the cold boot stub.
 */
static void enter_native_reset_mode(SomCtx *c)
{
    Cpu *r = &c->cpu;
    const bool was_emulation = r->e;
    r->e = false; /* CLC ; XCE: the cleared carry becomes the emulation flag ... */
    r->c = was_emulation; /* ... and the old emulation flag becomes the carry */
    i_sep(r, 0x30);
    TAIL_CALL(c, 0xC10010, SOM_RTS); /* jump_to_cold_boot */
}
SOM_REGISTER(0xC08004, SOM_RTS, "hand", enter_native_reset_mode, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 8, 4)

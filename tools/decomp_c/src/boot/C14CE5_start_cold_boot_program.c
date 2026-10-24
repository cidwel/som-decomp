#include "som_c.h"

/* C14CE5 start_cold_boot_program   [class A, 21 bytes, 10 instructions]
 * Source: src/rom/start_cold_boot_program.s
 * Documented in docs/boot.md
 * Entry: M=any X=any DB=any D=any (REP / SEP / TCS / PLB set every register this routine reads; the boot code calls it with DB=$00, D=$4300).  Callers read: ABXYCV.
 */
static void start_cold_boot_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    i_rep(r, 0x10);
    i_rep(r, 0x20);
    a_lda(r, 0x01FF);
    i_tcs(r);
    i_sep(r, 0x20);
    a_lda(r, 0x00);
    i_pha(c);
    i_plb(c);
    { const uint16_t sp_call = r->sp; JSR(c, 0x4CF5, 0xC14D0F); GUARD_JSR(c, sp_call, 0x4CF5); } /* initialize_hardware_and_load_boot_program */
    TAIL_CALL(c, 0x7EAF0B, SOM_RTS); /* initialize_cold_boot_resources_and_spawn_main_task */
}
SOM_REGISTER(0xC14CE5, SOM_RTS, "hand", start_cold_boot_program, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 21, 10)

#include "som_c.h"

/* C14CFA start_warm_boot_program   [class A, 21 bytes, 10 instructions]
 * Source: src/rom/start_warm_boot_program.s
 * Entry: M=any X=any DB=any D=any.  Callers read: nothing.
 */
static void start_warm_boot_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, -1)) return;
    uint16_t sp0 = r->sp;
    r->sp = 0x01FF;
    som_task_note(c);
    sp0 = r->sp;
    if (r->sp < 0x100 || sp0 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 0;
    r->a = 0x0100;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4D0A, 0xC14D0F); GUARD_JSR(c, sp_call, 0x4D0A); } /* initialize_hardware_and_load_boot_program */
    r->mf = 1;
    r->xf = 0;
    TAIL_CALL(c, 0x7EAF28, SOM_RTS); /* initialize_warm_boot_resources_and_spawn_intro_task */
}
SOM_REGISTER(0xC14CFA, SOM_RTS, "gen", start_warm_boot_program, 0, 0, 1, -1, -1, 21, 10)

#include "som_c.h"

/* C10100 restart_actor_program_on_script_error   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/restart_actor_program_on_script_error.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABYCZNV.
 */
static void restart_actor_program_on_script_error(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = y >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
    uint8_t value = RAM8(0x0180 + y);
    r->a = (a_hi << 8) | value;
    r->x = y;
    r->z = value == 0;
    r->n = value & 0x80;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0107, 0xC1263C); GUARD_JSR(c, sp_call, 0x0107); } /* restart_actor_program */
    r->sp += 2;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        BUS8_SET(c, (db_ret << 0x10) + 0x0140 + ((value4 << 8) | value3), 0);
        SET_A8(r, 0);
        r->y = (value4 << 8) | value3;
        r->z = 1;
        r->n = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC10100, SOM_RTS, "gen", restart_actor_program_on_script_error, 0, L_A | L_B | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 17, 9)

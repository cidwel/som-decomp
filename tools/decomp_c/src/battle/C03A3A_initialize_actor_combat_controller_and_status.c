#include "som_c.h"
#include "som_hand.h"

/* C03A3A initialize_actor_combat_controller_and_status   [class C, 479 bytes, 209 instructions]
 * Source: src/rom/initialize_actor_combat_controller_and_status.s
 * Documented in docs/rom-combat.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCV.
 */
/* The tail pops the caller frame and returns with RTL to whatever the caller's caller continues with; the original runs
 * on from there until the matching return, which the interpreter follows from the popped address. */
#define RETURN_RTL_CONTINUE(c) do { i_rtl(c); (c)->allow_unwind = 1; som_interp_run((c), SOM_RTS, sp_entry); (c)->allow_unwind = 0; return; } while (0)

static void initialize_actor_combat_controller_and_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp_entry = r->sp;
    const uint16_t sp0 = r->sp + 4;
    const uint16_t x = r->x;
    RAM16_SET(BATTLE_DEFENDER_PTR, x & 0x1FFF);
    RAM8(0x0381) = (x & 0x1FFF) >> 9;
    if (RAM8(0x00D9) == 0) {
        if (RAM8(0x00DA) == 0) {
            if (RAM8(0x00DB) == 0) {
                RAM8(0x00D9) = 0x81;
                RAM8(0xE02C) = 1;
            }
        }
    }
    r->x = x & 0x1FFF;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3A67, 0xC8E301); GUARD_JSL(c, sp_call, 0x3A67); } /* apply_actor_status_and_timers */
    { const uint16_t sp_call = r->sp; JSR(c, 0x3A6A, 0xC03E80); GUARD_JSR(c, sp_call, 0x3A6A); } /* rebuild_actor_stats_and_record_status_change_flags */
    uint8_t db_ret2 = r->db;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint8_t value4 = BUS8(c, (db_ret2 << 0x10) + 0xE1FA + x_ret3);
    uint8_t a1;
    uint16_t x1;
    if (value4 == 0) {
        a1 = value4;
        x1 = x_ret3;
    } else {
        BUS8_SET(c, (db_ret2 << 0x10) + 0xE1FA + x_ret3, 0);
        a1 = 4;
        x1 = (a_all2 >> 8 << 8) | value4;
    }
    if (a1 != 0) {
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->a = (a_all2 >> 8 << 8) | a1;
        r->x = x1;
        som_pull_p(c, sp0 - 3); /* PLP */
        r->db = value6;
        r->dp = (value8 << 8) | value7;
        r->z = r->dp == 0; /* PLD sets N and Z, and the code that runs on reads them */
        r->n = r->dp & 0x8000;
        r->sp += 4;
        RETURN_RTL_CONTINUE(c);
    }
    uint8_t value10 = RAM8(0x0000 + sp0 - 2);
    uint8_t value11 = RAM8(0x0000 + sp0 - 1);
    uint8_t value12 = RAM8(0x0000 + sp0);
    r->a = (a_all2 >> 8 << 8) | a1;
    r->x = x1;
    som_pull_p(c, sp0 - 3); /* PLP */
    r->db = value10;
    r->dp = (value12 << 8) | value11;
    r->z = r->dp == 0;
    r->n = r->dp & 0x8000;
    r->sp += 4;
    RETURN_RTL_CONTINUE(c);
}
SOM_REGISTER(0xC03A3A, SOM_RTS, "hand", initialize_actor_combat_controller_and_status, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 479, 209)

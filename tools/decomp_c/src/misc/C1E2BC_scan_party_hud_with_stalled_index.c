#include "som_c.h"

/* C1E2BC scan_party_hud_with_stalled_index   [class B, 41 bytes, 21 instructions]
 * Source: src/rom/scan_party_hud_with_stalled_index.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 * The loop never advances X (the code adds $0200 to A and compares, but there is no TAX), so with X = 0 the compare is always "below" and the routine never
 * returns: PLB / RTS are unreachable.  Only one pass of the body is observable, at the first record (E000 / E02C).  A window ends at the second arrival at
 * C1E2C8 (entry option exit=C1E2C8@2); a run without an exit window is an endless loop, which the contract treats as outside the domain.
 */
static void scan_party_hud_with_stalled_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    if (som_exit_arrive(c, 0xC1E2C8)) {
        r->a = (a_hi << 8) | 0x7E;
        r->x = 0;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->sp -= 1;
        c->cpu.k = 0xC1; c->cpu.pc = 0xE2C8; c->exited = 1;
        return;
    }
    const uint8_t value = RAM8(0xE000);
    if (value != 0 && !(value & 0x80)) {
        const uint8_t value2 = RAM8(0xE02C);
        if (value2 == 0) {
            r->a = (a_hi << 8) | value2;
            r->x = 0;
            r->z = 1;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xE2D6, 0xC1E2E5); GUARD_JSR(c, sp_call, 0xE2D6); } /* clear_party_hud_tilemap */
            r->sp += 1;
        }
    }
    if (som_exit_arrive(c, 0xC1E2C8)) {
        r->a = 0x0200;
        r->x = 0;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->v = 0;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->sp -= 1;
        c->cpu.k = 0xC1; c->cpu.pc = 0xE2C8; c->exited = 1;
        return;
    }
    c->fail = 1; /* X is never advanced: the original loops forever (outside the contract, the oracle runs away as well) */
    return;
}
SOM_REGISTER(0xC1E2BC, SOM_RTS, "hand", scan_party_hud_with_stalled_index, 0, L_ALL, 2, 1, 0, 41, 21)

#include "som_c.h"

/* C03F08 dispatch_pending_actor_status_program   [class B, 31 bytes, 15 instructions]
 * Source: src/rom/dispatch_pending_actor_status_program.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYV.
 */
static void dispatch_pending_actor_status_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(ACTOR_KIND_FLAGS + x);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool overflow1;
    if ((value & 8) == 0) {
        a_hi1 = a_hi;
        x1 = x;
        y1 = y;
        overflow1 = overflow;
    } else {
        RAM8(ACTOR_KIND_FLAGS + x) = value & 0xF7;
        uint8_t value2 = RAM8(ACTOR_KIND_FLAGS + x);
        uint8_t a1;
        bool zero1;
        bool negative1;
        if (value2 & 0x80) {
            a1 = 1;
            zero1 = value2 == 0;
            negative1 = value2 & 0x80;
        } else {
            a1 = 2;
            zero1 = 0;
            negative1 = 0;
        }
        r->a = (a_hi << 8) | a1;
        r->z = zero1;
        r->n = negative1;
        JSL(c, 0x3F21, 0xC10024); /* call_actor_status_program_long */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
        a_hi1 = a_all >> 8;
        x1 = battle_defender_ptr;
        y1 = y_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03F08, SOM_RTS, "gen", dispatch_pending_actor_status_program, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 31, 15)

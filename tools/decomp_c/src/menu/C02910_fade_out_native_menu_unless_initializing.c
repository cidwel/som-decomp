#include "som_c.h"

/* C02910 fade_out_native_menu_unless_initializing   [class D, 32 bytes, 15 instructions]
 * Source: src/rom/fade_out_native_menu_unless_initializing.s
 * Documented in docs/event-menu-frames.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void fade_out_native_menu_unless_initializing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0xA212);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero1;
    bool negative1;
    bool overflow2;
    if ((value & 0x10) != 0) {
        a2 = value;
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
        carry2 = carry;
        zero1 = (value & 0x10) == 0;
        negative1 = value & 0x80;
        overflow2 = overflow;
    } else {
        uint8_t a1 = 0x0F;
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = x;
        uint16_t y1 = y;
        bool carry1 = carry;
        bool overflow1 = overflow;
        for (;;) {
            r->a = (a_hi1 << 8) | a1;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = db;
            r->dp = 0;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x291D, 0xC028FF); GUARD_JSR(c, sp_call, 0x291D); } /* await_native_menu_vblank_edge */
            r->sp += 1;
            uint16_t a_all = r->a;
            BUS8_SET(c, 0x002100, a1);
            uint8_t a1_next = (uint8_t)(a1 - 2);
            uint8_t a_hi1_next = a_all >> 8;
            bool carry1_next = (uint8_t)(a1 - 2) >= 0xFF;
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            carry1 = carry1_next;
            if (!(a1 != 0xFF)) break;
        }
        BUS8_SET(c, 0x002100, 0);
        a2 = 0;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero1 = 1;
        negative1 = 0;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02910, SOM_RTS, "gen", fade_out_native_menu_unless_initializing, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 32, 15)

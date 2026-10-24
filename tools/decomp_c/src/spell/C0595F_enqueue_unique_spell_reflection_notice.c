#include "som_c.h"

/* C0595F enqueue_unique_spell_reflection_notice   [class B, 49 bytes, 23 instructions]
 * Source: src/rom/enqueue_unique_spell_reflection_notice.s
 * Documented in docs/actor-cast-spell-reflection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void enqueue_unique_spell_reflection_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x00B2) = 0x0B;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0xFFE2;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        if (RAM8(0xFE00 + (uint16_t)(x1 + 0x1E)) == 0) {
            RAM8(0x00B2)--;
            if (RAM8(0x00B2) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 0x1E) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 0x1E);
                bool carry1_next = x1 + 0x1E > 0xFFFF;
                bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x1E)) & ((uint16_t)(x1 + 0x1E) ^ 0x1E) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                carry1 = carry1_next;
                overflow1 = overflow1_next;
                continue;
            }
            uint8_t a_hi1_next4 = (uint16_t)(x1 + 0x1E) >> 8;
            uint16_t x1_next4 = (uint16_t)(x1 + 0x1E);
            bool carry1_next4 = x1 + 0x1E > 0xFFFF;
            bool overflow1_next4 = ((x1 ^ (uint16_t)(x1 + 0x1E)) & ((uint16_t)(x1 + 0x1E) ^ 0x1E) & 0x8000) != 0;
            a_hi1 = a_hi1_next4;
            x1 = x1_next4;
            carry1 = carry1_next4;
            overflow1 = overflow1_next4;
            break;
        }
        uint8_t value2 = RAM8(0xFE1D + (uint16_t)(x1 + 0x1E));
        if (value2 != 1) {
            RAM8(0x00B2)--;
            if (RAM8(0x00B2) != 0) {
                uint8_t a_hi1_next2 = (uint16_t)(x1 + 0x1E) >> 8;
                uint16_t x1_next2 = (uint16_t)(x1 + 0x1E);
                bool carry1_next2 = value2 >= 1;
                bool overflow1_next2 = ((x1 ^ (uint16_t)(x1 + 0x1E)) & ((uint16_t)(x1 + 0x1E) ^ 0x1E) & 0x8000) != 0;
                a_hi1 = a_hi1_next2;
                x1 = x1_next2;
                carry1 = carry1_next2;
                overflow1 = overflow1_next2;
                continue;
            }
            uint8_t a_hi1_next3 = (uint16_t)(x1 + 0x1E) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 0x1E);
            bool carry1_next3 = value2 >= 1;
            bool overflow1_next3 = ((x1 ^ (uint16_t)(x1 + 0x1E)) & ((uint16_t)(x1 + 0x1E) ^ 0x1E) & 0x8000) != 0;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            carry1 = carry1_next3;
            overflow1 = overflow1_next3;
            break;
        }
        r->a = ((uint16_t)(x1 + 0x1E) >> 8 << 8) | value2;
        RETURN_RTL(c);
    }
    r->x = x1;
    r->c = carry1;
    r->v = overflow1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5983, 0xC05D08); GUARD_JSR(c, sp_call, 0x5983); } /* allocate_reverse_combat_message_slot */
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    RAM8(0xFE1C + y_ret) = 1;
    r->a = (a_all >> 8 << 8) | 1;
    r->x = 0x62A3;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x598E, 0xC05C2A); GUARD_JSR(c, sp_call, 0x598E); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0595F, SOM_RTL, "gen", enqueue_unique_spell_reflection_notice, 0, L_B, 1, 1, 0, 49, 23)

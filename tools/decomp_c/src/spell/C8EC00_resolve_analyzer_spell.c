#include "som_c.h"

/* C8EC00 resolve_analyzer_spell   [class B, 59 bytes, 26 instructions]
 * Source: src/rom/resolve_analyzer_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void resolve_analyzer_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    uint8_t value = RAM8(0xE180 + battle_defender_ptr);
    if (value == 0xEA) {
        BUS8_SET(c, 0x004202, RAM8(0xE1CA + battle_defender_ptr));
        BUS8_SET(c, 0x004203, 5);
        uint16_t value3 = BUS16(c, 0x004216);
        uint8_t value4 = BUS8(c, 0xD03A51 + value3);
        uint8_t value5 = RAM8(0x039D);
        uint8_t a2;
        uint16_t x2;
        bool zero2;
        bool negative2;
        if ((value4 & 0x0F) == value5) {
            RAM8(ACTOR_MAX_HP + battle_defender_ptr) = 0xFF;
            a2 = 0xFF;
            x2 = battle_defender_ptr;
            zero2 = 0;
            negative2 = 1;
        } else {
            uint8_t a1;
            uint16_t x1;
            bool zero1;
            bool negative1;
            if ((value4 & 0x0F) >= value5) {
                a1 = value4 & 0x0F;
                x1 = value3;
                zero1 = (value4 & 0x0F) == value5;
                negative1 = (uint8_t)((value4 & 0x0F) - value5) & 0x80;
            } else {
                RAM8(ACTOR_MAX_HP + battle_defender_ptr) = 0xFF;
                a1 = 0xFF;
                x1 = battle_defender_ptr;
                zero1 = 0;
                negative1 = 1;
            }
            a2 = a1;
            x2 = x1;
            zero2 = zero1;
            negative2 = negative1;
        }
        r->a = (value3 >> 8 << 8) | a2;
        r->x = x2;
        r->c = (value4 & 0x0F) >= value5;
        r->z = zero2;
        r->n = negative2;
        RETURN_RTS(c);
    }
    r->a = (a_hi << 8) | value;
    r->x = battle_defender_ptr;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEC0C, 0xC0599D); GUARD_JSL(c, sp_call, 0xEC0C); } /* build_analyzer_actor_messages */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8EC00, SOM_RTS, "gen", resolve_analyzer_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 59, 26)

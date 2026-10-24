#include "som_c.h"

/* C8ED04 resolve_revivifier_spell   [class B, 79 bytes, 36 instructions]
 * Source: src/rom/resolve_revivifier_spell.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void resolve_revivifier_spell(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    uint8_t value = RAM8(ACTOR_KIND_FLAGS + battle_defender_ptr);
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero2;
    bool negative2;
    bool overflow1;
    if ((value & 0xC0) == 0) {
        x_flag = 0;
        a1 = value;
        a_hi1 = a_hi;
        x1 = battle_defender_ptr;
        y1 = y;
        carry1 = carry;
        zero2 = (value & 0xC0) == 0;
        negative2 = value & 0x80;
        overflow1 = overflow;
    } else {
        RAM8(0x038F) = 4;
        r->a = (a_hi << 8) | 4;
        r->x = battle_defender_ptr;
        { const uint16_t sp_call = r->sp; JSR(c, 0xED13, 0xC8E8C0); GUARD_JSR(c, sp_call, 0xED13); } /* calculate_spell_attack_roll */
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xED16, 0xC8EA69); GUARD_JSR(c, sp_call, 0xED16); } /* divide_spell_level_by_target_count */
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xED19, 0xC8E9FC); GUARD_JSR(c, sp_call, 0xED19); } /* cure_actor_statuses_and_shorten_timers */
        bool x_ret4 = r->xf;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret2 = r->y;
        RAM8(ACTOR_STATUS_HIGH + x_ret5) &= 0x7F;
        BUS16_SET(c, 0x004204, RAM16(BATTLE_DAMAGE));
        uint8_t value3 = RAM8(0x039D);
        BUS8_SET(c, 0x004206, (uint8_t)(9 - value3));
        uint16_t value4 = BUS16(c, 0x004214);
        RAM16_SET(ACTOR_PENDING_HP_HEAL + x_ret5, value4);
        uint16_t value5 = RAM16(ACTOR_HP + x_ret5);
        bool zero1;
        bool negative1;
        if (value5 != 0) {
            zero1 = value5 == 0;
            negative1 = value5 & 0x8000;
        } else {
            RAM16_SET(ACTOR_HP + x_ret5, (uint16_t)(RAM16(ACTOR_HP + x_ret5) + 1));
            zero1 = RAM16(ACTOR_HP + x_ret5) == 0;
            negative1 = RAM16(ACTOR_HP + x_ret5) & 0x8000;
        }
        RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x_ret5, 0);
        x_flag = x_ret4;
        a1 = (uint8_t)value5;
        a_hi1 = value5 >> 8;
        x1 = x_ret5;
        y1 = y_ret2;
        carry1 = value3 <= 9;
        zero2 = zero1;
        negative2 = negative1;
        overflow1 = ((value3 ^ 9) & ((uint8_t)(9 - value3) ^ 9) & 0x80) != 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow1;
    r->mf = 1;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8ED04, SOM_RTS, "gen", resolve_revivifier_spell, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 79, 36)

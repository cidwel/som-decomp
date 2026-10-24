#include "som_c.h"

/* C0532C apply_critical_hit_or_weapon_gauge   [class B, 239 bytes, hand written]
 * docs/rom-combat.md section 4.3 ("crit / gauge").  X = defender, Y = attacker, BATTLE_DAMAGE = pending damage.
 *   - a Saber/critical counter in the high nibble of ACTOR_SABER_AND_CRIT_COUNTER forces a critical hit and
 *     consumes one count;
 *   - otherwise, while the attacker's weapon gauge is not empty, the damage is halved and scaled by
 *     (AC - gauge) / AC with AC = (99 - agility) / 2 + 80, and there is no critical hit;
 *   - otherwise the critical chance is crit_base (doubled against a defender with status bit 4, plus 10 for hero
 *     slot 1 or 5 for another hero) in 256ths.
 * A critical hit queues the "critical" notice (C05990) and doubles BATTLE_DAMAGE.  Callers read: X, Y.
 */
static void critical_hit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    JSL(c, 0x5375, 0xC05990); /* enqueue_physical_critical_hit_notice */
    r->x = RAM16(BATTLE_DEFENDER_PTR);
    r->y = RAM16(BATTLE_ATTACKER_PTR);
    RAM16_SET(BATTLE_DAMAGE, (uint16_t)(RAM16(BATTLE_DAMAGE) << 1));
}

static void apply_critical_hit_or_weapon_gauge(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t defender = r->x;
    const uint16_t attacker = r->y;

    const uint8_t counter = RAM8(ACTOR_SABER_AND_CRIT_COUNTER + attacker);
    if (counter & 0xF0) {
        RAM8(ACTOR_SABER_AND_CRIT_COUNTER + attacker) = (uint8_t)(counter - 0x10);
        r->a = (r->a & 0xFF00) | (uint8_t)(counter - 0x10);
        critical_hit(c);
        RETURN_RTS(c);
    }

    const uint8_t gauge = RAM8(ACTOR_WEAPON_GAUGE + attacker);
    if (gauge != 0) {
        /* swing before the gauge emptied: half damage scaled by (AC - gauge) / AC, no critical */
        RAM16_SET(BATTLE_DAMAGE, RAM16(BATTLE_DAMAGE) >> 1);
        RAM16_SET(BATTLE_MUL_WORK, 0);
        RAM16_SET(BATTLE_DIV_WORK, 0);
        RAM8(BATTLE_MUL_WORK + 2) = 0;
        RAM8(BATTLE_DIV_WORK + 2) = 0;
        const uint8_t agility = RAM8(ACTOR_AGILITY + attacker);
        RAM8(BATTLE_TEMP_AC) = agility;
        const uint8_t gauge_cycle = (uint8_t)(((uint8_t)(0x63 - agility) >> 1) + 0x50); /* AC */
        RAM8(BATTLE_TEMP_AC) = gauge_cycle;
        RAM8(BATTLE_TEMP_A8) = gauge;
        const uint8_t factor = (uint8_t)(gauge_cycle - gauge);

        /* 24-bit product factor * damage, as two 8x8 multiplications: low byte first */
        BUS8_SET(c, 0x004202, factor);
        BUS8_SET(c, 0x004203, RAM8(BATTLE_DAMAGE));
        const uint16_t product_low = BUS16(c, 0x004216);
        RAM16_SET(BATTLE_MUL_WORK, product_low);
        BUS8_SET(c, 0x004203, RAM8(BATTLE_DAMAGE + 1));
        const uint16_t product_high = (uint16_t)(BUS16(c, 0x004216) + RAM16(BATTLE_MUL_WORK + 1));
        RAM16_SET(BATTLE_MUL_WORK + 1, product_high);

        /* divide that 24-bit value by AC with two 16/8 divisions: top 16 bits first, then remainder:low byte */
        BUS16_SET(c, 0x004204, product_high);
        BUS8_SET(c, 0x004206, gauge_cycle);
        const uint16_t quotient_high = BUS16(c, 0x004214);
        RAM16_SET(BATTLE_DIV_WORK + 1, quotient_high);
        const uint8_t remainder = BUS8(c, 0x004216);
        BUS16_SET(c, 0x004204, (uint16_t)((remainder << 8) | RAM8(BATTLE_MUL_WORK)));
        BUS8_SET(c, 0x004206, gauge_cycle);
        RAM16_SET(BATTLE_DAMAGE, (uint16_t)(BUS16(c, 0x004214) + RAM16(BATTLE_DIV_WORK)));
        RETURN_RTS(c);
    }

    /* normal swing: roll against the critical chance */
    uint8_t chance = RAM8(ACTOR_CRIT_BASE + attacker);
    RAM8(BATTLE_TEMP_A4) = chance;
    if (RAM8(ACTOR_STATUS + defender) & 0x10) {
        chance = (uint8_t)(chance << 1);
        RAM8(BATTLE_TEMP_A4) = chance;
    }
    if (RAM8(ACTOR_KIND_FLAGS + attacker) & 0x80) { /* hero attacker */
        chance = (uint8_t)(chance + (RAM8(BATTLE_ATTACKER_SLOT) == 1 ? 0x0A : 0x05));
        RAM8(BATTLE_TEMP_A4) = chance;
    }
    JSL(c, 0x5364, 0xC0389C); /* random_byte_long_wrapper */
    if ((uint8_t)r->a < chance) critical_hit(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0532C, SOM_RTS, "hand", apply_critical_hit_or_weapon_gauge, 0, L_X | L_Y, 16, 1, 0, 239, 118)

#include "som_c.h"

/* C8E6D4 apply_spell_hit_to_actor   [class C, 301 bytes, hand written]
 * docs/rom-combat.md section 5, docs/spells-non-damage.md.  Entry of the spell hit pipeline (C00054 -> D04C82 -> here).
 *
 * After prepare_cast_actor_context_long, X = target actor record and Y = caster actor record (offsets from $E000).
 * This routine:
 *   1. starts the hit-flash timer (ACTOR_HIT_FLASH_TIMER = 16) of both actors;
 *   2. on the first hit of a cast (all three cast hit-list slots still empty) advances the hero's spell level progress
 *      and charges the spell's MP cost (byte 15 of the 64-byte spell row at D0:2AD0 + id * 64) to the caster;
 *   3. records the target in the first free cast hit-list slot, or stops when it is already listed or the list is full;
 *   4. stops unless the target may be hit (monster-side actor, Revivifier, id $EA, or a target that is not "protected" by
 *      the high status bit 7), then notes the caster and an empty damage source on the target;
 *   5. for a monster-side target flags the controlling player's input word and returns; otherwise falls into the
 *      spell dispatcher resolve_spell_hit_on_target (C8E7A7, same routine here), which clears the pending damage of
 *      hero-side actors, selects the caster's magic stat and calls the handler of the spell id.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300; DP $81 = target slot, $82 = caster slot, $83 = caster record, $85 = target record.
 * Callers read: B (the high byte of A, which this routine leaves as documented below).
 */
enum {
    ACTOR_HIT_FLASH_TIMER_FIELD = 0xE1F8,
    ACTOR_SPELL_ID_FIELD = 0xE170,
    ACTOR_CAST_SPELL_LEVEL_FIELD = 0xE171,
    ACTOR_CAST_HIT_LIST_FIELD = 0xE172, /* three slots; bit 7 set = empty */
    ACTOR_TARGET_DIVISOR_FIELD = 0xE176,
    ACTOR_ID_FIELD = 0xE180,
    ACTOR_LAST_SPELL_CASTER_FIELD = 0xE1EC,
    ACTOR_LAST_DAMAGE_SOURCE_FIELD = 0xE1F0,
    ACTOR_CONTROL_ID_FIELD = 0xE02C,
    SPELL_ROW_MP_COST = 0x2ADF, /* D0:2AD0 + 15 */
    SPELL_REVIVIFIER = 0x21,
    ACTOR_ID_EXEMPT = 0xEA,
    DP_TARGET_SLOT = 0x0381,
    DP_CASTER_SLOT = 0x0382,
    DP_CASTER_RECORD = 0x0383,
    DP_TARGET_RECORD = 0x0385,
    DP_SPELL_ROW_PTR = 0x03DC,
    DP_SPELL_ROW_BANK = 0x03DE,
    DP_SPELL_LEVEL = 0x039D,
    DP_INPUT_FLAGS = 0x00D9 /* bank-0 absolute, indexed by the controlling player */
};

/* C8E7A7: the dispatcher half.  X = target record, Y = caster record.  Leaves the high byte of A as the last callee did. */
static void resolve_spell_hit_on_target(SomCtx *c, uint16_t x, uint16_t y)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (RAM8(ACTOR_KIND_FLAGS + x) & 0x40) RAM8(0xE00A + x) = RAM8(ACTOR_SPELL_ID_FIELD + y);
    if (RAM8(ACTOR_KIND_FLAGS + x) & 0x80) {
        RAM8(ACTOR_PENDING_HP_DAMAGE + x) = 0;
        RAM8(ACTOR_PENDING_HP_DAMAGE + 1 + x) = 0;
    }
    if (RAM8(ACTOR_KIND_FLAGS + y) & 0x80) {
        RAM8(ACTOR_PENDING_HP_DAMAGE + y) = 0;
        RAM8(ACTOR_PENDING_HP_DAMAGE + 1 + y) = 0;
    }
    r->x = x;
    r->y = y;
    JSR(c, 0xE7CE, 0xC8E855); /* select_caster_magic_stat_and_power */
    x = r->x;
    y = r->y;
    if (RAM8(ACTOR_KIND_FLAGS + y) & 0x80) { /* hero-side caster: spell power comes from the spell row (byte 10) */
        RAM8(0x0396) = BUS8(c, 0xD00000 | (uint16_t)(RAM16(DP_SPELL_ROW_PTR) + 0x2ADA));
        y = RAM16(DP_CASTER_RECORD);
    }
    if (RAM8(ACTOR_TARGET_DIVISOR_FIELD + y) == 0) return; /* no divisor: nothing to resolve */
    const uint8_t buffs_before = RAM8(ACTOR_BUFF_FLAGS + x);
    const uint8_t id = RAM8(ACTOR_SPELL_ID_FIELD + y);
    r->a = (uint8_t)(id << 1); /* LDA #0 / XBA clears the high byte of A, ASL doubles the id */
    r->c = id >> 7;
    r->z = (uint8_t)(id << 1) == 0;
    r->n = (id << 1) & 0x80;
    r->x = (uint8_t)(id << 1); /* 8-bit ASL: the table index wraps at 256 */
    r->y = y;
    ram[r->sp & 0x1FFFF] = buffs_before; /* PHA of the buff byte */
    r->sp -= 1;
    switch (id) {
    case 0x00: case 0x01: case 0x06: case 0x0C: case 0x0D: case 0x0E: case 0x12: case 0x13: case 0x1F: case 0x25: case 0x28:
        JSR(c, 0xE7F0, 0xC8EA8B); /* resolve_standard_damage_spell: Earth Slide, Gem Missile, Freeze, Fireball, Exploder, Lava Wave, Air Blast, Thunderbolt, Burst, Dark Force, Lucent Beam */
        break;
    case 0x02:
        JSR(c, 0xE7F0, 0xC8EA97); /* resolve_speed_down_spell: Speed Down */
        break;
    case 0x03:
        JSR(c, 0xE7F0, 0xC8EAA3); /* stone_saber_entry: Stone Saber */
        break;
    case 0x04:
        JSR(c, 0xE7F0, 0xC8EB04); /* apply_speed_up_spell: Speed Up */
        break;
    case 0x05:
        JSR(c, 0xE7F0, 0xC8EB20); /* apply_defender_spell: Defender */
        break;
    case 0x07:
        JSR(c, 0xE7F0, 0xC8EB39); /* resolve_acid_storm_spell: Acid Storm */
        break;
    case 0x08:
        JSR(c, 0xE7F0, 0xC8EB54); /* queue_energy_absorb_spell: Energy Absorb */
        break;
    case 0x09:
        JSR(c, 0xE7F0, 0xC8EAA8); /* ice_saber_entry: Ice Saber */
        break;
    case 0x0A:
        JSR(c, 0xE7F0, 0xC8EB9F); /* resolve_remedy_spell: Remedy */
        break;
    case 0x0B:
        JSR(c, 0xE7F0, 0xC8EBB3); /* queue_cure_water_healing: Cure Water */
        break;
    case 0x0F:
        JSR(c, 0xE7F0, 0xC8EAAD); /* flame_saber_entry: Flame Saber */
        break;
    case 0x10:
        JSR(c, 0xE7F0, 0xC8EBCA); /* resolve_fire_bouquet_spell: Fire Bouquet */
        break;
    case 0x11:
        JSR(c, 0xE7F0, 0xC8EBE5); /* resolve_blaze_wall_spell: Blaze Wall */
        break;
    case 0x14: case 0x16: case 0x18: case 0x1E:
        JSR(c, 0xE7F0, 0xC8EBF4); /* resolve_status_only_spell: Silence, Balloon, Change Form, Sleep Flower */
        break;
    case 0x15:
        JSR(c, 0xE7F0, 0xC8EAB2); /* thunder_saber_entry: Thunder Saber */
        break;
    case 0x17:
        JSR(c, 0xE7F0, 0xC8EC00); /* resolve_analyzer_spell: Analyzer */
        break;
    case 0x19:
        JSR(c, 0xE7F0, 0xC8EC3B); /* queue_magic_absorb_spell: Magic Absorb */
        break;
    case 0x1A:
        JSR(c, 0xE7F0, 0xC8EEF5); /* dispatch_lunar_magic_effect: Lunar Magic */
        break;
    case 0x1B:
        JSR(c, 0xE7F0, 0xC8EABC); /* moon_saber_entry: Moon Saber */
        break;
    case 0x1C:
        JSR(c, 0xE7F0, 0xC8ECB5); /* apply_lunar_boost_spell: Lunar Boost */
        break;
    case 0x1D:
        JSR(c, 0xE7F0, 0xC8ECD1); /* apply_moon_energy_spell: Moon Energy */
        break;
    case 0x20:
        JSR(c, 0xE7F0, 0xC8ECEA); /* apply_weapon_magic_first_timer: weapon magic 1 */
        break;
    case 0x21:
        JSR(c, 0xE7F0, 0xC8ED04); /* resolve_revivifier_spell: Revivifier */
        break;
    case 0x22:
        JSR(c, 0xE7F0, 0xC8ED53); /* apply_wall_spell: Wall */
        break;
    case 0x23:
        JSR(c, 0xE7F0, 0xC8ED68); /* apply_weapon_magic_second_timer: weapon magic 2 */
        break;
    case 0x24:
        JSR(c, 0xE7F0, 0xC8ED82); /* queue_evil_gate_spell: Evil Gate */
        break;
    case 0x26:
        JSR(c, 0xE7F0, 0xC8EDCB); /* resolve_dispel_magic_spell: Dispel Magic */
        break;
    case 0x27:
        JSR(c, 0xE7F0, 0xC8EAB7); /* light_saber_entry: Light Saber */
        break;
    case 0x29:
        JSR(c, 0xE7F0, 0xC8EEB7); /* apply_lucid_barrier_spell: Lucid Barrier */
        break;
    default:
        JSR(c, 0xE7F0, 0xC80000 | BUS16(c, 0xC8E801 + (uint8_t)(id << 1)));
        break;
    }
    r->mf = 1; /* SEP #$20 */
    r->sp += 1;
    const uint8_t pulled = ram[r->sp & 0x1FFFF]; /* PLA */
    x = RAM16(DP_TARGET_RECORD);
    const uint8_t cleared = (uint8_t)(~pulled) & RAM8(ACTOR_BUFF_FLAGS + x);
    r->x = x;
    r->a = (r->a & 0xFF00) | cleared; /* PLA/EOR/AND leave the high byte (B) alone */
    r->z = cleared == 0;
    r->n = (cleared & 0x80) != 0;
    r->y = r->a; /* TAY with 16-bit index copies B as well */
    JSL(c, 0xE7FF, 0xC05921); /* apply the cleared buff bits (Y) to the target */
}

static void apply_spell_hit_to_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }

    JSL(c, 0xE6D7, 0xC0395E); /* prepare_cast_actor_context_long */
    const uint16_t target = r->x;
    const uint16_t caster = r->y;
    uint8_t a_hi = r->a >> 8;

    RAM8(ACTOR_HIT_FLASH_TIMER_FIELD + target) = 0x10;
    RAM8(ACTOR_HIT_FLASH_TIMER_FIELD + caster) = 0x10;

    /* spell row pointer = D0:(spell id * 64), computed by the hardware multiplier */
    BUS8_SET(c, 0x004202, RAM8(ACTOR_SPELL_ID_FIELD + caster));
    BUS8_SET(c, 0x004203, 0x40);
    const uint16_t row_offset = BUS16(c, 0x004216);
    RAM16_SET(DP_SPELL_ROW_PTR, row_offset);
    a_hi = row_offset >> 8;
    r->a = (uint16_t)((a_hi << 8) | 0xD0); /* REP #$20 / LDA $4216 / STA $DC / SEP #$20 / LDA #$D0 */
    r->x = target;
    r->y = caster;
    RAM8(DP_SPELL_ROW_BANK) = 0xD0;

    uint16_t x = target;
    uint16_t y = caster;
    if ((RAM8(ACTOR_CAST_HIT_LIST_FIELD + y) & 0x80) && (RAM8(ACTOR_CAST_HIT_LIST_FIELD + 1 + y) & 0x80) &&
        (RAM8(ACTOR_CAST_HIT_LIST_FIELD + 2 + y) & 0x80)) {
        JSL(c, 0xE710, 0xD04DCD); /* advance_hero_spell_level_progress */
        a_hi = r->a >> 8;
        const uint8_t mp_cost = BUS8(c, 0xD00000 | (uint16_t)(RAM16(DP_SPELL_ROW_PTR) + SPELL_ROW_MP_COST));
        y = RAM16(DP_CASTER_RECORD);
        RAM8(0x03A4) = mp_cost;
        const uint8_t mp_left = (uint8_t)(RAM8(ACTOR_MP + y) - mp_cost);
        RAM8(ACTOR_MP + y) = (mp_left & 0x80) ? 0 : mp_left;
    }

    RAM8(0x0391) = 0;
    RAM8(0x039A) = 0;
    RAM8(0x039B) = 0;
    x = RAM16(DP_CASTER_RECORD);
    RAM8(DP_SPELL_LEVEL) = RAM8(ACTOR_CAST_SPELL_LEVEL_FIELD + x);

    /* already in the hit list? */
    for (int slot = 0; slot < 3; slot++)
        if (RAM8(DP_TARGET_SLOT) == RAM8(ACTOR_CAST_HIT_LIST_FIELD + x + slot))
            goto done;
    /* first free slot (bit 7 set) takes the target */
    {
        int slot = 0;
        while (slot < 3 && !(RAM8(ACTOR_CAST_HIT_LIST_FIELD + x + slot) & 0x80)) slot++;
        if (slot == 3) goto done;
        RAM8(ACTOR_CAST_HIT_LIST_FIELD + x + slot) = RAM8(DP_TARGET_SLOT);
    }

    x = RAM16(DP_TARGET_RECORD);
    y = RAM16(DP_CASTER_RECORD);
    if (RAM8(ACTOR_STATUS_HIGH + y) & 0x80) goto done;
    {
        const uint8_t target_kind = RAM8(ACTOR_KIND_FLAGS + x);
        const bool may_hit = (target_kind & 0x10) || RAM8(ACTOR_SPELL_ID_FIELD + y) == SPELL_REVIVIFIER ||
                             RAM8(ACTOR_ID_FIELD + x) == ACTOR_ID_EXEMPT || !(RAM8(ACTOR_STATUS_HIGH + x) & 0x80);
        if (!may_hit) goto done;
    }

    RAM8(ACTOR_LAST_SPELL_CASTER_FIELD + x) = RAM8(DP_CASTER_SLOT);
    RAM8(ACTOR_LAST_DAMAGE_SOURCE_FIELD + x) = 0xFF;
    a_hi = 0;
    {
        const uint8_t target_kind = RAM8(ACTOR_KIND_FLAGS + x);
        if ((target_kind & 0x10) == 0) {
            r->a = (uint16_t)((a_hi << 8) | target_kind);
            r->x = x;
            r->y = y;
            r->z = 1;
            r->n = target_kind & 0x80;
            resolve_spell_hit_on_target(c, x, y);
            RETURN_RTL(c);
        }
        /* monster-side target: mark the input word of the player who controls the caster */
        const uint8_t control = RAM8(ACTOR_CONTROL_ID_FIELD + y);
        if (control != 0) {
            uint8_t player = (uint8_t)(control - 1);
            if (player == 3) player = 2;
            RAM8(DP_INPUT_FLAGS + player) |= 0x80;
        }
    }

done:
    r->a = (uint16_t)((a_hi << 8) | (r->a & 0xFF));
    RETURN_RTL(c);
}
SOM_REGISTER(0xC8E6D4, SOM_RTL, "hand", apply_spell_hit_to_actor, 0, L_B, 16, 1, 0, 301, 134)

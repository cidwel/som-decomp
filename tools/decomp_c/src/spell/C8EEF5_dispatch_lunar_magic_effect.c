#include "som_c.h"

/* C8EEF5 dispatch_lunar_magic_effect   [class C, 36 bytes, 17 instructions]
 * Source: src/rom/dispatch_lunar_magic_effect.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void dispatch_lunar_magic_effect(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    r->x = RAM16(BATTLE_DEFENDER_PTR);
    { const uint16_t sp_call = r->sp; JSR(c, 0xEEF9, 0xC8E8A0); GUARD_JSR(c, sp_call, 0xEEF9); } /* select_spell_element_multiplier */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEEFC, 0xC8E8C0); GUARD_JSR(c, sp_call, 0xEEFC); } /* calculate_spell_attack_roll */
    uint16_t a_all2 = r->a;
    r->a = (a_all2 >> 8 << 8) | 8;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEF02, 0xC03884); GUARD_JSL(c, sp_call, 0xEF02); } /* random_below_long_wrapper */
    uint16_t a_all3 = r->a;
    RAM8(0x0000 + sp0) = a_all3 & 0x0F;
    r->a = a_all3 & 0x0F;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEF0E, 0xC05BA4); GUARD_JSL(c, sp_call, 0xEF0E); } /* enqueue_lunar_magic_effect_notice */
    r->sp += 1;
    bool x_ret5 = r->xf;
    uint16_t y_ret4 = r->y;
    uint8_t value = RAM8(0x0000 + sp0);
    if (x_ret5) {
        r->a = (uint8_t)(value << 1);
        r->x = (uint8_t)(value << 1);
        r->y = (uint8_t)y_ret4;
        r->c = value & 0x80;
        r->z = (uint8_t)(value << 1) == 0;
        r->n = (uint8_t)(value << 1) & 0x80;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp;
        switch ((uint8_t)(value << 1)) {
        case 0x0000: JSR(c, 0xEF17, 0xC8EF2B); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_heal_all_living_actors */
        case 0x0002: JSR(c, 0xEF17, 0xC8EF48); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_buff_target */
        case 0x0004: JSR(c, 0xEF17, 0xC8EF5E); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_debuff_target */
        case 0x0006: JSR(c, 0xEF17, 0xC8EF74); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_silence_all_actors */
        case 0x0008: JSR(c, 0xEF17, 0xC8EF8A); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_set_status_1000_all_actors */
        case 0x000A: JSR(c, 0xEF17, 0xC8EFA0); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_set_status_0200_heroes */
        case 0x000C: JSR(c, 0xEF17, 0xC8EFB6); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_set_status_0800_monsters */
        case 0x000E: JSR(c, 0xEF17, 0xC8EFD0); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_sleep_all_actors */
        case 0x0010: JSR(c, 0xEF17, 0xC8EFE6); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_halve_caster_maximum_mp */
        default: JSR(c, 0xEF17, 0xC80000 | BUS16(c, 0xC80000 + (uint16_t)(0xEF19 + ((uint8_t)(value << 1))))); GUARD_JSR(c, sp_call, 0xEF17);
        }
        }
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        r->a = (uint8_t)(value << 1);
        r->x = (uint8_t)(value << 1);
        r->c = value & 0x80;
        r->z = (uint8_t)(value << 1) == 0;
        r->n = (uint8_t)(value << 1) & 0x8000;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp;
        switch ((uint8_t)(value << 1)) {
        case 0x0000: JSR(c, 0xEF17, 0xC8EF2B); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_heal_all_living_actors */
        case 0x0002: JSR(c, 0xEF17, 0xC8EF48); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_buff_target */
        case 0x0004: JSR(c, 0xEF17, 0xC8EF5E); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_debuff_target */
        case 0x0006: JSR(c, 0xEF17, 0xC8EF74); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_silence_all_actors */
        case 0x0008: JSR(c, 0xEF17, 0xC8EF8A); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_set_status_1000_all_actors */
        case 0x000A: JSR(c, 0xEF17, 0xC8EFA0); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_set_status_0200_heroes */
        case 0x000C: JSR(c, 0xEF17, 0xC8EFB6); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_set_status_0800_monsters */
        case 0x000E: JSR(c, 0xEF17, 0xC8EFD0); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_sleep_all_actors */
        case 0x0010: JSR(c, 0xEF17, 0xC8EFE6); GUARD_JSR(c, sp_call, 0xEF17); break; /* lunar_halve_caster_maximum_mp */
        default: JSR(c, 0xEF17, 0xC80000 | BUS16(c, 0xC80000 + (uint16_t)(0xEF19 + ((uint8_t)(value << 1))))); GUARD_JSR(c, sp_call, 0xEF17);
        }
        }
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC8EEF5, SOM_RTS, "gen", dispatch_lunar_magic_effect, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 36, 17)

#include "som_c.h"
#include "som_hand_b.h"

/* C8E0B0 open_chest_and_select_reward_or_existing_notice   [class B, 124 bytes, 60 instructions]
 * Source: src/rom/open_chest_and_select_reward_or_existing_notice.s
 * Documented in docs/event-vm-chest-reward.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: nothing.
 */
static void open_chest_and_select_reward_or_existing_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    i_phd(c);
    i_phb(c);
    i_php(c);
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    i_pha(c);
    r->dp = 0x0300; /* LDA #$0300, TCD */
    i_pla(c);
    RAM16_SET(BATTLE_ATTACKER_PTR, r->a);
    RAM16_SET(BATTLE_DEFENDER_PTR, r->x);
    r->y = r->a;
    r->mf = 1; /* SEP #$20 */
    const uint32_t bank = (uint32_t)r->db << 16;
    const uint16_t attacker = r->y;
    const uint16_t defender = r->x;
    uint8_t status, busy, multiplier;
    BUS8_OK(c, bank + 0xE190 + attacker, status);
    BUS8_SET(c, bank + 0xE190 + attacker, status | 0x01);
    BUS8_SET(c, bank + 0xE1B4 + attacker, 0x02);
    BUS8_OK(c, bank + 0xE1FB + attacker, status);
    BUS8_SET(c, bank + 0xE1FB + attacker, status | 0x06);
    BUS8_SET(c, bank + 0xE1F0 + attacker, RAM8(0x0386) >> 1);
    BUS8_OK(c, bank + 0xE184 + defender, busy);
    r->a = (r->a & 0xFF00) | busy;
    i_pha(c);
    BUS8_OK(c, bank + 0xE1CA + defender, multiplier);
    BUS8_SET(c, 0x004202, multiplier);
    BUS8_SET(c, 0x004203, 5);
    r->mf = 0;
    r->x = BUS16(c, 0x004216); /* the product of the two writes above */
    r->mf = 1;
    i_pla(c);
    if ((r->a & 0xFF) == 0) {
        uint8_t table, level;
        BUS8_OK(c, 0xD03A51u + r->x, table);
        uint8_t roll_limit = (uint8_t)((table & 0xF0) >> 1);
        BUS8_OK(c, bank + 0xE189 + attacker, level);
        if (roll_limit >= level) {
            r->a = (r->a & 0xFF00) | roll_limit;
            r->c = 1;
            JSL_CHK(c, 0xE11D, 0xC0389C); /* random_byte_long_wrapper */
            if ((r->a & 1) == 0) {
                r->x = RAM16(BATTLE_DEFENDER_PTR);
                JSL_CHK(c, 0xE127, 0xC05907); /* publish_existing_chest_class_notice */
                goto leave;
            }
        }
    }
    {
        i_phx(c);
        uint16_t slot = RAM16(0x0385);
        BUS8_SET(c, bank + 0xE1C8 + slot, 0);
        r->a = (r->a & 0xFF00) | 0xFF;
        BUS8_SET(c, bank + 0xE183 + slot, 0xFF);
        i_plx(c);
        JSR_CHK(c, 0xE117, 0xC8E12C); /* select_chest_gold_item_or_weapon_orb_and_publish */
    }
leave:
    hand_plp(c);
    hand_plb(c);
    hand_pld(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC8E0B0, SOM_RTL, "hand", open_chest_and_select_reward_or_existing_notice, 0, 0, 6, -1, 0, 124, 60)

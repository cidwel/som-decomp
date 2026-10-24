#include "som_c.h"

/* C20F27 resolve_boss_contacts_combat_and_publish_counter_request   [class B, 50 bytes, 21 instructions]
 * Source: src/rom/resolve_boss_contacts_combat_and_publish_counter_request.s
 * Documented in docs/rom-combat.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void resolve_boss_contacts_combat_and_publish_counter_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    JSR(c, 0x0F2B, 0xC2058F); /* mark_boss_secondary_contact_in_party_and_boss_masks */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x0F2E, 0xC2052E); /* mark_boss_primary_contact_in_party_and_boss_masks */
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    JSL(c, 0x0F32, 0xC0002D); /* actor_combat_tick_public_jump */
    uint16_t a_all3 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret3 = r->y;
    RAM16_SET(0x0256, a_all3);
    if ((a_all3 & 0xFF) == 0) {
        r->a = a_all3 & 0xFF;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        RETURN_RTS(c);
    }
    if ((a_all3 & 0xFF) == 1) {
        RAM16_SET(0x0246, x_ret3);
        RAM16_SET(0x024E, y_ret3);
        uint16_t value2 = RAM16(0x0287);
        uint16_t value3 = RAM16(0x0246);
        r->a = value3;
        r->x = value2 & 0x1FFF;
        r->c = (a_all3 & 0xFF) >= 1;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSL(c, 0x0F57, 0xC18015); /* external */
        r->db = 0x7E;
        r->dp = 0x0200;
        RETURN_RTS(c);
    }
    if ((a_all3 & 0xFF) != 2) {
        r->a = a_all3 & 0xFF;
        r->c = (a_all3 & 0xFF) >= 2;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        RETURN_RTS(c);
    }
    r->a = a_all3 & 0xFF;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    JSR(c, 0x0F46, 0xC20F59); /* apply_boss_contact_class_eight_or_nine_control_reaction */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20F27, SOM_RTS, "hand", resolve_boss_contacts_combat_and_publish_counter_request, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 50, 21)

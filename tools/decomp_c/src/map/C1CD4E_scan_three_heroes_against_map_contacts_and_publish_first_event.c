#include "som_c.h"

/* C1CD4E scan_three_heroes_against_map_contacts_and_publish_first_event   [class B, 127 bytes, 57 instructions]
 * Source: src/rom/scan_three_heroes_against_map_contacts_and_publish_first_event.s
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: ABYCV.
 */
static void scan_three_heroes_against_map_contacts_and_publish_first_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t db = r->db;
    RAM16_SET(0x0018, RAM16(0x00C0) >> 1);
    uint16_t value2 = RAM16(0x00C2);
    RAM16_SET(0x001A, value2 >> 1);
    RAM16_SET(0x000E, 0);
    uint8_t value3 = RAM8(0x00FF);
    if (value3 & 0x80) {
        r->a = value2 >> 1;
        r->c = value2 & 0x01;
        r->v = value3 & 0x40;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (value3 & 0x40) {
        r->a = value2 >> 1;
        r->c = value2 & 0x01;
        r->v = value3 & 0x40;
        r->xf = 0;
        RETURN_RTL(c);
    }
    uint8_t value4 = RAM8(0x00F1);
    if (value4 & 0x80) {
        r->a = value2 >> 1;
        r->c = value2 & 0x01;
        r->v = value4 & 0x40;
        r->xf = 0;
        RETURN_RTL(c);
    }
    uint8_t value5 = RAM8(0x005C);
    if (value5 & 0x80) {
        r->a = value2 >> 1;
        r->c = value2 & 0x01;
        r->z = ((uint8_t)(value2 >> 1) & value5) == 0;
        r->n = value5 & 0x80;
        r->v = value5 & 0x40;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCD71, 0xC20015); GUARD_JSL(c, sp_call, 0xCD71); } /* public_three_boss_party_contact_jump */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xCF01);
    if (value6 & 0x01) {
        r->a = (value2 >> 1 >> 8 << 8) | (value6 >> 1);
        r->c = value6 & 0x01;
        r->v = value5 & 0x40;
        r->xf = 0;
        RETURN_RTL(c);
    }
    RAM8(0x0051) = 0x11;
    r->a = (value2 >> 1 >> 8 << 8) | 0x11;
    r->x = 0;
    r->c = value6 & 0x01;
    r->z = 1;
    r->n = 0;
    r->v = value5 & 0x40;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD82, 0xC1CDCD); GUARD_JSR(c, sp_call, 0xCD82); } /* scan_active_map_contact_pool_for_one_hero */
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0200;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD88, 0xC1CDCD); GUARD_JSR(c, sp_call, 0xCD88); } /* scan_active_map_contact_pool_for_one_hero */
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0400;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD8E, 0xC1CDCD); GUARD_JSR(c, sp_call, 0xCD8E); } /* scan_active_map_contact_pool_for_one_hero */
    bool x_ret3 = r->xf;
    uint8_t value7 = RAM8(0x00D0);
    if (value7 != 0) {
        SET_A8(r, value7);
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    if (x_ret3) {
        uint8_t value8 = RAM8(0x000E);
        if (value8 == 0) {
            SET_A8(r, value7);
            r->y = value8;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTL(c);
        }
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        uint16_t value9 = RAM16(0x000E);
        if (value9 == 0) {
            SET_A8(r, value7);
            r->y = value9;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint16_t value10 = RAM16(0x001C);
        uint16_t value11 = RAM16(0x001E);
        RAM16_SET(0x00D4, value10);
        RAM16_SET(0x003A, value11);
        if (value9 >= 0x8000) {
            r->a = value9 & 0x0FFF;
            r->x = value10;
            r->y = value11;
            r->c = value9 >= 0x8000;
            r->z = (value9 & 0x0FFF) == 0;
            r->n = value9 & 0x0FFF & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xCDCB, 0x01E76D); GUARD_JSL(c, sp_call, 0xCDCB); } /* event_command_map_context_entry */
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
        uint8_t value12 = BUS8_RDP(c, (db << 0x10) + 0xE010 + value10);
        uint8_t a1;
        if (value12 < 2) {
            a1 = value12 ^ 1;
        } else {
            a1 = value12 ^ 0x80;
        }
        BUS8_SET(c, (db << 0x10) + 0xE010 + value11, a1);
        BUS16_SET(c, (db << 0x10) + 0xE006 + value11, 0);
        BUS16_SET(c, (db << 0x10) + 0xE008 + value11, 0);
        uint16_t value13 = RAM16(0x000E);
        r->a = value13 & 0x0FFF;
        r->x = value10;
        r->y = value11;
        r->c = value12 >= 2;
        r->z = (value13 & 0x0FFF) == 0;
        r->n = value13 & 0x0FFF & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xCDCB, 0x01E76D); GUARD_JSL(c, sp_call, 0xCDCB); } /* event_command_map_context_entry */
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xC1CD4E, SOM_RTL, "gen", scan_three_heroes_against_map_contacts_and_publish_first_event, 0, L_A | L_B | L_Y | L_C | L_V, 1, 1, 1, 127, 57)

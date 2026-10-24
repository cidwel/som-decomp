#include "som_c.h"

/* C12F5E service_complete_spell_entity_irq   [class D, 134 bytes, 57 instructions]
 * Source: src/rom/service_complete_spell_entity_irq.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$01B4.  Callers read: ABXYCZNV.
 */
static void service_complete_spell_entity_irq(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xB4;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 5) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = a >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 6) = x >> 8;
    RAM8(0x0000 + sp0 - 7) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 8) = y >> 8;
    RAM8(0x0000 + sp0 - 9) = (uint8_t)y;
    BUS8_SET(c, 0x00212C, RAM8(0x0021));
    BUS8_SET(c, 0x00212D, RAM8(0x0022));
    BUS8_SET(c, 0x002105, RAM8(0x0029));
    if (RAM8(0x822A) == 0) {
        RETURN_RTI(c);
    }
    if (RAM8(0x8230) != 0) {
        RAM8(0x8230)++;
        RETURN_RTI(c);
    }
    uint8_t value6 = BUS8(c, 0x004210);
    RAM8(0x00EC) = 0;
    BUS8_SET(c, 0x002100, 0x80);
    r->a = (a >> 8 << 8) | 0x80;
    r->z = 0;
    r->n = 1;
    r->mf = 1;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FA6, 0xC12A1E); GUARD_JSR(c, sp_call, 0x2FA6); } /* service_pending_spell_entity_transfer_requests */
    r->sp += 10;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FA9, 0xC12A80); GUARD_JSR(c, sp_call, 0x2FA9); } /* drain_spell_entity_transfer_queue_to_ppu */
    r->sp += 10;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FAC, 0xC1453C); GUARD_JSR(c, sp_call, 0x2FAC); } /* publish_spell_entity_linked_registers_to_ppu */
    r->sp += 10;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    BUS8_SET(c, 0x002100, 0x0F);
    r->a = (a_all3 >> 8 << 8) | 0x0F;
    r->z = 0;
    r->n = 0;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FB5, 0xC12B80); GUARD_JSR(c, sp_call, 0x2FB5); } /* retire_completed_spell_entity_transfers */
    r->sp += 10;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FB8, 0xC145E0); GUARD_JSR(c, sp_call, 0x2FB8); } /* commit_spell_entity_register_shadows_and_recycle_transients */
    r->sp += 10;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FBB, 0xC1412A); GUARD_JSR(c, sp_call, 0x2FBB); } /* queue_spell_entity_oam_transfer */
    r->sp += 10;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all6 = r->a;
    r->a = (a_all6 >> 8 << 8) | 2;
    r->z = 0;
    r->n = 0;
    r->sp -= 10;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FC0, 0xC12896); GUARD_JSR(c, sp_call, 0x2FC0); } /* allocate_spell_entity_actor_slot */
    r->sp += 10;
    uint8_t db_ret6 = r->db;
    bool m_ret5 = r->mf;
    uint16_t x_ret14 = r->x;
    if (m_ret5) {
        BUS8_SET(c, (db_ret6 << 0x10) + 4 + x_ret14, 0);
        BUS8_SET(c, (db_ret6 << 0x10) + 0x0A + x_ret14, 0);
        BUS16_SET(c, (db_ret6 << 0x10) + 2 + x_ret14, 0x0600);
        BUS16_SET(c, (db_ret6 << 0x10) + 5 + x_ret14, 0x18);
        r->a = 0x18;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2FD7, 0xC12997); GUARD_JSR(c, sp_call, 0x2FD7); } /* publish_spell_entity_record_or_dma_channel */
        r->sp += 10;
        uint8_t db_ret7 = r->db;
        bool m_ret6 = r->mf;
        bool x_ret15 = r->xf;
        if (m_ret6) {
            uint8_t value7 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x8230);
            BUS8_SET(c, (db_ret7 << 0x10) + 0x8230, (uint8_t)(value7 + 1));
            if (x_ret15) {
                c->fail = 3;
                return;
            } else {
                uint8_t value16 = RAM8(0x0000 + sp0 - 9);
                uint8_t value17 = RAM8(0x0000 + sp0 - 8);
                uint8_t value18 = RAM8(0x0000 + sp0 - 7);
                uint8_t value19 = RAM8(0x0000 + sp0 - 6);
                uint8_t value20 = RAM8(0x0000 + sp0 - 5);
                uint8_t value21 = RAM8(0x0000 + sp0 - 4);
                uint8_t value22 = RAM8(0x0000 + sp0 - 3);
                uint8_t value24 = RAM8(0x0000 + sp0 - 1);
                uint8_t value25 = RAM8(0x0000 + sp0);
                r->a = (value21 << 8) | value20;
                r->x = (value19 << 8) | value18;
                r->y = (value17 << 8) | value16;
                r->db = value22;
                r->dp = (value25 << 8) | value24;
                RETURN_RTI(c);
            }
        } else {
            uint16_t value26 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x8230);
            BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x8230, (uint16_t)(value26 + 1));
            if (x_ret15) {
                c->fail = 3;
                return;
            } else {
                uint8_t value35 = RAM8(0x0000 + sp0 - 9);
                uint8_t value36 = RAM8(0x0000 + sp0 - 8);
                uint8_t value37 = RAM8(0x0000 + sp0 - 7);
                uint8_t value38 = RAM8(0x0000 + sp0 - 6);
                uint8_t value39 = RAM8(0x0000 + sp0 - 5);
                uint8_t value40 = RAM8(0x0000 + sp0 - 4);
                uint8_t value41 = RAM8(0x0000 + sp0 - 3);
                uint8_t value43 = RAM8(0x0000 + sp0 - 1);
                uint8_t value44 = RAM8(0x0000 + sp0);
                r->a = (value40 << 8) | value39;
                r->x = (value38 << 8) | value37;
                r->y = (value36 << 8) | value35;
                r->db = value41;
                r->dp = (value44 << 8) | value43;
                RETURN_RTI(c);
            }
        }
    } else {
        BUS16_SET(c, (db_ret6 << 0x10) + 4 + x_ret14, 0);
        BUS16_SET(c, (db_ret6 << 0x10) + 0x0A + x_ret14, 0);
        BUS16_SET(c, (db_ret6 << 0x10) + 2 + x_ret14, 0x0600);
        BUS16_SET(c, (db_ret6 << 0x10) + 5 + x_ret14, 0x18);
        r->a = 0x18;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2FD7, 0xC12997); GUARD_JSR(c, sp_call, 0x2FD7); } /* publish_spell_entity_record_or_dma_channel */
        r->sp += 10;
        uint8_t db_ret8 = r->db;
        bool m_ret7 = r->mf;
        bool x_ret17 = r->xf;
        if (m_ret7) {
            uint8_t value45 = BUS8_RDP(c, (db_ret8 << 0x10) + 0x8230);
            BUS8_SET(c, (db_ret8 << 0x10) + 0x8230, (uint8_t)(value45 + 1));
            if (x_ret17) {
                c->fail = 3;
                return;
            } else {
                uint8_t value54 = RAM8(0x0000 + sp0 - 9);
                uint8_t value55 = RAM8(0x0000 + sp0 - 8);
                uint8_t value56 = RAM8(0x0000 + sp0 - 7);
                uint8_t value57 = RAM8(0x0000 + sp0 - 6);
                uint8_t value58 = RAM8(0x0000 + sp0 - 5);
                uint8_t value59 = RAM8(0x0000 + sp0 - 4);
                uint8_t value60 = RAM8(0x0000 + sp0 - 3);
                uint8_t value62 = RAM8(0x0000 + sp0 - 1);
                uint8_t value63 = RAM8(0x0000 + sp0);
                r->a = (value59 << 8) | value58;
                r->x = (value57 << 8) | value56;
                r->y = (value55 << 8) | value54;
                r->db = value60;
                r->dp = (value63 << 8) | value62;
                RETURN_RTI(c);
            }
        } else {
            uint16_t value64 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x8230);
            BUS16_RMW_SET(c, (db_ret8 << 0x10) + 0x8230, (uint16_t)(value64 + 1));
            if (x_ret17) {
                c->fail = 3;
                return;
            } else {
                uint8_t value73 = RAM8(0x0000 + sp0 - 9);
                uint8_t value74 = RAM8(0x0000 + sp0 - 8);
                uint8_t value75 = RAM8(0x0000 + sp0 - 7);
                uint8_t value76 = RAM8(0x0000 + sp0 - 6);
                uint8_t value77 = RAM8(0x0000 + sp0 - 5);
                uint8_t value78 = RAM8(0x0000 + sp0 - 4);
                uint8_t value79 = RAM8(0x0000 + sp0 - 3);
                uint8_t value81 = RAM8(0x0000 + sp0 - 1);
                uint8_t value82 = RAM8(0x0000 + sp0);
                r->a = (value78 << 8) | value77;
                r->x = (value76 << 8) | value75;
                r->y = (value74 << 8) | value73;
                r->db = value79;
                r->dp = (value82 << 8) | value81;
                RETURN_RTI(c);
            }
        }
    }
}
SOM_REGISTER(0xC12F5E, SOM_RTI, "gen", service_complete_spell_entity_irq, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 10, 0, 0, 134, 57)

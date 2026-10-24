#include "som_c.h"

/* C013FD publish_dialogue_tile_pair_and_advance_cursor   [class B, 52 bytes, 22 instructions]
 * Source: src/rom/publish_dialogue_tile_pair_and_advance_cursor.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void publish_dialogue_tile_pair_and_advance_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA157) = RAM8(0xA17D);
    uint8_t value2 = RAM8(0xA17C);
    RAM8(0xA156) = value2;
    uint16_t value3 = RAM16(0xA17E);
    RAM8(0x0000 + sp0) = value3 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value3;
    r->a = (a_hi << 8) | value2;
    r->x = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x140F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x140F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    r->sp += 2;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        if (m_ret) {
            uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret << 0x10) + 0xA156, (uint8_t)(value5 + 1));
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(value4 + 1);
            r->x = (uint8_t)(value4 + 1);
            r->y = (uint8_t)y_ret;
            r->z = (uint8_t)(value5 + 1) == 0;
            r->n = (uint8_t)(value5 + 1) & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1418, 0xC01BC0); GUARD_JSR(c, sp_call, 0x1418); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint8_t db_ret2 = r->db;
            bool m_ret2 = r->mf;
            bool x_ret3 = r->xf;
            if (x_ret3) {
                c->fail = 3;
                return;
            } else {
                uint8_t value15 = RAM8(0x0000 + sp0 - 1);
                uint8_t value16 = RAM8(0x0000 + sp0);
                if (m_ret2) {
                    uint8_t value17 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0xA156, (uint8_t)(value17 - 1));
                    uint8_t value18 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0xA157, (uint8_t)(value18 + 1));
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xA17E, (uint16_t)(((value16 << 8) | value15) + 1));
                    uint8_t value19 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0xA17D, value19);
                    uint8_t value20 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret2 << 0x10) + 0xA17C, value20);
                    r->x = (uint16_t)(((value16 << 8) | value15) + 1);
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                } else {
                    uint16_t value21 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA156);
                    BUS16_RMW_SET(c, (db_ret2 << 0x10) + 0xA156, (uint16_t)(value21 - 1));
                    uint16_t value22 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA157);
                    BUS16_RMW_SET(c, (db_ret2 << 0x10) + 0xA157, (uint16_t)(value22 + 1));
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xA17E, (uint16_t)(((value16 << 8) | value15) + 1));
                    uint16_t value23 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA157);
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xA17D, value23);
                    uint16_t value24 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA156);
                    BUS16_SET(c, (db_ret2 << 0x10) + 0xA17C, value24);
                    r->a = value24;
                    r->x = (uint16_t)(((value16 << 8) | value15) + 1);
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
        } else {
            uint16_t value25 = BUS16_RDP(c, (db_ret << 0x10) + 0xA156);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0xA156, (uint16_t)(value25 + 1));
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(value4 + 1);
            r->x = (uint8_t)(value4 + 1);
            r->y = (uint8_t)y_ret;
            r->z = (uint16_t)(value25 + 1) == 0;
            r->n = (uint16_t)(value25 + 1) & 0x8000;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1418, 0xC01BC0); GUARD_JSR(c, sp_call, 0x1418); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint8_t db_ret3 = r->db;
            bool m_ret3 = r->mf;
            bool x_ret5 = r->xf;
            if (x_ret5) {
                c->fail = 3;
                return;
            } else {
                uint8_t value35 = RAM8(0x0000 + sp0 - 1);
                uint8_t value36 = RAM8(0x0000 + sp0);
                if (m_ret3) {
                    uint8_t value37 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0xA156, (uint8_t)(value37 - 1));
                    uint8_t value38 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0xA157, (uint8_t)(value38 + 1));
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xA17E, (uint16_t)(((value36 << 8) | value35) + 1));
                    uint8_t value39 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0xA17D, value39);
                    uint8_t value40 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret3 << 0x10) + 0xA17C, value40);
                    r->x = (uint16_t)(((value36 << 8) | value35) + 1);
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                } else {
                    uint16_t value41 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA156);
                    BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA156, (uint16_t)(value41 - 1));
                    uint16_t value42 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA157);
                    BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA157, (uint16_t)(value42 + 1));
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xA17E, (uint16_t)(((value36 << 8) | value35) + 1));
                    uint16_t value43 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA157);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xA17D, value43);
                    uint16_t value44 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA156);
                    BUS16_SET(c, (db_ret3 << 0x10) + 0xA17C, value44);
                    r->a = value44;
                    r->x = (uint16_t)(((value36 << 8) | value35) + 1);
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
        }
    } else {
        uint8_t value45 = RAM8(0x0000 + sp0 - 1);
        uint8_t value46 = RAM8(0x0000 + sp0);
        if (m_ret) {
            uint8_t value47 = BUS8_RDP(c, (db_ret << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret << 0x10) + 0xA156, (uint8_t)(value47 + 1));
            RAM8(0x0000 + sp0) = (uint16_t)(((value46 << 8) | value45) + 1) >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(((value46 << 8) | value45) + 1);
            r->x = (uint16_t)(((value46 << 8) | value45) + 1);
            r->z = (uint8_t)(value47 + 1) == 0;
            r->n = (uint8_t)(value47 + 1) & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1418, 0xC01BC0); GUARD_JSR(c, sp_call, 0x1418); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint8_t db_ret4 = r->db;
            bool m_ret4 = r->mf;
            bool x_ret7 = r->xf;
            if (x_ret7) {
                c->fail = 3;
                return;
            } else {
                uint8_t value57 = RAM8(0x0000 + sp0 - 1);
                uint8_t value58 = RAM8(0x0000 + sp0);
                if (m_ret4) {
                    uint8_t value59 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, (uint8_t)(value59 - 1));
                    uint8_t value60 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret4 << 0x10) + 0xA157, (uint8_t)(value60 + 1));
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xA17E, (uint16_t)(((value58 << 8) | value57) + 1));
                    uint8_t value61 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret4 << 0x10) + 0xA17D, value61);
                    uint8_t value62 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret4 << 0x10) + 0xA17C, value62);
                    r->x = (uint16_t)(((value58 << 8) | value57) + 1);
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                } else {
                    uint16_t value63 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA156);
                    BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0xA156, (uint16_t)(value63 - 1));
                    uint16_t value64 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA157);
                    BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0xA157, (uint16_t)(value64 + 1));
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xA17E, (uint16_t)(((value58 << 8) | value57) + 1));
                    uint16_t value65 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA157);
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xA17D, value65);
                    uint16_t value66 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA156);
                    BUS16_SET(c, (db_ret4 << 0x10) + 0xA17C, value66);
                    r->a = value66;
                    r->x = (uint16_t)(((value58 << 8) | value57) + 1);
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
        } else {
            uint16_t value67 = BUS16_RDP(c, (db_ret << 0x10) + 0xA156);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0xA156, (uint16_t)(value67 + 1));
            RAM8(0x0000 + sp0) = (uint16_t)(((value46 << 8) | value45) + 1) >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(((value46 << 8) | value45) + 1);
            r->x = (uint16_t)(((value46 << 8) | value45) + 1);
            r->z = (uint16_t)(value67 + 1) == 0;
            r->n = (uint16_t)(value67 + 1) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1418, 0xC01BC0); GUARD_JSR(c, sp_call, 0x1418); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            r->sp += 2;
            uint8_t db_ret5 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret9 = r->xf;
            if (x_ret9) {
                c->fail = 3;
                return;
            } else {
                uint8_t value77 = RAM8(0x0000 + sp0 - 1);
                uint8_t value78 = RAM8(0x0000 + sp0);
                if (m_ret5) {
                    uint8_t value79 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA156, (uint8_t)(value79 - 1));
                    uint8_t value80 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA157, (uint8_t)(value80 + 1));
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xA17E, (uint16_t)(((value78 << 8) | value77) + 1));
                    uint8_t value81 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA157);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA17D, value81);
                    uint8_t value82 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA156);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA17C, value82);
                    r->x = (uint16_t)(((value78 << 8) | value77) + 1);
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                } else {
                    uint16_t value83 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA156);
                    BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0xA156, (uint16_t)(value83 - 1));
                    uint16_t value84 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA157);
                    BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0xA157, (uint16_t)(value84 + 1));
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xA17E, (uint16_t)(((value78 << 8) | value77) + 1));
                    uint16_t value85 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA157);
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xA17D, value85);
                    uint16_t value86 = BUS16_RDP(c, (db_ret5 << 0x10) + 0xA156);
                    BUS16_SET(c, (db_ret5 << 0x10) + 0xA17C, value86);
                    r->a = value86;
                    r->x = (uint16_t)(((value78 << 8) | value77) + 1);
                    r->mf = 0;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
        }
    }
}
SOM_REGISTER(0xC013FD, SOM_RTS, "gen", publish_dialogue_tile_pair_and_advance_cursor, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 52, 22)

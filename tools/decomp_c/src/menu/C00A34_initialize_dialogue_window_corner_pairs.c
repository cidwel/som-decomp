#include "som_c.h"

/* C00A34 initialize_dialogue_window_corner_pairs   [class B, 89 bytes, 34 instructions]
 * Source: src/rom/initialize_dialogue_window_corner_pairs.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_dialogue_window_corner_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x0A36, 0xC00D8B); GUARD_JSR(c, sp_call, 0x0A36); } /* select_dialogue_window_geometry_from_state */
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    BUS8_SET(c, (db_ret << 0x10) + 0xA157, (uint8_t)a_all);
    BUS8_SET(c, (db_ret << 0x10) + 0xA166, (uint8_t)a_all);
    BUS8_SET(c, (db_ret << 0x10) + 0xA168, (uint8_t)((uint8_t)a_all + 1));
    BUS8_SET(c, (db_ret << 0x10) + 0xA156, a_all >> 8);
    BUS8_SET(c, (db_ret << 0x10) + 0xA165, a_all >> 8);
    BUS8_SET(c, (db_ret << 0x10) + 0xA167, (uint8_t)((a_all >> 8) + 1));
    r->a = ((uint8_t)((uint8_t)a_all + 1) << 8) | (uint8_t)((a_all >> 8) + 1);
    r->x = 0x0120;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0A51, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A51); } /* exchange_dialogue_tilemap_entry_and_request_upload */
    uint8_t db_ret2 = r->db;
    bool m_ret = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    if (m_ret) {
        uint8_t value = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA156);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA156, (uint8_t)(value + 1));
        r->x = 0x8120;
        r->z = 0;
        r->n = 1;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0A5A, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A5A); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        uint8_t db_ret3 = r->db;
        bool m_ret2 = r->mf;
        if (r->xf != 0) { c->fail = 3; return; }
        if (m_ret2) {
            uint8_t value2 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret3 << 0x10) + 0xA156, (uint8_t)(value2 - 1));
            uint8_t value3 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret3 << 0x10) + 0xA157, (uint8_t)(value3 + 1));
            r->x = 0x4120;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0A66, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A66); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            uint8_t db_ret4 = r->db;
            bool m_ret3 = r->mf;
            if (r->xf != 0) { c->fail = 3; return; }
            if (m_ret3) {
                uint8_t value4 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA156);
                BUS8_SET(c, (db_ret4 << 0x10) + 0xA156, (uint8_t)(value4 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret5 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value5 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, (uint8_t)(value5 + 1));
                uint8_t value6 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA162);
                uint8_t a1;
                bool zero1;
                bool negative1;
                if (value6 != 1) {
                    a1 = value6;
                    zero1 = value6 == 1;
                    negative1 = (uint8_t)(value6 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA15C, 3);
                    uint8_t value7 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA165, value7);
                    uint8_t value8 = BUS8_RDP(c, (db_ret5 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret5 << 0x10) + 0xA166, (uint8_t)(value8 - 1));
                    a1 = (uint8_t)(value8 - 1);
                    zero1 = (uint8_t)(value8 - 1) == 0;
                    negative1 = (uint8_t)(value8 - 1) & 0x80;
                }
                SET_A8(r, a1);
                r->c = value6 >= 1;
                r->z = zero1;
                r->n = negative1;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value9 = BUS16_RDP(c, (db_ret4 << 0x10) + 0xA156);
                BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0xA156, (uint16_t)(value9 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret6 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value10 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret6 << 0x10) + 0xA15C, (uint8_t)(value10 + 1));
                uint8_t value11 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA162);
                uint8_t a2;
                bool zero2;
                bool negative2;
                if (value11 != 1) {
                    a2 = value11;
                    zero2 = value11 == 1;
                    negative2 = (uint8_t)(value11 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret6 << 0x10) + 0xA15C, 3);
                    uint8_t value12 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret6 << 0x10) + 0xA165, value12);
                    uint8_t value13 = BUS8_RDP(c, (db_ret6 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret6 << 0x10) + 0xA166, (uint8_t)(value13 - 1));
                    a2 = (uint8_t)(value13 - 1);
                    zero2 = (uint8_t)(value13 - 1) == 0;
                    negative2 = (uint8_t)(value13 - 1) & 0x80;
                }
                SET_A8(r, a2);
                r->c = value11 >= 1;
                r->z = zero2;
                r->n = negative2;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value14 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA156);
            BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA156, (uint16_t)(value14 - 1));
            uint16_t value15 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xA157);
            BUS16_RMW_SET(c, (db_ret3 << 0x10) + 0xA157, (uint16_t)(value15 + 1));
            r->x = 0x4120;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0A66, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A66); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            uint8_t db_ret7 = r->db;
            bool m_ret4 = r->mf;
            if (r->xf != 0) { c->fail = 3; return; }
            if (m_ret4) {
                uint8_t value16 = BUS8_RDP(c, (db_ret7 << 0x10) + 0xA156);
                BUS8_SET(c, (db_ret7 << 0x10) + 0xA156, (uint8_t)(value16 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret8 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value17 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret8 << 0x10) + 0xA15C, (uint8_t)(value17 + 1));
                uint8_t value18 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA162);
                uint8_t a3;
                bool zero3;
                bool negative3;
                if (value18 != 1) {
                    a3 = value18;
                    zero3 = value18 == 1;
                    negative3 = (uint8_t)(value18 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret8 << 0x10) + 0xA15C, 3);
                    uint8_t value19 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret8 << 0x10) + 0xA165, value19);
                    uint8_t value20 = BUS8_RDP(c, (db_ret8 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret8 << 0x10) + 0xA166, (uint8_t)(value20 - 1));
                    a3 = (uint8_t)(value20 - 1);
                    zero3 = (uint8_t)(value20 - 1) == 0;
                    negative3 = (uint8_t)(value20 - 1) & 0x80;
                }
                SET_A8(r, a3);
                r->c = value18 >= 1;
                r->z = zero3;
                r->n = negative3;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value21 = BUS16_RDP(c, (db_ret7 << 0x10) + 0xA156);
                BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0xA156, (uint16_t)(value21 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret9 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value22 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret9 << 0x10) + 0xA15C, (uint8_t)(value22 + 1));
                uint8_t value23 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA162);
                uint8_t a4;
                bool zero4;
                bool negative4;
                if (value23 != 1) {
                    a4 = value23;
                    zero4 = value23 == 1;
                    negative4 = (uint8_t)(value23 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret9 << 0x10) + 0xA15C, 3);
                    uint8_t value24 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret9 << 0x10) + 0xA165, value24);
                    uint8_t value25 = BUS8_RDP(c, (db_ret9 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret9 << 0x10) + 0xA166, (uint8_t)(value25 - 1));
                    a4 = (uint8_t)(value25 - 1);
                    zero4 = (uint8_t)(value25 - 1) == 0;
                    negative4 = (uint8_t)(value25 - 1) & 0x80;
                }
                SET_A8(r, a4);
                r->c = value23 >= 1;
                r->z = zero4;
                r->n = negative4;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    } else {
        uint16_t value26 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA156);
        BUS16_RMW_SET(c, (db_ret2 << 0x10) + 0xA156, (uint16_t)(value26 + 1));
        r->x = 0x8120;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0A5A, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A5A); } /* exchange_dialogue_tilemap_entry_and_request_upload */
        uint8_t db_ret10 = r->db;
        bool m_ret5 = r->mf;
        if (r->xf != 0) { c->fail = 3; return; }
        if (m_ret5) {
            uint8_t value27 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA156);
            BUS8_SET(c, (db_ret10 << 0x10) + 0xA156, (uint8_t)(value27 - 1));
            uint8_t value28 = BUS8_RDP(c, (db_ret10 << 0x10) + 0xA157);
            BUS8_SET(c, (db_ret10 << 0x10) + 0xA157, (uint8_t)(value28 + 1));
            r->x = 0x4120;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0A66, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A66); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            uint8_t db_ret11 = r->db;
            bool m_ret6 = r->mf;
            if (r->xf != 0) { c->fail = 3; return; }
            if (m_ret6) {
                uint8_t value29 = BUS8_RDP(c, (db_ret11 << 0x10) + 0xA156);
                BUS8_SET(c, (db_ret11 << 0x10) + 0xA156, (uint8_t)(value29 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret12 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value30 = BUS8_RDP(c, (db_ret12 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret12 << 0x10) + 0xA15C, (uint8_t)(value30 + 1));
                uint8_t value31 = BUS8_RDP(c, (db_ret12 << 0x10) + 0xA162);
                uint8_t a5;
                bool zero5;
                bool negative5;
                if (value31 != 1) {
                    a5 = value31;
                    zero5 = value31 == 1;
                    negative5 = (uint8_t)(value31 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret12 << 0x10) + 0xA15C, 3);
                    uint8_t value32 = BUS8_RDP(c, (db_ret12 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret12 << 0x10) + 0xA165, value32);
                    uint8_t value33 = BUS8_RDP(c, (db_ret12 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret12 << 0x10) + 0xA166, (uint8_t)(value33 - 1));
                    a5 = (uint8_t)(value33 - 1);
                    zero5 = (uint8_t)(value33 - 1) == 0;
                    negative5 = (uint8_t)(value33 - 1) & 0x80;
                }
                SET_A8(r, a5);
                r->c = value31 >= 1;
                r->z = zero5;
                r->n = negative5;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value34 = BUS16_RDP(c, (db_ret11 << 0x10) + 0xA156);
                BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0xA156, (uint16_t)(value34 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret13 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value35 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret13 << 0x10) + 0xA15C, (uint8_t)(value35 + 1));
                uint8_t value36 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA162);
                uint8_t a6;
                bool zero6;
                bool negative6;
                if (value36 != 1) {
                    a6 = value36;
                    zero6 = value36 == 1;
                    negative6 = (uint8_t)(value36 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret13 << 0x10) + 0xA15C, 3);
                    uint8_t value37 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret13 << 0x10) + 0xA165, value37);
                    uint8_t value38 = BUS8_RDP(c, (db_ret13 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret13 << 0x10) + 0xA166, (uint8_t)(value38 - 1));
                    a6 = (uint8_t)(value38 - 1);
                    zero6 = (uint8_t)(value38 - 1) == 0;
                    negative6 = (uint8_t)(value38 - 1) & 0x80;
                }
                SET_A8(r, a6);
                r->c = value36 >= 1;
                r->z = zero6;
                r->n = negative6;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value39 = BUS16_RDP(c, (db_ret10 << 0x10) + 0xA156);
            BUS16_RMW_SET(c, (db_ret10 << 0x10) + 0xA156, (uint16_t)(value39 - 1));
            uint16_t value40 = BUS16_RDP(c, (db_ret10 << 0x10) + 0xA157);
            BUS16_RMW_SET(c, (db_ret10 << 0x10) + 0xA157, (uint16_t)(value40 + 1));
            r->x = 0x4120;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x0A66, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A66); } /* exchange_dialogue_tilemap_entry_and_request_upload */
            uint8_t db_ret14 = r->db;
            bool m_ret7 = r->mf;
            if (r->xf != 0) { c->fail = 3; return; }
            if (m_ret7) {
                uint8_t value41 = BUS8_RDP(c, (db_ret14 << 0x10) + 0xA156);
                BUS8_SET(c, (db_ret14 << 0x10) + 0xA156, (uint8_t)(value41 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret15 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value42 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret15 << 0x10) + 0xA15C, (uint8_t)(value42 + 1));
                uint8_t value43 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA162);
                uint8_t a7;
                bool zero7;
                bool negative7;
                if (value43 != 1) {
                    a7 = value43;
                    zero7 = value43 == 1;
                    negative7 = (uint8_t)(value43 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret15 << 0x10) + 0xA15C, 3);
                    uint8_t value44 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret15 << 0x10) + 0xA165, value44);
                    uint8_t value45 = BUS8_RDP(c, (db_ret15 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret15 << 0x10) + 0xA166, (uint8_t)(value45 - 1));
                    a7 = (uint8_t)(value45 - 1);
                    zero7 = (uint8_t)(value45 - 1) == 0;
                    negative7 = (uint8_t)(value45 - 1) & 0x80;
                }
                SET_A8(r, a7);
                r->c = value43 >= 1;
                r->z = zero7;
                r->n = negative7;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value46 = BUS16_RDP(c, (db_ret14 << 0x10) + 0xA156);
                BUS16_RMW_SET(c, (db_ret14 << 0x10) + 0xA156, (uint16_t)(value46 + 1));
                r->x = 0xC120;
                r->z = 0;
                r->n = 1;
                r->mf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x0A6F, 0xC01BC0); GUARD_JSR(c, sp_call, 0x0A6F); } /* exchange_dialogue_tilemap_entry_and_request_upload */
                uint8_t db_ret16 = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                uint8_t value47 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA15C);
                BUS8_SET(c, (db_ret16 << 0x10) + 0xA15C, (uint8_t)(value47 + 1));
                uint8_t value48 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA162);
                uint8_t a8;
                bool zero8;
                bool negative8;
                if (value48 != 1) {
                    a8 = value48;
                    zero8 = value48 == 1;
                    negative8 = (uint8_t)(value48 - 1) & 0x80;
                } else {
                    BUS8_SET(c, (db_ret16 << 0x10) + 0xA15C, 3);
                    uint8_t value49 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA196);
                    BUS8_SET(c, (db_ret16 << 0x10) + 0xA165, value49);
                    uint8_t value50 = BUS8_RDP(c, (db_ret16 << 0x10) + 0xA197);
                    BUS8_SET(c, (db_ret16 << 0x10) + 0xA166, (uint8_t)(value50 - 1));
                    a8 = (uint8_t)(value50 - 1);
                    zero8 = (uint8_t)(value50 - 1) == 0;
                    negative8 = (uint8_t)(value50 - 1) & 0x80;
                }
                SET_A8(r, a8);
                r->c = value48 >= 1;
                r->z = zero8;
                r->n = negative8;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0xC00A34, SOM_RTS, "gen", initialize_dialogue_window_corner_pairs, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 89, 34)

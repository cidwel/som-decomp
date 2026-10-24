#include "som_c.h"

/* C02443 execute_native_menu_page_record_commands   [class C, 76 bytes, 38 instructions]
 * Source: src/rom/execute_native_menu_page_record_commands.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void execute_native_menu_page_record_commands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xA20D);
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0xC7;
    uint16_t value2 = BUS16(c, 0xC70000 + (uint16_t)(value + 2));
    uint8_t a1 = 0xC7;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = (uint16_t)(value + 2);
    uint16_t y1 = value2;
    bool carry1 = carry;
    bool zero1 = value2 == 0;
    bool overflow1 = overflow;
    uint8_t data_bank = 0xC7;
    uint16_t direct_page = 0;
    for (;;) {
        RAM8(0xA20A) &= 0xF7;
        uint8_t value4 = BUS8_RDP(c, (data_bank << 0x10) + y1);
        if (value4 != 0) {
            RAM8(0x0000 + sp0 - 1) = value4;
            if ((value4 & 0x80) != 0) {
                RAM8(0xA20A) |= 0x18;
            }
            if ((value4 & 0x40) != 0) {
                RAM8(0x0000 + sp0 - 1) = value4;
                RAM8(0xA20A) |= 0x20;
            }
            r->a = (uint8_t)((uint8_t)((value4 & 0x1F) - 1) << 1);
            r->x = (uint8_t)((uint8_t)((value4 & 0x1F) - 1) << 1);
            r->y = (uint16_t)(y1 + 1);
            r->c = (uint8_t)((value4 & 0x1F) - 1) & 0x80;
            r->z = (uint8_t)((uint8_t)((value4 & 0x1F) - 1) << 1) == 0;
            r->n = (uint8_t)((uint8_t)((value4 & 0x1F) - 1) << 1) & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp;
            switch ((uint8_t)((uint8_t)((value4 & 0x1F) - 1) << 1)) {
            case 0x0000: JSR(c, 0x248A, 0xC0248F); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_frame_record_and_register_selection */
            case 0x0002: JSR(c, 0x248A, 0xC02626); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_attribute_rectangle */
            case 0x0004: JSR(c, 0x248A, 0xC02642); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_party_variant_rectangle */
            case 0x0006: JSR(c, 0x248A, 0xC0266D); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_rectangle_76af */
            case 0x0008: JSR(c, 0x248A, 0xC0267B); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_rectangle_76e3 */
            case 0x000A: JSR(c, 0x248A, 0xC02689); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_rectangle_76d1 */
            case 0x000C: JSR(c, 0x248A, 0xC02697); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_rectangle_76f5 */
            case 0x000E: JSR(c, 0x248A, 0xC026A5); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_rectangle_77d1 */
            case 0x0010: JSR(c, 0x248A, 0xC026B3); GUARD_JSR(c, sp_call, 0x248A); break; /* consume_native_menu_four_by_four_pattern */
            case 0x0012: JSR(c, 0x248A, 0xC02AA9); GUARD_JSR(c, sp_call, 0x248A); break; /* construct_native_title_page_short_call_wrapper */
            case 0x0014: JSR(c, 0x248A, 0xC02AB3); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_save_page_constructor */
            case 0x0016: JSR(c, 0x248A, 0xC02AAE); GUARD_JSR(c, sp_call, 0x248A); break; /* construct_native_load_page_short_call_wrapper */
            case 0x0018: JSR(c, 0x248A, 0xC02AA4); GUARD_JSR(c, sp_call, 0x248A); break; /* construct_native_name_page_short_call_wrapper */
            case 0x001A: JSR(c, 0x248A, 0xC02A9F); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_personality_page_constructor */
            case 0x001C: JSR(c, 0x248A, 0xC02ABD); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_settings_page_constructor */
            case 0x001E: JSR(c, 0x248A, 0xC02AC2); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_controller_page_constructor */
            case 0x0020: JSR(c, 0x248A, 0xC02A9A); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_party_status_page_constructor */
            case 0x0022: JSR(c, 0x248A, 0xC02A90); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_spell_page_constructor */
            case 0x0024: JSR(c, 0x248A, 0xC02A95); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_item_page_constructor */
            case 0x0026: JSR(c, 0x248A, 0xC02AB8); GUARD_JSR(c, sp_call, 0x248A); break; /* near_call_native_save_confirmation_page_constructor */
            default: JSR(c, 0x248A, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x2A68 + ((uint8_t)((uint8_t)((value4 & 0x1F) - 1) << 1))))); GUARD_JSR(c, sp_call, 0x248A);
            }
            }
            r->sp += 1;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            bool carry_ret = r->c;
            bool zero_ret = r->z;
            bool overflow_ret = r->v;
            if (m_ret != 1) { c->fail = 3; return; }
            if (x_ret != 0) { c->fail = 3; return; }
            a1 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            x1 = x_ret2;
            y1 = y_ret;
            carry1 = carry_ret;
            zero1 = zero_ret;
            overflow1 = overflow_ret;
            data_bank = db_ret;
            direct_page = dp_ret;
            continue;
        }
        a1 = value4;
        a_hi1 = 0;
        zero1 = value4 == 0;
        break;
    }
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = value7 == 0;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = value7;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02443, SOM_RTS, "gen", execute_native_menu_page_record_commands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 76, 38)

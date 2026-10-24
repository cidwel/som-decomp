#include "som_c.h"

/* C02BA5 dispatch_native_menu_idle_callback_when_selected_pad_is_empty   [class C, 21 bytes, 12 instructions]
 * Source: src/rom/dispatch_native_menu_idle_callback_when_selected_pad_is_empty.s
 * Documented in docs/ui-native-loaded-game-input-dispatch.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void dispatch_native_menu_idle_callback_when_selected_pad_is_empty(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(r->sp) = x >> 8; /* PHX: the callee and the direct page,X reads below can see the pushed bytes */
    RAM8((uint16_t)(r->sp - 1)) = (uint8_t)x;
    uint8_t value, value2;
    BUS8_OK(c, (uint16_t)(0x0042u + x), value); /* direct page,X: bank 0, wraps in 16 bits */
    BUS8_OK(c, (uint16_t)(0x0043u + x), value2);
    uint8_t a_hi1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if ((value | value2) != 0) {
        a_hi1 = a_hi;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
    } else {
        uint8_t value3 = RAM8(0xA202);
        r->a = (uint8_t)(value3 << 1);
        r->x = (uint8_t)(value3 << 1);
        r->c = value3 & 0x80;
        r->z = (uint8_t)(value3 << 1) == 0;
        r->n = (uint8_t)(value3 << 1) & 0x8000;
        r->sp -= 2;
        switch ((uint8_t)(value3 << 1)) {
        case 0x0000: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x0002: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x0004: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x0006: JSR(c, 0x2BB7, 0xC03244); break; /* set_native_name_idle_timer */
        case 0x0008: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x000A: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x000C: JSR(c, 0x2BB7, 0xC030FF); break; /* commit_native_controller_permutation_on_button_release */
        case 0x000E: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x0010: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x0012: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        case 0x0014: JSR(c, 0x2BB7, 0xC03296); break; /* return_from_native_menu_no_action_callback */
        default: JSR(c, 0x2BB7, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x339F + ((uint8_t)(value3 << 1)))));
        }
        r->sp += 2;
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02BA5, SOM_RTS, "hand", dispatch_native_menu_idle_callback_when_selected_pad_is_empty, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 21, 12)

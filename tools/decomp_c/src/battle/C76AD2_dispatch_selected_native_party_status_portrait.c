#include "som_c.h"
#include "som_hand_d.h"

/* C76AD2 dispatch_selected_native_party_status_portrait   [class C, 13 bytes, hand written]
 * docs/ui-native-party-status-portrait-targets.md.  Selects one of three portrait routines by the byte at $7E:19FE.
 *
 * LDA #0 ; XBA ; LDA $0019FE ; ASL ; TAX ; JSR ($6BDD,X) ; RTS
 * The table at C7:6BDD holds three near pointers (5ED0, 5ED4, 5EE3); the targets are code in the same bank that is not a
 * recovered routine yet, so the cases carry addresses only.  Ids above 2 read the pointer from the ROM like the CPU.
 * Entry: M=8 bit.  Exit A = id << 1 with B = 0.
 */
static void dispatch_selected_native_party_status_portrait(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, -1)) return;
    const uint8_t id = RAM8(0x19FE);
    const uint8_t index = (uint8_t)(id << 1); /* 8-bit ASL: the table index wraps at 256 */
    r->a = index; /* LDA #0 / XBA leaves B = 0, the load replaces the low byte */
    r->c = id >> 7;
    zn(r, index, true);
    r->x = index; /* TAX copies the accumulator (B = 0 for a 16-bit X) */
    switch (index) {
    case 0x00: JSR(c, 0x6ADD, 0xC75ED0); break;
    case 0x02: JSR(c, 0x6ADD, 0xC75ED4); break;
    case 0x04: JSR(c, 0x6ADD, 0xC75EE3); break;
    default: JSR(c, 0x6ADD, 0xC70000 | BUS16(c, 0xC76BDD + index)); break;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76AD2, SOM_RTS, "hand", dispatch_selected_native_party_status_portrait, 0, L_ALL, 16, 1, -1, 13, 6)

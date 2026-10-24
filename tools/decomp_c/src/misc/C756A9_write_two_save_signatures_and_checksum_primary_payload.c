#include "som_c.h"

/* C756A9 write_two_save_signatures_and_checksum_primary_payload   [class A, 39 bytes, 13 instructions]
 * Source: src/rom/write_two_save_signatures_and_checksum_primary_payload.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void write_two_save_signatures_and_checksum_primary_payload(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    BUS8_SET(c, 0x306000 + x, 0xC5);
    BUS8_SET(c, 0x307000 + x, 0xC5);
    BUS8_SET(c, 0x3062BB + x, 0x3A);
    BUS8_SET(c, 0x3072BB + x, 0x3A);
    JSR(c, 0x56BF, 0xC75CDC); /* sum_native_save_payload_bytes_into_sixteen_bit_checksum */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0xA173);
    BUS16_SET(c, 0x306001 + x_ret, value);
    BUS16_SET(c, 0x307001 + x_ret, value);
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC756A9, SOM_RTS, "gen", write_two_save_signatures_and_checksum_primary_payload, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 39, 13)

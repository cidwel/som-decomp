#include "som_c.h"
#include "som_hand_d.h"

/* C0800C reset_ui_scene_and_enter_real_main_map_for_carried_command   [class B, 44 bytes, 20 instructions]
 * Source: src/rom/reset_ui_scene_and_enter_real_main_map_for_carried_command.s
 * Documented in docs/ui-native-ui-to-map-reset.md
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCV.
 */
static void reset_ui_scene_and_enter_real_main_map_for_carried_command(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t sp_entry = r->sp;
    i_rep(r, 0x30);
    a_ldx(r, 0x1ff);
    i_txs(r);
    i_pha(c);
    a_lda(r, 0x0);
    i_tcd(r);
    i_sep(r, 0x20);
    i_pha(c);
    i_plb(c);
    JSL(c, 0x801E, 0x02B5E7); /* blank_display_and_reset_native_ppu_and_hardware_registers */
    JSL(c, 0x8022, 0x02AA17); /* initialize_ui_transition_state_from_saved_map_flags */
    i_rep(r, 0x30);
    i_pla(c);
    a_ora(r, 0x800);
    JSL(c, 0x802C, 0x01E76D); /* event_command_map_context_entry */
    i_sep(r, 0x20);
    STZ(c, DP, 0xff);
    a_lda(r, 0xa0);
    STA(c, DP, 0xe0);
    /* The callee runs on the reset stack and never returns; the original code is cut at the first RTS taken at the entry S of this routine. */
    som_call_frame(c, 0xC0B03F, SOM_RTS, (uint16_t)(sp_entry - r->sp)); /* initialize_main_map_loop_before_native_nmi_wait */
    return;
}
SOM_REGISTER(0xC0800C, SOM_RTS, "hand", reset_ui_scene_and_enter_real_main_map_for_carried_command, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 3, -1, -1, 44, 20)

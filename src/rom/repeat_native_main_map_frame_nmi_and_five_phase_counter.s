; Recovered Secret of Mana USA routine; behaviour documented in docs/map-live-frame-loop.md.
.setcpu "65816"
.smart
.a8
.i16

advance_complete_main_map_frame_and_finalize_native_oam = $B08C

.segment "CODE"
.org $B070
repeat_native_main_map_frame_nmi_and_five_phase_counter:
repeat_native_main_map_frame_nmi_and_five_phase_counter_c0b070:
    jsr advance_complete_main_map_frame_and_finalize_native_oam
    sep #$20
    .a8
    lda #$01
    tsb $EC
repeat_native_main_map_frame_nmi_and_five_phase_counter_c0b079:
    bit $EC
    bne repeat_native_main_map_frame_nmi_and_five_phase_counter_c0b079
    lda $56
    inc
    sta $56
    .a8
    cmp #$05
    bcc repeat_native_main_map_frame_nmi_and_five_phase_counter_c0b08a
    .a8
    lda #$00
    sta $56
repeat_native_main_map_frame_nmi_and_five_phase_counter_c0b08a:
    bra repeat_native_main_map_frame_nmi_and_five_phase_counter_c0b070

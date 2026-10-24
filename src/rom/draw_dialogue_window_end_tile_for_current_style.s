; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

draw_native_dialogue_window_rom_tile_sequence = $0478

.segment "CODE"
.org $0413
draw_dialogue_window_end_tile_for_current_style:
    rep #$20
    lda a:$A24E
    .a16
    and #$00FF
    asl
    asl
    asl
    clc
    .a16
    adc #$00F0
    sta a:$A1A0
    sep #$20
    .a8
    lda #$FF
    sta a:$A171
    .a8
    lda #$01
    sta a:$A164
    jsr draw_native_dialogue_window_rom_tile_sequence
    rts

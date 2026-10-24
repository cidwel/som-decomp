; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_dialogue_window_tile_orientation = $04D0

.segment "CODE"
.org $0478
draw_native_dialogue_window_rom_tile_sequence:
draw_native_dialogue_window_rom_tile_sequence_c00478:
    lda a:$A186
    sta a:$A16D
    ldx a:$A1A0
    lda f:$C7716A,X
    clc
    rol
    rol
    rol
    .a8
    and #$03
    eor a:$A16D
    sta a:$A16D
    .a8
    lda #$00
    xba
    lda f:$C77169,X
    pha
    lda a:$A15C
    .a8
    cmp #$05
    bcs draw_native_dialogue_window_rom_tile_sequence_c004a4
    inx
    inx
    bra draw_native_dialogue_window_rom_tile_sequence_c004a6
draw_native_dialogue_window_rom_tile_sequence_c004a4:
    dex
    dex
draw_native_dialogue_window_rom_tile_sequence_c004a6:
    stx a:$A1A0
    pla
    rep #$20
    sec
    .a16
    sbc #$0010
    sta a:$A173
    lda a:$A24E
    .a16
    and #$00FF
    asl
    asl
    asl
    clc
    adc a:$A173
    asl
    asl
    asl
    asl
    tax
    sep #$20
    jsr dispatch_dialogue_window_tile_orientation
    dec a:$A164
    bne draw_native_dialogue_window_rom_tile_sequence_c00478
    rts

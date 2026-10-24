; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-tile-rows.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c00b00 = $0B00

.segment "CODE"
.org $99F3
configure_rom_row_cursor_and_execute_relocated_rle_decoder:
    rep #$30
    .a16
    and #$01FF
    tay
    .a16
    lda #$0B00
    tcd
    tya
    xba
    asl
    .a16
    and #$FE00
    sta a:$2181
    tya
    asl
    tax
    lda f:$C68000,X
    tax
    .a16
    and #$FF00
    sta $01
    sta $17
    txa
    .a16
    and #$00FF
    sta $3A
    tya
    lsr
    lsr
    lsr
    tax
    sep #$30
    .a8
    lda #$01
    sta a:$2183
    lda f:$C67FC0,X
    sta $3C
    tya
    .a8
    and #$07
    tax
    bne configure_rom_row_cursor_and_execute_relocated_rle_decoder_c09a37
    lda $3C
    bra configure_rom_row_cursor_and_execute_relocated_rle_decoder_c09a3d
configure_rom_row_cursor_and_execute_relocated_rle_decoder_c09a37:
    lda $3C
configure_rom_row_cursor_and_execute_relocated_rle_decoder_c09a39:
    lsr
    dex
    bne configure_rom_row_cursor_and_execute_relocated_rle_decoder_c09a39
configure_rom_row_cursor_and_execute_relocated_rle_decoder_c09a3d:
    .a8
    and #$01
    .a8
    ora #$C6
    sta $3E
    sep #$30
    lda $3E
    phb
    pha
    plb
    rep #$10
    ldy $3A
    .i16
    ldx #$01FF
    stz $3B
    jsr routine_c00b00
    sep #$20
    plb
    rep #$20
    .a16
    lda #$0000
    tcd
    rts

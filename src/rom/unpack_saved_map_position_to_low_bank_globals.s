; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $58D1
unpack_saved_map_position_to_low_bank_globals:
    phb
    .a8
    lda #$00
    pha
    plb
    .i16
    ldy #$0000
    .a8
    lda #$03
unpack_saved_map_position_to_low_bank_globals_c758db:
    xba
    lda f:$306000,X
    sta a:$00EE,Y
    inx
    iny
    xba
    dec
    bne unpack_saved_map_position_to_low_bank_globals_c758db
    plb
    rts

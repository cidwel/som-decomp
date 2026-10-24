; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5745
initialize_new_game_save_records_preserving_context:
    phd
    phb
    php
    rep #$30
    .a16
    lda #$0300
    tcd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$CC00
    .a8
    lda #$FF
    .i16
    ldy #$0024
initialize_new_game_save_records_preserving_context_c0575c:
    sta a:$0000,X
    inx
    dey
    bne initialize_new_game_save_records_preserving_context_c0575c
    .a8
    lda #$FF
    .i16
    ldy #$0038
initialize_new_game_save_records_preserving_context_c05768:
    sta a:$0000,X
    inx
    dey
    bne initialize_new_game_save_records_preserving_context_c05768
    .a8
    lda #$FE
    sta a:$CC2F
    sta a:$CC3B
    sta a:$CC47
    rep #$20
    lda f:$C057B3
    sta a:$CC6A
    lda f:$C057B5
    sta a:$CFFC
    lda f:$C057B7
    sta a:$CC73
    sep #$20
    lda f:$C057B9
    sta a:$CC75
    lda f:$C057BA
    sta a:$CC7A
    lda f:$C057BB
    sta a:$CC7B
    lda f:$C057BC
    sta a:$CC7C
    plp
    plb
    pld
    rtl

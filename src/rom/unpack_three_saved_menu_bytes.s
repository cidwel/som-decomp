; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5948
unpack_three_saved_menu_bytes:
    .i16
    ldy #$0000
    .a8
    lda #$03
unpack_three_saved_menu_bytes_c7594d:
    xba
    lda f:$306000,X
    sta a:$A257,Y
    inx
    iny
    xba
    dec
    bne unpack_three_saved_menu_bytes_c7594d
    rts

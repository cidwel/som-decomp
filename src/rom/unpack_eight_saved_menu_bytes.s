; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $591A
unpack_eight_saved_menu_bytes:
    .i16
    ldy #$0000
    .a8
    lda #$08
unpack_eight_saved_menu_bytes_c7591f:
    xba
    lda f:$306000,X
    sta a:$A24F,Y
    inx
    iny
    xba
    dec
    bne unpack_eight_saved_menu_bytes_c7591f
    rts

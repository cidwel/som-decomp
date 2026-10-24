; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $576F
pack_seventeen_menu_bytes_into_saved_slot:
    .i16
    ldy #$0000
    .a8
    lda #$11
pack_seventeen_menu_bytes_into_saved_slot_c75774:
    xba
    lda a:$A23E,Y
    sta f:$306000,X
    sta f:$307000,X
    inx
    iny
    xba
    dec
    bne pack_seventeen_menu_bytes_into_saved_slot_c75774
    rts

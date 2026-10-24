; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5787
pack_twelve_menu_bytes_into_saved_slot:
    .i16
    ldy #$0000
    .a8
    lda #$0C
pack_twelve_menu_bytes_into_saved_slot_c7578c:
    xba
    lda a:$A24F,Y
    sta f:$306000,X
    sta f:$307000,X
    inx
    iny
    xba
    dec
    bne pack_twelve_menu_bytes_into_saved_slot_c7578c
    rts

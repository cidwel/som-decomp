; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5731
pack_low_bank_map_position_into_saved_slot:
    phb
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$03
    .i16
    ldy #$0000
pack_low_bank_map_position_into_saved_slot_c7573b:
    xba
    lda a:$00EE,Y
    sta f:$306000,X
    sta f:$307000,X
    inx
    iny
    xba
    dec
    bne pack_low_bank_map_position_into_saved_slot_c7573b
    plb
    rts

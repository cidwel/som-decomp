; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $574F
select_active_controller_binding_and_pack_low_nibble:
    lda $D9
    .a8
    bit #$80
    bne select_active_controller_binding_and_pack_low_nibble_c75763
    lda $DA
    .a8
    bit #$80
    bne select_active_controller_binding_and_pack_low_nibble_c75763
    lda $DB
    .a8
    bit #$80
    bne select_active_controller_binding_and_pack_low_nibble_c75763
    .a8
    lda #$01
select_active_controller_binding_and_pack_low_nibble_c75763:
    .a8
    and #$0F
    sta f:$306000,X
    sta f:$307000,X
    inx
    rts

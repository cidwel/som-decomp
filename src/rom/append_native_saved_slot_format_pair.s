; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $59E0
append_native_saved_slot_format_pair:
    asl
    sta a:$9C01,X
    .a8
    lda #$5C
    sta a:$9C00,X
    inx
    inx
    rts

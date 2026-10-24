; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $538D
append_native_saved_slot_text_line_token:
    .a8
    lda #$7F
    sta a:$9C00,X
    inx
    rts

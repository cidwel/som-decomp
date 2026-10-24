; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-cast.md.
.setcpu "65816"
.smart
.a8
.i16

cast_selected_spell_at_parent_target_and_execute_success = $82E4

.segment "CODE"
.org $82B2
cast_right_spell13:
    .a16
    lda #$0013
    jsr cast_selected_spell_at_parent_target_and_execute_success
    rts

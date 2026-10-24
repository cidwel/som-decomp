; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-definitions.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $6CAB
initialize_position_height_boss_child:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$00D9
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$07FF
    sta a:$0022,X

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-effects.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $31A3
initialize_boss_death_explosion_then_check_animation:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$7FFF
    sta a:$0022,X
    .a16
    lda #$0001
    sta a:$000B,X
    stz a:$0029,X
    stz a:$0030,X
    stz a:$0066,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$015C
    jsr select_boss_animation_and_reset_frame_cursor

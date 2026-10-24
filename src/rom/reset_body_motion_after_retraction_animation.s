; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $4BC5
reset_body_motion_after_retraction_animation:
    ldx $87
    lda a:$00B0,X
    tax
    inc a:$00BC,X
    ldx $87
    lda a:$009E,X
    bne reset_body_motion_after_retraction_animation_c24bea
    inc a:$0094,X
    stz a:$0096,X
    stz a:$003C,X
    stz a:$0040,X
    .a16
    lda #$0000
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$001E,X
reset_body_motion_after_retraction_animation_c24bea:
    clc
    rts

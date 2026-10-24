; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child.md.
.setcpu "65816"
.smart
.a8
.i16

descriptor_zero_child_return_without_termination = $3E7D
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $3E69
advance_descriptor_zero_child_when_global_freeze_releases:
    ldx $87
    lda f:$7ECFFF
    .a16
    bit #$0001
    bne descriptor_zero_child_return_without_termination
    inc a:$0094,X
    .a16
    lda #$00E6
    jsr select_boss_animation_and_reset_frame_cursor

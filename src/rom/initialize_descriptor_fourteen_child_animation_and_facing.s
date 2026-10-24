; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0
update_descriptor_fourteen_child_parent_state_or_terminate = $538B

.segment "CODE"
.org $5360
initialize_descriptor_fourteen_child_animation_and_facing:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    inc a:$0094,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$0087
    sta a:$00B4,X
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$539F
    sta a:$0090,X
    lda a:$00B2,X
    beq update_descriptor_fourteen_child_parent_state_or_terminate
    lda a:$0098,X
    .a16
    ora #$0040
    sta a:$0098,X

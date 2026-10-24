; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $6A1D
initialize_descriptor_thirteen_child_and_position_callback:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$0001
    sta a:$0000,X
    inc a:$0094,X
    .a16
    lda #$014A
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$6A98
    sta a:$0090,X

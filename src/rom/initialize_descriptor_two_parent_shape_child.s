; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-child.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $409D
initialize_descriptor_two_parent_shape_child:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    stz a:$0066,X
    .a16
    lda #$0034
    sta a:$00B6,X
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0001
    sta a:$0000,X
    inc a:$0094,X
    stz a:$00B2,X
    stz a:$00AB,X
    .a16
    lda #$4143
    sta a:$0090,X

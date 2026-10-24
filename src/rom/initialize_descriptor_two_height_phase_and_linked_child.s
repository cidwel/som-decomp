; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $3F78
initialize_descriptor_two_height_phase_and_linked_child:
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$0010
    sta a:$0066,X
    stz a:$007E,X
    .i16
    ldy #$3801
    .i16
    ldx #$4091
    jsr allocate_boss_object_pool_slot
    lda $87
    sta a:$00B0,X
    rts

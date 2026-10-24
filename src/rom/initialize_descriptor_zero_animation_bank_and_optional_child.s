; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $3D48
initialize_descriptor_zero_animation_bank_and_optional_child:
    jsr set_boss_animation_bank_low_byte_c7
    lda a:$0042,X
    bne initialize_descriptor_zero_animation_bank_and_optional_child_c23d59
    .i16
    ldx #$3E27
    .i16
    ldy #$2901
    jsr allocate_boss_object_pool_slot
initialize_descriptor_zero_animation_bank_and_optional_child_c23d59:
    rts

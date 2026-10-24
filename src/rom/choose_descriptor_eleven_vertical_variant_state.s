; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven.md.
.setcpu "65816"
.smart
.a8
.i16

select_nearest_active_living_party_actor = $3224
update_descriptor_eleven_facing_phase_or_return_transition_abort = $8BF7

.segment "CODE"
.org $8B3F
choose_descriptor_eleven_vertical_variant_state:
    jsr select_nearest_active_living_party_actor
    sta a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0032,X
    sec
    sbc a:$0004,Y
    bpl choose_descriptor_eleven_vertical_variant_state_c28b58
    eor $C7
    inc
choose_descriptor_eleven_vertical_variant_state_c28b58:
    .a16
    cmp #$0050
    bcc choose_descriptor_eleven_vertical_variant_state_c28b61
    .a16
    lda #$F032
    rts
choose_descriptor_eleven_vertical_variant_state_c28b61:
    lda a:$002B,X
    sec
    sbc a:$0002,Y
    bpl choose_descriptor_eleven_vertical_variant_state_c28b6d
    eor $C7
    inc
choose_descriptor_eleven_vertical_variant_state_c28b6d:
    .a16
    cmp #$0020
    bcc choose_descriptor_eleven_vertical_variant_state_c28b76
    .a16
    lda #$F034
    rts
choose_descriptor_eleven_vertical_variant_state_c28b76:
    jsr update_descriptor_eleven_facing_phase_or_return_transition_abort
    bcs choose_descriptor_eleven_vertical_variant_state_c28b84
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE5B5,X
choose_descriptor_eleven_vertical_variant_state_c28b84:
    rts

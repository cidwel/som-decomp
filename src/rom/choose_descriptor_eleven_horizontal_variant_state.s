; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven.md.
.setcpu "65816"
.smart
.a8
.i16

select_nearest_active_living_party_actor = $3224
update_descriptor_eleven_facing_phase_or_return_transition_abort = $8BF7

.segment "CODE"
.org $8B85
choose_descriptor_eleven_horizontal_variant_state:
    jsr select_nearest_active_living_party_actor
    sta a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$002B,X
    sec
    sbc a:$0002,Y
    bpl choose_descriptor_eleven_horizontal_variant_state_c28b9e
    eor $C7
    inc
choose_descriptor_eleven_horizontal_variant_state_c28b9e:
    .a16
    cmp #$0050
    bcc choose_descriptor_eleven_horizontal_variant_state_c28ba7
    .a16
    lda #$F032
    rts
choose_descriptor_eleven_horizontal_variant_state_c28ba7:
    lda a:$0032,X
    sec
    sbc a:$0004,Y
    bpl choose_descriptor_eleven_horizontal_variant_state_c28bb3
    eor $C7
    inc
choose_descriptor_eleven_horizontal_variant_state_c28bb3:
    .a16
    cmp #$0020
    bcc choose_descriptor_eleven_horizontal_variant_state_c28bbc
    .a16
    lda #$F036
    rts
choose_descriptor_eleven_horizontal_variant_state_c28bbc:
    ldx $87
    jsr update_descriptor_eleven_facing_phase_or_return_transition_abort
    bcs choose_descriptor_eleven_horizontal_variant_state_c28bcc
    lda a:$00AB,X
    asl
    tax
    lda f:$DCE5B5,X
choose_descriptor_eleven_horizontal_variant_state_c28bcc:
    rts

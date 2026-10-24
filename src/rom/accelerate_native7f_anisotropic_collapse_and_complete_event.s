; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-motion-collapse.md.
.setcpu "65816"
.smart
.a8
.i16

derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle = $97FD
mark_controller_and_request_numeric_boss_death_event = $0C11

.segment "CODE"
.org $95BD
accelerate_native7f_anisotropic_collapse_and_complete_event:
    ldx $87
    .a16
    lda #$0003
    clc
    adc a:$00BC,X
    .a16
    cmp #$0020
    bcc accelerate_native7f_anisotropic_collapse_and_complete_event_c295ce
    .a16
    lda #$0020
accelerate_native7f_anisotropic_collapse_and_complete_event_c295ce:
    sta a:$00BC,X
    lda a:$00B4,X
    clc
    adc a:$00BC,X
    sta a:$00B4,X
    lda a:$00B6,X
    bne accelerate_native7f_anisotropic_collapse_and_complete_event_c2961d
    .a16
    lda #$0001
    sta a:$00B8,X
    lda a:$00B0,X
    sec
    sbc a:$00B8,X
    bpl accelerate_native7f_anisotropic_collapse_and_complete_event_c295f1
    lda $C5
accelerate_native7f_anisotropic_collapse_and_complete_event_c295f1:
    sta a:$00B0,X
    .a16
    lda #$0003
    clc
    adc a:$00BA,X
    sta a:$00BA,X
    lda a:$00B2,X
    clc
    adc a:$00BA,X
    .a16
    cmp #$1000
    sta a:$00B2,X
    bcc accelerate_native7f_anisotropic_collapse_and_complete_event_c29646
    lda $C7
    sta a:$00B6,X
    stz a:$00B8,X
    .a16
    lda #$8000
    sta a:$00B2,X
    bra accelerate_native7f_anisotropic_collapse_and_complete_event_c29646
accelerate_native7f_anisotropic_collapse_and_complete_event_c2961d:
    .a16
    lda #$0003
    clc
    adc a:$00B8,X
    sta a:$00B8,X
    clc
    adc a:$00B0,X
    .a16
    cmp #$1000
    bcc accelerate_native7f_anisotropic_collapse_and_complete_event_c29643
    .a16
    lda #$8000
    sta a:$00B0,X
    lda a:$0072,X
    jsr mark_controller_and_request_numeric_boss_death_event
    ldx $87
    jsr derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle
    sec
    rts
accelerate_native7f_anisotropic_collapse_and_complete_event_c29643:
    sta a:$00B0,X
accelerate_native7f_anisotropic_collapse_and_complete_event_c29646:
    jsr derive_anisotropic_native7f_mode7_matrix_from_two_scales_and_angle
    clc
    rts

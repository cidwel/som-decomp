; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

select_native54_body_nearest_party_target = $4BEC

.segment "CODE"
.org $4B7F
begin_body_segment_growth_after_animation:
    ldx $87
    lda a:$00B0,X
    tax
    inc a:$00BC,X
    ldx $87
    lda a:$009E,X
    bne begin_body_segment_growth_after_animation_c24bc3
    .a16
    lda #$0004
    sta a:$0094,X
    .a16
    lda #$0002
    sta a:$001E,X
    stz a:$0096,X
    stz a:$00B2,X
    stz a:$00B4,X
    stz a:$00B6,X
    tya
    clc
    .a16
    adc #$F803
    sta a:$00B8,X
    .a16
    lda #$0006
    sta a:$00BA,X
    stz a:$00BC,X
    jsr select_native54_body_nearest_party_target
    ldx $87
    sta a:$00A9,X
    stz a:$0059,X
begin_body_segment_growth_after_animation_c24bc3:
    clc
    rts

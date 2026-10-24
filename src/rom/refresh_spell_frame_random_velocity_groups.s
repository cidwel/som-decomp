; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

advance_spell_frame_signed_velocity = $F567
damp_spell_frame_velocity_with_mode7_product = $F5B8
draw_spell_entity_bounded_random_long = $C12ED1

.segment "CODE"
.org $F6C9
refresh_spell_frame_random_velocity_groups:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    dec a:$0110,X
    bne refresh_spell_frame_random_velocity_groups_d3f73e
    stx $03
    .a8
    lda #$10
    jsl f:draw_spell_entity_bounded_random_long
    ldx $03
    inc
    sta a:$0110,X
    .a8
    lda #$00
    jsl f:draw_spell_entity_bounded_random_long
    ldx $03
    sta a:$0105,X
    .a8
    lda #$00
    jsl f:draw_spell_entity_bounded_random_long
    ldx $03
    sta a:$0102,X
    txy
    rep #$20
    clc
    tya
    .a16
    adc #$0102
    tay
    clc
    txa
    .a16
    adc #$00F0
    tax
    .a16
    lda #$0003
    sta $01
refresh_spell_frame_random_velocity_groups_d3f713:
    jsr advance_spell_frame_signed_velocity
    clc
    txa
    .a16
    adc #$0006
    tax
    dec $01
    bne refresh_spell_frame_random_velocity_groups_d3f713
    ldx $03
    clc
    txa
    .a16
    adc #$00F0
    tax
    .a16
    lda #$0003
    sta $01
refresh_spell_frame_random_velocity_groups_d3f72d:
    lda $01
    inc
    inc
    jsr damp_spell_frame_velocity_with_mode7_product
    clc
    txa
    .a16
    adc #$0006
    tax
    dec $01
    bne refresh_spell_frame_random_velocity_groups_d3f72d
refresh_spell_frame_random_velocity_groups_d3f73e:
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts

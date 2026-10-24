; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16

draw_spell_entity_bounded_random_long = $C12ED1

.segment "CODE"
.org $F747
reset_spell_frame_sprite_record:
    phd
    php
    rep #$30
    phb
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    stx $01
    .a8
    lda #$FF
    sta a:$0004,X
    rep #$20
    .a16
    lda #$F000
    sta a:$0002,X
    .a16
    lda #$0000
    jsl f:draw_spell_entity_bounded_random_long
    ldx $01
    sta a:$0006,X
    .a16
    lda #$0004
    jsl f:draw_spell_entity_bounded_random_long
    pha
    asl
    clc
    .a16
    adc #$0144
    ldx $01
    ldy a:$0000,X
    sta a:$0006,Y
    pla
    .a16
    cmp #$0003
    bcc reset_spell_frame_sprite_record_d3f792
    .a16
    lda #$0003
    jsl f:draw_spell_entity_bounded_random_long
    ldx $01
reset_spell_frame_sprite_record_d3f792:
    sta a:$0008,X
    sep #$20
    sta $03,S
    pla
    pla
    pla
    plp
    pld
    rts

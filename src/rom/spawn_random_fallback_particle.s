; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

draw_spell_entity_bounded_random_long = $C12ED1

.segment "CODE"
.org $FEFB
spawn_random_fallback_particle:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    stx $01
    lda a:$0144,X
    inc
    .a16
    cmp #$0014
    bcc spawn_random_fallback_particle_d3ff14
    .a16
    lda #$0000
spawn_random_fallback_particle_d3ff14:
    sta a:$0144,X
    sep #$20
    xba
    .a8
    lda #$10
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    clc
    adc $01
    tay
    lda a:$000C,Y
    inc
    bne spawn_random_fallback_particle_d3ffae
    sta a:$000C,Y
    .a16
    lda #$0110
    sta a:$0004,Y
    .a16
    lda #$0001
    sta a:$000E,Y
    sty $03
    sep #$20
    .a8
    lda #$00
    jsl f:draw_spell_entity_bounded_random_long
    ldy $03
    sta a:$000A,Y
    .a8
    lda #$01
    jsl f:draw_spell_entity_bounded_random_long
    rep #$20
    ldy $03
    clc
    .a16
    adc #$0001
    .a16
    eor #$FFFF
    sta a:$0008,Y
    .a16
    lda #$0040
    jsl f:draw_spell_entity_bounded_random_long
    sec
    .a16
    sbc #$0020
    ldx $01
    ldy $03
    clc
    adc a:$0140,X
    sta a:$0002,Y
    .a16
    lda #$0020
    jsl f:draw_spell_entity_bounded_random_long
    clc
    .a16
    adc #$0004
    ldx $01
    sta a:$0148,X
    dec a:$0146,X
    bne spawn_random_fallback_particle_d3ffae
    stz a:$0148,X
    ldy $03
    lda a:$8434
    clc
    .a16
    adc #$0110
    sta a:$0004,Y
    lda a:$8434
    asl
    asl
    asl
    asl
    sta a:$8434
    .a16
    lda #$0000
    sta a:$000A,Y
spawn_random_fallback_particle_d3ffae:
    ldx $01
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts

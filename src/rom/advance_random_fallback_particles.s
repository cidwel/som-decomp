; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record_long = $C12E94

.segment "CODE"
.org $FE71
advance_random_fallback_particles:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    stz $03
    .a16
    lda #$0014
    sta $01
advance_random_fallback_particles_d3fe83:
    lda a:$000C,X
    inc
    beq advance_random_fallback_particles_d3fee4
    dec a:$000E,X
    bne advance_random_fallback_particles_d3fe9f
    .a16
    cmp #$0004
    bcc advance_random_fallback_particles_d3fe96
    .a16
    lda #$0000
advance_random_fallback_particles_d3fe96:
    sta a:$000C,X
    .a16
    lda #$0004
    sta a:$000E,X
advance_random_fallback_particles_d3fe9f:
    lda a:$000C,X
    asl
    .a16
    and #$00FF
    clc
    .a16
    adc #$FE82
    sec
    .a16
    sbc #$F800
    txy
    phx
    tax
    lda a:$0002,Y
    pha
    sep #$20
    lda a:$000A,Y
    clc
    adc a:$0006,Y
    sta a:$0006,Y
    rep #$20
    lda a:$0004,Y
    adc a:$0008,Y
    pha
    sta a:$0004,Y
    clc
    .a16
    adc #$0008
    bpl advance_random_fallback_particles_d3fedb
    .a16
    lda #$FFFF
    sta a:$000C,Y
    bra advance_random_fallback_particles_d3fee1
advance_random_fallback_particles_d3fedb:
    inc $03
    jsl f:project_packed_spell_entity_sprite_record_long
advance_random_fallback_particles_d3fee1:
    ply
    ply
    plx
advance_random_fallback_particles_d3fee4:
    clc
    txa
    .a16
    adc #$0010
    tax
    dec $01
    bne advance_random_fallback_particles_d3fe83
    lda $03
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts

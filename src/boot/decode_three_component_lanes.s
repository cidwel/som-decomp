; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decode_component_ramp = $837E

.segment "CODE"
.org $83AD
decode_three_component_lanes:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    stx $01
    ldy a:$001A
    .a8
    lda #$E8
    jsr decode_component_ramp
    ldy a:$001A
    iny
    ldx $01
    .a8
    lda #$E8
    jsr decode_component_ramp
    ldy a:$001A
    iny
    iny
    ldx $01
    .a8
    lda #$E8
    jsr decode_component_ramp
    plb
    pla
    pla
    plp
    pld
    rts

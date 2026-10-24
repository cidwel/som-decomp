; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

decode_signed_delta_or_zero_run = $A1A7

.segment "CODE"
.org $837E
decode_component_ramp:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    sta $01
    stz $02
decode_component_ramp_838d:
    phy
    jsr decode_signed_delta_or_zero_run
    ply
    clc
    adc $02
    sta a:$0000,Y
    sta $02
    clc
    rep #$20
    tya
    .a16
    adc #$0004
    tay
    sep #$20
    dec $01
    bne decode_component_ramp_838d
    pla
    pla
    plp
    pld
    rts

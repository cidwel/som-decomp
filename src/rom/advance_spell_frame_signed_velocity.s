; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F567
advance_spell_frame_signed_velocity:
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
    .a8
    lda #$01
    sta $04
    lda a:$0000,Y
    sta $03
    rep #$20
    lda a:$0000,X
    clc
    adc $03
    sta a:$0000,X
    sep #$20
    bcc advance_spell_frame_signed_velocity_d3f58f
    stz a:$0002,X
advance_spell_frame_signed_velocity_d3f58f:
    lda a:$0003,Y
    sta $01
    stz $02
    .a8
    bit #$80
    beq advance_spell_frame_signed_velocity_d3f59c
    dec $02
advance_spell_frame_signed_velocity_d3f59c:
    rep #$20
    lda a:$0003,X
    clc
    adc $01
    sta a:$0003,X
    sep #$20
    lda a:$0005,X
    adc $02
    sta a:$0005,X
    pla
    pla
    pla
    pla
    plp
    pld
    rts

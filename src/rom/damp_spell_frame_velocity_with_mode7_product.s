; Recovered Secret of Mana USA routine; behaviour documented in docs/map-oam-spell-frames.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F5B8
damp_spell_frame_velocity_with_mode7_product:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    lda $09,S
    .a16
    and #$00FF
    sta $09
    lda a:$0003,X
    bpl damp_spell_frame_velocity_with_mode7_product_d3f5d4
    .a16
    eor #$FFFF
    inc
damp_spell_frame_velocity_with_mode7_product_d3f5d4:
    sta $01
    lda a:$0000,X
    bpl damp_spell_frame_velocity_with_mode7_product_d3f5df
    .a16
    eor #$FFFF
    inc
damp_spell_frame_velocity_with_mode7_product_d3f5df:
    sta $03
    cmp $01
    bcs damp_spell_frame_velocity_with_mode7_product_d3f5ed
    sta $07
    lda $01
    sta $05
    bra damp_spell_frame_velocity_with_mode7_product_d3f5f3
damp_spell_frame_velocity_with_mode7_product_d3f5ed:
    sta $05
    lda $01
    sta $07
damp_spell_frame_velocity_with_mode7_product_d3f5f3:
    lda $07
    lsr
    clc
    adc $05
    lsr
    sep #$20
    sta f:$00211B
    xba
    sta f:$00211B
    lda $09
    sta f:$00211C
    sta f:$00211C
    rep #$20
    lda f:$002134
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    .a16
    eor #$FFFF
    inc
    .a16
    and #$007F
    sta $09
    lda a:$0003,X
    asl
    sep #$20
    sta f:$00211B
    xba
    sta f:$00211B
    lda $09
    sta f:$00211C
    sta f:$00211C
    rep #$20
    lda f:$002134
    lda f:$002135
    bne damp_spell_frame_velocity_with_mode7_product_d3f64c
    stz a:$0004,X
damp_spell_frame_velocity_with_mode7_product_d3f64c:
    sta a:$0003,X
    lda a:$0000,X
    asl
    sep #$20
    sta f:$00211B
    xba
    sta f:$00211B
    lda $09
    sta f:$00211C
    sta f:$00211C
    rep #$20
    lda f:$002134
    lda f:$002135
    bne damp_spell_frame_velocity_with_mode7_product_d3f677
    stz a:$0001,X
damp_spell_frame_velocity_with_mode7_product_d3f677:
    sta a:$0000,X
    tsc
    clc
    .a16
    adc #$000A
    tcs
    plp
    pld
    rts

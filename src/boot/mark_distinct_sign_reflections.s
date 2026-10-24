; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

mark_translated_colour_candidates = $8444
test_distinct_component_offset = $84AE

.segment "CODE"
.org $84EB
mark_distinct_sign_reflections:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0009
    tcd
    tcs
    stx $06
    lda a:$0018
    clc
    .a16
    adc #$0004
    tax
    sta $04
    sta $08
    stz $02
    sep #$20
    .a8
    lda #$00
mark_distinct_sign_reflections_850a:
    sta $01
    ldy $06
    xba
    lda a:$0000,Y
    xba
    .a8
    bit #$01
    beq mark_distinct_sign_reflections_851c
    xba
    .a8
    eor #$FF
    inc
    xba
mark_distinct_sign_reflections_851c:
    xba
    sta a:$0000,X
    lda a:$0001,Y
    xba
    .a8
    bit #$02
    beq mark_distinct_sign_reflections_852d
    xba
    .a8
    eor #$FF
    inc
    xba
mark_distinct_sign_reflections_852d:
    xba
    sta a:$0001,X
    lda a:$0002,Y
    xba
    .a8
    bit #$04
    beq mark_distinct_sign_reflections_853e
    xba
    .a8
    eor #$FF
    inc
    xba
mark_distinct_sign_reflections_853e:
    xba
    sta a:$0002,X
    ldy $08
    jsr test_distinct_component_offset
    .a8
    cmp #$00
    beq mark_distinct_sign_reflections_8560
    jsr mark_translated_colour_candidates
    rep #$20
    clc
    adc $02
    sta $02
    lda $04
    clc
    .a16
    adc #$0004
    sta $04
    tax
    sep #$20
mark_distinct_sign_reflections_8560:
    lda $01
    inc
    .a8
    cmp #$08
    bcc mark_distinct_sign_reflections_850a
    rep #$20
    lda $02
    sta $08,S
    tsc
    clc
    .a16
    adc #$0007
    tcs
    pla
    plp
    pld
    rts

; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

mark_distinct_sign_reflections = $84EB
test_distinct_component_offset = $84AE

.segment "CODE"
.org $8577
mark_cyclic_component_permutations:
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
    txy
    lda a:$0018
    clc
    .a16
    adc #$0024
    tax
    sta $04
    sta $08
    sep #$20
    lda a:$0000,Y
    sta a:$0000,X
    rep #$20
    lda a:$0001,Y
    sta a:$0001,X
    jsr mark_distinct_sign_reflections
    sta $02
    lda $04
    clc
    .a16
    adc #$0004
    sta $04
    tax
    ldy $06
    lda a:$0000,Y
    sta a:$0001,X
    sep #$20
    lda a:$0002,Y
    sta a:$0000,X
    ldy $08
    jsr test_distinct_component_offset
    .a8
    cmp #$00
    beq mark_cyclic_component_permutations_85f7
    jsr mark_distinct_sign_reflections
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
    ldy $06
    lda a:$0001,Y
    sta a:$0000,X
    sep #$20
    lda a:$0000,Y
    sta a:$0002,X
    rep #$20
    jsr mark_distinct_sign_reflections
    clc
    adc $02
    sta $02
    sep #$20
mark_cyclic_component_permutations_85f7:
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

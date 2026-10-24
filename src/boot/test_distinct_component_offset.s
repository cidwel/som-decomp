; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $84AE
test_distinct_component_offset:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    stx $01
test_distinct_component_offset_84b9:
    cpy $01
    bcs test_distinct_component_offset_84e2
    lda a:$0000,Y
    cmp a:$0000,X
    bne test_distinct_component_offset_84d6
    lda a:$0001,Y
    cmp a:$0001,X
    bne test_distinct_component_offset_84d6
    lda a:$0002,Y
    sec
    sbc a:$0002,X
    beq test_distinct_component_offset_84e4
test_distinct_component_offset_84d6:
    clc
    rep #$20
    tya
    .a16
    adc #$0004
    tay
    sep #$20
    bra test_distinct_component_offset_84b9
test_distinct_component_offset_84e2:
    .a8
    lda #$01
test_distinct_component_offset_84e4:
    sta $02,S
    pla
    pla
    plp
    pld
    rts

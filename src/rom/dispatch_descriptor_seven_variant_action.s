; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven.md.
.setcpu "65816"
.smart
.a8
.i16

select_alive_hero_nearest_on_vertical_axis = $7303

.segment "CODE"
.org $7110
dispatch_descriptor_seven_variant_action:
    jsr select_alive_hero_nearest_on_vertical_axis
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sty $95
    lda a:$0042,X
    asl
    tax
    jmp ($7127,X)

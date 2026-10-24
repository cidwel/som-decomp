; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D1FB
offset_armor_inventory_description_by_position:
    php
    rep #$30
    .a16
    and #$003F
    phx
    pha
    lda a:$1809
    .a16
    and #$00FF
    .a16
    cmp #$0003
    bne offset_armor_inventory_description_by_position_d0d22b
    pla
    pha
    txa
    sec
    .a16
    sbc #$0054
    sep #$20
    pha
    asl
    asl
    asl
    clc
    adc $01,S
    sta $01,S
    pla
    rep #$20
    .a16
    and #$00FF
    clc
    adc $01,S
    sta $01,S
offset_armor_inventory_description_by_position_d0d22b:
    pla
    plx
    plp
    rtl

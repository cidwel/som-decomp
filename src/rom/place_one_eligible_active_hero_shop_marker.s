; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DA3D
place_one_eligible_active_hero_shop_marker:
    beq place_one_eligible_active_hero_shop_marker_d0da51
    lda f:$7E0000,X
    .a16
    and #$00FF
    .a16
    cmp #$0001
    bne place_one_eligible_active_hero_shop_marker_d0da51
    lda a:$1820
    sta a:$0000,Y
place_one_eligible_active_hero_shop_marker_d0da51:
    iny
    iny
    iny
    iny
    lda a:$1820
    clc
    .a16
    adc #$000A
    sta a:$1820
    rts

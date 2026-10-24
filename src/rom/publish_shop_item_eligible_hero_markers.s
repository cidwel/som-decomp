; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

place_one_eligible_active_hero_shop_marker = $DA3D
read_native_item_usability_and_category_bits = $C07A02

.segment "CODE"
.org $D9F6
publish_shop_item_eligible_hero_markers:
    sep #$30
    .i8
    cpx #$06
    bcc publish_shop_item_eligible_hero_markers_d0da3c
    jsl f:read_native_item_usability_and_category_bits
    rep #$30
    pha
    sep #$20
    lda a:$181C
    sec
    .a8
    sbc #$02
    xba
    lda a:$181A
    sec
    .a8
    sbc #$0C
    rep #$20
    sta a:$1820
    .i16
    ldy #$082C
    .i16
    ldx #$E000
    lda $01,S
    .a16
    bit #$0040
    jsr place_one_eligible_active_hero_shop_marker
    .i16
    ldx #$E200
    lda $01,S
    .a16
    bit #$0020
    jsr place_one_eligible_active_hero_shop_marker
    .i16
    ldx #$E400
    lda $01,S
    .a16
    bit #$0010
    jsr place_one_eligible_active_hero_shop_marker
    pla
publish_shop_item_eligible_hero_markers_d0da3c:
    rts

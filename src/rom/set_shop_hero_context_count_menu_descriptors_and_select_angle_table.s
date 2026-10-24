; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-list-geometry.md.
.setcpu "65816"
.smart
.a8
.i16

set_native_menu_ring_center_from_hero_position_and_offset = $7134

.segment "CODE"
.org $714C
set_shop_hero_context_count_menu_descriptors_and_select_angle_table:
    ldx a:$183E
    txa
    clc
    .a16
    adc #$E180
    sta a:$1844
    .i16
    ldy #$FFCF
    jsr set_native_menu_ring_center_from_hero_position_and_offset
    .i16
    ldx #$0000
set_shop_hero_context_count_menu_descriptors_and_select_angle_table_c07160:
    lda a:$1880,X
    .a16
    cmp #$FFFF
    beq set_shop_hero_context_count_menu_descriptors_and_select_angle_table_c0716c
    inx
    inx
    bra set_shop_hero_context_count_menu_descriptors_and_select_angle_table_c07160
set_shop_hero_context_count_menu_descriptors_and_select_angle_table_c0716c:
    txa
    lsr
    sep #$20
    sta a:$180B
    rep #$20
    .a16
    and #$00FF
    dec
    asl
    tax
    lda f:$D8FF18,X
    sta a:$180E
    lda a:$1808
    .a16
    and #$00FF
    asl
    xba
    .a16
    and #$0600
    sta a:$1849
    lda a:$1880
    sec
    .a16
    sbc #$FFFF
    beq set_shop_hero_context_count_menu_descriptors_and_select_angle_table_c071a1
    lda a:$1880
    sec
    sbc f:$D8FF16
set_shop_hero_context_count_menu_descriptors_and_select_angle_table_c071a1:
    rts

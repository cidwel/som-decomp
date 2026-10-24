; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-category.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6EF0
step_native_menu_ring_category_across_shop_and_hero_constraints:
    sep #$30
    .a8
    lda #$08
    bit a:$1803
    beq step_native_menu_ring_category_across_shop_and_hero_constraints_c06f0f
    lda a:$1814
    .i8
    ldx #$06
    clc
    adc a:$1809
    .a8
    cmp #$04
    bcc step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
    tax
    .a8
    cmp #$07
    bcc step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
    .i8
    ldx #$04
    bra step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
step_native_menu_ring_category_across_shop_and_hero_constraints_c06f0f:
    lda a:$1847
    .a8
    cmp #$02
    bne step_native_menu_ring_category_across_shop_and_hero_constraints_c06f35
step_native_menu_ring_category_across_shop_and_hero_constraints_c06f16:
    lda a:$1809
    .i8
    ldx #$06
    clc
    adc a:$1814
    bmi step_native_menu_ring_category_across_shop_and_hero_constraints_c06f28
    tax
    .a8
    cmp #$07
    bcc step_native_menu_ring_category_across_shop_and_hero_constraints_c06f28
    .i8
    ldx #$00
step_native_menu_ring_category_across_shop_and_hero_constraints_c06f28:
    stx a:$1809
    .i8
    cpx #$00
    beq step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
    .i8
    cpx #$04
    bcc step_native_menu_ring_category_across_shop_and_hero_constraints_c06f16
    bra step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
step_native_menu_ring_category_across_shop_and_hero_constraints_c06f35:
    lda a:$1809
    .i8
    ldx #$03
    clc
    adc a:$1814
    bmi step_native_menu_ring_category_across_shop_and_hero_constraints_c06f47
    tax
    .a8
    cmp #$04
    bcc step_native_menu_ring_category_across_shop_and_hero_constraints_c06f47
    .i8
    ldx #$00
step_native_menu_ring_category_across_shop_and_hero_constraints_c06f47:
    lda a:$1808
    bne step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
    .i8
    cpx #$01
    bne step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
    lda a:$1814
    bpl step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57
    .i8
    ldx #$00
step_native_menu_ring_category_across_shop_and_hero_constraints_c06f57:
    txa
    sta a:$1809
    rep #$20
    rts

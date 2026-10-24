; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-builder.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $73AC
test_native_equipment_row_eligibility_from_hero_state_and_level:
    rep #$30
    lda a:$1844
    clc
    .a16
    adc #$FEE0
    tax
    sep #$20
    lda f:$7E0000,X
    beq test_native_equipment_row_eligibility_from_hero_state_and_level_c073c2
    .a8
    cmp #$40
    bne test_native_equipment_row_eligibility_from_hero_state_and_level_c073d9
test_native_equipment_row_eligibility_from_hero_state_and_level_c073c2:
    .i16
    ldx #$0186
    lda a:$1808
    .a8
    and #$01
    bne test_native_equipment_row_eligibility_from_hero_state_and_level_c073cf
    .i16
    ldx #$0386
test_native_equipment_row_eligibility_from_hero_state_and_level_c073cf:
    lda f:$7EE200,X
    sec
    sbc a:$1843
    bcs test_native_equipment_row_eligibility_from_hero_state_and_level_c073da
test_native_equipment_row_eligibility_from_hero_state_and_level_c073d9:
    clc
test_native_equipment_row_eligibility_from_hero_state_and_level_c073da:
    rtl

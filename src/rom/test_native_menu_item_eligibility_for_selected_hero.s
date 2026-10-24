; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

read_native_item_usability_and_category_bits = $C07A02

.segment "CODE"
.org $79C7
test_native_menu_item_eligibility_for_selected_hero:
    sep #$30
    ldx a:$1809
    .i8
    cpx #$03
    beq test_native_menu_item_eligibility_for_selected_hero_c079e3
    jsl f:read_native_item_usability_and_category_bits
    dey
    bmi test_native_menu_item_eligibility_for_selected_hero_c079dc
    asl
    dey
    bmi test_native_menu_item_eligibility_for_selected_hero_c079dc
    asl
test_native_menu_item_eligibility_for_selected_hero_c079dc:
    .a8
    bit #$40
    bne test_native_menu_item_eligibility_for_selected_hero_c079f6
test_native_menu_item_eligibility_for_selected_hero_c079e0:
    .a8
    lda #$00
    rtl
test_native_menu_item_eligibility_for_selected_hero_c079e3:
    rep #$30
    lda a:$182A
    .a16
    and #$FE00
    tax
    sep #$20
    lda f:$7E0191,X
    .a8
    and #$C7
    bne test_native_menu_item_eligibility_for_selected_hero_c079e0
test_native_menu_item_eligibility_for_selected_hero_c079f6:
    .a8
    lda #$01
    rtl

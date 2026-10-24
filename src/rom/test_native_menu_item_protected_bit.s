; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-fields.md.
.setcpu "65816"
.smart
.a8
.i16

read_native_item_usability_and_category_bits = $C07A02

.segment "CODE"
.org $79F9
test_native_menu_item_protected_bit:
    sep #$30
    jsl f:read_native_item_usability_and_category_bits
    .a8
    bit #$80
    rts

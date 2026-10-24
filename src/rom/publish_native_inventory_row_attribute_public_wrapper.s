; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-attributes.md.
.setcpu "65816"
.smart
.a8
.i16

publish_native_inventory_owner_and_rotated_selection_attribute = $D279

.segment "CODE"
.org $D275
publish_native_inventory_row_attribute_public_wrapper:
    jsr publish_native_inventory_owner_and_rotated_selection_attribute
    rtl

; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

format_five_native_saved_slot_decimal_digits_via_hardware_division = $5D17

.segment "CODE"
.org $5AFC
format_and_append_native_saved_slot_decimal_pair:
    jsr format_five_native_saved_slot_decimal_digits_via_hardware_division

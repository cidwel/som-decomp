; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5A87
begin_native_saved_slot_seven_bit_value:
    .i16
    ldx #$0000

; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_space_token = $5389

.segment "CODE"
.org $5386
append_two_native_saved_slot_text_space_tokens:
    jsr append_native_saved_slot_text_space_token

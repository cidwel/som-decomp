; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_saved_slot_text_space_token = $5389
read_native_saved_slot_character_level = $5B25

.segment "CODE"
.org $5AED
append_native_saved_slot_level_label:
    jsr append_native_saved_slot_text_space_token
    .a8
    lda #$A6
    sta a:$9C00,X
    stz a:$A177
    inx
    jsr read_native_saved_slot_character_level

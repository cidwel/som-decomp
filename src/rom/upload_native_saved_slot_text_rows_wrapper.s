; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

upload_native_menu_assembled_text_tiles = $23BA

.segment "CODE"
.org $2ADF
upload_native_saved_slot_text_rows_wrapper:
    jsr upload_native_menu_assembled_text_tiles
    rtl

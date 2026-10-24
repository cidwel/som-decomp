; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-page.md.
.setcpu "65816"
.smart
.a8
.i16

upload_complete_native_menu_oam_table = $1F5B

.segment "CODE"
.org $2AD3
upload_native_menu_sprite_tables_long_wrapper:
    jsr upload_complete_native_menu_oam_table
    rtl

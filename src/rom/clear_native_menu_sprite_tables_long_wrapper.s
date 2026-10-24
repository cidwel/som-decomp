; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_and_high_oam_tables = $1F36

.segment "CODE"
.org $2ACF
clear_native_menu_sprite_tables_long_wrapper:
    jsr clear_native_menu_sprite_and_high_oam_tables
    rtl

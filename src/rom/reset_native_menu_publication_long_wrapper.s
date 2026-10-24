; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-page.md.
.setcpu "65816"
.smart
.a8
.i16

reset_native_menu_publication_and_scroll_state = $1F88

.segment "CODE"
.org $2AC7
reset_native_menu_publication_long_wrapper:
    jsr reset_native_menu_publication_and_scroll_state
    rtl

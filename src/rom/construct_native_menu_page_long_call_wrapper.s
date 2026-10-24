; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-pages.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_menu_page_with_saved_slots_and_real_text_publication = $21DB

.segment "CODE"
.org $2ACB
construct_native_menu_page_long_call_wrapper:
    jsr construct_native_menu_page_with_saved_slots_and_real_text_publication
    rtl

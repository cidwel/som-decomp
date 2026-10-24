; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-strip.md.
.setcpu "65816"
.smart
.a8
.i16

normalize_menu_native_direct_page_and_bank = $C064A4
resolve_twelve_native_menu_icon_descriptor_words = $C86C
upload_native_twelve_icon_strip_and_upper_palette = $C8A3

.segment "CODE"
.org $C856
publish_native_icon_strip_with_saved_menu_context:
    php
    phb
    phd
    jsl f:normalize_menu_native_direct_page_and_bank
    rep #$30
    stx a:$180C
    jsr resolve_twelve_native_menu_icon_descriptor_words
    jsr upload_native_twelve_icon_strip_and_upper_palette
    pld
    plb
    plp
    rtl

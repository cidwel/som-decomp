; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-state-api.md.
.setcpu "65816"
.smart
.a8
.i16

normalize_menu_native_direct_page_and_bank = $C064A4

.segment "CODE"
.org $6433
initialize_native_menu_hero_categories_with_saved_context:
    php
    phb
    phd
    jsl f:normalize_menu_native_direct_page_and_bank
    rep #$30
    .a16
    lda #$0000
    tax
    sep #$20
    sta a:$1806
    sta a:$1807
initialize_native_menu_hero_categories_with_saved_context_c06448:
    sta a:$1870,X
    inx
    .i16
    cpx #$0010
    bcc initialize_native_menu_hero_categories_with_saved_context_c06448
    .a8
    lda #$03
    sta a:$1870
    sta a:$1871
    sta a:$1872

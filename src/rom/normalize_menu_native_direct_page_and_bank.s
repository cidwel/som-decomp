; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-actor-selection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $64A4
normalize_menu_native_direct_page_and_bank:
    rep #$30
    pha
    .a16
    lda #$0000
    tcd
    sep #$20
    pha
    plb
    rep #$30
    pla
    rtl

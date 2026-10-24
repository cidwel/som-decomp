; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $793D
hide_shop_hero_markers_before_price_selection:
    .a16
    lda #$E800
    sta a:$082C
    sta a:$0830
    sta a:$0834
    rtl

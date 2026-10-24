; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-icon-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CB2C
select_upper_icon_palette_page_then_fall_through:
    .i16
    ldx #$0782

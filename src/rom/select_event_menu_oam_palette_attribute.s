; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-graphics.md.
.setcpu "65816"
.smart
.a8
.i16

select_event_menu_palette_slot = $70EC

.segment "CODE"
.org $70E3
select_event_menu_oam_palette_attribute:
    jsr select_event_menu_palette_slot
    xba
    asl
    .a16
    ora #$3000
    rts

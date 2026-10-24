; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-palette-graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $70EC
select_event_menu_palette_slot:
    sep #$20
    pha
    lda a:$1802
    .a8
    and #$01
    beq select_event_menu_palette_slot_c070fa
    .a8
    lda #$00
    bra select_event_menu_palette_slot_c070fc
select_event_menu_palette_slot_c070fa:
    .a8
    lda #$04
select_event_menu_palette_slot_c070fc:
    clc
    adc $01,S
    sta $01,S
    pla
    rep #$20
    .a16
    and #$0007
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-name-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $50E0
select_native_name_entry_tile_at_cursor:
    .a8
    lda #$00
    xba
    lda a:$A15A
    sec
    .a8
    sbc #$48
    .a8
    and #$F8
    rep #$20
    asl
    asl
    asl
    sta a:$A173
    lda a:$A159
    .a16
    and #$00FF
    sec
    .a16
    sbc #$0010
    .a16
    and #$00F8
    lsr
    lsr
    clc
    adc a:$A173
    tax
    lda a:$9246,X
    sec
    beq select_native_name_entry_tile_at_cursor_c75116
    sta a:$A1A0
    inc
    inc
    sta a:$A1A2
    clc
select_native_name_entry_tile_at_cursor_c75116:
    sep #$20
    rtl

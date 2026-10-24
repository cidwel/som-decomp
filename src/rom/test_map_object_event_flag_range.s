; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C757
test_map_object_event_flag_range:
    sep #$20
    .a8
    lda #$00
    xba
    lda a:$C808,Y
    phx
    tax
    lda a:$CF00,X
    plx
    sta $00
    lda a:$C809,Y
    pha
    .a8
    and #$0F
    sta $01
    pla
    lsr
    lsr
    lsr
    lsr
    sta $02
    lda $00
    cmp $02
    bcc test_map_object_event_flag_range_c2c784
    cmp $01
    beq test_map_object_event_flag_range_c2c782
    bcs test_map_object_event_flag_range_c2c784
test_map_object_event_flag_range_c2c782:
    sec
    rtl
test_map_object_event_flag_range_c2c784:
    clc
    rtl

; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0E2A
reverse_dialogue_bitmap_byte_preserving_counter_byte:
    xba
    pha
    stz a:$A198
    .a8
    lda #$08
reverse_dialogue_bitmap_byte_preserving_counter_byte_c00e31:
    xba
    asl
    ror a:$A198
    xba
    dec
    bne reverse_dialogue_bitmap_byte_preserving_counter_byte_c00e31
    pla
    xba
    lda a:$A198
    rts

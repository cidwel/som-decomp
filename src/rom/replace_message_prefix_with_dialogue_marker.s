; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


message_queue_buffer = $FE00

.segment "CODE"
.org $5A7F
replace_message_prefix_with_dialogue_marker:
    dey
    .a8
    lda #$30
    sta a:message_queue_buffer,Y
    iny
    rts

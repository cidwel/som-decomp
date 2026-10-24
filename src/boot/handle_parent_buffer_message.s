; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258
release_eight_byte_record = $B1DD

.segment "CODE"
.org $D081
handle_parent_buffer_message:
    phd
    php
    rep #$30
    sep #$20
    lda a:$0003,X
    pha
    jsr release_eight_byte_record
    pla
    .a8
    cmp #$01
    beq handle_parent_buffer_message_d098
    stz a:$0312
    bra handle_parent_buffer_message_d0ab
handle_parent_buffer_message_d098:
    jsr allocate_eight_byte_record
    rep #$20
    lda a:$0306
    sta a:$0004,X
    sep #$20
    lda a:$0312
    jsr append_pending_record
handle_parent_buffer_message_d0ab:
    plp
    pld
    rts

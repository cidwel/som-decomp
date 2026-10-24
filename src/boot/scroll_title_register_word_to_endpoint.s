; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_ppu_register_entry = $C030
append_oneshot_ppu_entry = $C097
dispatch_parent_messages = $D17F

.segment "CODE"
.org $D348
scroll_title_register_word_to_endpoint:
    phd
    php
    rep #$30
scroll_title_register_word_to_endpoint_d34c:
    .a16
    lda #$000E
    jsr allocate_ppu_register_entry
    lda a:$0002,X
    dec
    sta a:$0002,X
    pha
    jsr append_oneshot_ppu_entry
    pla
    .a16
    cmp #$FFF0
    beq scroll_title_register_word_to_endpoint_d371
    .i16
    ldx #$0008
    jsr dispatch_parent_messages
    .a16
    and #$00FF
    bne scroll_title_register_word_to_endpoint_d34c
    .a16
    lda #$0080
scroll_title_register_word_to_endpoint_d371:
    .a16
    eor #$0080
    plp
    pld
    rts

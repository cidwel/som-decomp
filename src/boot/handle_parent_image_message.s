; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_eight_byte_record = $B1A9
append_pending_record = $B258
release_eight_byte_record = $B1DD

.segment "CODE"
.org $CFE2
handle_parent_image_message:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    lda a:$0003,X
    sta $01
    lda a:$0004,X
    sta $02
    jsr release_eight_byte_record
    lda $01
    .a8
    cmp #$01
    beq handle_parent_image_message_d01c
    .a8
    cmp #$02
    beq handle_parent_image_message_d01c
    .a8
    cmp #$04
    beq handle_parent_image_message_d01c
    jsr allocate_eight_byte_record
    lda $02
    .a8
    cmp #$04
    bne handle_parent_image_message_d014
    .a8
    lda #$01
    sta a:$0003,X
handle_parent_image_message_d014:
    lda a:$0311
    jsr append_pending_record
    .a8
    lda #$00
handle_parent_image_message_d01c:
    sta $02,S
    pla
    pla
    plp
    pld
    rts

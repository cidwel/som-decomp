; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-line-completion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $133C
publish_eight_dialogue_control_object_sprite_records:
    rep #$20
    lda f:$001D14
    tax
    lda a:$0000,X
    .a16
    and #$00FF
    bne publish_eight_dialogue_control_object_sprite_records_c0139d
    lda f:$001D16
    tay
    sep #$20
    .i16
    ldx #$0028
    .a8
    lda #$08
publish_eight_dialogue_control_object_sprite_records_c01357:
    xba
    lda a:$0001,Y
    sec
    .a8
    sbc #$98
    sta f:$000800,X
    lda a:$0002,Y
    sta f:$000801,X
    lda a:$0003,Y
    sta f:$000802,X
    lda a:$0004,Y
    sta f:$000803,X
    iny
    iny
    iny
    iny
    dex
    dex
    dex
    dex
    xba
    dec
    bne publish_eight_dialogue_control_object_sprite_records_c01357
    lda f:$000A00
    .a8
    ora #$80
    sta f:$000A00
    .a8
    lda #$AA
    sta f:$000A01
    lda f:$000A02
    .a8
    ora #$2A
    sta f:$000A02
publish_eight_dialogue_control_object_sprite_records_c0139d:
    sep #$20
    rts

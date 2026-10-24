; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

animate_auxiliary_sprite_tile_orientation = $C485
prepare_auxiliary_sprite_screen_position = $C4C9
emit_packed_actor_sprite_list_long = $E324

.segment "CODE"
.org $C3E5
emit_one_actor_auxiliary_sprite_record:
    sep #$20
    lda a:$D000,Y
    bne emit_one_actor_auxiliary_sprite_record_c2c3ed
emit_one_actor_auxiliary_sprite_record_c2c3ec:
    rts
emit_one_actor_auxiliary_sprite_record_c2c3ed:
    .a8
    bit #$F8
    bne emit_one_actor_auxiliary_sprite_record_c2c3ec
    .a8
    cmp #$02
    beq emit_one_actor_auxiliary_sprite_record_c2c41b
    lda a:$D007,Y
    bne emit_one_actor_auxiliary_sprite_record_c2c405
    bcc emit_one_actor_auxiliary_sprite_record_c2c405
    lda $F4
    .a8
    bit #$03
    bne emit_one_actor_auxiliary_sprite_record_c2c405
    jsr animate_auxiliary_sprite_tile_orientation
emit_one_actor_auxiliary_sprite_record_c2c405:
    jsr prepare_auxiliary_sprite_screen_position
    .a16
    lda #$0001
    sta $02
    tya
    clc
    .a16
    adc #$000C
    .a16
    ora #$D000
    tax
    jsl f:emit_packed_actor_sprite_list_long
    rts
emit_one_actor_auxiliary_sprite_record_c2c41b:
    jsr prepare_auxiliary_sprite_screen_position
    .a16
    lda #$0002
    sta $02
    tya
    .a16
    and #$03C0
    .a16
    ora #$D038
    tax
    lda a:$D00C,Y
    sta a:$0000,X
    sta a:$0004,X
    lda a:$D00E,Y
    sta a:$0002,X
    sta a:$0006,X
    sep #$20
    lda a:$D001,Y
    .a8
    and #$03
    beq emit_one_actor_auxiliary_sprite_record_c2c467
    dec
    beq emit_one_actor_auxiliary_sprite_record_c2c46f
    dec
    beq emit_one_actor_auxiliary_sprite_record_c2c454
    lda a:$0004,X
    sec
    .a8
    sbc #$10
    bra emit_one_actor_auxiliary_sprite_record_c2c45a
emit_one_actor_auxiliary_sprite_record_c2c454:
    lda a:$0004,X
    clc
    .a8
    adc #$10
emit_one_actor_auxiliary_sprite_record_c2c45a:
    sta a:$0004,X
    lda a:$0007,X
    .a8
    eor #$40
    sta a:$0007,X
    bra emit_one_actor_auxiliary_sprite_record_c2c480
emit_one_actor_auxiliary_sprite_record_c2c467:
    lda a:$0005,X
    clc
    .a8
    adc #$10
    bra emit_one_actor_auxiliary_sprite_record_c2c475
emit_one_actor_auxiliary_sprite_record_c2c46f:
    lda a:$0005,X
    sec
    .a8
    sbc #$10
emit_one_actor_auxiliary_sprite_record_c2c475:
    sta a:$0005,X
    lda a:$0007,X
    .a8
    eor #$80
    sta a:$0007,X
emit_one_actor_auxiliary_sprite_record_c2c480:
    jsl f:emit_packed_actor_sprite_list_long
    rts

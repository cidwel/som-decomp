; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E5CE
prepare_and_emit_actor_body_sprites:
    sep #$20
    ldx $14
    lda a:$E00E,X
    beq prepare_and_emit_actor_body_sprites_c0e5e0
    asl
    bpl prepare_and_emit_actor_body_sprites_c0e5e0
    lda $F4
    lsr
    bcc prepare_and_emit_actor_body_sprites_c0e5e0
prepare_and_emit_actor_body_sprites_c0e5df:
    rts
prepare_and_emit_actor_body_sprites_c0e5e0:
    rep #$20
    lda a:$E083,X
    .a16
    and #$000F
    sta $02
    beq prepare_and_emit_actor_body_sprites_c0e5df
    lda $14
    .a16
    ora #$0090
    .a16
    ora #$E000
    tay
    ldx $14
    lda a:$E020,X
    sta $04
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    sec
    adc a:$E022,X
    sta $06
    sep #$20
    lda a:$E00D,X
    beq prepare_and_emit_actor_body_sprites_c0e63f
    sec
    .a8
    sbc #$10
    sta a:$E00D,X
    bcs prepare_and_emit_actor_body_sprites_c0e625
    .a8
    lda #$00
    sta a:$E00D,X
    bra prepare_and_emit_actor_body_sprites_c0e63f
prepare_and_emit_actor_body_sprites_c0e625:
    lsr
    bcc prepare_and_emit_actor_body_sprites_c0e633
    pha
    lda $F4
    .a8
    and #$01
    asl
    eor $04
    sta $04
    pla
prepare_and_emit_actor_body_sprites_c0e633:
    lsr
    bcc prepare_and_emit_actor_body_sprites_c0e63f
    lda $F4
    .a8
    and #$01
    asl
    eor $06
    sta $06
prepare_and_emit_actor_body_sprites_c0e63f:
    tyx

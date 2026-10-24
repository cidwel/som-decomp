; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

clip_and_emit_ground_shadow_piece = $E807

.segment "CODE"
.org $E760
emit_actor_ground_shadow:
    sep #$20
    .i16
    ldy #$FFF8
    sty $04
    lda a:$E00F,X
    beq emit_actor_ground_shadow_c0e76d
emit_actor_ground_shadow_c0e76c:
    rts
emit_actor_ground_shadow_c0e76d:
    sep #$20
    lda a:$CF01
    .a8
    bit #$06
    beq emit_actor_ground_shadow_c0e785
    .a8
    bit #$04
    beq emit_actor_ground_shadow_c0e780
    cpx $D4
    beq emit_actor_ground_shadow_c0e76c
    bne emit_actor_ground_shadow_c0e785
emit_actor_ground_shadow_c0e780:
    .i16
    cpx #$0600
    bcc emit_actor_ground_shadow_c0e76c
emit_actor_ground_shadow_c0e785:
    lda a:$E00E,X
    bmi emit_actor_ground_shadow_c0e76c
    lda a:$E074,X
    bpl emit_actor_ground_shadow_c0e76c
    stz $0E
    lda a:$E08E,X
    beq emit_actor_ground_shadow_c0e79c
    asl
    asl
    asl
    asl
    bra emit_actor_ground_shadow_c0e79f
emit_actor_ground_shadow_c0e79c:
    lda a:$E08B,X
emit_actor_ground_shadow_c0e79f:
    .a8
    and #$30
    sta $0F
    lda a:$E089,X
    .a8
    and #$03
    beq emit_actor_ground_shadow_c0e7b2
    dec
    beq emit_actor_ground_shadow_c0e7bd
    dec
    beq emit_actor_ground_shadow_c0e7d3
    bra emit_actor_ground_shadow_c0e7e9
emit_actor_ground_shadow_c0e7b2:
    rep #$20
    .a16
    lda #$0200
    .i16
    ldy #$FFF8
    brl clip_and_emit_ground_shadow_piece
emit_actor_ground_shadow_c0e7bd:
    rep #$20
    .a16
    lda #$0202
    .i16
    ldy #$FFF0
    jsr clip_and_emit_ground_shadow_piece
    rep #$20
    .a16
    lda #$4202
    .i16
    ldy #$0000
    brl clip_and_emit_ground_shadow_piece
emit_actor_ground_shadow_c0e7d3:
    rep #$20
    .a16
    lda #$0204
    .i16
    ldy #$FFF0
    jsr clip_and_emit_ground_shadow_piece
    rep #$20
    .a16
    lda #$4204
    .i16
    ldy #$0000
    brl clip_and_emit_ground_shadow_piece
emit_actor_ground_shadow_c0e7e9:
    rep #$20
    .a16
    lda #$0206
    .i16
    ldy #$FFE8
    jsr clip_and_emit_ground_shadow_piece
    rep #$20
    .a16
    lda #$0208
    .i16
    ldy #$FFF8
    jsr clip_and_emit_ground_shadow_piece
    rep #$20
    .a16
    lda #$4206
    .i16
    ldy #$0008

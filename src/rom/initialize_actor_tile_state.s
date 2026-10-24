; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DF37
initialize_actor_tile_state:
    rep #$30
    lda a:$E002,X
    lsr
    lsr
    lsr
    lsr
    sta $00
    lda a:$E004,X
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $00
    tay
    sep #$20
    .a8
    lda #$7F
    sta $06
    sta $09
    lda a:$E00B,X
    asl
    rep #$20
    bcc initialize_actor_tile_state_c1df6a
    .a16
    lda #$4000
    sta $04
    .a16
    lda #$BC00
    sta $07
    bra initialize_actor_tile_state_c1df74
initialize_actor_tile_state_c1df6a:
    .a16
    lda #$0000
    sta $04
    .a16
    lda #$B800
    sta $07
initialize_actor_tile_state_c1df74:
    lda [$04],Y
    sta $00
    .a16
    and #$00FF
    asl
    asl
    tay
    lda [$07],Y
    sep #$20
    .a8
    and #$03
    ora a:$E00B,X
    sta a:$E00B,X
    xba
    .a8
    and #$07
    sta a:$E08E,X
    lda $00
    sta a:$E04C,X
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-hidden-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1024
initialize_hidden_effect_global_handle_and_animation017A:
    sep #$20
    ldx a:$0287
    stz a:$0000,X
    rep #$20
    txa
    sta f:$001D14
    lda a:$0289
    sta f:$001D16
    .a16
    lda #$07FF
    sta a:$0022,X
    .a16
    lda #$0068
    sta a:$002B,X
    stz a:$0032,X
    .a16
    lda #$017A
    sta a:$009A,X
    stz a:$009C,X
    .a16
    lda #$0001
    sta a:$009E,X
    sep #$20
    sta a:$000B,X
    .a8
    lda #$CA
    sta a:$00A2,X
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-execution-check.md.
.setcpu "65816"
.smart
.a8
.i16

execute_ordinary_actor_cast_presentation = $8775
load_hero_cast_graphics_and_palette = $860A
prepare_actor_cast_directional_offset = $8898

.segment "CODE"
.org $8707
execute_actor_cast_request:
    sep #$20
    stz a:$E012,X
    stz a:$E025,X
    stz a:$E084,X
    bit $F1
    bpl execute_actor_cast_request_c1871a
    stz a:$E060,X
    rtl
execute_actor_cast_request_c1871a:
    .i16
    cpx #$0600
    bcc execute_actor_cast_request_c18723
    jsr execute_ordinary_actor_cast_presentation
    rtl
execute_actor_cast_request_c18723:
    stx $14
    jsr prepare_actor_cast_directional_offset
    sep #$20
    .a8
    lda #$80
    sta a:$E060,X
    lda a:$E170,X
    txy
    rep #$20
    .a16
    and #$007F
    asl
    asl
    asl
    asl
    asl
    asl
    tax
    rep #$20
    lda f:$D02AA0,X
    sta a:$E0FC,Y
    lda a:$E177,Y
    .a16
    and #$0007
    asl
    asl
    tax
    lda f:$D02A82,X
    sta a:$E06A,Y
    lda f:$D02A80,X
    sta $00
    sep #$20
    .i16
    cpy #$0400
    bcc execute_actor_cast_request_c18769
    lsr
    lsr
    lsr
    lsr
execute_actor_cast_request_c18769:
    .a8
    ora #$F0
    sta a:$E04F,Y
    tyx
    rep #$20
    jsr load_hero_cast_graphics_and_palette
    rtl

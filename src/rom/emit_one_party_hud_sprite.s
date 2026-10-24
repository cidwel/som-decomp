; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E668
emit_one_party_hud_sprite:
    xba
    .a8
    and #$1F
    dec
    dec
    asl
    asl
    asl
    sta $02
    .a8
    lda #$C7
    sta $03
    rep #$20
    .a16
    and #$0E00
    .a16
    ora #$3000
    sta $00
    tya
    ldy $7C
    ora $00
    sta a:$0802,Y
    lda $02
    sta a:$0800,Y
    tya
    clc
    .a16
    adc #$0004
    tay
    sty $7C
    sep #$20
    lda $59
    asl
    asl
    bcc emit_one_party_hud_sprite_c1e6a1
    inc $5A
    .a8
    lda #$01
emit_one_party_hud_sprite_c1e6a1:
    sta $59
    rts

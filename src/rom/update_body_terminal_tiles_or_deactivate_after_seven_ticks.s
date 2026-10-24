; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

ensure_regular_boss_animation_graphic_cached = $1B03

.segment "CODE"
.org $4D4C
update_body_terminal_tiles_or_deactivate_after_seven_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0007
    bcs update_body_terminal_tiles_or_deactivate_after_seven_ticks_c24d9a
    asl
    tax
    ldy $89
    lda a:$0000,Y
    .a16
    and #$00FF
    beq update_body_terminal_tiles_or_deactivate_after_seven_ticks_c24d98
    sta $95
    tya
    clc
    .a16
    adc #$0003
    tay
    phy
    lda f:$C24DAB,X
    sta $97
    sep #$10
    .a16
    and #$01FF
    jsr ensure_regular_boss_animation_graphic_cached
    rep #$10
    lda $97
    .a16
    and #$FE00
    .a16
    ora #$000A
    sta $97
    ply
    ldx $C5
update_body_terminal_tiles_or_deactivate_after_seven_ticks_c24d88:
    lda $97
    sta a:$0000,Y
    tya
    clc
    .a16
    adc #$0004
    tay
    inx
    cpx $95
    bcc update_body_terminal_tiles_or_deactivate_after_seven_ticks_c24d88
update_body_terminal_tiles_or_deactivate_after_seven_ticks_c24d98:
    clc
    rts
update_body_terminal_tiles_or_deactivate_after_seven_ticks_c24d9a:
    stz a:$0000,X
    sep #$20
    lda a:$0380
    .a8
    and #$7F
    sta a:$0380
    rep #$20
    sec
    rts

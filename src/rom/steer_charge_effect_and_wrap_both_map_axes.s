; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-effect-update.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C681
steer_charge_effect_and_wrap_both_map_axes:
    sep #$20
    lda a:$D00A,Y
    clc
    .a8
    adc #$08
    bcc steer_charge_effect_and_wrap_both_map_axes_c2c68d
    .a8
    sbc #$08
steer_charge_effect_and_wrap_both_map_axes_c2c68d:
    sta a:$D00A,Y
    rep #$20
    .a16
    and #$00FF
    asl
    phx
    tax
    lda f:$00FD22,X
    lsr
    lsr
    lsr
    lsr
    lsr
    sta $02
    plx
    lda a:$E020,X
    sec
    sbc $04
    bpl steer_charge_effect_and_wrap_both_map_axes_c2c6b9
    .a16
    cmp #$FFF8
    bcs steer_charge_effect_and_wrap_both_map_axes_c2c6c0
    lda $02
    .a16
    eor #$FFFF
    inc
    bra steer_charge_effect_and_wrap_both_map_axes_c2c6c0
steer_charge_effect_and_wrap_both_map_axes_c2c6b9:
    .a16
    cmp #$0008
    bcc steer_charge_effect_and_wrap_both_map_axes_c2c6c0
    lda $02
steer_charge_effect_and_wrap_both_map_axes_c2c6c0:
    sta $00
    lda a:$E074,X
    .a16
    and #$007F
    clc
    adc a:$E045,X
    .a16
    eor #$FFFF
    sec
    adc a:$E022,X
    sec
    sbc $06
    bpl steer_charge_effect_and_wrap_both_map_axes_c2c6e5
    .a16
    cmp #$FFF8
    bcs steer_charge_effect_and_wrap_both_map_axes_c2c6ec
    lda $02
    .a16
    eor #$FFFF
    inc
    bra steer_charge_effect_and_wrap_both_map_axes_c2c6ec
steer_charge_effect_and_wrap_both_map_axes_c2c6e5:
    .a16
    cmp #$0008
    bcc steer_charge_effect_and_wrap_both_map_axes_c2c6ec
    lda $02
steer_charge_effect_and_wrap_both_map_axes_c2c6ec:
    sta $02
    lda a:$D001,Y
    .a16
    and #$0003
    beq steer_charge_effect_and_wrap_both_map_axes_c2c714
    dec
    beq steer_charge_effect_and_wrap_both_map_axes_c2c720
    dec
    beq steer_charge_effect_and_wrap_both_map_axes_c2c708
    lda $00
    bpl steer_charge_effect_and_wrap_both_map_axes_c2c72a
    .a16
    eor #$FFFF
    inc
    sta $00
    bra steer_charge_effect_and_wrap_both_map_axes_c2c72a
steer_charge_effect_and_wrap_both_map_axes_c2c708:
    lda $00
    bmi steer_charge_effect_and_wrap_both_map_axes_c2c72a
    .a16
    eor #$FFFF
    inc
    sta $00
    bra steer_charge_effect_and_wrap_both_map_axes_c2c72a
steer_charge_effect_and_wrap_both_map_axes_c2c714:
    lda $02
    bpl steer_charge_effect_and_wrap_both_map_axes_c2c72a
    .a16
    eor #$FFFF
    inc
    sta $02
    bra steer_charge_effect_and_wrap_both_map_axes_c2c72a
steer_charge_effect_and_wrap_both_map_axes_c2c720:
    lda $02
    bmi steer_charge_effect_and_wrap_both_map_axes_c2c72a
    .a16
    eor #$FFFF
    inc
    sta $02
steer_charge_effect_and_wrap_both_map_axes_c2c72a:
    lda $02
    clc
    adc a:$D004,Y
    bpl steer_charge_effect_and_wrap_both_map_axes_c2c737
    clc
    adc $C2
    bra steer_charge_effect_and_wrap_both_map_axes_c2c73d
steer_charge_effect_and_wrap_both_map_axes_c2c737:
    cmp $C2
    bcc steer_charge_effect_and_wrap_both_map_axes_c2c73d
    sbc $C2
steer_charge_effect_and_wrap_both_map_axes_c2c73d:
    sta a:$D004,Y
    lda $00
    clc
    adc a:$D002,Y
    bpl steer_charge_effect_and_wrap_both_map_axes_c2c74d
    clc
    adc $C0
    bra steer_charge_effect_and_wrap_both_map_axes_c2c753
steer_charge_effect_and_wrap_both_map_axes_c2c74d:
    cmp $C0
    bcc steer_charge_effect_and_wrap_both_map_axes_c2c753
    sbc $C0
steer_charge_effect_and_wrap_both_map_axes_c2c753:
    sta a:$D002,Y
    rts

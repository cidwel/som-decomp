; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BF83
prepare_actor_charge_effect_eight_tiles:
    phx
    stx $0A
    lda a:$D000,Y
    phy
    ldy a:$E06C,X
    .a8
    cmp #$01
    bne prepare_actor_charge_effect_eight_tiles_c2bfa0
    lda a:$E010,X
    .i16
    ldx #$FFC8
    .a8
    cmp #$02
    bcs prepare_actor_charge_effect_eight_tiles_c2bfc4
    .i16
    ldx #$FFD0
    bra prepare_actor_charge_effect_eight_tiles_c2bfc4
prepare_actor_charge_effect_eight_tiles_c2bfa0:
    .a8
    cmp #$02
    bne prepare_actor_charge_effect_eight_tiles_c2bfb3
    lda a:$E010,X
    .i16
    ldx #$FFD8
    .a8
    cmp #$02
    bcs prepare_actor_charge_effect_eight_tiles_c2bfc4
    .i16
    ldx #$FFE0
    bra prepare_actor_charge_effect_eight_tiles_c2bfc4
prepare_actor_charge_effect_eight_tiles_c2bfb3:
    .i16
    ldx #$FFE8
    .a8
    cmp #$03
    beq prepare_actor_charge_effect_eight_tiles_c2bfc4
    .i16
    ldx #$FFF0
    .a8
    cmp #$04
    beq prepare_actor_charge_effect_eight_tiles_c2bfc4
    .i16
    ldx #$FFF8
prepare_actor_charge_effect_eight_tiles_c2bfc4:
    rep #$20
    tya
    clc
    .a16
    adc #$0040
    tay
    lda $0A
    asl
    asl
    asl
    clc
    .a16
    adc #$2000
    sta $0A
    .a16
    lda #$0008
prepare_actor_charge_effect_eight_tiles_c2bfda:
    pha
    lda f:$D40000,X
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    bne prepare_actor_charge_effect_eight_tiles_c2bfec
    .a16
    lda #$CB00
    bra prepare_actor_charge_effect_eight_tiles_c2bff3
prepare_actor_charge_effect_eight_tiles_c2bfec:
    asl
    asl
    asl
    asl
    asl
    adc $0A
prepare_actor_charge_effect_eight_tiles_c2bff3:
    sta a:$0000,Y
    iny
    iny
    inx
    pla
    dec
    bne prepare_actor_charge_effect_eight_tiles_c2bfda
    ply
    plx
    rts

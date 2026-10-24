; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-gauge-presentation.md.
.setcpu "65816"
.smart
.a8
.i16

convert_hardware_charge_percentage_to_native_three_glyphs = $ECB1
routine_01c9f1 = $1C9F1
routine_01ca04 = $1CA04
routine_c0bb11 = $BB11

.segment "CODE"
.org $EBB6
present_actor_charge_gauge_and_deferred_flash:
    pha
    rep #$20
    txa
    xba
    asl
    asl
    asl
    tay
    .a16
    lda #$2817
    sta a:$0A56,Y
    sep #$20
    pla
    bne present_actor_charge_gauge_and_deferred_flash_c0ec07
    lda a:$E063,X
    clc
    .a8
    adc #$10
    sta a:$E063,X
    .a8
    and #$F0
    beq present_actor_charge_gauge_and_deferred_flash_c0ebe8
    inc a:$E1ED,X
    .a8
    cmp #$40
    bne present_actor_charge_gauge_and_deferred_flash_c0ebe4
    phy
    jsl f:routine_01c9f1
    ply
present_actor_charge_gauge_and_deferred_flash_c0ebe4:
    .a8
    lda #$00
    bra present_actor_charge_gauge_and_deferred_flash_c0ec07
present_actor_charge_gauge_and_deferred_flash_c0ebe8:
    sta a:$0A50,Y
    sta a:$0A51,Y
    sta a:$0A52,Y
    sta a:$0A53,Y
    sta a:$0A54,Y
    sec
    jsl f:routine_01ca04
    lda a:$E02C,X
    bne present_actor_charge_gauge_and_deferred_flash_c0ec02
    rts
present_actor_charge_gauge_and_deferred_flash_c0ec02:
    .a8
    lda #$A6
    jmp routine_c0bb11
present_actor_charge_gauge_and_deferred_flash_c0ec07:
    sta f:$004202
    .a8
    lda #$64
    sta f:$004203
    rep #$20
    txa
    sep #$20
    xba
    lsr
    sta $00
    lda $F4
    .a8
    and #$03
    cmp $00
    beq present_actor_charge_gauge_and_deferred_flash_c0ec23
    rts
present_actor_charge_gauge_and_deferred_flash_c0ec23:
    .a8
    lda #$64
    sec
    sbc a:$E189,X
    lsr
    clc
    .a8
    adc #$32
    sta $00
    rep #$20
    lda f:$004216
    sta f:$004204
    sep #$20
    lda $00
    sta f:$004206
    .a8
    lda #$14
    sta a:$0A50,Y
    inc
    sta a:$0A54,Y
    jsr convert_hardware_charge_percentage_to_native_three_glyphs
    sep #$20
    lda $02
    clc
    .a8
    adc #$08
    sta a:$0A51,Y
    lda $01
    clc
    .a8
    adc #$08
    sta a:$0A52,Y
    lda $00
    clc
    .a8
    adc #$08
    sta a:$0A53,Y
    rep #$20
    tya
    lsr
    tay
    lda f:$001D04
    .a16
    bit #$0020
    bne present_actor_charge_gauge_and_deferred_flash_c0ec85
    lda f:$D27E00
    sta a:$060C,Y
    lda f:$D27E02
    sta a:$060E,Y
    bra present_actor_charge_gauge_and_deferred_flash_c0ec93
present_actor_charge_gauge_and_deferred_flash_c0ec85:
    lda f:$D27E00
    sta a:$DE0C,Y
    lda f:$D27E02
    sta a:$DE0E,Y
present_actor_charge_gauge_and_deferred_flash_c0ec93:
    sep #$20
    .i16
    cpx #$0600
    bcs present_actor_charge_gauge_and_deferred_flash_c0ecb0
    lda a:$E02C,X
    beq present_actor_charge_gauge_and_deferred_flash_c0ecb0
    lda a:$E1ED,X
    .a8
    cmp #$02
    bcc present_actor_charge_gauge_and_deferred_flash_c0ecb0
    lda a:$E100,X
    bmi present_actor_charge_gauge_and_deferred_flash_c0ecb0
    clc
    jsl f:routine_01ca04
present_actor_charge_gauge_and_deferred_flash_c0ecb0:
    rts

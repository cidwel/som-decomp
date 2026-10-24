; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

copy_actor_charge_effect_secondary_records = $C000
prepare_actor_charge_effect_eight_tiles = $BF83
prepare_actor_charge_effect_primary_record = $C021

.segment "CODE"
.org $BF1D
initialize_actor_charge_effect_records:
    sep #$20
    lda a:$E061,X
    beq initialize_actor_charge_effect_records_c2bf25
initialize_actor_charge_effect_records_c2bf24:
    rtl
initialize_actor_charge_effect_records_c2bf25:
    rep #$20
    txa
    lsr
    lsr
    lsr
    tay
    sep #$20
    lda a:$D030,Y
    beq initialize_actor_charge_effect_records_c2bf24
    stz a:$E02E,X
    inc a:$E061,X
    jsr prepare_actor_charge_effect_primary_record
    jsr copy_actor_charge_effect_secondary_records
    sep #$20
    lda a:$E19B,X
    .a8
    cmp #$06
    bcc initialize_actor_charge_effect_records_c2bf59
    lda a:$D000,Y
    pha
    .a8
    ora #$50
    sta a:$D010,Y
    pla
    .a8
    ora #$A0
    sta a:$D020,Y
    bra initialize_actor_charge_effect_records_c2bf65
initialize_actor_charge_effect_records_c2bf59:
    .a8
    cmp #$03
    bcc initialize_actor_charge_effect_records_c2bf7c
    lda a:$D000,Y
    .a8
    ora #$50
    sta a:$D010,Y
initialize_actor_charge_effect_records_c2bf65:
    lda a:$D000,Y
    .a8
    and #$07
    .a8
    cmp #$02
    bne initialize_actor_charge_effect_records_c2bf7c
    lda a:$D00A,Y
    clc
    .a8
    adc #$02
    sta a:$D01A,Y
    .a8
    adc #$02
    sta a:$D02A,Y
initialize_actor_charge_effect_records_c2bf7c:
    inc a:$E08D,X
    jsr prepare_actor_charge_effect_eight_tiles
    rtl

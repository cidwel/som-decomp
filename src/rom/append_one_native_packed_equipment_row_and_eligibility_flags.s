; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-builder.md.
.setcpu "65816"
.smart
.a8
.i16

routine_d0cebf = $D0CEBF
test_native_equipment_row_eligibility_from_hero_state_and_level = $C073AC

.segment "CODE"
.org $D058
append_one_native_packed_equipment_row_and_eligibility_flags:
    pha
    phx
    .a16
    and #$0001
    beq append_one_native_packed_equipment_row_and_eligibility_flags_d0d0a7
    lda a:$1808
    .a16
    and #$00FF
    dec
    bne append_one_native_packed_equipment_row_and_eligibility_flags_d0d06e
    txa
    clc
    .a16
    adc #$0006
    tax
append_one_native_packed_equipment_row_and_eligibility_flags_d0d06e:
    txa
    clc
    adc a:$1828
    tax
    lda f:$D80000,X
    .a16
    and #$FF7F
    sta a:$0000,Y
    sep #$20
    lda f:$D80000,X
    .a8
    and #$80
    sta a:$0021,Y
    lda a:$184F
    jsl f:routine_d0cebf
    rep #$30
    jsl f:test_native_equipment_row_eligibility_from_hero_state_and_level
    bcs append_one_native_packed_equipment_row_and_eligibility_flags_d0d0a3
    rep #$30
    lda a:$0020,Y
    .a16
    ora #$4000
    sta a:$0020,Y
append_one_native_packed_equipment_row_and_eligibility_flags_d0d0a3:
    rep #$30
    iny
    iny
append_one_native_packed_equipment_row_and_eligibility_flags_d0d0a7:
    inc a:$184F
    plx
    inx
    inx
    pla
    lsr
    rts

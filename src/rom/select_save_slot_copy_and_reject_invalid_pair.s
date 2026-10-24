; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-load.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $583C
select_save_slot_copy_and_reject_invalid_pair:
    lda a:$A215
    sta a:$A216
    lda a:$A211
    pha
    rep #$20
    .a16
    and #$00FF
    xba
    asl
    asl
    tax
    sep #$20
    pla
    beq select_save_slot_copy_and_reject_invalid_pair_c7585d
select_save_slot_copy_and_reject_invalid_pair_c75854:
    lsr a:$A216
    lsr a:$A216
    dec
    bne select_save_slot_copy_and_reject_invalid_pair_c75854
select_save_slot_copy_and_reject_invalid_pair_c7585d:
    lda a:$A216
    .a8
    bit #$01
    beq select_save_slot_copy_and_reject_invalid_pair_c75879
    .a8
    bit #$02
    bne select_save_slot_copy_and_reject_invalid_pair_c75874
    rep #$20
    txa
    clc
    .a16
    adc #$1000
    tax
    sep #$20
    bra select_save_slot_copy_and_reject_invalid_pair_c75879
select_save_slot_copy_and_reject_invalid_pair_c75874:
    .a8
    lda #$04
    tsb a:$A212
select_save_slot_copy_and_reject_invalid_pair_c75879:
    rts

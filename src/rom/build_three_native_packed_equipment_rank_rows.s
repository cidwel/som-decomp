; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-inventory-builder.md.
.setcpu "65816"
.smart
.a8
.i16

append_one_native_packed_equipment_row_and_eligibility_flags = $D058
locate_selected_armor_with_nonzero_level = $D0D0DA
locate_selected_weapon_with_nonzero_level = $D0D0B0

.segment "CODE"
.org $CFFA
build_three_native_packed_equipment_rank_rows:
    lda a:$1808
    .a16
    and #$00FF
    dec
    bne build_three_native_packed_equipment_rank_rows_d0d014
    jsl f:locate_selected_weapon_with_nonzero_level
    pha
    lda a:$1878,X
    .a16
    and #$00F0
    lsr
    lsr
    lsr
    lsr
    bra build_three_native_packed_equipment_rank_rows_d0d01f
build_three_native_packed_equipment_rank_rows_d0d014:
    jsl f:locate_selected_armor_with_nonzero_level
    pha
    lda a:$1878,X
    .a16
    and #$000F
build_three_native_packed_equipment_rank_rows_d0d01f:
    sta a:$182E
    .i16
    cpx #$0007
    bne build_three_native_packed_equipment_rank_rows_d0d028
    dex
build_three_native_packed_equipment_rank_rows_d0d028:
    txa
    asl
    pha
    asl
    clc
    adc $01,S
    sta $01,S
    lda a:$1808
    .a16
    bit #$0001
    beq build_three_native_packed_equipment_rank_rows_d0d040
    lda $01,S
    inc
    inc
    inc
    sta $01,S
build_three_native_packed_equipment_rank_rows_d0d040:
    pla
    sta a:$184F
    txa
    asl
    tax
    lda f:$D8FD70,X
    sta a:$1828
    pla
    .i16
    ldx #$0000
    jsr append_one_native_packed_equipment_row_and_eligibility_flags
    jsr append_one_native_packed_equipment_row_and_eligibility_flags

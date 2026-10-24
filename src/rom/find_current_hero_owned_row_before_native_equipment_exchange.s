; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-swap.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c07598 = $7598
routine_c0777d = $777D

.segment "CODE"
.org $7715
find_current_hero_owned_row_before_native_equipment_exchange:
    sep #$30
    lda a:$185C
    cmp a:$180A
    bne routine_c0777d
    ldy a:$180B
    .i8
    ldx #$00
    lda a:$1808
    inc
find_current_hero_owned_row_before_native_equipment_exchange_c07728:
    cmp a:$18A0,X
    beq find_current_hero_owned_row_before_native_equipment_exchange_c07735
    inx
    inx
    dey
    bne find_current_hero_owned_row_before_native_equipment_exchange_c07728
    jmp routine_c07598
find_current_hero_owned_row_before_native_equipment_exchange_c07735:
    txa
    lsr
    sta a:$185C

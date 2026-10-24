; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-swap.md.
.setcpu "65816"
.smart
.a8
.i16

locate_menu_category_inventory_and_equipment_spans = $D0C800
publish_native_inventory_owner_bits_after_equipment_exchange = $77E7
publish_native_menu_transaction_result_with_real_vblank_and_ring_phase = $761A
read_native_actor_equipment_field_and_restore_index_status = $7A54
resolve_native_owned_row_actor_and_physical_inventory_slot = $7866
routine_c07601 = $7601
routine_c07732 = $7732
validate_write_native_exchanged_equipment_and_rebuild_actor = $781E

.segment "CODE"
.org $773A
exchange_native_equipment_fields_and_inventory_ownership:
    sep #$20
    .a8
    lda #$20
    tsb a:$1804
    jsl f:locate_menu_category_inventory_and_equipment_spans
    rep #$30
    sty a:$1853
    stz a:$1820
    lda a:$185C
    jsr resolve_native_owned_row_actor_and_physical_inventory_slot
    stx a:$184F
    sty a:$1855
    lda a:$180A
    jsr resolve_native_owned_row_actor_and_physical_inventory_slot
    stx a:$1851
    sty a:$1857
    sep #$20
    lda a:$19F0
    .a8
    cmp #$02
    bne exchange_native_equipment_fields_and_inventory_ownership_c0777f
    lda f:$7EE01C,X
    bne exchange_native_equipment_fields_and_inventory_ownership_c0777d
    ldx a:$184F
    lda f:$7EE01C,X
    beq exchange_native_equipment_fields_and_inventory_ownership_c0777f
exchange_native_equipment_fields_and_inventory_ownership_c0777d:
    bra routine_c07732
exchange_native_equipment_fields_and_inventory_ownership_c0777f:
    rep #$30
    inc a:$1820
    lda a:$185C
    jsr resolve_native_owned_row_actor_and_physical_inventory_slot
    lda a:$180A
    jsr resolve_native_owned_row_actor_and_physical_inventory_slot
    lda a:$184F
    clc
    adc a:$1853
    tax
    jsr read_native_actor_equipment_field_and_restore_index_status
    pha
    phx
    lda a:$1851
    clc
    adc a:$1853
    tax
    jsr read_native_actor_equipment_field_and_restore_index_status
    plx
    jsr validate_write_native_exchanged_equipment_and_rebuild_actor
    lda a:$1851
    clc
    adc a:$1853
    tax
    pla
    jsr validate_write_native_exchanged_equipment_and_rebuild_actor
    lda a:$184F
    ldy a:$1857
    jsr publish_native_inventory_owner_bits_after_equipment_exchange
    lda a:$1851
    ldy a:$1855
    jsr publish_native_inventory_owner_bits_after_equipment_exchange
    sep #$20
    lda a:$1850
    bne exchange_native_equipment_fields_and_inventory_ownership_c077d2
    inc
exchange_native_equipment_fields_and_inventory_ownership_c077d2:
    sta a:$19F2
    lda a:$1852
    bne exchange_native_equipment_fields_and_inventory_ownership_c077db
    inc
exchange_native_equipment_fields_and_inventory_ownership_c077db:
    ora a:$19F2
    sta a:$19F2
    jsr publish_native_menu_transaction_result_with_real_vblank_and_ring_phase
    jmp routine_c07601

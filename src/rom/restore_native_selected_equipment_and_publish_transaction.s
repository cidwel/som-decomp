; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_native_equipment_stats_publish_rows_and_request_refresh = $75E4
remove_native_inventory_owner_and_return_owner_bits = $76CC
routine_c07598 = $7598
write_native_actor_equipment_field_with_weapon_palette_alias = $7A7D

.segment "CODE"
.org $7571
restore_native_selected_equipment_and_publish_transaction:
    sep #$20
    lda a:$1809
    .a8
    cmp #$03
    beq routine_c07598
    lda a:$1808
    jsr remove_native_inventory_owner_and_return_owner_bits
    ldx a:$182A
    lda a:$1840
    jsr write_native_actor_equipment_field_with_weapon_palette_alias
    jsr rebuild_native_equipment_stats_publish_rows_and_request_refresh
    sep #$20
    .a8
    lda #$42
    trb a:$1803
    rts

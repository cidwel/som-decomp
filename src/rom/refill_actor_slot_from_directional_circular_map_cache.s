; Recovered Secret of Mana USA routine; behaviour documented in docs/map-object-refill-cpu.md.
.setcpu "65816"
.smart
.a8
.i16

scan_map_object_cache_for_creation = $DDBE
select_directional_map_object_load_window = $E058

.segment "CODE"
.org $DFD4
refill_actor_slot_from_directional_circular_map_cache:
    sep #$20
    lda $FF
    ora $52
    bne refill_actor_slot_from_directional_circular_map_cache_c0dfe6
    lda $E8
    .a8
    and #$04
    bne refill_actor_slot_from_directional_circular_map_cache_c0dfe6
    lda $BC
    bne refill_actor_slot_from_directional_circular_map_cache_c0dfe7
refill_actor_slot_from_directional_circular_map_cache_c0dfe6:
    rts
refill_actor_slot_from_directional_circular_map_cache_c0dfe7:
    jsr select_directional_map_object_load_window
    sep #$20
    lda $BC
    lsr
    lsr
    lsr
    inc
    sta $0C
    clc
    adc $BD
    cmp $BC
    bcc refill_actor_slot_from_directional_circular_map_cache_c0dffd
    sbc $BC
refill_actor_slot_from_directional_circular_map_cache_c0dffd:
    sta $BD
    rep #$20
    .a16
    and #$00FF
    asl
    asl
    asl
    asl
    tay
    jmp scan_map_object_cache_for_creation

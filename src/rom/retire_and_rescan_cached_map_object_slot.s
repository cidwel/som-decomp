; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-object-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

release_map_actor_to_object_cache = $E2E1
scan_map_object_cache_for_creation = $DDBE

.segment "CODE"
.org $E00C
retire_and_rescan_cached_map_object_slot:
    sep #$20
    lda a:$E000,X
    beq retire_and_rescan_cached_map_object_slot_c0e019
    stz a:$E000,X
    jsr release_map_actor_to_object_cache
retire_and_rescan_cached_map_object_slot_c0e019:
    sep #$20
    stz a:$E043,X
    lda $BC
    sta $0C
    .i16
    ldy #$0000
    rep #$20
    stz $04
    stz $06
    .a16
    lda #$FFFF
    sta $08
    jsr scan_map_object_cache_for_creation
    rtl

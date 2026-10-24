; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_map_object_cache_and_saved_positions = $DCFC
prepare_map_object_slots_and_buffers = $E1A8
scan_initial_map_object_slots = $DD8B

.segment "CODE"
.org $DCDC
load_ordinary_map_objects:
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    lda a:$E800
    sta $BC
load_ordinary_map_objects_c0dce8:
    .a8
    cmp #$31
    bcs load_ordinary_map_objects_c0dce8
    lda a:$E804
    sta $0F
    jsr prepare_map_object_slots_and_buffers
    jsr initialize_map_object_cache_and_saved_positions
    jsr scan_initial_map_object_slots
    plb
    rts

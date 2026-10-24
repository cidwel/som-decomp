; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

advance_boss_object_counters_and_dispatch_definition = $0F83
reload_boss_graphics_cache_markers_through_wram_port = $0E6A
resolve_boss_contacts_combat_and_publish_counter_request = $0F27
snapshot_boss_camera_and_tick_enabled_animation = $0E42
store_three_party_relative_distances_and_direction_bits = $0E9B

.segment "CODE"
.org $0DB2
update_nine_boss_actor_slots_combat_definition_and_animation:
    stz a:$0E69
    sep #$20
    lda a:$0056
    sta a:$02C9
    bne update_nine_boss_actor_slots_combat_definition_and_animation_c20dc2
    jsr reload_boss_graphics_cache_markers_through_wram_port
update_nine_boss_actor_slots_combat_definition_and_animation_c20dc2:
    stz $CA
    .i16
    ldx #$0000
update_nine_boss_actor_slots_combat_definition_and_animation_c20dc7:
    lda a:$0E60,X
    beq update_nine_boss_actor_slots_combat_definition_and_animation_c20e39
    phx
    rep #$20
    txa
    sta $8B
    xba
    asl
    clc
    .a16
    adc #$E600
    tax
    stx $87
    lda $8B
    xba
    lsr
    clc
    .a16
    adc #$F800
    sta $89
    lda a:$0098,X
    .a16
    bit #$4000
    bne update_nine_boss_actor_slots_combat_definition_and_animation_c20df8
    lda a:$0099,X
    eor a:$02C9
    .a16
    and #$0003
    bne update_nine_boss_actor_slots_combat_definition_and_animation_c20e36
update_nine_boss_actor_slots_combat_definition_and_animation_c20df8:
    lda a:$0098,X
    .a16
    bit #$2000
    bne update_nine_boss_actor_slots_combat_definition_and_animation_c20e1e
    lda a:$0094,X
    beq update_nine_boss_actor_slots_combat_definition_and_animation_c20e16
    lda f:$7ECFFF
    .a16
    bit #$0001
    bne update_nine_boss_actor_slots_combat_definition_and_animation_c20e36
    lda a:$1D04
    .a16
    bit #$0040
    bne update_nine_boss_actor_slots_combat_definition_and_animation_c20e36
update_nine_boss_actor_slots_combat_definition_and_animation_c20e16:
    jsr store_three_party_relative_distances_and_direction_bits
    jsr resolve_boss_contacts_combat_and_publish_counter_request
    ldx $87
update_nine_boss_actor_slots_combat_definition_and_animation_c20e1e:
    jsr advance_boss_object_counters_and_dispatch_definition
    ldx $87
    bcc update_nine_boss_actor_slots_combat_definition_and_animation_c20e33
    stz a:$0000,X
    stz a:$008C,X
    plx
    sep #$20
    stz a:$0E60,X
    bra update_nine_boss_actor_slots_combat_definition_and_animation_c20e39
update_nine_boss_actor_slots_combat_definition_and_animation_c20e33:
    jsr snapshot_boss_camera_and_tick_enabled_animation
update_nine_boss_actor_slots_combat_definition_and_animation_c20e36:
    plx
    sep #$20
update_nine_boss_actor_slots_combat_definition_and_animation_c20e39:
    inx
    .i16
    cpx #$0009
    bne update_nine_boss_actor_slots_combat_definition_and_animation_c20dc7
    rep #$20
    rts

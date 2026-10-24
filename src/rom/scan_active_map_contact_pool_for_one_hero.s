; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-map-contacts.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_fixed_radius_contact_distance = $CE59
probe_map_cell_contact_and_update_live_tile = $D293
resolve_toroidal_map_contact_distance_event_and_motion = $CE62

.segment "CODE"
.org $CDCD
scan_active_map_contact_pool_for_one_hero:
    sep #$20
    lda a:$E000,X
    bne scan_active_map_contact_pool_for_one_hero_c1cdd5
scan_active_map_contact_pool_for_one_hero_c1cdd4:
    rts
scan_active_map_contact_pool_for_one_hero_c1cdd5:
    bmi scan_active_map_contact_pool_for_one_hero_c1cdd4
    lda a:$E00E,X
    ora a:$E191,X
    bmi scan_active_map_contact_pool_for_one_hero_c1cdd4
    bit $ED
    bmi scan_active_map_contact_pool_for_one_hero_c1ce14
    lda a:$E02C,X
    bne scan_active_map_contact_pool_for_one_hero_c1cde9
    rts
scan_active_map_contact_pool_for_one_hero_c1cde9:
    .i16
    ldy #$0600
scan_active_map_contact_pool_for_one_hero_c1cdec:
    sep #$20
    lda a:$E000,Y
    beq scan_active_map_contact_pool_for_one_hero_c1ce06
    bmi scan_active_map_contact_pool_for_one_hero_c1ce06
    lda a:$E00B,X
    eor a:$E00B,Y
    bmi scan_active_map_contact_pool_for_one_hero_c1ce06
    .a8
    and #$03
    .a8
    cmp #$03
    beq scan_active_map_contact_pool_for_one_hero_c1ce06
    jsr prepare_fixed_radius_contact_distance
scan_active_map_contact_pool_for_one_hero_c1ce06:
    rep #$20
    tya
    clc
    .a16
    adc #$0200
    tay
    .a16
    cmp #$1800
    bcc scan_active_map_contact_pool_for_one_hero_c1cdec
    rts
scan_active_map_contact_pool_for_one_hero_c1ce14:
    lda $82
    bne scan_active_map_contact_pool_for_one_hero_c1ce20
    lda a:$E0C2,X
    beq scan_active_map_contact_pool_for_one_hero_c1ce20
    jsr probe_map_cell_contact_and_update_live_tile
scan_active_map_contact_pool_for_one_hero_c1ce20:
    sep #$20
    .a8
    lda #$11
    sta $50
    .i16
    ldy #$0600
scan_active_map_contact_pool_for_one_hero_c1ce29:
    sep #$20
    lda a:$E000,Y
    beq scan_active_map_contact_pool_for_one_hero_c1ce43
    bmi scan_active_map_contact_pool_for_one_hero_c1ce43
    lda a:$E00B,X
    eor a:$E00B,Y
    bmi scan_active_map_contact_pool_for_one_hero_c1ce43
    .a8
    and #$03
    .a8
    cmp #$03
    beq scan_active_map_contact_pool_for_one_hero_c1ce43
    jsr resolve_toroidal_map_contact_distance_event_and_motion
scan_active_map_contact_pool_for_one_hero_c1ce43:
    sep #$20
    asl $50
    rep #$20
    tya
    clc
    .a16
    adc #$0200
    tay
    .a16
    cmp #$0C00
    bcc scan_active_map_contact_pool_for_one_hero_c1ce29
    sep #$20
    asl $51
    rts

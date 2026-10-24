; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-action-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
create_boss_projectile_with_graphics_and_palette = $33BE
derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
select_farthest_active_living_party_actor_last_tie = $325A
select_nearest_living_target_and_eight_way_direction = $3A41

.segment "CODE"
.org $7D5B
choose_native58_farthest_close_or_nearest_projectile_attack:
    .a16
    lda #$0001
    jsr draw_boss_frame_random_number
    bne choose_native58_farthest_close_or_nearest_projectile_attack_c27d97
    ldx $87
    jsr select_farthest_active_living_party_actor_last_tie
    ldx $87
    sta a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    .a16
    cmp #$0008
    bcs choose_native58_farthest_close_or_nearest_projectile_attack_c27d8b
    stz $95
    stz $97
    ldy a:$00A9,X
    .a16
    lda #$001C
    jsr create_boss_projectile_with_graphics_and_palette
    .a16
    lda #$002E
    ldx $87
    jsl f:boss_attack_row_public_jump
choose_native58_farthest_close_or_nearest_projectile_attack_c27d8b:
    ldx $87
    .a16
    lda #$0001
    eor a:$00B8,X
    sta a:$00B8,X
    rts
choose_native58_farthest_close_or_nearest_projectile_attack_c27d97:
    ldx $87
    jsr select_nearest_living_target_and_eight_way_direction
    stz $95
    stz $97
    ldy a:$00A9,X
    .a16
    lda #$001E
    jsr create_boss_projectile_with_graphics_and_palette
    .a16
    lda #$002E
    ldx $87
    jsl f:boss_attack_row_public_jump
    ldx $87
    rts

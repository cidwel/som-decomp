; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16

add_direction_table_acceleration_and_clamp_boss_velocity = $32BC
copy_boss_palette_with_cpu_words = $26F9
derive_eight_way_direction_to_low_byte_target = $0941
derive_low_byte_target_manhattan_distance = $08E3
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $4FEB
home_native54_projectile_or_enter_contact_animation:
    ldx $87
    lda a:$00A9,X
    jsr derive_low_byte_target_manhattan_distance
    ldx $87
    .a16
    cmp #$0020
    bcs home_native54_projectile_or_enter_contact_animation_c25002
    lda a:$0066,X
    .a16
    cmp #$0040
    bcc home_native54_projectile_or_enter_contact_animation_c25021
home_native54_projectile_or_enter_contact_animation_c25002:
    lda a:$00A9,X
    jsr derive_eight_way_direction_to_low_byte_target
    ldx $87
    sta a:$00AB,X
    .a16
    lda #$0002
    sta $1A
    .a16
    lda #$DC00
    sta $0D
    .a16
    lda #$E663
    sta $0C
    jsr add_direction_table_acceleration_and_clamp_boss_velocity
    clc
    rts
home_native54_projectile_or_enter_contact_animation_c25021:
    inc a:$0094,X
    stz a:$00A7,X
    stz a:$0090,X
    stz a:$0066,X
    stz a:$00B2,X
    .a16
    lda #$0170
    jsr select_boss_animation_and_reset_frame_cursor
    .a16
    lda #$0048
    .i16
    ldx #$000F
    jsr copy_boss_palette_with_cpu_words
    clc
    rts

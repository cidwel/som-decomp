; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-projectiles.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_parent_linked_boss_effect_and_copy_coordinates = $3385
copy_boss_palette_with_cpu_words = $26F9
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $4F91
initialize_native54_homing_projectile_and_linked_effect_palette:
    ldx $87
    inc a:$0094,X
    .a16
    lda #$0080
    sta a:$0066,X
    .a16
    lda #$0001
    sta a:$0000,X
    lda a:$0032,X
    sta a:$0022,X
    .a16
    lda #$0075
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00A7,X
    .a16
    lda #$507D
    sta a:$0090,X
    stz a:$003A,X
    stz a:$003C,X
    stz a:$003E,X
    stz a:$0040,X
    stz a:$00C4,X
    .a16
    lda #$0010
    sta a:$00C6,X
    .a16
    lda #$0001
    jsr allocate_parent_linked_boss_effect_and_copy_coordinates
    ldx $87
    lda a:$00B0,X
    tax
    lda a:$0042,X
    asl
    clc
    adc a:$0042,X
    .a16
    adc #$0022
    .i16
    ldx #$000F
    jsr copy_boss_palette_with_cpu_words
    clc
    rts

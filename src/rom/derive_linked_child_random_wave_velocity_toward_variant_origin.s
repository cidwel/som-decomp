; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-motion.md.
.setcpu "65816"
.smart
.a8
.i16

derive_cosine_by_adding_quarter_turn = $2A59
derive_fine_direction_from_coordinate_pairs = $2E77
draw_boss_frame_random_number = $300B
mask_angle_and_derive_native_sine = $2A60

.segment "CODE"
.org $5DEF
derive_linked_child_random_wave_velocity_toward_variant_origin:
    .a16
    lda #$007F
    jsr draw_boss_frame_random_number
    sec
    .a16
    sbc #$0040
    sta $00
    ldy $87
    lda a:$007A,Y
    asl
    asl
    tax
    lda f:$C25A39,X
    sta $46
    lda f:$C25A3B,X
    sta $4E
    lda a:$00B8,Y
    sta $56
    lda a:$00BA,Y
    sta $5E
    jsr derive_fine_direction_from_coordinate_pairs
    asl
    asl
    clc
    adc $00
    ldx $87
    sta $00
    jsr derive_cosine_by_adding_quarter_turn
    asl
    ldx $87
    sta a:$0076,X
    lda $00
    jsr mask_angle_and_derive_native_sine
    sta $00
    .a16
    lda #$007F
    jsr draw_boss_frame_random_number
    clc
    adc $00
    ldx $87
    sta a:$0078,X
    rts

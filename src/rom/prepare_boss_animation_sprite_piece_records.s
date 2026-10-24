; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_animation_piece_horizontal_offset = $1EEB
prepare_boss_animation_piece_tile_attributes = $1F25
prepare_boss_animation_piece_vertical_offset = $1F07

.segment "CODE"
.org $1E80
prepare_boss_animation_sprite_piece_records:
    lda $8D
    .a16
    bit #$8000
    bne prepare_boss_animation_sprite_piece_records_c21ebe
prepare_boss_animation_sprite_piece_records_c21e87:
    sep #$30
    .i8
    ldy #$03
    lda [$79],Y
    asl
    asl
    asl
    rol
    .a8
    and #$01
    tax
    lda f:$C21EE9,X
    sta $70
    jsr prepare_boss_animation_piece_horizontal_offset
    jsr prepare_boss_animation_piece_vertical_offset
    jsr prepare_boss_animation_piece_tile_attributes
    rep #$30
    lda $79
    clc
    .a16
    adc #$0004
    sta $79
    lda $7C
    clc
    .a16
    adc #$0004
    sta $7C
    inc $66
    lda $66
    cmp $85
    bcc prepare_boss_animation_sprite_piece_records_c21e87
    rts
prepare_boss_animation_sprite_piece_records_c21ebe:
    .a16
    lda #$0010
    sta $70
prepare_boss_animation_sprite_piece_records_c21ec3:
    sep #$30
    jsr prepare_boss_animation_piece_horizontal_offset
    jsr prepare_boss_animation_piece_vertical_offset
    jsr prepare_boss_animation_piece_tile_attributes
    rep #$30
    lda $79
    clc
    .a16
    adc #$0004
    sta $79
    lda $7C
    clc
    .a16
    adc #$0004
    sta $7C
    inc $66
    lda $66
    cmp $85
    bcc prepare_boss_animation_sprite_piece_records_c21ec3
    rts

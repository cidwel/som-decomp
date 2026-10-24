; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

align_boss_camera_scroll_and_screen_position = $102B
consume_boss_palette_commands = $10AC
emit_boss_sprite_piece_list = $1F80
integrate_boss_height_and_dispatch_enabled_motion_callback = $11F4

.segment "CODE"
.org $0F91
emit_selected_boss_object_camera_palette_callback_and_sprites:
    txa
    sta $8B
    clc
    .a16
    adc #$E000
    sta $87
    tax
    sec
    .a16
    sbc #$E600
    lsr
    lsr
    clc
    .a16
    adc #$F800
    sta $89
    lda a:$0098,X
    sta $8D
    .a16
    bit #$0008
    beq emit_selected_boss_object_camera_palette_callback_and_sprites_c20fb4
    jsr align_boss_camera_scroll_and_screen_position
emit_selected_boss_object_camera_palette_callback_and_sprites_c20fb4:
    ldx $87
    lda a:$00ED
    .a16
    bit #$0040
    beq emit_selected_boss_object_camera_palette_callback_and_sprites_c20fc7
    lda a:$0098,X
    .a16
    bit #$1000
    bne emit_selected_boss_object_camera_palette_callback_and_sprites_c20fc7
    rts
emit_selected_boss_object_camera_palette_callback_and_sprites_c20fc7:
    jsr consume_boss_palette_commands
    jsr integrate_boss_height_and_dispatch_enabled_motion_callback
    ldx $87
    lda a:$0070,X
    .a16
    bit #$0004
    beq emit_selected_boss_object_camera_palette_callback_and_sprites_c20fef
    .a16
    bit #$0002
    beq emit_selected_boss_object_camera_palette_callback_and_sprites_c20fe6
    .a16
    lda #$0002
    eor a:$0070,X
    sta a:$0070,X
    rts
emit_selected_boss_object_camera_palette_callback_and_sprites_c20fe6:
    .a16
    lda #$0002
    ora a:$0070,X
    sta a:$0070,X
emit_selected_boss_object_camera_palette_callback_and_sprites_c20fef:
    lda a:$007C
    lsr
    lsr
    sta $7F
    lda a:$0059
    sta $81
    .a16
    lda #$0080
    sta $83
    jsr emit_boss_sprite_piece_list
    lda $7F
    asl
    asl
    sta a:$007C
    lda $7F
    .a16
    and #$0003
    tax
    lda $7F
    lsr
    lsr
    tay
    sep #$20
    lda f:$D97F2D,X
    sta a:$0059
    tya
    sta a:$005A
    rep #$20
    .a16
    lda #$0001
    sta a:$0FAC
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

emit_boss_sprite_piece_list = $1F80
integrate_boss_height_and_dispatch_enabled_motion_callback = $11F4

.segment "CODE"
.org $133F
emit_nine_boss_objects_on_alternating_phases:
    lda a:$007C
    lsr
    lsr
    sta $7F
    lda a:$0059
    sta $81
    .a16
    lda #$0080
    sta $83
    .i16
    ldy #$0000
emit_nine_boss_objects_on_alternating_phases_c21353:
    tya
    xba
    asl
    clc
    .a16
    adc #$E600
    sta $87
    tax
    lda a:$008C,X
    beq emit_nine_boss_objects_on_alternating_phases_c21380
    lda a:$00ED
    .a16
    bit #$0040
    bne emit_nine_boss_objects_on_alternating_phases_c21378
    lda a:$008C,X
    .a16
    eor #$0002
    sta a:$008C,X
    .a16
    bit #$0002
    beq emit_nine_boss_objects_on_alternating_phases_c21380
emit_nine_boss_objects_on_alternating_phases_c21378:
    phy
    jsr integrate_boss_height_and_dispatch_enabled_motion_callback
    jsr emit_boss_sprite_piece_list
    ply
emit_nine_boss_objects_on_alternating_phases_c21380:
    iny
    .i16
    cpy #$0009
    bne emit_nine_boss_objects_on_alternating_phases_c21353
    lda $7F
    asl
    asl
    sta a:$007C
    .a16
    lda #$0001
    sta a:$0FAC
    rts

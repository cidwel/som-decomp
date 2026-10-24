; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_boss_animation_odd_byte_command = $1425

.segment "CODE"
.org $13EB
interpret_boss_animation_commands_until_frame_record:
    rep #$20
    lda a:$009A,X
    asl
    tax
    lda f:$DBF9A8,X
    sta $76
    ldx $87
    sep #$20
    ldy a:$009C,X
interpret_boss_animation_commands_until_frame_record_c213ff:
    lda [$76],Y
    sta $66
    iny
    .a8
    bit #$01
    beq interpret_boss_animation_commands_until_frame_record_c2140f
    jsr dispatch_boss_animation_odd_byte_command
    sep #$20
    bra interpret_boss_animation_commands_until_frame_record_c213ff
interpret_boss_animation_commands_until_frame_record_c2140f:
    sta a:$00A0,X
    lda [$76],Y
    sta a:$00A1,X
    iny
    lda [$76],Y
    sta a:$009E,X
    iny
    rep #$20
    tya
    sta a:$009C,X
    rts

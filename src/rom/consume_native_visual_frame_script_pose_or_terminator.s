; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_visual_frame_script_control_operand = $82F9

.segment "CODE"
.org $8276
consume_native_visual_frame_script_pose_or_terminator:
    .a8
    lda #$D1
    sta $02
    lda a:$E012,X
    beq consume_native_visual_frame_script_pose_or_terminator_c18285
    dec
    sta a:$E012,X
    clc
    rts
consume_native_visual_frame_script_pose_or_terminator_c18285:
    rep #$20
    lda a:$E0FC,X
    sta $00
consume_native_visual_frame_script_pose_or_terminator_c1828c:
    sep #$20
    lda [$00]
    bpl consume_native_visual_frame_script_pose_or_terminator_c18297
    jsr dispatch_native_visual_frame_script_control_operand
    bcs consume_native_visual_frame_script_pose_or_terminator_c1828c
consume_native_visual_frame_script_pose_or_terminator_c18297:
    sep #$20
    lda a:$E060,X
    .a8
    cmp #$C0
    bne consume_native_visual_frame_script_pose_or_terminator_c182b4
    rep #$20
    lda a:$E006,X
    sta a:$E11C,X
    lda a:$E036,X
    sta a:$E11E,X
    stz a:$E006,X
    stz a:$E036,X
consume_native_visual_frame_script_pose_or_terminator_c182b4:
    rep #$20
    lda $00
    inc
    inc
    sta a:$E0FC,X
    sep #$20
    inc a:$E00C,X
    rep #$20
    lda [$00]
    sep #$20
    pha
    asl
    sta a:$E028,X
    pla
    .a8
    and #$07
    .a8
    cmp #$04
    bcc consume_native_visual_frame_script_pose_or_terminator_c182d6
    .a8
    lda #$00
consume_native_visual_frame_script_pose_or_terminator_c182d6:
    sta a:$E012,X
    xba
    .a8
    cmp #$FF
    beq consume_native_visual_frame_script_pose_or_terminator_c182ee
    rep #$20
    .a16
    and #$00FF
    asl
    sta a:$E026,X
    sep #$20
    stz a:$E025,X
    clc
    rts
consume_native_visual_frame_script_pose_or_terminator_c182ee:
    stz a:$E00C,X
    stz a:$E084,X
    clc
    rts
    ply
    sec
    rts

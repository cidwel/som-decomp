; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-visual-effect-scripts.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01d48d = $1D48D
routine_01d52a = $1D52A
routine_01d5c0 = $1D5C0
routine_01d6dc = $1D6DC
routine_c182f6 = $82F6

.segment "CODE"
.org $82F9
dispatch_native_visual_frame_script_control_operand:
    .a8
    cmp #$FF
    bne dispatch_native_visual_frame_script_control_operand_c18316
    .a8
    lda #$00
    sta a:$E012,X
    lda a:$E05D,X
    beq dispatch_native_visual_frame_script_control_operand_c18313
    stz a:$E05D,X
    rep #$20
    lda a:$E05E,X
    sta $00
    sec
    rts
dispatch_native_visual_frame_script_control_operand_c18313:
    brl routine_c182f6
dispatch_native_visual_frame_script_control_operand_c18316:
    .a8
    cmp #$B0
    bcs dispatch_native_visual_frame_script_control_operand_c18320
    jsl f:routine_01d5c0
    sec
    rts
dispatch_native_visual_frame_script_control_operand_c18320:
    .a8
    cmp #$F0
    bcs dispatch_native_visual_frame_script_control_operand_c1832a
    jsl f:routine_01d6dc
    sec
    rts
dispatch_native_visual_frame_script_control_operand_c1832a:
    .a8
    cmp #$F8
    bcs dispatch_native_visual_frame_script_control_operand_c18334
    jsl f:routine_01d52a
    sec
    rts
dispatch_native_visual_frame_script_control_operand_c18334:
    jsl f:routine_01d48d
    sec
    rts

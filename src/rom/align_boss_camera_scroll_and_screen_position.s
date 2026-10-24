; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_boss_sprite_screen_position = $2005

.segment "CODE"
.org $102B
align_boss_camera_scroll_and_screen_position:
    lda a:$002B,X
    sta a:$0FB0
    lda a:$0066,X
    lsr
    eor $C7
    inc
    clc
    adc a:$0032,X
    sta a:$0FB2
    lda $8D
    .a16
    and #$0004
    .a16
    eor #$0004
    tax
    lda a:$0FB0
    clc
    adc a:$0FB4
    sec
    sbc a:$00A8
    .a16
    eor #$FFFF
    inc
    sta a:$00B0,X
    sta a:$0FBE
    lda $8D
    .a16
    bit #$0004
    bne align_boss_camera_scroll_and_screen_position_c21079
    lda a:$0FBE
    clc
    .a16
    adc #$0110
    bmi align_boss_camera_scroll_and_screen_position_c21073
    sec
    .a16
    sbc #$01A0
    bmi align_boss_camera_scroll_and_screen_position_c21079
align_boss_camera_scroll_and_screen_position_c21073:
    .a16
    lda #$FEF0
    sta a:$00B0,X
align_boss_camera_scroll_and_screen_position_c21079:
    lda a:$00AA
    sta $95
    lda a:$00C2
    sec
    .a16
    sbc #$00E0
    cmp $95
    bcs align_boss_camera_scroll_and_screen_position_c21092
    lda a:$00AA
    sec
    sbc a:$00C2
    sta $95
align_boss_camera_scroll_and_screen_position_c21092:
    lda a:$0FB2
    clc
    adc a:$0FB6
    sec
    sbc $95
    sta a:$0FBC
    .a16
    eor #$FFFF
    inc
    sta a:$00B2,X
    ldx $87
    jsr prepare_boss_sprite_screen_position
    rts

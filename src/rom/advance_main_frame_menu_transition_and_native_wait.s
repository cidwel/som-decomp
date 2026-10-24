; Recovered Secret of Mana USA routine; behaviour documented in docs/map-main-frame-transition.md.
.setcpu "65816"
.smart
.a8
.i16

publish_main_menu_transition_hdma_stripes_from_rom_patterns = $A4EE
request_slow_black_fade = $8B16
slide_special_scene_camera_across_128_real_frames = $C059

.segment "CODE"
.org $A462
advance_main_frame_menu_transition_and_native_wait:
    sep #$30
    lda $52
    bne advance_main_frame_menu_transition_and_native_wait_c0a469
advance_main_frame_menu_transition_and_native_wait_c0a468:
    rts
advance_main_frame_menu_transition_and_native_wait_c0a469:
    bmi advance_main_frame_menu_transition_and_native_wait_c0a468
    .a8
    cmp #$03
    bcs advance_main_frame_menu_transition_and_native_wait_c0a4ca
    lda $3E
    clc
    .a8
    adc #$08
    sta $3E
    beq advance_main_frame_menu_transition_and_native_wait_c0a488
    .a8
    cmp #$C0
    bne publish_main_menu_transition_hdma_stripes_from_rom_patterns
    lda $52
    .a8
    cmp #$02
    bcs advance_main_frame_menu_transition_and_native_wait_c0a48c
    jsr publish_main_menu_transition_hdma_stripes_from_rom_patterns
    jmp slide_special_scene_camera_across_128_real_frames
advance_main_frame_menu_transition_and_native_wait_c0a488:
    inc $52
    bra publish_main_menu_transition_hdma_stripes_from_rom_patterns
advance_main_frame_menu_transition_and_native_wait_c0a48c:
    stz $52
    .i8
    ldx #$1D
    .a8
    lda #$00
advance_main_frame_menu_transition_and_native_wait_c0a492:
    sta a:$0602,X
    sta f:$7EDE02,X
    dex
    bpl advance_main_frame_menu_transition_and_native_wait_c0a492
    .i8
    ldx #$03
advance_main_frame_menu_transition_and_native_wait_c0a49e:
    lda f:$D27E00,X
    sta a:$0604,X
    sta f:$7EDE04,X
    dex
    bpl advance_main_frame_menu_transition_and_native_wait_c0a49e
    stz $3E
    stz $40
    .a8
    lda #$02
    sta $EC
advance_main_frame_menu_transition_and_native_wait_c0a4b4:
    bit $EC
    bne advance_main_frame_menu_transition_and_native_wait_c0a4b4
    .a8
    lda #$58
    sta a:$2109
    stz a:$2111
    stz a:$2111
    stz a:$2112
    stz a:$2112
    rts
advance_main_frame_menu_transition_and_native_wait_c0a4ca:
    lda $3E
    sec
    .a8
    sbc #$08
    sta $3E
    bne publish_main_menu_transition_hdma_stripes_from_rom_patterns
    lda $52
    inc
    sta $52
    .a8
    cmp #$05
    bcc advance_main_frame_menu_transition_and_native_wait_c0a4e1
    .a8
    lda #$00
    sta $52
    rts
advance_main_frame_menu_transition_and_native_wait_c0a4e1:
    .a8
    lda #$80
    sta $FF
    .a8
    lda #$00
    sta $E0
    jsr request_slow_black_fade
    sep #$30

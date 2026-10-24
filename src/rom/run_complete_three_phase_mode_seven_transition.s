; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004
await_next_mode_seven_scene_vblank = $459C
build_mode_seven_transition_hdma_line_records = $41F6
clip_and_pack_visible_mode_seven_transition_objects = $4285
compute_signed_mode_seven_transition_matrix = $44DB
fade_mode_seven_scene_over_seventeen_vblanks = $45BA
initialize_mode_seven_transition_vram_and_palettes = $438F
scale_mode_seven_scene_step_by_two_hardware_products = $45D3
upload_complete_mode_seven_scene_oam_buffer = $C646C5

.segment "CODE"
.org $4028
run_complete_three_phase_mode_seven_transition:
    .a8
    lda #$8F
    sta a:$2100
    .a8
    lda #$01
    sta a:$4200
    stz a:$420C
    .a8
    lda #$02
    sta a:$2101
    .a8
    lda #$07
    sta a:$2105
    stz a:$2106
    stz a:$210D
    stz a:$210D
    .a8
    lda #$FF
    sta a:$210E
    .a8
    lda #$FE
    sta a:$210E
    .a8
    lda #$80
    sta a:$211A
    .a8
    lda #$01
    stz a:$211B
    sta a:$211B
    stz a:$211C
    stz a:$211C
    stz a:$211D
    stz a:$211D
    stz a:$211E
    sta a:$211E
    stz a:$211F
    stz a:$211F
    stz a:$2120
    stz a:$2120
    .a8
    lda #$11
    sta a:$212C
    stz a:$212D
    stz a:$212E
    stz a:$212F
    stz a:$2130
    stz a:$2131
    .a8
    lda #$E0
    sta a:$2132
    jsr initialize_mode_seven_transition_vram_and_palettes
    .a8
    lda #$00
    sta a:$4360
    .a8
    lda #$21
    sta a:$4361
    .i16
    ldx #$1000
    stx a:$4362
    stz a:$4364
    .a8
    lda #$02
    sta a:$4370
    .a8
    lda #$22
    sta a:$4371
    .i16
    ldx #$1020
    stx a:$4372
    stz a:$4374
    stz $4A
    stz $4B
    jsr build_mode_seven_transition_hdma_line_records
    .i16
    ldx #$2801
    stx a:$1E00
    .i16
    ldx #$FF0E
    stx a:$1E02
    jsl f:audio_command_sender_public_jump
    jsr await_next_mode_seven_scene_vblank
    .a8
    lda #$C0
    sta a:$420C
    .a8
    lda #$0F
    sta a:$2100
run_complete_three_phase_mode_seven_transition_c640e3:
    jsr clip_and_pack_visible_mode_seven_transition_objects
    jsr await_next_mode_seven_scene_vblank
    jsr build_mode_seven_transition_hdma_line_records
    jsl f:upload_complete_mode_seven_scene_oam_buffer
    lda $4A
    clc
    .a8
    adc #$10
    sta $4A
    .a8
    cmp #$E0
    bne run_complete_three_phase_mode_seven_transition_c640e3
    jsr clip_and_pack_visible_mode_seven_transition_objects
    jsr await_next_mode_seven_scene_vblank
    stz a:$420C
    stz a:$2121
    lda $48
    sta a:$2122
    lda $49
    sta a:$2122
    .a8
    lda #$03
    sta $2C
    .i16
    ldx #$0010
    stx $2E
    bra run_complete_three_phase_mode_seven_transition_c64122
run_complete_three_phase_mode_seven_transition_c6411c:
    jsr clip_and_pack_visible_mode_seven_transition_objects
    jsr await_next_mode_seven_scene_vblank
run_complete_three_phase_mode_seven_transition_c64122:
    jsl f:upload_complete_mode_seven_scene_oam_buffer
    rep #$20
    lda $4A
    clc
    adc $2E
    sta $4A
    sep #$20
    dec $2C
    bne run_complete_three_phase_mode_seven_transition_c6411c
    .a8
    lda #$03
    sta $2C
    dec $2E
    lda $2E
    .a8
    cmp #$01
    bne run_complete_three_phase_mode_seven_transition_c6411c
    jsr clip_and_pack_visible_mode_seven_transition_objects
    jsr await_next_mode_seven_scene_vblank
    jsl f:upload_complete_mode_seven_scene_oam_buffer
    .a8
    lda #$4C
    sta a:$210D
    .a8
    lda #$FF
    sta a:$210D
    .a8
    lda #$D9
    sta $4D
    sta a:$210E
    .a8
    lda #$FF
    sta a:$210E
    sta a:$211F
    stz a:$211F
    sta a:$2120
    stz a:$2120
    .a8
    lda #$30
    sta $44
    .i16
    ldx #$0001
    stx $40
    stx $42
    stx $46
    jsr compute_signed_mode_seven_transition_matrix
    rep #$20
    lda $4A
    clc
    .a16
    adc #$0001
    sta $4A
    sep #$20
    stz $45
run_complete_three_phase_mode_seven_transition_c6418b:
    jsr clip_and_pack_visible_mode_seven_transition_objects
    jsr await_next_mode_seven_scene_vblank
    jsl f:upload_complete_mode_seven_scene_oam_buffer
    lda $4D
    sta a:$210E
    .a8
    lda #$FF
    sta a:$210E
    dec $4D
    .a8
    lda #$10
    sta a:$211F
    stz a:$211F
    sta a:$2120
    stz a:$2120
    jsr compute_signed_mode_seven_transition_matrix
    dec $44
    bpl run_complete_three_phase_mode_seven_transition_c641ba
    .a8
    lda #$47
    sta $44
run_complete_three_phase_mode_seven_transition_c641ba:
    ldx $46
    stx $30
    lda $45
    sta $33
    jsr scale_mode_seven_scene_step_by_two_hardware_products
    rep #$20
    lda $30
    lsr $32
    ror
    lsr $32
    ror
    clc
    adc $46
    sta $40
    sta $42
    lda $4A
    clc
    .a16
    adc #$0001
    sta $4A
    sep #$20
    inc $45
    lda $45
    .a8
    cmp #$04
    bcc run_complete_three_phase_mode_seven_transition_c641ee
    asl $46
    rol $47
    stz $45
run_complete_three_phase_mode_seven_transition_c641ee:
    ldx $46
    bne run_complete_three_phase_mode_seven_transition_c6418b
    jsr fade_mode_seven_scene_over_seventeen_vblanks
    rts

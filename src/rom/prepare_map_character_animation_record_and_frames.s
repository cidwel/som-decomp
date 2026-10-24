; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_map_graphics_motion_type = $B2AD
dispatch_map_graphics_two_tile_motion_type = $C1A1

.segment "CODE"
.org $B1D0
prepare_map_character_animation_record_and_frames:
    lda f:$C80000,X
    pha
    ldx $14
    .a16
    and #$03FF
    asl
    asl
    asl
    asl
    .a16
    ora #$0000
    sta a:$8206,X
    pla
    pha
    lsr
    lsr
    lsr
    lsr
    .a16
    and #$0F00
    sta a:$8200,X
    pla
    lsr
    lsr
    .a16
    and #$0300
    sep #$20
    bne prepare_map_character_animation_record_and_frames_c1b203
    .a8
    lda #$01
    xba
    lda $12
    .a8
    and #$01
    bra prepare_map_character_animation_record_and_frames_c1b218
prepare_map_character_animation_record_and_frames_c1b203:
    xba
    .a8
    cmp #$03
    bne prepare_map_character_animation_record_and_frames_c1b211
    sec
    rol
    xba
    lda $12
    .a8
    and #$07
    bra prepare_map_character_animation_record_and_frames_c1b218
prepare_map_character_animation_record_and_frames_c1b211:
    sec
    rol
    xba
    lda $12
    .a8
    and #$03
prepare_map_character_animation_record_and_frames_c1b218:
    inc $12
    rep #$20
    sta a:$8208,X
    lda $06
    sta a:$8202,X
    .a16
    lda #$0000
    sta a:$8204,X
    lda $14
    clc
    .a16
    adc #$0010
    sta $14
    lda a:$8206,X
    sep #$20
    pha
    .a8
    lda #$00
    pha
    plb
    .a8
    lda #$80
    sta a:$2115
    pla
    rep #$20
    sta a:$2116
    .a16
    lda #$3981
    sta a:$4370
    lda $06
    sta a:$4372
    .a16
    lda #$00C0
    sta a:$4375
    lda a:$2139
    sep #$30
    .a8
    lda #$7F
    sta a:$4374
    .a8
    lda #$80
    sta a:$420B
    .a8
    lda #$7F
    pha
    plb
    lda a:$8201,X
    .a8
    cmp #$08
    bcc prepare_map_character_animation_record_and_frames_c1b275
    jmp dispatch_map_graphics_two_tile_motion_type
prepare_map_character_animation_record_and_frames_c1b275:
    bra dispatch_map_graphics_motion_type

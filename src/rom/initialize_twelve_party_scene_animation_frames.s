; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

decode_upload_and_advance_party_scene_frame = $FB79

.segment "CODE"
.org $FB0D
initialize_twelve_party_scene_animation_frames:
    rep #$10
    lda $F4
    .a8
    and #$0F
initialize_twelve_party_scene_animation_frames_c1fb13:
    .a8
    cmp #$03
    bcc initialize_twelve_party_scene_animation_frames_c1fb1b
    .a8
    sbc #$03
    bra initialize_twelve_party_scene_animation_frames_c1fb13
initialize_twelve_party_scene_animation_frames_c1fb1b:
    asl
    asl
    pha
    clc
    .a8
    adc #$86
    sta a:$E040
    pla
    clc
    .a8
    adc #$04
    .a8
    cmp #$0C
    bcc initialize_twelve_party_scene_animation_frames_c1fb2e
    .a8
    sbc #$0C
initialize_twelve_party_scene_animation_frames_c1fb2e:
    pha
    clc
    .a8
    adc #$86
    sta a:$E240
    pla
    clc
    .a8
    adc #$04
    .a8
    cmp #$0C
    bcc initialize_twelve_party_scene_animation_frames_c1fb3f
    .a8
    sbc #$0C
initialize_twelve_party_scene_animation_frames_c1fb3f:
    clc
    .a8
    adc #$86
    sta a:$E440
    rep #$20
    .a16
    lda #$3A00
    sta a:$E08A
    .a16
    lda #$3C08
    sta a:$E28A
    .a16
    lda #$3E20
    sta a:$E48A
    .a16
    lda #$0004
    sta $1E
    stz $1C
initialize_twelve_party_scene_animation_frames_c1fb60:
    .i16
    ldx #$0000
    jsr decode_upload_and_advance_party_scene_frame
    .i16
    ldx #$0200
    jsr decode_upload_and_advance_party_scene_frame
    .i16
    ldx #$0400
    jsr decode_upload_and_advance_party_scene_frame
    sep #$20
    dec $1E
    bne initialize_twelve_party_scene_animation_frames_c1fb60
    rts

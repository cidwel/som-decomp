; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-mode7-transition.md.
.setcpu "65816"
.smart
.a8
.i16

append_five_byte_mode_seven_scene_object = $C64604
pack_mode_seven_scene_objects_into_complete_oam_buffer = $C6462B

.segment "CODE"
.org $4285
clip_and_pack_visible_mode_seven_transition_objects:
    phb
    .a8
    lda #$C7
    pha
    plb
    rep #$20
    stz $4E
    .a16
    lda #$0320
    sec
    sbc $4A
    sta $26
    .a16
    lda #$00F0
    sec
    sbc $26
    bcc clip_and_pack_visible_mode_seven_transition_objects_c642ea
    .a16
    sbc #$0020
    .a16
    cmp #$00E0
    bcs clip_and_pack_visible_mode_seven_transition_objects_c642ea
    sep #$20
    sta $22
    .a8
    lda #$B4
    sta $20
    .a8
    lda #$02
    sta $21
    .i16
    ldx #$0000
    stx $24
    jsl f:append_five_byte_mode_seven_scene_object
    lda $20
    clc
    .a8
    adc #$10
    sta $20
    .a8
    lda #$02
    sta $24
    jsl f:append_five_byte_mode_seven_scene_object
    lda $22
    clc
    .a8
    adc #$10
    sta $22
    .a8
    lda #$22
    sta $24
    jsl f:append_five_byte_mode_seven_scene_object
    lda $20
    sec
    .a8
    sbc #$10
    sta $20
    .a8
    lda #$20
    sta $24
    jsl f:append_five_byte_mode_seven_scene_object
    rep #$20
clip_and_pack_visible_mode_seven_transition_objects_c642ea:
    .i16
    ldy #$FBA0
    .a16
    lda #$0008
    sta $28
clip_and_pack_visible_mode_seven_transition_objects_c642f2:
    lda a:$0001,Y
    clc
    .a16
    adc #$0010
    sec
    sbc $26
    bcc clip_and_pack_visible_mode_seven_transition_objects_c64345
    .a16
    sbc #$0010
    .a16
    cmp #$00E0
    bcs clip_and_pack_visible_mode_seven_transition_objects_c64345
    sep #$20
    sta $22
    lda a:$0000,Y
    sta $20
    .a8
    lda #$00
    sta $21
    .i16
    ldx #$0004
    stx $24
    jsl f:append_five_byte_mode_seven_scene_object
    lda $20
    clc
    .a8
    adc #$08
    sta $20
    inc $24
    jsl f:append_five_byte_mode_seven_scene_object
    lda $20
    clc
    .a8
    adc #$08
    sta $20
    inc $24
    jsl f:append_five_byte_mode_seven_scene_object
    lda $20
    clc
    .a8
    adc #$08
    sta $20
    inc $24
    jsl f:append_five_byte_mode_seven_scene_object
    rep #$20
clip_and_pack_visible_mode_seven_transition_objects_c64345:
    iny
    iny
    iny
    dec $28
    bne clip_and_pack_visible_mode_seven_transition_objects_c642f2
    .i16
    ldy #$FBB8
    .a16
    lda #$0008
    sta $28
clip_and_pack_visible_mode_seven_transition_objects_c64354:
    lda a:$0001,Y
    clc
    .a16
    adc #$0020
    sec
    sbc $26
    bcc clip_and_pack_visible_mode_seven_transition_objects_c64380
    .a16
    sbc #$0020
    .a16
    cmp #$00E0
    bcs clip_and_pack_visible_mode_seven_transition_objects_c64380
    sep #$20
    sta $22
    lda a:$0000,Y
    sta $20
    .a8
    lda #$02
    sta $21
    .i16
    ldx #$0008
    stx $24
    jsl f:append_five_byte_mode_seven_scene_object
    rep #$20
clip_and_pack_visible_mode_seven_transition_objects_c64380:
    iny
    iny
    iny
    dec $28
    bne clip_and_pack_visible_mode_seven_transition_objects_c64354
    sep #$20
    plb
    jsl f:pack_mode_seven_scene_objects_into_complete_oam_buffer
    rts

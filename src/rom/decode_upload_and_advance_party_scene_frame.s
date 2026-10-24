; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00eb02 = $EB02
upload_two_rows_of_eight_character_tiles = $FBDC

.segment "CODE"
.org $FB79
decode_upload_and_advance_party_scene_frame:
    sep #$20
    .a8
    lda #$0E
    sta a:$E06F,X
    stz a:$E08E,X
    .a8
    lda #$D1
    sta $02
    lda a:$E040,X
    rep #$20
    .a16
    and #$00FF
    asl
    adc a:$E02A,X
    sta $00
    lda [$00]
    pha
    xba
    .a16
    and #$00FF
    asl
    sta $00
    pla
    sep #$20
    .a8
    and #$C0
    sta a:$E088,X
    lda a:$E033,X
    sta $02
    sta $12
    rep #$20
    lda a:$E072,X
    clc
    adc $00
    sta $00
    lda [$00]
    stx $14
    jsl f:routine_00eb02
    jsr upload_two_rows_of_eight_character_tiles
    sep #$20
    rep #$10
    ldx $14
    inc a:$E040,X
    lda a:$E08A,X
    clc
    .a8
    adc #$28
    .a8
    bit #$10
    beq decode_upload_and_advance_party_scene_frame_c1fbd8
    .a8
    adc #$10
decode_upload_and_advance_party_scene_frame_c1fbd8:
    sta a:$E08A,X
    rts

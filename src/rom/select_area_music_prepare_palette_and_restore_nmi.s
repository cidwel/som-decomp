; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-music-palette-transition.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004
routine_01f8e5 = $1F8E5

.segment "CODE"
.org $8CB0
select_area_music_prepare_palette_and_restore_nmi:
    .a8
    lda #$0D
    stz a:$1E02
    lda $E3
    stz $E3
    .a8
    and #$02
    .a8
    cmp #$02
    bcs select_area_music_prepare_palette_and_restore_nmi_c08cc1
    .a8
    lda #$03
select_area_music_prepare_palette_and_restore_nmi_c08cc1:
    sta a:$1E01
    ror $E3
    bmi select_area_music_prepare_palette_and_restore_nmi_c08cd1
    .a8
    lda #$0B
    sta a:$1E02
    .a8
    lda #$40
    tsb $E3
select_area_music_prepare_palette_and_restore_nmi_c08cd1:
    stz $8C
    lda $E3
    asl
    rol
    rol
    .a8
    and #$03
    sta f:$7ECF02
    .a8
    lda #$01
    sta a:$1E00
    .a8
    lda #$0F
    sta a:$1E03
    stz a:$4200
    bit $E3
    bvc select_area_music_prepare_palette_and_restore_nmi_c08cf3
    jsl f:routine_01f8e5
select_area_music_prepare_palette_and_restore_nmi_c08cf3:
    jsl f:audio_command_sender_public_jump
    sep #$20
    .a8
    lda #$B1
    sta a:$4200
    rts

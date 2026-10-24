; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-to-map-reset.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01e76d = $1E76D
routine_02aa17 = $2AA17
routine_02b5e7 = $2B5E7
routine_c0b03f = $B03F

.segment "CODE"
.org $800C
reset_ui_scene_and_enter_real_main_map_for_carried_command:
    rep #$30
    .i16
    ldx #$01FF
    txs
    pha
    .a16
    lda #$0000
    tcd
    sep #$20
    pha
    plb
    jsl f:routine_02b5e7
    jsl f:routine_02aa17
    rep #$30
    pla
    .a16
    ora #$0800
    jsl f:routine_01e76d
    sep #$20
    stz $FF
    .a8
    lda #$A0
    sta $E0
    jmp routine_c0b03f

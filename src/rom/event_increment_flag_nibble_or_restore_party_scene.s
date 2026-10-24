; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-flag-increment.md.
.setcpu "65816"
.smart
.a8
.i16

restore_party_hud_across_two_native_frames = $E0DB
routine_02c976 = $2C976
routine_c1ec8d = $EC8D

.segment "CODE"
.org $EC46
event_increment_flag_nibble_or_restore_party_scene:
    ldx $05
    beq event_increment_flag_nibble_or_restore_party_scene_c1ec58
    lda a:$CF00,X
event_increment_flag_nibble_or_restore_party_scene_c1ec4d:
    inc
    .a8
    and #$0F
    bne event_increment_flag_nibble_or_restore_party_scene_c1ec54
    .a8
    lda #$0F
event_increment_flag_nibble_or_restore_party_scene_c1ec54:
    sta $00
    bra routine_c1ec8d
event_increment_flag_nibble_or_restore_party_scene_c1ec58:
    lda a:$CF00,X
    bne event_increment_flag_nibble_or_restore_party_scene_c1ec4d
    lda $ED
    bmi event_increment_flag_nibble_or_restore_party_scene_c1ec6f
    .a8
    eor #$80
    sta $ED
    stz $CC
    stz $CD
    stz $CE
    stz $00
    bra routine_c1ec8d
event_increment_flag_nibble_or_restore_party_scene_c1ec6f:
    inc a:$CF00,X
    rep #$20
    inc $D1
    inc $D1
    jsl f:routine_02c976
    jmp restore_party_hud_across_two_native_frames

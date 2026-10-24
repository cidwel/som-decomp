; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

release_party_control_and_restore_boss_palette_music = $6273
select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $5FE0
begin_descriptor_five_terminal_animation_and_restore_party_palette_music:
    ldx $87
    .a16
    lda #$00AE
    jsr select_boss_animation_and_reset_frame_cursor
    inc a:$0094,X
    stz a:$0096,X
    jsr release_party_control_and_restore_boss_palette_music

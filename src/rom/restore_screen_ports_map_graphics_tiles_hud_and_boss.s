; Recovered Secret of Mana USA routine; behaviour documented in docs/event-screen-restore.md.
.setcpu "65816"
.smart
.a8
.i16

configure_map_backgrounds = $FD52
restore_boss_screen_resources_long_entry = $C20012
routine_00c45e = $C45E
routine_00c9e6 = $C9E6
routine_01e0d7 = $1E0D7

.segment "CODE"
.org $FF6B
restore_screen_ports_map_graphics_tiles_hud_and_boss:
    stz a:$420C
    stz $2C
    lda $20
    sta a:$2106
    stz a:$2124
    stz a:$2125
    stz a:$212A
    stz a:$212B
    lda $21
    sta a:$212C
    lda $22
    sta a:$212D
    stz a:$212E
    stz a:$212F
    .a8
    lda #$02
    sta a:$2130
    lda $23
    sta a:$2131
    stz a:$2132
    .a8
    lda #$00
    sta a:$2126
    sta a:$2128
    .a8
    lda #$FF
    sta a:$2127
    sta a:$2129
    lda $91
    sta a:$2101
    .a8
    lda #$0F
    trb $E3
    lda $B0
    sta a:$210D
    stz a:$210D
    lda $B2
    sta a:$210E
    stz a:$210E
    .a8
    lda #$B8
    sta a:$4207
    stz a:$4208
    .a8
    lda #$C4
    sta a:$4209
    stz a:$420A
    stz $E8
    jsr configure_map_backgrounds
    jsl f:routine_00c45e
    jsl f:routine_00c9e6
    jsl f:routine_01e0d7
    sep #$20
    bit $5C
    bpl restore_screen_ports_map_graphics_tiles_hud_and_boss_c1fff4
    rep #$20
    jsl f:restore_boss_screen_resources_long_entry
restore_screen_ports_map_graphics_tiles_hud_and_boss_c1fff4:
    rep #$20
    lda $27
    sta a:$0600
    sta f:$7EDE00
    rts

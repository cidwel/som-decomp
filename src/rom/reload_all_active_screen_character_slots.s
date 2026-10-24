; Recovered Secret of Mana USA routine; behaviour documented in docs/event-screen-tile-reload.md.
.setcpu "65816"
.smart
.a8
.i16

reload_screen_character_slot_two_plane_groups = $F936

.segment "CODE"
.org $F900
reload_all_active_screen_character_slots:
    sep #$30
    .a8
    lda #$00
    pha
    plb
    .i8
    ldx #$01
    stx a:$4360
    stx a:$4370
    .i8
    ldx #$18
    stx a:$4361
    stx a:$4371
    .i8
    ldx #$7F
    stx a:$4364
    stx a:$4374
    .i8
    ldx #$00
reload_all_active_screen_character_slots_dbf920:
    lda f:$7E0F55,X
    bmi reload_all_active_screen_character_slots_dbf92e
    sta $68
    txa
    phx
    jsr reload_screen_character_slot_two_plane_groups
    plx
reload_all_active_screen_character_slots_dbf92e:
    inx
    .i8
    cpx #$4D
    bne reload_all_active_screen_character_slots_dbf920
    rep #$30
    rtl

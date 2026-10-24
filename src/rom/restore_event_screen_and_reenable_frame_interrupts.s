; Recovered Secret of Mana USA routine; behaviour documented in docs/event-screen-restore.md.
.setcpu "65816"
.smart
.a8
.i16

restore_screen_ports_map_graphics_tiles_hud_and_boss = $FF6B

.segment "CODE"
.org $FF3A
restore_event_screen_and_reenable_frame_interrupts:
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    stz a:$4200
    .a8
    lda #$8F
    sta a:$2100
    lda $1F
    pha
    jsr restore_screen_ports_map_graphics_tiles_hud_and_boss
    rep #$20
    .a16
    lda #$0F00
    sta $E6
    .a16
    lda #$0101
    sta $E4
    sep #$20
    .a8
    lda #$01
    tsb $E2
    .a8
    lda #$B1
    sta a:$4200
    pla
    sta $1F
    plb
    rts

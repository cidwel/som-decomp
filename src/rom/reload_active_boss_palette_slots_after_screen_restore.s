; Recovered Secret of Mana USA routine; behaviour documented in docs/event-boss-screen-restore.md.
.setcpu "65816"
.smart
.a8
.i16

load_boss_palette_through_wram_dma = $26AC

.segment "CODE"
.org $01E3
reload_active_boss_palette_slots_after_screen_restore:
    ldx $C5
reload_active_boss_palette_slots_after_screen_restore_c201e5:
    lda a:$033F,X
    .a16
    and #$00FF
    beq reload_active_boss_palette_slots_after_screen_restore_c201f2
    phx
    jsr load_boss_palette_through_wram_dma
    plx
reload_active_boss_palette_slots_after_screen_restore_c201f2:
    inx
    .i16
    cpx #$0010
    bne reload_active_boss_palette_slots_after_screen_restore_c201e5
    rts

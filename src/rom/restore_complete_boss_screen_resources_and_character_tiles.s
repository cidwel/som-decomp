; Recovered Secret of Mana USA routine; behaviour documented in docs/event-boss-screen-restore.md.
.setcpu "65816"
.smart
.a8
.i16

interpret_boss_loader_commands = $21B7
reload_active_boss_palette_slots_after_screen_restore = $01E3
reload_all_active_screen_character_slots = $DBF900

.segment "CODE"
.org $019E
restore_complete_boss_screen_resources_and_character_tiles:
    php
    phd
    phb
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    .a16
    lda #$0200
    tcd
    lda $C7
    sta a:$0364
    lda a:$0FA2
    sec
    .a16
    sbc #$0054
    asl
    tax
    lda f:$C20146,X
    jsr interpret_boss_loader_commands
    jsr reload_active_boss_palette_slots_after_screen_restore
    lda a:$EE8E
    .a16
    cmp #$3D34
    bne restore_complete_boss_screen_resources_and_character_tiles_c201d0
    stz a:$EE00
restore_complete_boss_screen_resources_and_character_tiles_c201d0:
    lda a:$F08E
    .a16
    cmp #$3D34
    bne restore_complete_boss_screen_resources_and_character_tiles_c201db
    stz a:$F000
restore_complete_boss_screen_resources_and_character_tiles_c201db:
    jsl f:reload_all_active_screen_character_slots
    plb
    pld
    plp
    rtl

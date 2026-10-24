; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

boss_death_initialization_reserved_return = $0B4F
boss_external_actor_command_if_selected = $3963
copy_boss_palette_with_cpu_words = $26F9
prepare_boss_loader_resource_expansion = $24C3

.segment "CODE"
.org $0B14
prepare_boss_death_palettes_graphics_and_selected_actor:
    sep #$20
    .a8
    lda #$20
    sta a:$0060,X
    rep #$20
    stz a:$0096,X
    .i16
    ldy #$0000
prepare_boss_death_palettes_graphics_and_selected_actor_c20b23:
    lda a:$0018,X
    .a16
    and #$00FF
    beq prepare_boss_death_palettes_graphics_and_selected_actor_c20b3d
    phx
    phy
    tax
    .a16
    lda #$0049
    jsr copy_boss_palette_with_cpu_words
    ply
    plx
    inx
    iny
    .i16
    cpy #$0004
    bcc prepare_boss_death_palettes_graphics_and_selected_actor_c20b23
prepare_boss_death_palettes_graphics_and_selected_actor_c20b3d:
    .a16
    lda #$0027
    jsr prepare_boss_loader_resource_expansion
    .a16
    lda #$8B00
    jsr boss_external_actor_command_if_selected
    jsr boss_death_initialization_reserved_return
    ldx $87
    rts

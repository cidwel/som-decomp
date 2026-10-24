; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_colors_from_rom = $2700

.segment "CODE"
.org $11C7
set_boss_actor_palettes_and_advance_command:
    phy
set_boss_actor_palettes_and_advance_command_c211c8:
    lda a:$0018,X
    beq set_boss_actor_palettes_and_advance_command_c211e3
    rep #$20
    phx
    .a16
    and #$00FF
    tax
    .a16
    lda #$0001
    jsr copy_boss_palette_colors_from_rom
    plx
    sep #$20
    inx
    txa
    .a8
    and #$04
    beq set_boss_actor_palettes_and_advance_command_c211c8
set_boss_actor_palettes_and_advance_command_c211e3:
    plx
    .a8
    lda #$C1
    sta a:$0100,X
    ldx $87
    rts

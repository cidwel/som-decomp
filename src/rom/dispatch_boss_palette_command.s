; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_actor_palette_group = $111C
reload_boss_actor_cached_palettes = $10F6
request_boss_actor_cached_palette_reload = $11EC
rotate_boss_actor_palette_group = $1171
set_boss_actor_palettes_and_advance_command = $11C7

.segment "CODE"
.org $10D2
dispatch_boss_palette_command:
    .a8
    cmp #$80
    bne dispatch_boss_palette_command_c210d9
    jmp reload_boss_actor_cached_palettes
dispatch_boss_palette_command_c210d9:
    .a8
    cmp #$B0
    bne dispatch_boss_palette_command_c210e0
    jmp copy_boss_actor_palette_group
dispatch_boss_palette_command_c210e0:
    .a8
    cmp #$B4
    bne dispatch_boss_palette_command_c210e7
    jmp rotate_boss_actor_palette_group
dispatch_boss_palette_command_c210e7:
    .a8
    cmp #$C0
    bne dispatch_boss_palette_command_c210ee
    jmp set_boss_actor_palettes_and_advance_command
dispatch_boss_palette_command_c210ee:
    .a8
    cmp #$C1
    bne dispatch_boss_palette_command_c210f5
    jmp request_boss_actor_cached_palette_reload
dispatch_boss_palette_command_c210f5:
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_boss_palette_color_interval = $1187

.segment "CODE"
.org $1171
rotate_boss_actor_palette_group:
    xba
    sta $46
rotate_boss_actor_palette_group_c21174:
    lda a:$0018,X
    beq rotate_boss_actor_palette_group_c21184
    phx
    jsr rotate_boss_palette_color_interval
    plx
    inx
    txa
    .a8
    and #$04
    beq rotate_boss_actor_palette_group_c21174
rotate_boss_actor_palette_group_c21184:
    ldx $87
    rts

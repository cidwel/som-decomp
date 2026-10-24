; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_seven_colors = $1135

.segment "CODE"
.org $111C
copy_boss_actor_palette_group:
    phy
    xba
    sta $46
copy_boss_actor_palette_group_c21120:
    lda a:$0018,X
    beq copy_boss_actor_palette_group_c2112e
    jsr copy_boss_palette_seven_colors
    inx
    txa
    .a8
    and #$04
    beq copy_boss_actor_palette_group_c21120
copy_boss_actor_palette_group_c2112e:
    plx
    stz a:$0100,X
    ldx $87
    rts

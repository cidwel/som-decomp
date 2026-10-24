; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

clip_boss_sprite_horizontal = $2095
clip_boss_sprite_vertical = $20C0
write_normal_boss_sprite_attributes = $20ED

.segment "CODE"
.org $206D
emit_normal_boss_sprite_piece:
    lda $95
    asl
    asl
    tax
    jsr clip_boss_sprite_horizontal
    bcs emit_normal_boss_sprite_piece_c22080
    jsr clip_boss_sprite_vertical
    bcs emit_normal_boss_sprite_piece_c22080
    jsr write_normal_boss_sprite_attributes
    clc
emit_normal_boss_sprite_piece_c22080:
    rts

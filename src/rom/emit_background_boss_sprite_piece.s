; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

clip_boss_sprite_horizontal = $2095
clip_boss_sprite_vertical = $20C0
write_background_boss_sprite_attributes = $2150

.segment "CODE"
.org $2081
emit_background_boss_sprite_piece:
    lda $95
    asl
    asl
    tax
    jsr clip_boss_sprite_horizontal
    bcs emit_background_boss_sprite_piece_c22094
    jsr clip_boss_sprite_vertical
    bcs emit_background_boss_sprite_piece_c22094
    jsr write_background_boss_sprite_attributes
    clc
emit_background_boss_sprite_piece_c22094:
    rts

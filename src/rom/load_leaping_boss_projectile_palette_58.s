; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9

.segment "CODE"
.org $7273
load_leaping_boss_projectile_palette_58:
    .i16
    ldx #$000F
    .a16
    lda #$0058
    jsr copy_boss_palette_with_cpu_words
    rts

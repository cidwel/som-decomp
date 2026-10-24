; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

copy_boss_palette_with_cpu_words = $26F9

.segment "CODE"
.org $65DD
load_boss_palette_38_into_slot_fifteen:
    .a16
    lda #$0038
    .i16
    ldx #$000F
    jsr copy_boss_palette_with_cpu_words
    rts

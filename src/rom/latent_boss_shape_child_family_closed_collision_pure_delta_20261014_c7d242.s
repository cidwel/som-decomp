; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $D242
boss_collision_word_c7d242:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorCC/CD
    .word $0002

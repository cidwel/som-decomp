; Functional collision parameters only; global sprite/background aliases excluded.
.setcpu "65816"
.segment "RODATA"
.org $EB22
boss_collision_word_caeb22:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorCC/CD
    .word $0002

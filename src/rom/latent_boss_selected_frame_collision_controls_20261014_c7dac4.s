; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $DAC4
boss_collision_word_c7dac4:
    ; collision packed-axis extents/presence to actorCA/CB
    .word $100C
boss_collision_word_c7dac6:
    ; collision signed-axis displacement to actorC8/C9
    .word $E80C
boss_collision_word_c7dac8:
    ; collision packed-axis extents/presence to actorC2/C3
    .word $110A
boss_collision_word_c7daca:
    ; collision signed-axis displacement to actorC0/C1
    .word $EF24
boss_collision_word_c7dacc:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $070B
boss_collision_word_c7dace:
    ; collision signed-axis displacement to actorCC/CD
    .word $E724

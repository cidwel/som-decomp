; Functional boss collision extents and displacements; sprite payload excluded.
.setcpu "65816"
.segment "RODATA"
.org $FB16
boss_collision_word_cafb16:
    ; collision packed-axis extents/presence to actorCA/CB; collision signed-axis displacement to actorC0/C1
    .word $0001
boss_collision_word_cafb18:
    ; collision packed-axis extents/presence to actorCE/CF; collision signed-axis displacement to actorC8/C9
    .word $F8F8
boss_collision_word_cafb1a:
    ; collision packed-axis extents/presence to actorC2/C3; collision signed-axis displacement to actorCC/CD
    .word $1FA6
boss_collision_word_cafb1c:
    ; collision signed-axis displacement to actorC0/C1
    .word $0004
boss_collision_word_cafb1e:
    ; collision packed-axis extents/presence to actorCE/CF
    .word $F0F0
boss_collision_word_cafb20:
    ; collision signed-axis displacement to actorCC/CD
    .word $1FC0

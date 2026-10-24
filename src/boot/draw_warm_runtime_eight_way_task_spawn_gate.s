; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_0095f8 = $95F8
routine_7ec288 = $C288

.segment "CODE"
.org $9633
draw_warm_runtime_eight_way_task_spawn_gate:
    .a8
    lda #$08
    jsr routine_7ec288
    .a8
    cmp #$00
    bne routine_0095f8

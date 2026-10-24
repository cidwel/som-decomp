; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-startup-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eab88 = $AB88
routine_7ead75 = $AD75

.segment "CODE"
.org $AF28
initialize_warm_boot_resources_and_spawn_intro_task:
    jsr routine_7ead75
    .i16
    ldx #$5EC3
    .a8
    lda #$7E
    jsr routine_7eab88

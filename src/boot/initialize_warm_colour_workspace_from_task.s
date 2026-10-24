; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-colour-setup.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e87df = $87DF

.segment "CODE"
.org $9569
initialize_warm_colour_workspace_from_task:
    .a16
    lda #$0000
    .i16
    ldx #$0100
    .i16
    ldy #$00E0
    jsr routine_7e87df

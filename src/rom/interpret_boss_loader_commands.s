; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_boss_loader_command = $21D2

.segment "CODE"
.org $21B7
interpret_boss_loader_commands:
    sta $30
    .a16
    lda #$00C1
    sta $32
interpret_boss_loader_commands_c221be:
    sep #$30
    lda [$30]
    .a8
    cmp #$FF
    beq interpret_boss_loader_commands_c221cf
    rep #$30
    inc $30
    jsr dispatch_boss_loader_command
    bra interpret_boss_loader_commands_c221be
interpret_boss_loader_commands_c221cf:
    rep #$30
    rts

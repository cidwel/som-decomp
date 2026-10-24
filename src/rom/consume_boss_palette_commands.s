; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_boss_palette_command = $10D2

.segment "CODE"
.org $10AC
consume_boss_palette_commands:
    sep #$20
    lda a:$0100,X
    beq consume_boss_palette_commands_c210cf
    lda a:$0102,X
    beq consume_boss_palette_commands_c210c3
    xba
    lda a:$0103,X
    xba
    txy
    iny
    iny
    jsr dispatch_boss_palette_command
consume_boss_palette_commands_c210c3:
    lda a:$0100,X
    xba
    lda a:$0101,X
    xba
    txy
    jsr dispatch_boss_palette_command
consume_boss_palette_commands_c210cf:
    rep #$20
    rts

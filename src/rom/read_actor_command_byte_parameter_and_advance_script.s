; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D6DC
read_actor_command_byte_parameter_and_advance_script:
    pha
    .i16
    ldy #$0001
    lda [$00],Y
    sta $0C
    rep #$20
    lda $00
    inc
    inc
    sta $00
    sep #$20
    pla

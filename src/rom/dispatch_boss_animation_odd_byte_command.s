; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1425
dispatch_boss_animation_odd_byte_command:
    rep #$20
    .a16
    and #$00FE
    tax
    jmp ($142E,X)

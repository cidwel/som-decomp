; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1E2C
actor_script_compare_mp_to_spell_argument_cost:
    ldx a:$0144,Y
    lda f:$D04F17,X
    rep #$20
    .a16
    and #$00FF
    xba
    lsr
    lsr
    tax
    sep #$20
    lda a:$0186,Y
    sec
    sbc f:$D02ADF,X
    rts

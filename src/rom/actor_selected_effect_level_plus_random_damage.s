; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

random_byte_long_wrapper = $C0389C

.segment "CODE"
.org $E29C
actor_selected_effect_level_plus_random_damage:
    ldx $85
    jsl f:random_byte_long_wrapper
    rep #$20
    .a16
    and #$0007
    clc
    adc a:$E181,X
    .a16
    and #$00FF
    inc
    sta a:$E1F1,X
    sep #$20
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

random_byte_long_wrapper = $C0389C

actor_selected_effect_random_status_table = $C8E296

.segment "CODE"
.org $E26C
actor_selected_effect_random_low_status:
    jsl f:random_byte_long_wrapper
    sta f:$004202
    .a8
    lda #$03
    sta f:$004203
    .a8
    lda #$00
    xba
    nop
    nop
    lda f:$004217
    asl
    tax
    rep #$20
    lda f:actor_selected_effect_random_status_table,X
    ldx $85
    ora a:$E190,X
    sta a:$E190,X
    sep #$20
    rts

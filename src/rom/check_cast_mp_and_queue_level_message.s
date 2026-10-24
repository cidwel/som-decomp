; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

queue_cast_spell_level_message = $C05AFD
restore_combat_context_and_return_long = $4000

.segment "CODE"
.org $3F69
check_cast_mp_and_queue_level_message:
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    .a16
    lda #$0000
    sep #$20
    lda f:$D02ADF,X
    ldx $83
    sta $A4
    lda a:$E186,X
    sec
    sbc $A4
    bpl check_cast_mp_and_queue_level_message_c03f8c
    .a8
    lda #$FF
    bra restore_combat_context_and_return_long
check_cast_mp_and_queue_level_message_c03f8c:
    jsl f:queue_cast_spell_level_message
    .a8
    lda #$00
    bra restore_combat_context_and_return_long

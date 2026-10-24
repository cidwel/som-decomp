; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

event_command_public_jump_mirror_01 = $18000

.segment "CODE"
.org $E2F6
actor_selected_effect_request_event:
    .a8
    lda #$05
    xba
    lda a:$E1C9,Y
    jsl f:event_command_public_jump_mirror_01
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

routine_018003 = $18003

.segment "CODE"
.org $3963
boss_external_actor_command_if_selected:
    ldx a:$0362
    bmi boss_external_actor_command_if_selected_c2396c
    jsl f:routine_018003
boss_external_actor_command_if_selected_c2396c:
    rts

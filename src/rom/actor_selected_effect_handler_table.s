; Nine observed effect destinations indexed by caster byte1C8.
.setcpu "65816"
actor_selected_effect_request_event = $E2F6

.segment "CODE"
.org $E259
actor_selected_effect_handler_table:
    .word $E26B, $E26C, $E29C, $E2B5, $E29C, $E2C0, $E2CB, $E26B, actor_selected_effect_request_event

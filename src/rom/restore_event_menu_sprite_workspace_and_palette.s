; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-sprite-context.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00e351 = $E351
routine_02ab30 = $2AB30

.segment "CODE"
.org $F3EA
restore_event_menu_sprite_workspace_and_palette:
    jsl f:routine_00e351
    jsl f:routine_02ab30
    rts

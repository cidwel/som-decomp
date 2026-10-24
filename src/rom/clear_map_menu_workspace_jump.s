; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_map_menu_workspace = $1063

.segment "CODE"
.org $0098
clear_map_menu_workspace_jump:
    jmp clear_map_menu_workspace

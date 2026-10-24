; Bank C0 near-call targets, button-major then page; docs/ui-native-menu-callback-tables.md.
.setcpu "65816"
.segment "CODE"
.org $339F
native_menu_idle_page_callbacks:
    ; Idle callbacks 0; pages 0 through 10.
    .word $3296, $3296, $3296, $3244, $3296, $3296, $30FF, $3296, $3296, $3296, $3296

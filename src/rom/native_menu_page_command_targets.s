; Consumer-typed near targets for the nine native page commands.
.setcpu "65816"
.segment "CODE"
.org $2A68
native_menu_page_command_targets:
    .word $248F, $2626, $2642, $266D, $267B, $2689, $2697, $26A5, $26B3

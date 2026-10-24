.setcpu "65816"
.segment "CODE"
.org $239F
map_control_0c239f:
    .byte $F3 ; progressive-copy count
    .byte $E2 ; previous-row copy count

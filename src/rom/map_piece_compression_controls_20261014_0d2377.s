.setcpu "65816"
.segment "CODE"
.org $2377
map_control_0d2377:
    .byte $E2 ; previous-row copy count
    .byte $F1 ; progressive-copy count

.setcpu "65816"
.segment "CODE"
.org $E305
map_control_0fe305:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count

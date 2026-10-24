.setcpu "65816"
.segment "CODE"
.org $20FF
map_control_0d20ff:
    .byte $E1 ; previous-row copy count

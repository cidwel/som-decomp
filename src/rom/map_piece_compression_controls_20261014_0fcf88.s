.setcpu "65816"
.segment "CODE"
.org $CF88
map_control_0fcf88:
    .byte $E6 ; previous-row copy count

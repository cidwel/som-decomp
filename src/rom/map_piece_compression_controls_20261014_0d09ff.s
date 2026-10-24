.setcpu "65816"
.segment "CODE"
.org $09FF
map_control_0d09ff:
    .byte $E1 ; previous-row copy count

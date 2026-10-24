.setcpu "65816"
.segment "CODE"
.org $60DD
map_control_0d60dd:
    .byte $E1 ; previous-row copy count

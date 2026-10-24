.setcpu "65816"
.segment "CODE"
.org $CD74
map_control_0dcd74:
    .byte $E1 ; previous-row copy count

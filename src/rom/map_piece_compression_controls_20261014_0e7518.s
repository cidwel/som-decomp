.setcpu "65816"
.segment "CODE"
.org $7518
map_control_0e7518:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

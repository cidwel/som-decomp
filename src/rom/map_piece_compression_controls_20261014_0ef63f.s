.setcpu "65816"
.segment "CODE"
.org $F63F
map_control_0ef63f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

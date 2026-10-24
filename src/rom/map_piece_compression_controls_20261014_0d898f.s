.setcpu "65816"
.segment "CODE"
.org $898F
map_control_0d898f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

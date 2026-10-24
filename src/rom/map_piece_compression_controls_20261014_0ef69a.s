.setcpu "65816"
.segment "CODE"
.org $F69A
map_control_0ef69a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

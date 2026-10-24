.setcpu "65816"
.segment "CODE"
.org $1771
map_control_0c1771:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

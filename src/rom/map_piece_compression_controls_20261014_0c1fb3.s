.setcpu "65816"
.segment "CODE"
.org $1FB3
map_control_0c1fb3:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count

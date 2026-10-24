.setcpu "65816"
.segment "CODE"
.org $1649
map_control_0d1649:
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count

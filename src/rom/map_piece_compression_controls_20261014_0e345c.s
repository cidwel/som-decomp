.setcpu "65816"
.segment "CODE"
.org $345C
map_control_0e345c:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

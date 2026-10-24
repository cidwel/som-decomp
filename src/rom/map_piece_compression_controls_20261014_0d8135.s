.setcpu "65816"
.segment "CODE"
.org $8135
map_control_0d8135:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $DD1D
map_control_0ddd1d:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count

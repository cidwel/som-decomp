.setcpu "65816"
.segment "CODE"
.org $CA06
map_control_0fca06:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

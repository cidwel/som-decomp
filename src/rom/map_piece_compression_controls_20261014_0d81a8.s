.setcpu "65816"
.segment "CODE"
.org $81A8
map_control_0d81a8:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

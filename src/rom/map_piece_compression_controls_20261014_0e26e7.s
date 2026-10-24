.setcpu "65816"
.segment "CODE"
.org $26E7
map_control_0e26e7:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

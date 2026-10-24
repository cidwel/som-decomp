.setcpu "65816"
.segment "CODE"
.org $D34D
map_control_0fd34d:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

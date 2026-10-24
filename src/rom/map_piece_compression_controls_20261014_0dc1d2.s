.setcpu "65816"
.segment "CODE"
.org $C1D2
map_control_0dc1d2:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

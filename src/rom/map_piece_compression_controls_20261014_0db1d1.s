.setcpu "65816"
.segment "CODE"
.org $B1D1
map_control_0db1d1:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $B1D4
map_control_0db1d4:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count

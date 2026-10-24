.setcpu "65816"
.segment "CODE"
.org $1295
map_control_0d1295:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

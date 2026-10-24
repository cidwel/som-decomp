.setcpu "65816"
.segment "CODE"
.org $3CF3
map_control_0e3cf3:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $DF71
map_control_0fdf71:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

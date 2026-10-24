.setcpu "65816"
.segment "CODE"
.org $D185
map_control_0fd185:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count

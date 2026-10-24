.setcpu "65816"
.segment "CODE"
.org $1146
map_control_0c1146:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $1107
map_control_0e1107:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $1096
map_control_0e1096:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count

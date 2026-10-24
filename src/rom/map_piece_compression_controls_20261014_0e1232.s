.setcpu "65816"
.segment "CODE"
.org $1232
map_control_0e1232:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

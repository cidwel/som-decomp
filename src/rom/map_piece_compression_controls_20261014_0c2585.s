.setcpu "65816"
.segment "CODE"
.org $2585
map_control_0c2585:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

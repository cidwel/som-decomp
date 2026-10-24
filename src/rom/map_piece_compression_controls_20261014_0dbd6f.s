.setcpu "65816"
.segment "CODE"
.org $BD6F
map_control_0dbd6f:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

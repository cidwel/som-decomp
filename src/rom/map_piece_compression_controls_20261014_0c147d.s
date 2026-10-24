.setcpu "65816"
.segment "CODE"
.org $147D
map_control_0c147d:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

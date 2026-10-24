.setcpu "65816"
.segment "CODE"
.org $3A69
map_control_0c3a69:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

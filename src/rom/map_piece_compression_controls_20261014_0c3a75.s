.setcpu "65816"
.segment "CODE"
.org $3A75
map_control_0c3a75:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

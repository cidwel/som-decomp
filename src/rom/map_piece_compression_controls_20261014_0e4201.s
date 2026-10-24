.setcpu "65816"
.segment "CODE"
.org $4201
map_control_0e4201:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

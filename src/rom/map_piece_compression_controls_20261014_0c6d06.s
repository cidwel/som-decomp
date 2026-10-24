.setcpu "65816"
.segment "CODE"
.org $6D06
map_control_0c6d06:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

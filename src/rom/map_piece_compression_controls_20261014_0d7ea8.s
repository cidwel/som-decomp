.setcpu "65816"
.segment "CODE"
.org $7EA8
map_control_0d7ea8:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

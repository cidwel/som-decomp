.setcpu "65816"
.segment "CODE"
.org $EC68
map_control_0eec68:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

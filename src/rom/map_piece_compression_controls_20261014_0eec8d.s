.setcpu "65816"
.segment "CODE"
.org $EC8D
map_control_0eec8d:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

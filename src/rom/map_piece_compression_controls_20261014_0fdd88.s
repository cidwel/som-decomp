.setcpu "65816"
.segment "CODE"
.org $DD88
map_control_0fdd88:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count

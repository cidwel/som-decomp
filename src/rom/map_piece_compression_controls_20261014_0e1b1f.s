.setcpu "65816"
.segment "CODE"
.org $1B1F
map_control_0e1b1f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

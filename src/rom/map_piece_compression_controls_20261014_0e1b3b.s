.setcpu "65816"
.segment "CODE"
.org $1B3B
map_control_0e1b3b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

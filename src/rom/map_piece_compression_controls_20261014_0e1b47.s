.setcpu "65816"
.segment "CODE"
.org $1B47
map_control_0e1b47:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

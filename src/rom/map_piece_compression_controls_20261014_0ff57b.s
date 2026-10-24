.setcpu "65816"
.segment "CODE"
.org $F57B
map_control_0ff57b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

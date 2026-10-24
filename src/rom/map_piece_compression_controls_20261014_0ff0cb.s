.setcpu "65816"
.segment "CODE"
.org $F0CB
map_control_0ff0cb:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

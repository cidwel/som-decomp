.setcpu "65816"
.segment "CODE"
.org $F49D
map_control_0ff49d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

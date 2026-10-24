.setcpu "65816"
.segment "CODE"
.org $F3C2
map_control_0ff3c2:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

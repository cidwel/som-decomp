.setcpu "65816"
.segment "CODE"
.org $F1A0
map_control_0ff1a0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

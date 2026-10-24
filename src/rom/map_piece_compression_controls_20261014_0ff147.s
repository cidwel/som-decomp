.setcpu "65816"
.segment "CODE"
.org $F147
map_control_0ff147:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

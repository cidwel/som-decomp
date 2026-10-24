.setcpu "65816"
.segment "CODE"
.org $011B
map_control_0e011b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

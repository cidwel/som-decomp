.setcpu "65816"
.segment "CODE"
.org $F3ED
map_control_0ff3ed:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

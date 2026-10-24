.setcpu "65816"
.segment "CODE"
.org $F4C1
map_control_0ff4c1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

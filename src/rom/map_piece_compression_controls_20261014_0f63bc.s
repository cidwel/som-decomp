.setcpu "65816"
.segment "CODE"
.org $63BC
map_control_0f63bc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

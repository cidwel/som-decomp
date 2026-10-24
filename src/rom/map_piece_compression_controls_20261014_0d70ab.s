.setcpu "65816"
.segment "CODE"
.org $70AB
map_control_0d70ab:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

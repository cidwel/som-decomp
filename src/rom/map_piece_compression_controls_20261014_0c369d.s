.setcpu "65816"
.segment "CODE"
.org $369D
map_control_0c369d:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count

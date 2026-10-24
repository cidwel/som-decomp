.setcpu "65816"
.segment "CODE"
.org $730D
map_control_0d730d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

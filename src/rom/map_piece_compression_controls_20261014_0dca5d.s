.setcpu "65816"
.segment "CODE"
.org $CA5D
map_control_0dca5d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

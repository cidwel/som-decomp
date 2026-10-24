.setcpu "65816"
.segment "CODE"
.org $F0E9
map_control_0cf0e9:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

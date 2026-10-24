.setcpu "65816"
.segment "CODE"
.org $F7D6
map_control_0cf7d6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

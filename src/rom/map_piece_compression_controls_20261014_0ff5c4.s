.setcpu "65816"
.segment "CODE"
.org $F5C4
map_control_0ff5c4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

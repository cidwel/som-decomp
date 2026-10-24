.setcpu "65816"
.segment "CODE"
.org $F5E7
map_control_0ff5e7:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

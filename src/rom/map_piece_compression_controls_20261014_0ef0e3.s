.setcpu "65816"
.segment "CODE"
.org $F0E3
map_control_0ef0e3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count

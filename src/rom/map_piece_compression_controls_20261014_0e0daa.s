.setcpu "65816"
.segment "CODE"
.org $0DAA
map_control_0e0daa:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

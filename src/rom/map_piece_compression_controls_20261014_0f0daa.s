.setcpu "65816"
.segment "CODE"
.org $0DAA
map_control_0f0daa:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

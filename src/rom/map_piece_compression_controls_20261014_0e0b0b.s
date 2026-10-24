.setcpu "65816"
.segment "CODE"
.org $0B0B
map_control_0e0b0b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

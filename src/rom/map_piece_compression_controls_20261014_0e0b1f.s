.setcpu "65816"
.segment "CODE"
.org $0B1F
map_control_0e0b1f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count

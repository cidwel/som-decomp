.setcpu "65816"
.segment "CODE"
.org $0CD3
map_control_0e0cd3:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

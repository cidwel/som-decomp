.setcpu "65816"
.segment "CODE"
.org $0375
map_control_0e0375:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count

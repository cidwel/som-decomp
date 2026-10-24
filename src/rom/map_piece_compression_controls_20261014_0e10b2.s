.setcpu "65816"
.segment "CODE"
.org $10B2
map_control_0e10b2:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

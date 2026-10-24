.setcpu "65816"
.segment "CODE"
.org $4508
map_control_0e4508:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

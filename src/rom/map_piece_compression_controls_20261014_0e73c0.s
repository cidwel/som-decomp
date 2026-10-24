.setcpu "65816"
.segment "CODE"
.org $73C0
map_control_0e73c0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

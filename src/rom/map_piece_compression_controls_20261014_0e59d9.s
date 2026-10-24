.setcpu "65816"
.segment "CODE"
.org $59D9
map_control_0e59d9:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count

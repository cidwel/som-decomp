.setcpu "65816"
.segment "CODE"
.org $C1A3
map_control_0dc1a3:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $C1EF
map_control_0dc1ef:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $5DE6
map_control_0f5de6:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count

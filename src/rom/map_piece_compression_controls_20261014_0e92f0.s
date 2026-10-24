.setcpu "65816"
.segment "CODE"
.org $92F0
map_control_0e92f0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

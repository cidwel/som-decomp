.setcpu "65816"
.segment "CODE"
.org $E7F0
map_control_0fe7f0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

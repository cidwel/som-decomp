.setcpu "65816"
.segment "CODE"
.org $177F
map_control_0c177f:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

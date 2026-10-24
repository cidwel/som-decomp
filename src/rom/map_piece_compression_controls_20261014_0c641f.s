.setcpu "65816"
.segment "CODE"
.org $641F
map_control_0c641f:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count

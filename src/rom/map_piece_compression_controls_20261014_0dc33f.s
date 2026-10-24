.setcpu "65816"
.segment "CODE"
.org $C33F
map_control_0dc33f:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count

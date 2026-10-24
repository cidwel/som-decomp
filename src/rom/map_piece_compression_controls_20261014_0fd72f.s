.setcpu "65816"
.segment "CODE"
.org $D72F
map_control_0fd72f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count

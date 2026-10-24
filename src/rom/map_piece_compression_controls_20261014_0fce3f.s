.setcpu "65816"
.segment "CODE"
.org $CE3F
map_control_0fce3f:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count

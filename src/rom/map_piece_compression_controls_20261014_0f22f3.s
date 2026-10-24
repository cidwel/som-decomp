.setcpu "65816"
.segment "CODE"
.org $22F3
map_control_0f22f3:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

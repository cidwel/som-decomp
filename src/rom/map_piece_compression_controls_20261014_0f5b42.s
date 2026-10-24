.setcpu "65816"
.segment "CODE"
.org $5B42
map_control_0f5b42:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

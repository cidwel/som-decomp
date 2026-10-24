.setcpu "65816"
.segment "CODE"
.org $5B47
map_control_0f5b47:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

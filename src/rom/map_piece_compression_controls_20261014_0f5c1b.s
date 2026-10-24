.setcpu "65816"
.segment "CODE"
.org $5C1B
map_control_0f5c1b:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

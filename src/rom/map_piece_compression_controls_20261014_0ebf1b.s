.setcpu "65816"
.segment "CODE"
.org $BF1B
map_control_0ebf1b:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count

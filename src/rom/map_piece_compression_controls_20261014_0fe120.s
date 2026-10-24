.setcpu "65816"
.segment "CODE"
.org $E120
map_control_0fe120:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

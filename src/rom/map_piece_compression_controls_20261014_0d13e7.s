.setcpu "65816"
.segment "CODE"
.org $13E7
map_control_0d13e7:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count

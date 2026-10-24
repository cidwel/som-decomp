.setcpu "65816"
.segment "CODE"
.org $528F
map_control_0e528f:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count

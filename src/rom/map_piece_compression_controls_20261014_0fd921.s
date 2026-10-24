.setcpu "65816"
.segment "CODE"
.org $D921
map_control_0fd921:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count

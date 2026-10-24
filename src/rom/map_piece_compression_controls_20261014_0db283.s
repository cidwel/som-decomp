.setcpu "65816"
.segment "CODE"
.org $B283
map_control_0db283:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count

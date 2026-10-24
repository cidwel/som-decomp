.setcpu "65816"
.segment "CODE"
.org $66B9
map_control_0d66b9:
    .byte $E0 ; previous-row copy escape
    .byte $DA ; row-distance/count

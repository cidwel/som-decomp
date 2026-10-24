.setcpu "65816"
.segment "CODE"
.org $297A
map_control_0c297a:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count

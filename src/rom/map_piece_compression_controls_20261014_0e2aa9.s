.setcpu "65816"
.segment "CODE"
.org $2AA9
map_control_0e2aa9:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count

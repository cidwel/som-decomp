.setcpu "65816"
.segment "CODE"
.org $FD45
map_control_0dfd45:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count

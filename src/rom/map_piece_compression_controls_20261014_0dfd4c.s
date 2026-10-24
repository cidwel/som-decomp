.setcpu "65816"
.segment "CODE"
.org $FD4C
map_control_0dfd4c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

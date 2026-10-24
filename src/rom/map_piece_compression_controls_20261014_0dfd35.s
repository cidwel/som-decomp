.setcpu "65816"
.segment "CODE"
.org $FD35
map_control_0dfd35:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $B331
map_control_0fb331:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $1436
map_control_0c1436:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count

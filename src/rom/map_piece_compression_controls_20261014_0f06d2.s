.setcpu "65816"
.segment "CODE"
.org $06D2
map_control_0f06d2:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count

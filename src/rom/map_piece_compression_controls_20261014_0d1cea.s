.setcpu "65816"
.segment "CODE"
.org $1CEA
map_control_0d1cea:
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count

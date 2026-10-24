.setcpu "65816"
.segment "CODE"
.org $31E9
map_control_0d31e9:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count

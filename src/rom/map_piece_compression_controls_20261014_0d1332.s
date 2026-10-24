.setcpu "65816"
.segment "CODE"
.org $1332
map_control_0d1332:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count

.setcpu "65816"
.segment "CODE"
.org $82AC
map_control_0e82ac:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count

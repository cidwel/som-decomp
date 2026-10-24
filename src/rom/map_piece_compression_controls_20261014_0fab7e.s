.setcpu "65816"
.segment "CODE"
.org $AB7E
map_control_0fab7e:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count

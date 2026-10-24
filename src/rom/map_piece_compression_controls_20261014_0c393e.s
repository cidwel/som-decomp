.setcpu "65816"
.segment "CODE"
.org $393E
map_control_0c393e:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count

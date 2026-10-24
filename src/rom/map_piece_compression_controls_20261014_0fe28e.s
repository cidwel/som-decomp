.setcpu "65816"
.segment "CODE"
.org $E28E
map_control_0fe28e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

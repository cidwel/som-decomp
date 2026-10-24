.setcpu "65816"
.segment "CODE"
.org $E27E
map_control_0fe27e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

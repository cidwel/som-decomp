.setcpu "65816"
.segment "CODE"
.org $7D6E
map_control_0e7d6e:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count

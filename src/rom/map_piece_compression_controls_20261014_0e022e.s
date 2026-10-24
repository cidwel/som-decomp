.setcpu "65816"
.segment "CODE"
.org $022E
map_control_0e022e:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count

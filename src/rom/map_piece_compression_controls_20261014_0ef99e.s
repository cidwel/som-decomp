.setcpu "65816"
.segment "CODE"
.org $F99E
map_control_0ef99e:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count

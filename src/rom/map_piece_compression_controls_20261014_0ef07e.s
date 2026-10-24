.setcpu "65816"
.segment "CODE"
.org $F07E
map_control_0ef07e:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count

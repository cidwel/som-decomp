.setcpu "65816"
.segment "CODE"
.org $572E
map_control_0d572e:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count

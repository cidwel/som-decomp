.setcpu "65816"
.segment "CODE"
.org $533E
map_control_0f533e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count

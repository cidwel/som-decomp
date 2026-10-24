.setcpu "65816"
.segment "CODE"
.org $F55E
map_control_0df55e:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
